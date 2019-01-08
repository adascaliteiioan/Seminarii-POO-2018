#include<iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<fstream>
using namespace std;


class MosCraciun {
private:
	string nume;
	int nrJucarii;
	string* jucarii;
public:
	MosCraciun() {
		this->nume = "Mos Craciun";
		this->nrJucarii = 0;
		this->jucarii = NULL;
	}

	MosCraciun(string nume, int nrJucarii, string* jucarii) {
		this->nume = nume;
		this->nrJucarii = nrJucarii;
		this->jucarii = jucarii;
	}

	friend ostream& operator<<(ostream& out, MosCraciun& m) {
		out << "Nume = " << m.nume << "\tNr jucarii = " << m.nrJucarii << "\nJucariile = ";
		for (int i = 0; i < m.nrJucarii; i++) {
			out << m.jucarii[i] << "\t";
		}
		return out;
	}

	friend ofstream& operator<<(ofstream& out, MosCraciun& m) {
		out << m.nume << endl;
		out << m.nrJucarii << endl;
		for (int i = 0; i < m.nrJucarii; i++) {
			out << m.jucarii[i] << "\t";
		}
		return out;
	}

	friend istream& operator>>(istream& in, MosCraciun& m) {
		cout << "Nume = ";
		in >> m.nume;
		cout << "\nNr jucarii = ";
		in >> m.nrJucarii;
		m.jucarii = new string[m.nrJucarii];
		for (int i = 0; i < m.nrJucarii; i++) {
			cout << "\nJucaria " << to_string(i + 1) << " = ";
			in >> m.jucarii[i];
		}
		return in;
	}

	friend ifstream& operator>>(ifstream& in, MosCraciun& m) {
		getline(in, m.nume);
		in >> m.nrJucarii;
		m.jucarii = new string[m.nrJucarii];
		for (int i = 0; i < m.nrJucarii; i++) {
			in >> m.jucarii[i];
		}
		return in;
	}

};

int main() {
	string jucarii[] = { "jucarie1", "masina", "lego" };
	string jucarii2[] = { "tren", "masina" };
	MosCraciun m("Mos Craciun", 3, jucarii);
	MosCraciun m1;
	MosCraciun m2("Mos Craciun", 2, jucarii2);
	//cin >> m1;
	//cout << m1;

	//deschidere fisier normal pt a scrie
	ofstream f;
	f.open("fisier.txt", ios::out);
	f << m << endl;
	f.write((char*)&m2, sizeof(MosCraciun));
	f.close();

	//deschidere fisier normal pt a citi
	ifstream f1;
	f1.open("fisier.txt", ios::in);
	MosCraciun m3, m4;
	f1 >> m3 >> m4;
	f1.close();
	cout << m3 << endl << m4;
	cout << "\n================================\n";

	//deschidere fisier binar pt a scrie
	ofstream fBin;
	fBin.open("fisierBinar.dat", ios::binary | ios::out);
	fBin << m << endl;
	fBin << m2;
	fBin.close();

	//deschidere fisier binar pt a citi
	ifstream f1Bin;
	f1Bin.open("fisierBinar.dat", ios::binary | ios::in);
	MosCraciun m5, m6;
	f1Bin >> m5;
	f1Bin >> m6;
	f1Bin.close();
	cout << m5 << endl;

	return 0;
}