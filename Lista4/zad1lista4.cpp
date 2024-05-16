#include <iostream>
#include <vector>
using namespace std;

// Definiowanie operatora *
double operator*(const vector<double>& v1, const vector<double>& v2) {

// Przemnożenie kazdego elementu i na końcu dodawanie ich
    double wynik2 = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        wynik2 += v1[i] * v2[i];
    }
    return wynik2;
}

int main() {
    vector<double> v1; // Stworzenie 2-ch wektorów o równej liczbie elementów
    v1.push_back(1.0);
    v1.push_back(2.0);
    v1.push_back(3.0);

    vector<double> v2;
    v2.push_back(4.0);
    v2.push_back(5.0);
    v2.push_back(6.0);

    // Obliczenie iloczynu skalarnego
    double wynik = v1 * v2;

    cout << "Iloczyn skalarny v1 i v2: " << wynik << endl; // Wypisanie wyniku mnożenia skalarnego
    return 0;
}
