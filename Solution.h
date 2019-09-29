#pragma once
#include "stdafx.h"
#include "SingleItem.h"
#include "WStringTool.h"
using namespace std;

class Solution {
public:
	SingleItem Solve(wstring input);
	bool IsMunicipality(wstring &input, SingleItem &ans);
	int GetDifficulty(const wstring &input);
	wstring GetName(const wstring &input);
	wstring GetTel(const wstring &input);
	wstring GetProvince(wstring &input);
	wstring GetCity(wstring &input, const wstring &province);
	wstring GetThird(wstring &input);
	wstring GetFourth(wstring &input);
	wstring GetFifth(wstring &input);
	wstring GetSixth(wstring &input);
};

