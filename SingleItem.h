#pragma once
#include "stdafx.h"
#include "WStringTool.h"
using namespace std;
class SingleItem {
private:
	int difficulty;     //�Ѷ�1-3
	wstring name, tel;
	wstring address[8]; //���7����ַ
public:
	friend class Solution;
	void Print();
};
