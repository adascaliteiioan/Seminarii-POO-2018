#include<iostream>
#include<string>
using namespace std;

class Hotel {
private:
	string nume;
	float pretMediu;
	int nrCamere;
	string* camere;

public:

	Hotel() {
		cout << "Se ruleaza constructorul fara parametri\n";
		this->nume = "Cismigiu";
		this->pretMediu = 150.5;
		this->nrCamere = 2;
		this->camere = new string[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			this->camere[i] = "Camera " + to_string(i + 1);
		}
	}

	Hotel(string nume, float pretMediu, int nrCamere, string* camere) {
		cout << "Se ruleaza constructorul cu parametri\n";
		this->nume = nume;
		this->pretMediu = pretMediu;
		this->nrCamere = nrCamere;
		this->camere = new string[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			this->camere[i] = camere[i];
		}
	}

	~Hotel() {
		cout << "Se ruleaza destructorul\n";
		if (this->camere != NULL) {
			delete[] this->camere;
		}
	}

	void afisareHotel();


};

void Hotel::afisareHotel() {
	cout<< "Nume hotel = "<< this->nume <<"\n";
	cout<< "Pret mediu = " << this->pretMediu << "\n";
	cout << "Numar camere = " << this->nrCamere << "\n";
	cout << "Camerele hotelului sunt: \n ";
	for (int i = 0; i < this->nrCamere; i++) {
		cout<<this->camere[i] <<endl;
	}
}


int main() {
	Hotel h;
	h.afisareHotel();
	cout << "\n=================================\n";
	Hotel *ph = new Hotel();
	ph->afisareHotel();
	cout << "\n=================================\n";
	string denumire = "Herastrau";
	float pretMediu = 200;
	int nrCamere = 5;
	string * camere = new string[nrCamere];
	for (int i = 0; i < nrCamere; i++) {
		camere[i] = "Camera " + to_string(i + 1);
	}
	cout << "\n=================================\n";
	Hotel h2(denumire, pretMediu, nrCamere, camere);
	h2.afisareHotel();
	return 0;
}