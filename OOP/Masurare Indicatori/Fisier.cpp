#include <iostream>

class Floare {
	int nrPetale;
	char* culoare;

	Floare() {
		this->nrPetale = 5;
		this->culoare = new char[strlen("Albastru")];
		strcpy_s(this->culoare, strlen("Albastru") + 1, "Albastru");
	}


};
