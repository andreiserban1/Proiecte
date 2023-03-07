#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// convertor de moneda


void main() {

	unsigned int indiceMoneda;
	double sumaBani;
	double sumaSchimbataInLei;
	double sumaSchimbataInEuro;
	double sumaSchimbataInDolari;
	
	

		cout << "Introduceti indicele monedei pe care doriti sa o schimbati (LEU = 1; EUR = 2; USD = 3): ";
		cin >> indiceMoneda;

		if (indiceMoneda == 1) {
			cout << "Introduceti valoarea in LEI pe care doriti sa o schimbati: ";
			cin >> sumaBani;
			if (sumaBani != 0 && indiceMoneda == 1 && sumaBani > 0) {
				sumaSchimbataInEuro = sumaBani / 4.91;
				sumaSchimbataInDolari = sumaBani / 4.54;
				cout << "Suma de " << sumaBani << " LEI poate fi schimbata in " << sumaSchimbataInEuro << " EUR sau in " << sumaSchimbataInDolari << " USD " << endl;
			}
		
		}

		if (indiceMoneda == 2) {
			cout << "Introduceti valoarea in EURO pe care doriti sa o schimbati: ";
			cin >> sumaBani;
			if (sumaBani != 0 && indiceMoneda == 2 && sumaBani > 0) {
				sumaSchimbataInLei = sumaBani * 4.92;
				sumaSchimbataInDolari = sumaBani * 1.06;
				cout << "Suma de " << sumaBani << " EURO poate fi schimbata in " << sumaSchimbataInLei << " LEI sau in " << sumaSchimbataInDolari << " USD " << endl;
			}
			
		}

		if (indiceMoneda == 3) {
			cout << "Introduceti valoarea in DOLARI pe care doriti sa o schimbati: ";
			cin >> sumaBani;
			if (sumaBani != 0 && indiceMoneda == 3 && sumaBani > 0) {
				sumaSchimbataInLei = sumaBani * 4.65;
				sumaSchimbataInEuro = sumaBani / 1.063;
				cout << "Suma de " << sumaBani << " USD poate fi schimbata in " << sumaSchimbataInLei << " LEI sau in " << sumaSchimbataInEuro << " EUR " << endl;
			}
			
		}	

		cout << endl;
	
}
	



