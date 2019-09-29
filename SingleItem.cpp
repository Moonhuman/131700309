#include "stdafx.h"
#include "Solution.h"
#include "SingleItem.h"
#include "WStringTool.h"
using namespace std;

extern ifstream infile;
extern ofstream outfile;
extern string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;

void SingleItem::Print() //wstring要转string
{

	outfile << s1;
	outfile << s2 << s3 << UnicodeToUTF8(name) << s4;
	outfile << s5 << s6 << UnicodeToUTF8(tel) << s7;
	outfile << s8;
	outfile << s9;


	/*
	outfile << L"{";
	outfile << L"\"姓名\":" << L"\"" << UnicodeToUTF8(name) << L"\",";
	outfile << L"\"手机\":" << L"\"" << UnicodeToUTF8(tel) << L"\",";
	outfile << L"\"地址\":";
	outfile << L"[";
	*/
	int end = difficulty == 1 ? 5 : 7;
	for (int i = 1; i <= end; i++)
	{
		if (i != 1)
			outfile << s10;
		outfile << s3 << UnicodeToUTF8(address[i]) << s3;
	}
	outfile << s11;
	outfile << s12;
}