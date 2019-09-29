#pragma once
#pragma comment(lib, "comsuppw.lib")
#include "stdafx.h"
using namespace std;
string UnicodeToUTF8(const wstring & wstr);
wstring UTF8ToUnicode(const string & str);
void Initial();