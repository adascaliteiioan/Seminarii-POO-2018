#include<iostream>
#include<string>
using namespace std;

//Numele structurilor cu litere mari (uppercase)
//Numele metodelor si al variabilelor urmeaza pattern-ul camelCase 
//ex: initializarePensiune(...), afisarePensiune(...), denumirePensiune 
//deschiderea/inchiderea acoladelor
//structura programului 
// 1. un program are DOAR O FUNCTIE MAIN
// 2. semnatura metodelor TREBUIE definita deasupra flunctiei MAIN 
// 3. declararea metodei se poate dace oriunde in fisier in afara functiei MAIN


struct Pensiune {
	int id;
	char* denumirePensiune;
	char adresa[100];
	string rating;
	bool deschis;
	unsigned int capacitate;
	float * tarife;
};

void initializarePensiune(Pensiune * p) {
	cout << "Id: ";
	cin >> (*p).id;
	cout << "==========================================\n";
	cout << "Nume pensiune: ";
	char buffer[50];
	cin >> buffer;
	p->denumirePensiune = new char[strlen(buffer) + 1];
	strcpy(p->denumirePensiune, buffer);
	cout << "==========================================\n";
	cout << "Adresa: ";
	//cin >> p->adresa;
	cin.ignore();
	cin.getline(p->adresa, 100);
	cout << "==========================================\n";
	cout << "Rating: ";
	//cin >> p->rating;
	getline(cin, p->rating);
	cout << "==========================================\n";
	cout << "Deschis? 1/0 : ";
	cin >> p->deschis;
	cout << "==========================================\n";
	cout << "Capacitate: ";
	cin >> p->capacitate;
	cout << "==========================================\n";
	p->tarife = new float[p->capacitate];
	for (int i = 0; i < p->capacitate; i++) {
		cout << "Pretul camerei " << i + 1 << " : ";
		cin >> p->tarife[i];
	}
};

void afisarePensiune(Pensiune p) {
	cout << "Id = " << p.id <<endl;
	cout << "Denumire = " << p.denumirePensiune << endl;
	cout << "Adresa = " << p.adresa << endl;
	cout << "Rating = " << p.rating << endl;
	if (p.deschis == true) {
		cout << "Pensiune deschisa\n";
	}
	else {
		cout << "Pensiune inchisa\n";
	}
	cout << "Capacitatea pensiunii este de " << p.capacitate << " camere\n";
	for (int i = 0; i < p.capacitate; i++) {
		cout << "Pretul camerei " << i + 1 << " este " << p.tarife[i] << endl;
	}
}

void actualizareDenumire(Pensiune &p) {
	cout << "Dati numele nou: ";
	char buffer[50];
	cin >> buffer;
	if (p.denumirePensiune != NULL) {
		delete[] p.denumirePensiune;
	}
	p.denumirePensiune = new char[strlen(buffer) + 1];
	strcpy(p.denumirePensiune, buffer);
}

float costMediu(Pensiune p) {
	if (p.capacitate == 0) {
		cout << "Nu sunt camere\n";
		return 0;
	}
	float suma = 0;
	for (int i = 0; i < p.capacitate; i++) {
		suma += p.tarife[i];
	}
	return suma / p.capacitate;
}

int main() {

	Pensiune p;
	initializarePensiune(&p);
	cout << "\n==========================================\n";
	afisarePensiune(p);
	cout << "\n==========================================\n";
	actualizareDenumire(p);
	cout << "\n==========================================\n";
	afisarePensiune(p);
	cout << "\n==========================================\n";

	Pensiune * ph;
	ph = &p;
	afisarePensiune(*ph);

	cout << "\n==========================================\n";

	cout << "Pret mediu " << costMediu(p);
	return 0;
}