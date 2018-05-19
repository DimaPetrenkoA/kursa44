#include <sstream>
#include "fly.h"

using namespace std;
class bomber : public Fly {
protected:
	int fradius;	//боевой радиус (м)
	int fmass;		//боевая нагрузка (кг)
	int ptime;		//время патрулирования(ч)

	const int maxdist = 14000; //макс. дистанция полета бомбардировщика
	const int maxheight = 20000; //макс. высота полета бомбардировщика
	const int maxspeed = 2200; //макс. скорость полета бомбардировщика
public:
	bomber();
	bomber(int S, int Dis, int Num, int H, int fr, int fm, int pt);
	~bomber();
	int setFradius();
	int getFradius();
	int setFmass();
	int getFmass();
	int setPtime();
	int getPtime();
	int SetDistance();
	int SetHeight();
	int SetNumOfPass();
	int SetSpeed();

	void print();
	void Edit();

};