#include <iostream>
using namespace std;

//podpunkt a
int suma(const int tab[], unsigned size) {
    int wynik = 0;
    for (int i = 0; i < size; ++i) {
        wynik += tab[i];
    }
    return wynik;
}

//podpunkt b
void suma(const int tab[], unsigned size, int* result) {
    *result = 0;

    for (int i = 0; i < size; ++i) {
        *result += tab[i];
    }
}

//podpunkt c
void pisz(const int* tab, size_t size, std::ostream& out) {
    for (size_t i = 0; i < size; ++i) {
        out << tab[i] << " ";
    }
    out << endl;
}

//podpunkt d
void iota(int tab[], unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        tab[i] = i;
    }
}

//podpunkt e
void reverse(int* tab, size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        int nowazmienna = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = nowazmienna;
    }
    for(size_t i =0; i<size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}
//podpunkt f
int dot_product(const int* tab3, const int* tab4, size_t size) {
    int wynik = 0;
    for (size_t i = 0; i < size; ++i) {
        wynik += tab3[i] * tab4[i];
    }
    return wynik;
}


int main() {
    const int tab[] = {2, 1, 3, 4, 5};
    unsigned size = 3;
    cout << "Suma " << size << " pierwszych elementow uzywajac int suma to " << suma(tab, size) <<endl;

    int sum_result;
    suma(tab, size, &sum_result); // Wywo�anie funkcji i przekazanie wska�nika do zmiennej sum_result
    cout << "Suma " << size << " pierwszych elementow uzywajac void suma to " << sum_result <<endl;

    pisz(tab, size, std::cout);

    int tab2[size];
    iota(tab2, size);


    int tab1[] = {2, 1, 3, 4, 5};
    reverse(tab1, size);

    const int tab3[] = {1, 2, 3};
    const int tab4[] = {4, 5, 6};
    size_t size2 = 3;
    cout << "Iloczyn skalarny tablic to " << dot_product(tab3, tab4, size2) << endl;

    return 0;
}
