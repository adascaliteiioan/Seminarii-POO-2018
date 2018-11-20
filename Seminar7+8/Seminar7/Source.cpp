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
	Masina() :serie(1) {
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

	Masina(string marca, int anFabricatie, string tipCaroserie, float pret, int nrModele, string* modele) :serie(2) {
		this->marca = marca;
		this->anFabricatie = anFabricatie;
		this->tipCaroserie = tipCaroserie;
		this->pret = pret;
		this->nrModele = nrModele;
		this->modele = modele;
		this->nrMasini++;
	}

	Masina(const Masina& masina) :serie(3) {
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

	float getPret() {
		return this->pret;
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


	friend ostream& operator<<(ostream& out, Masina& a) {
		out << "Marca = " << a.marca << endl;
		out << "An fabricatie = " << a.anFabricatie << endl;
		out << "Tip caroserie = " << a.tipCaroserie << endl;
		out << "Pret = " << a.pret << endl;
		out << "Numar modele = " << a.nrModele << endl;
		for (int i = 0; i < a.nrModele; i++) {
			out << "\t " << a.modele[i] << endl;
		}
		out << "Serie = " << a.serie << endl;
		out << "Numar masini = " << a.nrMasini << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Masina& a) {
		cout << "Dati marca: ";
		in >> a.marca;
		cout << "Dati anul fabricatiei: ";
		in >> a.anFabricatie;
		cout << "Dati tip caroserie: ";
		in >> a.tipCaroserie;
		cout << "Dati pret: ";
		in >> a.pret;
		cout << "Dati nr modele: ";
		in >> a.nrModele;

		if (a.modele != NULL) {
			delete[] a.modele;
		}
		a.modele = new string[a.nrModele];
		for (int i = 0; i < a.nrModele; i++) {
			cout << "Dati modelul " << i + 1 << ": ";
			in >> a.modele[i];
		}

		return in;
	}

	//supraincarcare operator + 
	//este folosit pentru a aduna o variabila de tip float cu un obiect Masina
	//folosit pentru a face operatii de forma: m1+250.0f
	Masina operator+(float nr) {
		Masina copie = *this;
		copie.pret += nr;
		return copie;
	}

	//folosit pentru a face operatii de forma: 250.0f + m1
	friend Masina operator+(float valoare, Masina m) {
		Masina copie = m;
		copie.pret = valoare - copie.pret;
		return copie;
	}

	//scade valoarea atributului anFabricatie cu valoarea lui nr
	//folosit pentru a face operatii de forma: m1 - 2
	Masina operator-(int nr) {
		Masina copie = *this;
		copie.anFabricatie -= nr;
		return copie;
	}

	//scade din valoarea lui nr valoarea atributului anFabricatie
	//folosit pentru a face operatii de forma: 2000 - m1
	friend Masina operator-(float nr, Masina m) {
		Masina copie = m;
		copie.anFabricatie = nr - copie.anFabricatie;
		return copie; 
	}

	//supraincarcare == pentru a verifica daca 2 obiecte sunt egale
	//folosit pentru a face operatii de forma: m1 == m2
	bool operator==(Masina m) {
		if (m.anFabricatie == this->anFabricatie &&
			m.marca == this->marca) {
			return true;
		}
		else {
			return false;
		}
	}

	//supraincarcare ! pentru a nega un obiect
	//folosit pentru a face operatii de forma: !m1 
	bool operator!() {
		if (this->modele != NULL) {
			return false;
		}
		else {
			return true;
		}
	}

	//supraincarcare operator cast la float care face cast de la o masina la pretul sau
	//folosit pentru a face operatii de forma: (float)m1
	explicit operator float() {
		return this->pret;
	}

	//supraincarcarea operatorului de indexare care sa permita accesul la unul din modele
	//folosit pentru a face operatii de forma: m1[0]
	string& operator[](int index)
	{
		if (index < 0 || index >= this->nrModele)
		{
			cout << "Index in afara limitelor!" << endl;
			throw new exception("Index in afara limitelor!");
		}
		else
		{
			return this->modele[index];
		}
	}


	//supraincarcarea operatorului ++ (forma postfixata)
	//Acesta va creste numarul de modele cu 1
	//folosit pentru a face operatii de forma: m1++
	Masina& operator++()
	{
		//creez un vector nou de modele care sa includa si noul model
		string* modeleNoi = new string[this->nrModele + 1];
		//copiez modelele existente
		for (int i = 0; i < this->nrModele; i++)
		{
			modeleNoi[i] = this->modele[i];
		}
		//adaug noul model
		modeleNoi[this->nrModele] = "Model nou adaugat";
		//actualizez numarul de modele
		this->nrModele++;
		if (this->modele != NULL)
		{
			delete[] this->modele;
		}
		this->modele = modeleNoi;

		return *this;
	}

	//supraincarcarea oepratorului ++ (forma prefixata)
	//Acesta va creste numarul de modele cu 1
	//folosit pentru a face operatii de forma: ++m1
	Masina operator++(int)
	{
		Masina copie = *this;
		//creez un vector nou de modele care sa includa si noul model
		string* modeleNoi = new string[this->nrModele + 1];
		//copiez modelele existente
		for (int i = 0; i < this->nrModele; i++)
		{
			modeleNoi[i] = this->modele[i];
		}
		//adaug noul model
		modeleNoi[this->nrModele] = "Model nou adaugat";
		//actualizez numarul de modele
		this->nrModele++;
		if (this->modele != NULL)
		{
			delete[] this->modele;
		}
		this->modele = modeleNoi;

		return copie;
	}

	void afisare() {
		cout << "Serie = " << this->serie << endl;
		cout << "Nr masini = " << this->nrMasini << endl;
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
	Masina m2;
	m1.afisare();
	cout << "\n=============================\n";

	cout << "Apel operator + de forma m1 + 20.0f\n";
	m2 = m1 + 20.0f;
	cout << "Pretul nou este = " << m2.getPret() << endl;
	cout << "Apel operator + de forma 20.0f + m1\n";
	m2 = 20.0f + m1;
	cout << "Pretul nou este = " << m2.getPret() << endl;
	cout << "\n=============================\n";

	cout << "Apel operator - de forma m1 - 20\n";
	m2 = m1 - 20;
	cout << "An fabricatie nou este = " << m2.getAnFabricatie() << endl;
	cout << "Apel operator - de forma 20 + m1\n";
	m2 = 20 - m1;
	cout << "An fabricatie nou este = " << m2.getAnFabricatie() << endl;
	cout << "\n=============================\n";

	string marca = "Dacia";
	int anFabricatie = 2013;
	int nrModele = 2;
	float pret = 5236.2;
	string tipCaroserie = "caroserie";
	string *modele = new string[nrModele];
	for (int i = 0; i < nrModele; i++) {
		modele[i] = "Model " + to_string(i + 300);
	}
	Masina m3(marca, anFabricatie, tipCaroserie, pret, nrModele, modele);
	cout << "Apel operator ==\n";
	cout << "m1 este egal cu m3?\n";
	Masina m4;
	if (m1 == m3) {
		cout << "m1 = m3\n";
	}
	else {
		cout << "m1 != m3\n";
	}
	cout << "m1 este egal cu m4?\n";
	if (m1 == m4) {
		cout << "m1 = m4";
	}
	else {
		cout << "m1 != m4";
	}

	cout << "\n=============================\n";
	cout << "Apel operator ! (not)\n";
	if (!m2) {
		cout << "m2 are atributul modele NULL\n";
	}
	else {
		cout << "m2 are atributul modele diferit de NULL\n";
	}
	cout << "\n=============================\n";

	cout << "Apel operator cast\n";
	cout << (float)m1 << endl;
	cout << "\n=============================\n";

	cout << "Operator index\n";
	cout<<"Apel m1 cu index = 0 " << m1[0]<<endl;
	//Apelul de mai jos va arunca o exceptie
	try {
		cout << "Apel m1 cu index = 3 " << m1[3] << endl;
	}
	catch (exception* e) {
		cout<< e->what() << " Exceptie prinsa\n";
	}
	catch (string& e) {
		cout << e << " Exceptie prinsa\n";
	} 
	catch (...) {
		cout << "Exceptie prinsa\n";
	}
	cout << "\n=============================\n";

	cout << "Apel operator ++ (m1++)\n";
	m1++;
	cout << m1;
	cout << "\n=============================\n";

	cout << "Apel operator ++ (++m1)\n";
	++m1;
	cout << m1; 
	return 0;
}