#include <iostream>
#include <cmath>
#include <iomanip> // biblioteka ktora umozliwia modyfikacje trybu wyswietlania liczby
using namespace std;

const int N = 1000000;

//podpunkt A
double a()
{
    double suma = 0;
    for (int i = 1; i <= N ; i++)
    {
        suma += pow(-1, i + 1) / (2.0 * i - 1);
    }
    return 4 * suma;
}
//podpunkt B
double b()
{
    double iloczyn = 1;
    for (int i = 1; i <= N; i++)
    {
        iloczyn *= (4 * pow(i, 2)) / (4 * pow(i, 2) - 1);
    }
    return 2 * iloczyn;
}
//podpunkt C
double c()
{
    double suma = 0;
    for (int i = 1; i <= N; i++)
    {
        suma += 1.0 / pow(2 * i - 1, 2); // Podpunkt c ma najbliższe oszacowanie liczby pi (3.141592335)
    }
    return sqrt(8 * suma);
}

int main()
{
    cout << setprecision(10) << a() << endl << b() << endl << c();
    return 0;
}
