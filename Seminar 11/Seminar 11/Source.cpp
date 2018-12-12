#include<iostream>
#include<string>
using namespace std;

/*int max(int a, int b) {
	return a >= b ? a : b;
}

float max(float a, float b) {
	return a >= b ? a : b;
}*/

//Metode template
template <class T>
T max(T a, T b) {
	return a >= b ? a : b;
}

template <typename G, typename U>
G min(G a, U b) {
	return a <= b ? a : b;
}

//clasa cu atribute template
template <class T>
class Pair {
	T a, b;
public:
	Pair(T first, T second) {
		this->a = first;
		this->b = second;
	}

	T getMin() {
		return a <= b ? a : b;
	}

	T getMax();

};

template<class T>
T Pair<T>::getMax() {
	return a >= b ? a : b;
}


template <typename T>
T increase(T element) {
	return ++element;
}
//specializare template
template <typename T = char>
char increase(char element) {
	if ((element >= 'a') && (element <= 'z')) {
		element += 'A' - 'a';
	}
	return element;
}

int main() {

	cout << "Apel max int: " << max(8.2, 9.0) << endl;
	cout << "Apel max float: " << max(10, 9) << endl;
	cout << "Apel max template: " << max<int>(10, 9) << endl;
	cout << "Apel max template: " << max<float>(1, 9) << endl;
	cout << "Apel max template: " << max<double>(1.5, 0.9) << endl;
	int a = max(12, 23);
	cout << "a = " << a << endl;
	cout << "Apel min: " << min(8, 2.0) << endl;
	Pair<int> obj(10, 12);
	cout << "Apel getMax: " << obj.getMax() << endl;
	cout << "Apel getMin: " << obj.getMin() << endl;
	cout << "Apel increase int: " << increase<int>(8) << endl;
	cout << "Apel increase char: " << increase<char>('a') << endl;
	return 0;
}