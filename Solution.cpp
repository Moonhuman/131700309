#include "stdafx.h"
#include "SingleItem.h"
#include "WStringTool.h"
#include "Solution.h"
using namespace std;

extern vector<wstring> prov_vec; 
extern map<wstring, vector<wstring>> prov_s_city;

SingleItem Solution::Solve(wstring input)
{
	input.pop_back(); //ɾ����β����
	SingleItem ans;
	ans.difficulty = GetDifficulty(input);
	ans.name = GetName(input);
	ans.tel = GetTel(input);
	input.erase(0, input.find(L",") + 1); //���ַ�����,��֮ǰ���ռ��Ĳ���ɾ��
	input.erase(input.find(ans.tel), 11); //���ַ����е绰����ɾ��
	if (IsMunicipality(input, ans) == false) //�ж��ǲ���ֱϽ�У���������ռ���ɾ��һ��������ַ���������������в���
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
		ans.address[7] = input; //ʣ��ļ�Ϊ�߼���ַ
	}
	return ans;
}
int Solution::GetDifficulty(const wstring &input) //�����Ѷ�
{
	if (input[0] == L'1') return 1;
	if (input[0] == L'2') return 2;
	if (input[0] == L'3') return 3;
}
wstring Solution::GetName(const wstring &input) //��������
{
	wstring ret;
	for (int i = 2; input[i] != L','; i++)
		ret.push_back(input[i]);
	return ret;
}
wstring Solution::GetTel(const wstring &input) //���ҵ绰
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
bool Solution::IsMunicipality(wstring &input, SingleItem &ans) //�ж��ǲ���ֱϽ�У���������ռ���ɾ��һ��������ַ
{
	for (int i = 0; i < 4; i++)
	{
		if (input.find(prov_vec[i]) != input.npos)
		{
			ans.address[1] = prov_vec[i];
			ans.address[2] = prov_vec[i] + L"��";
			if (input[2] == L'��')
				input.erase(0, 3);
			else
				input.erase(0, 2);
			return true;
		}
	}
	return false;
}
wstring Solution::GetProvince(wstring &input) //����ʡ
{
	wstring ret;
	for (int i = 0; i < prov_vec.size(); i++)
	{
		if (input.find(prov_vec[i]) != input.npos)
		{
			ret = prov_vec[i] + L'ʡ';
			if (input[prov_vec[i].size()] == L'ʡ')
				input.erase(0, prov_vec[i].size() + 1);
			else
				input.erase(0, prov_vec[i].size());
			break;
		}
	}
	return ret;
}
wstring Solution::GetCity(wstring &input, const wstring &province) //������
{
	wstring ret;
	vector<wstring> city = prov_s_city[province.substr(0, province.size()-1)];
	for (int i = 0; i < city.size(); i++)
	{
		if (input.find(city[i].substr(0, city[i].size()-1)) != input.npos)
		{
			ret = city[i];
			if (input[city[i].size() - 1] == L'��')
				input.erase(0, city[i].size());
			else
				input.erase(0, city[i].size() - 1);
			break;
		}
	}
	return ret;
}
wstring Solution::GetThird(wstring &input) //��������ַ
{
	wstring ret;
	int pos;
	for (pos = 0; pos < input.length(); pos++)
		if (input[pos] == L'��' || input[pos] == L'��' || input[pos] == L'��')
			break;
	if (pos != input.length())
	{
		if (pos <= 3) //��Ϊ��������ܲ��ǵ���������
		{
			ret = input.substr(0, pos + 1);
			input.erase(0, ret.length());
		}
	}
	return ret;
}
wstring Solution::GetFourth(wstring &input) //���ļ���ַ
{
	wstring ret;
	int pos;
	for (pos = 0; pos < input.length(); pos++)
		if ((pos && input.substr(pos-1, 2) == L"�ֵ�") || input[pos] == L'��' || input[pos] == L'��')
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
		if (input[pos] == L'·' || input[pos] == L'��' || input[pos] == L'��')
			break;
	if (pos != input.length())
	{
		ret = input.substr(0, pos + 1);
		input.erase(0, ret.length());
	}
	return ret;
}
wstring Solution::GetSixth(wstring &input) //��������ַ���ƺ�
{
	wstring ret;
	int pos = input.find(L"��");
	if (pos != input.npos)
	{
		ret = input.substr(0, pos + 1);
		input.erase(0, pos + 1);
	}
	return ret;
}