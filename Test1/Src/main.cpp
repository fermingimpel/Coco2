#include <iostream>

#include "Coco2/Coco2.h"

int main() {

	std::cout << "ASD" << std::endl;

	Coco2* coco = new Coco2();

	coco->Print();

	delete coco;

	return 0;
}