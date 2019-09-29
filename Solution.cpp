#include "stdafx.h"
#include "SingleItem.h"
#include "WStringTool.h"
#include "Solution.h"
using namespace std;

extern vector<wstring> prov_vec; 
extern map<wstring, vector<wstring>> prov_s_city;

SingleItem Solution::Solve(wstring input)
{
	input.pop_back(); //删除句尾逗号
	SingleItem ans;
	ans.difficulty = GetDifficulty(input);
	ans.name = GetName(input);
	ans.tel = GetTel(input);
	input.erase(0, input.find(L",") + 1); //将字符串“,”之前已收集的部分删除
	input.erase(input.find(ans.tel), 11); //将字符串中电话号码删除
	if (IsMunicipality(input, ans) == false) //判断是不是直辖市，如果是则收集并删除一级二级地址，不是则在数据中查找
	{
		ans.address[1] = GetProvince(input);
		ans.address[2] = GetCity(input, ans.address[1]);
	}
	ans.address[3] = GetThird(input);
	ans.address[4] = GetFourth(input);
	if (ans.difficulty == 1)
		ans.address[5] = input;
	else
	{
		ans.address[5] = GetFifth(input);
		ans.address[6] = GetSixth(input);
		ans.address[7] = input; //剩余的即为七级地址
	}
	return ans;
}
int Solution::GetDifficulty(const wstring &input) //查找难度
{
	if (input[0] == L'1') return 1;
	if (input[0] == L'2') return 2;
	if (input[0] == L'3') return 3;
}
wstring Solution::GetName(const wstring &input) //查找姓名
{
	wstring ret;
	for (int i = 2; input[i] != L','; i++)
		ret.push_back(input[i]);
	return ret;
}
wstring Solution::GetTel(const wstring &input) //查找电话
{
	wstring ret;
	for (int i = 0; i < input.length(); i++)
	{
		if (L'0' <= input[i] && input[i] <= L'9')
			ret.push_back(input[i]);
		else
			ret = L"";
		if (ret.length() == 11)
			break;
	}
	return ret;
}
bool Solution::IsMunicipality(wstring &input, SingleItem &ans) //判断是不是直辖市，如果是则收集并删除一级二级地址
{
	for (int i = 0; i < 4; i++)
	{
		if (input.find(prov_vec[i]) != input.npos)
		{
			ans.address[1] = prov_vec[i];
			ans.address[2] = prov_vec[i] + L"市";
			if (input[2] == L'市')
				input.erase(0, 3);
			else
				input.erase(0, 2);
			return true;
		}
	}
	return false;
}
wstring Solution::GetProvince(wstring &input) //查找省
{
	wstring ret;
	for (int i = 0; i < prov_vec.size(); i++)
	{
		if (input.find(prov_vec[i]) != input.npos)
		{
			ret = prov_vec[i] + L'省';
			if (input[prov_vec[i].size()] == L'省')
				input.erase(0, prov_vec[i].size() + 1);
			else
				input.erase(0, prov_vec[i].size());
			break;
		}
	}
	return ret;
}
wstring Solution::GetCity(wstring &input, const wstring &province) //查找市
{
	wstring ret;
	vector<wstring> city = prov_s_city[province.substr(0, province.size()-1)];
	for (int i = 0; i < city.size(); i++)
	{
		if (input.find(city[i].substr(0, city[i].size()-1)) != input.npos)
		{
			ret = city[i];
			if (input[city[i].size() - 1] == L'市')
				input.erase(0, city[i].size());
			else
				input.erase(0, city[i].size() - 1);
			break;
		}
	}
	return ret;
}
wstring Solution::GetThird(wstring &input) //查三级地址
{
	wstring ret;
	int pos;
	for (pos = 0; pos < input.length(); pos++)
		if (input[pos] == L'区' || input[pos] == L'县' || input[pos] == L'市')
			break;
	if (pos != input.length())
	{
		if (pos <= 3) //因为这个区可能不是第三级地名
		{
			ret = input.substr(0, pos + 1);
			input.erase(0, ret.length());
		}
	}
	return ret;
}
wstring Solution::GetFourth(wstring &input) //查四级地址
{
	wstring ret;
	int pos;
	for (pos = 0; pos < input.length(); pos++)
		if ((pos && input.substr(pos-1, 2) == L"街道") || input[pos] == L'镇' || input[pos] == L'乡')
			break;
	if (pos != input.length())
	{
		ret = input.substr(0, pos + 1);
		input.erase(0, ret.length());
	}
	return ret;
}
wstring Solution::GetFifth(wstring &input)
{
	wstring ret;
	int pos;
	for (pos = 0; pos < input.length(); pos++)
		if (input[pos] == L'路' || input[pos] == L'街' || input[pos] == L'巷')
			break;
	if (pos != input.length())
	{
		ret = input.substr(0, pos + 1);
		input.erase(0, ret.length());
	}
	return ret;
}
wstring Solution::GetSixth(wstring &input) //查六级地址门牌号
{
	wstring ret;
	int pos = input.find(L"号");
	if (pos != input.npos)
	{
		ret = input.substr(0, pos + 1);
		input.erase(0, pos + 1);
	}
	return ret;
}