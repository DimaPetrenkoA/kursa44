#pragma once
#include <map>
#include <string>
using namespace std;
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

class Lang {
	static string langName;
	
public:
	static string ln2;
	static string ln1;
	static string setLangFile(string filename);
	static map <int, string> lang;
	static void setLang(string);
	static string getLangName();
	static void setLangFilename();
	static void check();
	static string getLangFilename();
};
