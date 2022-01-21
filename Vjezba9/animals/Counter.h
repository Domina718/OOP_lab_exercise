#pragma once
#include "Animal.h"
#include "Sparrow.h"
#include "Cockroach.h"
#include "Tarantula.h"
#include <vector>

class Counter {
	vector<Animal*> animals;
public:
	void addAnimal(Animal* animal);
	void printAnimalNames();
	void totalAnimalLegs();
};