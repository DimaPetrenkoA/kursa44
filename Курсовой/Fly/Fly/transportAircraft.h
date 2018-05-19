#include <sstream>
#include "fly.h"
#include "plain.h"

using namespace std;
class transportAircraft : public Fly {
protected:
	int carrying;
	string prefix;

	const int maxdist = 4500; //макс. дистанция полета летательного аппарата
	const int maxheight = 11000; //макс. высота полета летательного аппарата
	const int maxspeed = 850; //макс. скорость полета летательного аппарата
public:
	transportAircraft();
	transportAircraft(int S, int Dis, int Num, int H, int car, string pre);
	~transportAircraft();
	int SetNumOfPass();
	int SetHeight();
	int setPrefix();
	string getPrefix();
	int setCarrying();
	int SetDistance();
	int SetSpeed();
	int getCarrying();

	void print();
	void Edit();
};
