#include "Counter.h"
#include "Animal.h"
#include <iostream>

using namespace std;

void Counter::addAnimal(Animal* animal) {
	animals.push_back(animal);
}

void Counter::printAnimalNames() {
	for (auto animal : animals) {
		cout << "\nAdded: " << animal->getName() << endl;
	}
}

void Counter::totalAnimalLegs() {
	int legCounter = 0;
	for (auto animal : animals) {
		legCounter += animal->getLegs();
	}
	cout << "\nTotal legs: " << legCounter << endl;
}