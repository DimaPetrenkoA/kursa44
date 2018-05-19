#include "stdafx.h"
#include "Cache.h"
#include "manager.h"
#include "fly.h"
#include "helicopter.h"
#include "getvalues.h"
#include "jetfighter.h"
#include "bomber.h"
#include "plain.h"
#include "transportAircraft.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream> 
#include "lang.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

string FCache::filename;		//��� ����� ����

//����� ��������� ����� ����� ����
void FCache::setCacheFilename(string filename) {

	FCache::filename = filename;
}

//����� ���������� �������� � ����
void FCache::saveCache() {
	setlocale(LC_ALL, "Russian");
	ofstream Cache;
	Cache.open(getCacheName());		//��������� �����
		
	if (Cache.is_open()) {			//���� ������, �������� ������
		Cache << setiosflags(ios::left);
		Cache << Lang::getLangName() << endl;	//������ ������� - ��� ����� ����������
		Cache << setw(10);						//����� ���������� ��� ����� ����� �������
		Cache << Lang::lang[85];
		Cache << setw(15);
		Cache << Lang::lang[86];
		Cache << setw(20);
		Cache << Lang::lang[87];
		Cache << setw(30);
		Cache << Lang::lang[88];
		Cache << setw(15);
		Cache << Lang::lang[89];
		Cache << setw(20);
		Cache << Lang::lang[90];
		Cache << setw(20);
		Cache << Lang::lang[91];
		Cache << setw(20);
		Cache << Lang::lang[92];
		Cache << setw(20);
		Cache << Lang::lang[93];
		Cache << setw(20);
		Cache << Lang::lang[94];
		Cache << setw(20);
		Cache << Lang::lang[95];
		Cache << setw(20);
		Cache << Lang::lang[96];
		Cache << setw(20);
		Cache << Lang::lang[97];
		Cache << setw(20);
		Cache << Lang::lang[99];
		Cache << setw(20);
		Cache << Lang::lang[100];
		Cache << setw(25);
		Cache << Lang::lang[101];
		Cache << setw(25);
		Cache << Lang::lang[144];
		Cache << setw(18);
		Cache << Lang::lang[145];
		Cache << setw(18);
		Cache << Lang::lang[146] << endl;
		Cache << setw(20);

		//���������� ���� �� ������ �� ����� �������, ��������� �������
		for (int i = 0; i < Flies::devices.size(); i++) {
			Fly* device = Flies::devices[i];			//�������� ������
			int type = device->GetCl();	
			Cache << setw(10);							
			Cache << type;								//���������� ����� ������
			Cache.width(15);
			Cache << device->GetSpeed();				//���������� ��� �������� ����, ���� �������� ����������� ���������� "none"
			Cache << '|';
			Cache << setw(20);
			(device->GetDistance()) ? Cache << device->GetDistance() : Cache << "none";
			Cache << '|';
			Cache << setw(29);
			(device->GetNumOfPass()) ? Cache << device->GetNumOfPass() : Cache << "none";
			Cache << '|';
			Cache << setw(14);
			(device->GetHeight()) ? Cache << device->GetHeight() : Cache << "none";
			Cache << '|';

			switch (type)
			{
			case 2: {
				helicopter* device = (helicopter*)Flies::devices[i];		//���� ��������� ����� �� ��������, �������� ������ � ������������ ����
				Cache << setw(19);										//���������� ������ �������� �����
				Cache << '|';
				Cache << device->GetNumOfScrew();
				Cache << setw(19);
				Cache << '|';
				Cache << device->GetCapacity();
				Cache << '|';
				break;}
			case 3: {
				jetfighter* device = (jetfighter*)(Flies::devices[i]);	//���� ��������� ����� �� ��������, �������� ������ � ������������ ����
				Cache << setw(40);										//���������� ������ �������� �����
				Cache << '|';
				Cache << device->getType();
				Cache << setw(13);
				Cache << '|';
				Cache << device->getCountry();
				Cache << setw(17);
				Cache << '|';
				Cache << device->getGuns();
				Cache << '|';
				break;
			}
			case 4: {
				bomber* device = (bomber*)(Flies::devices[i]);	//���� ��������� ����� �� ��������, �������� ������ � ������������ ����
				Cache << setw(100);								//���������� ������ �������� �����
				Cache << '|';
				Cache << device->getFmass();
				Cache << setw(15);
				Cache << '|';
				Cache << device->getFradius();
				Cache << setw(16);
				Cache << '|';
				Cache << device->getPtime();
				Cache << '|';
				break;
			}
			case 5: {
				plain* device = (plain*)(Flies::devices[i]);		//���� ��������� ����� �� ��������, �������� ������ � ������������ ����
				Cache << setw(200);									//���������� ������ �������� �����
				Cache << '|';
				Cache << device->getCrew();
				Cache << setw(24);
				Cache << '|';
				Cache << device->getEngines();
				Cache << setw(24);
				Cache << '|';
				Cache << device->getAge();
				Cache << setw(17);
				Cache << '|';
				Cache << device->getModel();
				Cache << '|';
				break;
			}
			case 6: {
				transportAircraft* device = (transportAircraft*)(Flies::devices[i]);	//���� ��������� ����� �� ��������, �������� ������ � ������������ ����
				Cache << setw(160);														//���������� ������ �������� �����
				Cache << '|';
				Cache << device->getCarrying();
				Cache << setw(18);
				Cache << '|';
				Cache << device->getPrefix();
				Cache << '|';
				break;
			}
			default:
				break;
			}

			Cache << endl;

		}
		Cache.close();		//���� �������� ������ ���, ��������� �����

	}
	else {
		cout << Lang::lang[84] << endl;		//����� ������� ��������� � ������������� ������� ���� ����
		system("pause");
		_exit(0);
	}

}

//����� ��� ���������� ������ �� ����� ����
vector<Fly*> FCache::getCache() {
	ifstream Cache(FCache::filename, ios_base::in);		//����� ��� ��������� �����
	if (Cache.is_open()) {
		if (!Cache.eof()) {		//���� �� ����� �����
			string temp;
			string temp22;
			string temp4;
			stringstream temp2;
			stringstream temp3;

			getline(Cache, temp, '\n');				//�������� ������ ������ ���������� ����
			if (temp != Lang::getLangName() && temp != "") {
				Lang::setLang(temp);
			}

			getline(Cache, temp22, '\n');		//��������� ��������� ������ �� ������� \n - ����� �����

			while (getline(Cache, temp4, '\n')) {	//��������� ��������� ������ �� ������� \n - ������ ������
				temp2 << temp4;						//�������� ���������� �� ������ � stringbuffer
				//char* t = temp4.c_str();

				string Typee;
				getline(temp2, Typee, ' ');			//����� ��������� ���������� �� ������� - ��� �������
				const char* n = Typee.c_str();
				int type = atoi(n);

				string speedTemp;										//��������� ����� �� ����������� "|" � ������� �� ������
				getline(temp2, speedTemp, '|');							//� ������������ ��������� ��������� �� ��������
				char *speed = new char[speedTemp.length() + 1];
				strcpy(speed, speedTemp.c_str());
				int spd = atoi(speed);

				string heightTemp;
				getline(temp2, heightTemp, '|');
				char *height = new char[heightTemp.length() + 1];
				strcpy(height, heightTemp.c_str());
				int hei = atoi(height);

				string numTemp;
				getline(temp2, numTemp, '|');
				char *numb = new char[numTemp.length() + 1];
				strcpy(numb, numTemp.c_str());
				int num = atoi(numb);

				string distTemp;
				getline(temp2, distTemp, '|');
				char *distance = new char[distTemp.length() + 1];
				strcpy(distance, distTemp.c_str());
				int dist = atoi(distance);

				//� ����������� �� ���� ������� ���������� ��������� ����
				switch (type) {
				case 1:
					Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new Fly(spd, dist, num, hei)));	//�������� ������ � ����������� ������ � ������
					Flies::counts[1]++;								//����������� ���������� ��� ������� ���� ��������
					Flies::devices[0]->id = 1;
					break;
				case 2: {
					string str = "none";					//���������� ��������� ���� �� ����������� "|"
					string screwTemp = "none";
					string capacityTemp = "none";
					if (type == 2) {
						getline(temp2, str, '|');
						getline(temp2, screwTemp, '|');
						getline(temp2, capacityTemp, '|');
					}
					if (screwTemp != "none" && capacityTemp != "none") {
						char *screw = new char[screwTemp.length() + 1];
						strcpy(screw, screwTemp.c_str());
						int scr = atoi(screw);

						char *cap = new char[capacityTemp.length() + 1];
						strcpy(cap, capacityTemp.c_str());
						int cp = atoi(cap);

						Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new helicopter(spd, dist, num, hei, scr, cp)));
						Flies::counts[2]++;
						helicopter* device = (helicopter*)Flies::devices[Flies::devices.size() - 1];
					}
					break;
				}
				case 3: {				
					string str = "none";				//���������� ��������� ���� �� ����������� "|"
					string TypeTemp = "none";
					string GunsTemp = "none";
					string CountryTemp = "none";

					getline(temp2, str, '|');
					getline(temp2, TypeTemp, '|');
					TypeTemp.erase(0, 38);
					getline(temp2, CountryTemp, '|');
					CountryTemp.erase(0, 10);
					getline(temp2, GunsTemp, '|');
					if (CountryTemp != "none" && GunsTemp != "none" && TypeTemp != "none") {
						string countr;
						countr = CountryTemp;

						string tp;
						tp = TypeTemp;

						char *gns = new char[GunsTemp.length() + 1];
						strcpy(gns, GunsTemp.c_str());
						int g = atoi(gns);
						Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new jetfighter(spd, dist, num, hei, countr, g, tp)));
						Flies::counts[3]++;
						jetfighter* device = (jetfighter*)(Flies::devices[Flies::devices.size() - 1]);
						break;
					}
				}
				case 4: {
					string str = "none";				//���������� ��������� ���� �� ����������� "|"
					string massTemp = "none";
					string radTemp = "none";
					string timeTemp = "none";
					if (type == 4) {
						getline(temp2, str, '|');
						getline(temp2, radTemp, '|');
						getline(temp2, massTemp, '|');
						getline(temp2, timeTemp, '|');
					}
					if (radTemp != "none" && massTemp != "none" && timeTemp!= "none") {
						char *radius = new char[radTemp.length() + 1];
						strcpy(radius, radTemp.c_str());
						int rad = atoi(radius);

						char *mass = new char[massTemp.length() + 1];
						strcpy(mass, massTemp.c_str());
						int mas = atoi(mass);

						char *time = new char[timeTemp.length() + 1];
						strcpy(time, timeTemp.c_str());
						int tm = atoi(time);

						
						Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new bomber(spd, dist, num, hei, rad, mas, tm)));
						Flies::counts[4]++;
						bomber* device = (bomber*)(Flies::devices[Flies::devices.size() - 1]);

					}
					break;
				}
				case 5: {
					string str = "none";				//���������� ��������� ���� �� ����������� "|"
					string crewTemp = "none";
					string enginesTemp = "none";
					string modelTemp = "none";
					string ageTemp = "none";
					if (type == 5) {
						getline(temp2, str, '|');
						getline(temp2, crewTemp, '|');
						getline(temp2, enginesTemp, '|');
						getline(temp2, modelTemp, '|');
						getline(temp2, ageTemp, '|');
						
					}
					if (crewTemp != "none" && enginesTemp != "none" && modelTemp != "none" && ageTemp != "none") {

						char *crew = new char[crewTemp.length() + 1];
						strcpy(crew, crewTemp.c_str());
						int crw = atoi(crew);
						
						char *engines = new char[enginesTemp.length() + 1];
						strcpy(engines, enginesTemp.c_str());
						int eng = atoi(engines);

						char *mode = new char[modelTemp.length() + 1];
						strcpy(mode, modelTemp.c_str());
						int mdl = atoi(mode);

						char *age = new char[ageTemp.length() + 1];
						strcpy(age, ageTemp.c_str());
						int a = atoi(age);

						Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new plain(spd, dist, num, hei, crw, eng, mdl, a)));
						Flies::counts[5]++;
						plain* device = (plain*)(Flies::devices[Flies::devices.size() - 1]);

					}
					break;
				}
				case 6: {
					string str = "none";				//���������� ��������� ���� �� ����������� "|"
					string carrTemp = "none";
					string prefTemp = "none";

					if (type == 6) {
						getline(temp2, str, '|');
						getline(temp2, carrTemp, '|');
						getline(temp2, prefTemp, '|');
						prefTemp.erase(0, 17);
					}

					char *carr = new char[carrTemp.length() + 1];
					strcpy(carr, carrTemp.c_str());
					int cr = atoi(carr);

					string pref = prefTemp;

					Flies::devices.insert(Flies::devices.end(), dynamic_cast<Fly*>(new transportAircraft(spd, dist, num, hei, cr, pref)));
					Flies::counts[6]++;
					transportAircraft* device = (transportAircraft*)(Flies::devices[Flies::devices.size() - 1]);

					break;
				}
				}
			}
		}

		Cache.close();			//��������� ����� �����

	}
	else {
		cout << Lang::lang[84] << endl;		//����� ������� ��������� � ������������ ������ � ������
		system("pause");
	}

	return Flies::devices;			//���������� ������ �� ���������� ���������
}

//����� ��������� ����� �������� ����� ����
string FCache::getCacheName() {
	return filename;
}