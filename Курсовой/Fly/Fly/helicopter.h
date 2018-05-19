#include <sstream>
#include "fly.h"
using namespace std;

class helicopter: public Fly {
protected:
	int numOfScrew;
	int capacity;
	const int maxdist = 800; //макс. дальность полета вертолета
	const int maxheight = 9150; //макс. высота полета вертолета
	const int maxpass = 85; //макс. количество пассажиров вертолета
	int maxspeed = 295; //макс. скорость полета вертолета
public:
	int Fuel;
	helicopter();
	helicopter(int S, int Dis, int num, int H, int numS, int Cap);
	~helicopter();
	int GetNumOfScrew();
	int SetNumOfScrew();
	int GetCapacity();
	int SetCapacity();
	int AddFuel(int F);
	int operator~();
	int SetDistance();
	int SetSpeed();
	int SetNumOfPass();
	int SetHeight();
	void print();
	void Edit();
};
