#include <iostream>
#include "Counter.h"


using namespace std;

int main()
{
	Counter cnt;

	cnt.addAnimal(new Sparrow());
	cnt.addAnimal(new Cockroach());
	cnt.addAnimal(new Tarantula());

	cnt.printAnimalNames();

	cnt.totalAnimalLegs();

	return 0;
}
