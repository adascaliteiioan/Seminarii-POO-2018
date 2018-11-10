#include<iostream>
#include<string>
using namespace std;

class Masina {
private:
	string marca;
	int anFabricatie;
	string tipCaroserie;
	float pret;
	int nrModele;
	string* modele;
	const int serie;
	static unsigned int nrMasini;

public:
	Masina():serie(1) {
		this->marca = "Dacia";
		this->anFabricatie = 2012;
		this->tipCaroserie = "berlina";
		this->pret = 1234.5;
		this->nrModele = 2;
		this->modele = new string[nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = "Model " + to_string(i + 200);
		}
		this->nrMasini++;
	}

	Masina(string marca, int anFabricatie, string tipCaroserie, float pret, int nrModele, string* modele):serie(2) {
		this->marca = marca;
		this->anFabricatie = anFabricatie;
		this->tipCaroserie = tipCaroserie;
		this->pret = pret;
		this->nrModele = nrModele;
		this->modele = modele;
		this->nrMasini++;
	}

	Masina(const Masina& masina):serie(3) {
		this->marca = masina.marca;
		this->anFabricatie = masina.anFabricatie;
		this->tipCaroserie = masina.tipCaroserie;
		this->pret = masina.pret;
		this->nrModele = masina.nrModele;
		this->modele = new string[masina.nrModele];
		for (int i = 0; i < masina.nrModele; i++) {
			this->modele[i] = masina.modele[i];
		}
		this->nrMasini++;
	}


	Masina& operator=(const Masina& masina) {
		this->marca = masina.marca;
		this->anFabricatie = masina.anFabricatie;
		this->tipCaroserie = masina.tipCaroserie;
		this->pret = masina.pret;
		this->nrModele = masina.nrModele;
		this->modele = new string[masina.nrModele];
		for (int i = 0; i < masina.nrModele; i++) {
			this->modele[i] = masina.modele[i];
		}
		return *this;
	}

	string getMarca() {
		return this->marca;
	}

	void setMarca(string marcaNoua) {
		this->marca = marcaNoua;
	}

	int getAnFabricatie() {
		return this->anFabricatie;
	}

	void setAnFabricatie(int anFabricatieNou) {
		this->anFabricatie = anFabricatieNou;
	}

	string* getModele() {
		return this->modele;
	}

	void setModele(string* modeleNoi, int nrModeleNoi) {
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		this->nrModele = nrModeleNoi;
		this->modele = new string[this->nrModele];
		for (int i = 0; i < this->nrModele; i++) {
			this->modele[i] = modeleNoi[i];
		}
	}

	int getSerie() {
		return this->serie;
	}

	static unsigned int getNrMasini() {
		return nrMasini;
	}

	static void setNrMasini(unsigned int nrMasini) {
		Masina::nrMasini = nrMasini;
	}

	~Masina() {
		if (this->modele != NULL) {
			delete[] this->modele;
		}
		Masina::nrMasini--;
	}


	void afisare() {
		cout << "Serie = " << this->serie<<endl;
		cout << "Nr masini = " << this->nrMasini<<endl;
		cout << "Marca = " << this->marca << endl;
		cout << "An fabricatie = " << this->anFabricatie << endl;
		cout << "Tip caroserie = " << this->tipCaroserie << endl;
		cout << "Pret = " << this->pret << endl;
		cout << "Nr modele =  " << this->nrModele << endl;
		for (int i = 0; i < this->nrModele; i++) {
			cout << this->modele[i] << endl;
		}
	}

};

unsigned int Masina::nrMasini = 0;

int main() {
	Masina m1;
	m1.afisare();
	cout << "\n=============================\n";

	/*Masina *m2;
	m2 = &m1;
	m2->afisare();
	cout << "\n=============================\n";

	Masina *m3 = new Masina();
	m3->afisare();
	cout << "\n=============================\n";

	delete m3;
	string marca = "Dacia";
	int anFabricatie = 2013;
	int nrModele = 2;
	float pret = 5236.2;
	string tipCaroserie = "caroserie";
	string *modele = new string[nrModele];
	for (int i = 0; i < nrModele; i++) {
		modele[i] = "Model " + to_string(i + 300);
	}
	Masina m4(marca, anFabricatie, tipCaroserie, pret, nrModele, modele);
	m4.afisare();
	cout << "\n=============================\n";

	Masina *m5 = new Masina(marca, anFabricatie, tipCaroserie, pret, nrModele, modele);
	m5->afisare();
	cout << "\n=============================\n";

	m1.setMarca("Marca noua");
	m1.afisare();
	cout << "\n=============================\n";

	
	m1.setModele(modele, nrModele);
	m1.afisare();
	cout << "\n=============================\n Constructor de copiere\n";
	//apel constructor copiere
	Masina m6 = m1;
	m6.afisare();

	cout << "\n=============================\n Constructor de copiere\n";
	//apel constructor copiere
	Masina m7(m6);
	m7.afisare();*/
	//apel operator =
	Masina m8;
	m8 = m1;
	m8.afisare();
	Masina::setNrMasini(20);
	cout << Masina::getNrMasini()<<endl;
	cout << m8.getSerie();
	return 0;
}