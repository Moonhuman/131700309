#pragma once
#include "stdafx.h"
#include "WStringTool.h"
using namespace std;
class SingleItem {
private:
	int difficulty;     //难度1-3
	wstring name, tel;
	wstring address[8]; //最多7级地址
public:
	friend class Solution;
	void Print();
};
