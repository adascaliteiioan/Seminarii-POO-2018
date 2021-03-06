#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

//Declarare structura Hotel -> se definesc atributele necesare structurii
struct Hotel {
	//numele hotelului care este pastrat intr-o variabila de tip string(tip folosit pentru stocare de siruri de caractere)
	string nume;
	//pretul mediu al unei camere de hotel pastrat intr-o variabila de tip float
	float pretMediu;
	//numarul de camere al hotelului pastrat intr-o variabila de tip int
	int nrCamere;
	//denumirile camerelor hotelului pastrate intr-un pointer la string
	//string n, *pn
	//n = "Vasile"
	//pn = &n -> pn pastreasa ADRESA la care este stocata variabila n
	//*pn = "Gheorghe" => n = "Gheorghe" deoarece *pn pointeaza la adresa lui n (si schimba valoarea de la adresa respectiva)
	string* camere;
};

Hotel initializareHotel() {
	Hotel hotel;
	hotel.nume = "Hotel California";
	hotel.pretMediu = 123.25;
	hotel.nrCamere = 5;
	hotel.camere = new string[hotel.nrCamere];
	for (int i = 0; i < hotel.nrCamere; i++) {
		//to_string(parametru) converteste parametrul primit intr-o variabila de tip string
		hotel.camere[i] = "Camera numarul " + to_string(i+1);
	}
	return hotel;
}

void modificaPretMediu1(Hotel h) {
	h.pretMediu = h.pretMediu * 1.5;
}

void modificaPretMediu2(Hotel *hotel) {
	hotel->pretMediu = hotel->pretMediu * 1.7;
}

void modificaPretMediu3(Hotel &hotel) {
	hotel.pretMediu = hotel.pretMediu * 1.9;
}

int main()
{

	Hotel hotel = initializareHotel();
	cout << "Numele hotelului este " << hotel.nume << " si are " << hotel.nrCamere << " camere, cu un pret mediu de " << hotel.pretMediu << "\n";
	cout << "Camerele hotelului sunt:\n";
	for (int i = 0; i < hotel.nrCamere; i++) {
		cout << hotel.camere[i] << "\n";
	}

	modificaPretMediu1(hotel);
	cout<< "Pret modificare 1 " << hotel.pretMediu <<"\n";
	modificaPretMediu2(&hotel);
	cout << "Pret modificare 2 " << hotel.pretMediu << "\n";
	modificaPretMediu3(hotel);
	cout << "Pret modificare 3 " << hotel.pretMediu << "\n";

	return 0;
}


