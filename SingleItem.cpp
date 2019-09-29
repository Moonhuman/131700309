#include "stdafx.h"
#include "Solution.h"
#include "SingleItem.h"
#include "WStringTool.h"
using namespace std;

extern ifstream infile;
extern ofstream outfile;

void SingleItem::Print() //wstringҪתstring
{
	outfile << "{";
	outfile << "\"����\":" << "\"" << wstring2string(name) << "\",";
	outfile << "\"�ֻ�\":" << "\"" << wstring2string(tel) << "\",";
	outfile << "\"��ַ\":";
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