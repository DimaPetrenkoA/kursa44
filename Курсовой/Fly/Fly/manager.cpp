#include "stdafx.h"
#include "fly.h"
#include "manager.h"
#include <algorithm>
#include "Cache.h"
vector <Fly*> Flies::devices;
map <int, int> Flies::counts;

//метод добавления объекта в вектор
int Flies::AddFly(Fly* Fly) {
	Flies::counts[Fly->GetCl()]++;	//увеличиваем размерность вектора
	Flies::devices.insert(Flies::devices.end(), Fly);	//добавляем новый объект в конец
	return Flies::devices.size();	//возвращаем текущую размерность вектора
}

//метод очистки вектора (удаление всех объектов)
void Flies::DeleteAllFlies() {
	for (int i = 0; i<Flies::devices.size(); i++)
		delete Flies::devices[i];	//удаляем каждый объект отдельно
	Flies::devices.clear();			//очищаем вектор
	Flies::counts.clear();			//обнуляем переменные для каждого класса
	FCache::saveCache();			//сохраняем текущее состояние в кеш
}

//метод для удаления одного объекта
void Flies::DeleteOneFly(Fly* e) {
	auto F = find(devices.begin(), devices.end(), e);	//ищем в векторе заданный объект
	if (F != devices.end()) {
		devices.erase(F);		//удаляем
	}
	Flies::counts[e->GetCl()]--;	//уменьшаем размерность вектора
	FCache::saveCache();			//сохраняем изменения
}



