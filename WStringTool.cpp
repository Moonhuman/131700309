#include "stdafx.h"
#include "WStringTool.h"
#include <codecvt> 
using namespace std;


string UnicodeToUTF8(const wstring & wstr) {
	string ret;
	try {
		wstring_convert< codecvt_utf8<wchar_t> > wcv;
		ret = wcv.to_bytes(wstr);
	}
	catch (const exception & e) {
		cerr << e.what() << endl;
		exit(0);
	}
	return ret;
}
wstring UTF8ToUnicode(const string & str) {
	wstring ret;
	try {
		wstring_convert< codecvt_utf8<wchar_t> > wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const exception & e) {
		cerr << e.what() << endl;
		exit(0);
	}
	return ret;
}

vector<wstring> prov_vec; //�����е�ʡ
map<wstring, vector<wstring>> prov_s_city; //ʡ�µ���
string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;

void Initial()
{
	s1 = UnicodeToUTF8(L"{"); s2 = UnicodeToUTF8(L"\"����\":"); s3 = UnicodeToUTF8(L"\"");
	s4 = UnicodeToUTF8(L"\","); s5 = UnicodeToUTF8(L"\"�ֻ�\":"); s6 = UnicodeToUTF8(L"\"");
	s7 = UnicodeToUTF8(L"\","); s8 = UnicodeToUTF8(L"\"��ַ\":"); s9 = UnicodeToUTF8(L"[");
	s10 = UnicodeToUTF8(L","); s11 = UnicodeToUTF8(L"]"); s12 = UnicodeToUTF8(L"}");

	ifstream in("AddressData.txt");
	if (!in.is_open())
	{
		cout << "Can not open AddressData file" << endl;
		exit(0);
	}
	string province;
	while (in >> province)
	{
		//cout << province << endl;
		wstring wprovince = UTF8ToUnicode(province);
		prov_vec.push_back(wprovince);
		string city;
		while (in >> city)
		{
			wstring wcity = UTF8ToUnicode(city);
			if (wcity == L"#")
				break;
			prov_s_city[wprovince].push_back(wcity);
		}
	}
	in.close();
}