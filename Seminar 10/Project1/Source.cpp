#include<iostream>
#include<string>
using namespace std;

class FormaGeometrica {
private:
	unsigned int nrLaturi;
public:

	FormaGeometrica() {
		this->nrLaturi = 4;
	}

	FormaGeometrica(unsigned int nrLaturi) {
		this->nrLaturi = nrLaturi;
	}

	void setNrLaturi(unsigned int nrLaturi) {
		this->nrLaturi = nrLaturi;
	}

	unsigned int getNrLaturi() {
		return this->nrLaturi;
	}

	virtual	void arie() {
		cout << "Aria FormaGeometrica\n";
	}

	virtual ~FormaGeometrica() {};
};

//Interfata
class IOperatiiTriunghi {
public:
	virtual void calculUnghiAscutit() = 0;
	virtual void calculUnghiObtuz() = 0;
};


//clasa abstracta
class Triunghi : public FormaGeometrica {
private:
	string tipForma;
public:
	Triunghi() :FormaGeometrica() {
		tipForma = "triunghi\n";
	}

	Triunghi(unsigned int nrLaturi, string tipForma) : FormaGeometrica(nrLaturi) {
		this->tipForma = tipForma;
	}

	string getTipForma() {
		return this->tipForma;
	}

	void setTipForma(string tipForma) {
		this->tipForma = tipForma;
	}

	virtual void arie() override {
		cout << "Aria Triunghi\n";
	}

	//metoda virtual pura
	virtual void perimetru() = 0;

	virtual ~Triunghi() {};
};

class TriunghiIsoscel : public Triunghi, public IOperatiiTriunghi {
public:
	virtual void perimetru() {
		cout << "Perimetrul triunghiului isoscel\n";
	}
	virtual void calculUnghiAscutit() {
		cout << "Calcul unghi ascutit\n";
	}

	virtual void calculUnghiObtuz() {
		cout << "Calcul unghi obtuz\n";
	}
};

int main() {
	TriunghiIsoscel t1;
	FormaGeometrica f1;
	t1.arie();
	f1.arie();

	FormaGeometrica *f2 = new TriunghiIsoscel();
	f2->arie();
	t1.calculUnghiAscutit();
	t1.calculUnghiObtuz();
	t1.perimetru();
	
	return 0;
}