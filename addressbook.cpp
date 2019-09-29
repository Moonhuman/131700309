#include "stdafx.h"
#include "SingleItem.h"
#include "WStringTool.h"
#include "Solution.h"
using namespace std;

ifstream infile;
ofstream outfile;

int main(int argv, char** argc)
{
	wcin.imbue(locale("chs"));
	wcout.imbue(locale("chs"));
	Initial();
	
	infile.open(argc[1]);
	outfile.open(argc[2]);

	int cnt = 0;
	string line;
	wstring input;
	Solution solution;
	SingleItem ans;
	outfile << UnicodeToUTF8(L"[");
	while (infile >> line)
	{
		input = UTF8ToUnicode(line);
		ans = solution.Solve(input);
		if (++cnt != 1)
			outfile << UnicodeToUTF8(L",");
		ans.Print();
	}
	outfile << UnicodeToUTF8(L"]");

	infile.close();
	outfile.close();

    return 0;
}
