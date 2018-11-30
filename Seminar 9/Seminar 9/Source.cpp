#include<iostream>
#include<string>
using namespace std;

class Persoana {
private:
	string nume;
	unsigned int varsta;
public:

	Persoana() {
		cout << "Apel constructor fara parametri -- clasa Persoana\n";
		this->nume = "Persoana";
		this->varsta = 20;
	}

	Persoana(string nume, unsigned int varsta) {
		cout << "Apel constructor cu parametri -- clasa Persoana\n";
		this->nume = nume;
		this->varsta = varsta;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	string getNume() {
		return this->nume;
	}

	void setVarsta(unsigned int varsta) {
		this->varsta = varsta;
	}

	unsigned int getVarsta() {
		return this->varsta;
	}

	Persoana(const Persoana &p) {
		this->nume = p.nume;
		this->varsta = p.varsta;
	}

	~Persoana() {
		cout << "Apel destructor -- clasa Persoana\n";
	}
};

class Profesor: public Persoana {
protected:
	string facultate;
	string departament;
public:
	Profesor() :Persoana() {
		cout << "Apel constructor fara parametri -- clasa Profesor\n";
		this->facultate = "CSIE";
		this->departament = "Cibernetica";
	}

	Profesor(string nume, unsigned int varsta, string facultate, string departament) :Persoana(nume, varsta) {
		cout << "Apel constructor cu parametri -- clasa Profesor\n";
		this->facultate = facultate;
		this->departament = departament;
	}

	void setFacultate(string facultate) {
		this->facultate = facultate;
	}

	string getFacultate() {
		return this->facultate;
	}

	void setDepartament(string departament) {
		this->departament = departament;
	}

	string getDepartament() {
		return this->departament;
	}

	Profesor(const Profesor &p): Persoana(p) {
		this->departament = p.departament;
		this->facultate = p.facultate;
	}

	void afisareProfesor() {
		cout << "Nume = " << this->getNume() << endl;
		cout << "Varsta = " << this->getVarsta() << endl;
		cout << "Facultate = " << this->facultate << endl;
		cout << "Departament = " << this->departament << endl;
	}

	~Profesor() {
		cout << "Apel destructor -- clasa Profesor\n";
	}
};

class ProfesorPOO: public Profesor {
private:
	string materiePrincipala;
public:

	ProfesorPOO() : Profesor() {
		cout << "Apel constructor fara parametri -- clasa ProfesorPOO\n";
		this->materiePrincipala = "POO";
	}

	ProfesorPOO(string nume, unsigned int varsta, string facultate, string departament, string materiePrincipala)
		:Profesor(nume, varsta, facultate, departament) {
		cout << "Apel constructor cu parametri -- clasa ProfesorPOO\n";
		this->materiePrincipala = materiePrincipala;
	}

	void setMateriePrincipala(string materiePrincipala) {
		this->materiePrincipala = materiePrincipala;
	}

	string getMateriePrincipala() {
		return this->materiePrincipala;
	}

	void afisareProfesorPOO_V1() {
		cout << "Nume = " << this->getNume() << endl;
		cout << "Varsta = " << this->getVarsta() << endl;
		cout << "Facultate = " << this->facultate << endl;
		cout << "Departament = " << this->departament << endl;
		cout << "Materie principala = " << this->materiePrincipala << endl;
	}

	void afisareProfesorPOO_v2() {
		afisareProfesor();
		cout << "Materie principala = " << this->materiePrincipala << endl;
	}

	~ProfesorPOO() {
		cout << "Apel destructor -- clasa ProfesorPOO\n";
	}
};

int main() {
	cout << "Creare obiect Persoana\n";
	Persoana p;
	cout << "\n=========================================\n";
	cout << "Creare obiect Profesor\n";
	Profesor pr;
	cout << "\n=========================================\n";
	cout << "Creare obiect ProfesorPOO\n";
	ProfesorPOO pp;
	cout << "\n=========================================\n";
	cout << "Afisare obiect Profesor\n";
	pr.afisareProfesor();
	cout << "\n=========================================\n";
	cout << "Afisare obiect ProfesorPOO\n";
	pp.afisareProfesorPOO_V1();
	cout << "\n=========================================\n";
	cout << "Apel constructor copiere Profesor\n";
	Profesor pr2 = pr;
	pr2.afisareProfesor();
	cout << "\n=========================================\n";
}