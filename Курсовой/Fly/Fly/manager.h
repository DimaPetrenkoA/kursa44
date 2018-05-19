#pragma once
#include "stdafx.h"
#include <vector>
#include <map>
#include <iterator>
#include "fly.h"
using namespace std;

class Flies {
public:
	int id;
	static map <int, int> counts;
	static vector<Fly* > devices;
	static int AddFly(Fly* device);
	static void DeleteOneFly(Fly*);
	static void DeleteAllFlies();

};
