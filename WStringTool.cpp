#include "stdafx.h"
#include "WStringTool.h"
using namespace std;
string wstring2string(const wstring& ws)
{
	_bstr_t t = ws.c_str();
	char* pchar = (char*)t;
	string result = pchar;
	return result;
}
wstring string2wstring(const string& s)
{
	_bstr_t t = s.c_str();
	wchar_t* pwchar = (wchar_t*)t;
	wstring result = pwchar;
	return result;
}
vector<wstring> prov_vec; //存所有的省
map<wstring, vector<wstring>> prov_s_city; //省下的市
void Initial()
{
	ifstream in("AddressData.txt");
	if (!in.is_open())
	{
		cout << "Can not open AddressData file" << endl;
		exit(0);
	}
	string province;
	while (in >> province)
	{
		wstring wprovince = string2wstring(province);
		prov_vec.push_back(wprovince);
		string city;
		while (in >> city)
		{
			if (city == "#")
				break;
			wstring wcity = string2wstring(city);
			prov_s_city[wprovince].push_back(wcity);
		}
	}
	in.close();
}