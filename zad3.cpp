#include <iostream>
using namespace std;

double downdouble(int n) {
    int i = 1;
    double suma = 0.0;
    while (i <= n) {
        suma += 1.0 / i;
        i++;
    }
    return suma;
}

double updouble(int n) {
    int i = 0;
    double suma = 0.0;
    int b;
    while (i < n) {
        b = n - i;
        suma += 1.0 / b;
        i++;
    }
    return suma;
}

float downfloat(int n) {
    int i = 1;
    float suma = 0.0;
    while (i <= n) {
        suma += 1.0f / i;
        i++;
    }
    return suma;
}

float upfloat(int n) {
    int i = 0;
    float suma = 0.0;
    int b;
    while (i < n) {
        b = n - i;
        suma += 1.0f / b;
        i++;
    }
    return suma;
}

int main() {
    int n;
    float suma1 = 0.0;
    float suma2 = 0.0;
    double suma3 = 0.0;
    double suma4 = 0.0;
    float roznica1;
    double roznica2;

    for (int a = 0; a < 3; a++) {
        switch (a) {
            case 0:
                n = 100;
                break;
            case 1:
                n = 100000;
                break;
            case 2:
                n = 100000000;
                break;
        }
        suma3 = downdouble(n);
        cout << "Dla n rownego " << n << " suma down korzystajac z double wynosi " << suma3 << endl;
        suma4 = updouble(n);
        cout << "Dla n rownego " << n << " suma up korzystajac z double wynosi " << suma4 << endl<<endl;
        roznica2=suma4-suma3;
        cout<< " Roznica miedzy tymi wartosciami z double-a wynosi: " << roznica2 << endl << endl;
        suma1 = downfloat(n);
        cout << "Dla n rownego " << n << " suma down korzystajac z float wynosi " << suma1 << endl;
        suma2 = upfloat(n);
        cout << "Dla n rownego " << n << " suma up korzystajac z float wynosi " << suma2 << endl<<endl;
        roznica1=suma2-suma1;
        cout<<" Roznica miedzy tymi wartosciami z float-u wynosi: " << roznica1 << endl << endl; // tłumaczone na zajęciach było, iż lepiej sumować od liczb mniejszych do większych, gdyż w
        // przeciwnym wypadku, małe liczby na końcu sumowania są nijako pomijane, nie mają wpływu na ostateczny wynik
        // metoda obliczania z double jest ponadto o wiele dokładniejsza, precyzyjniejsza - różnica jest o wiele mniejsza w KAŻDYM przypadku w porównaniu do metody float

    }

    return 0;
}
