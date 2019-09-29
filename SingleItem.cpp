#include "stdafx.h"
#include "Solution.h"
#include "SingleItem.h"
#include "WStringTool.h"
using namespace std;

extern ifstream infile;
extern ofstream outfile;

void SingleItem::Print() //wstring要转string
{
	outfile << "{";
	outfile << "\"姓名\":" << "\"" << wstring2string(name) << "\",";
	outfile << "\"手机\":" << "\"" << wstring2string(tel) << "\",";
	outfile << "\"地址\":";
	outfile << "[";
	int end = difficulty == 1 ? 5 : 7;
	for (int i = 1; i <= end; i++)
	{
		if (i != 1)
			outfile << ',';
		outfile << "\"" << wstring2string(address[i]) << "\"";
	}
	outfile << "]";
	outfile << "}";
}