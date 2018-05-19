#pragma once
#include <sstream>
#include "fly.h"

using namespace std;
class plain : public Fly {
protected:
	int crew;
	int engines;
	int age;
	int model;

	const int maxdist = 21601; //макс. дистанция пассажирского самолета
	const int maxheight = 37650; //макс. высота пассажирского самолета
	const int maxpass = 850; //макс. количество пассажиров пассажирского самолета
	const int maxspeed = 2570; //макс. скорость пассажирского самолета

public:
	plain();
	plain(int S, int Dis, int Num, int H, int cr, int eng, int a, int m);
	~plain();
	int setEngines();
	int getEngines();
	int setCrew();
	int getCrew();
	int setAge();
	int getAge();
	int setModel();
	int getModel();

	int SetDistance();
	int SetHeight();
	int SetSpeed();
	int SetNumOfPass();

	friend plain& operator++(plain&); //перегрузка оператора ++ Новое действие повысить срок эксаплуатации самолета
	void print();
	void Edit();
};