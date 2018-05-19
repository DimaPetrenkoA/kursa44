#pragma once
#include <vector>
#include "fly.h"
#include <string.h>
using namespace std;

class FCache {
private:
	static string filename;
public:
	static void setCacheFilename(string);
	static vector<Fly*> getCache();
	static void saveCache();
	static string getCacheName();
};