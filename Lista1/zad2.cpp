#include<iostream>
#include<cmath>

using namespace std;

long double metoda_a()
{
    long double t = 1 / sqrt(3.0); // wyraz zerowy
    long double pi;
    for (int i = 0; i <= 30; i++) // stworzenie ciągu do wyświetlania wyniku
    {
        if(i==0)
        {
            pi = 6 * pow(2.0, i) * t;
            cout<<"Dla i równego: "<<i<<" pi wynosi: "<<pi<<endl;
        }
        else
        {
            t = (sqrt(t * t + 1.0) - 1.0) / t;
            pi = 6 * pow(2.0, i) * t;
            cout << "Dla i rownego: " << i << " pi wynosi: " << pi << endl;
        }

    }
    return 0;
}

long double metoda_b()
{
    long double t = 1 / sqrt(3.0); // wyraz 0
    long double pi;
    for (int i = 0; i <= 30; i++)
    {
        if(i==0)
        {
            pi = 6 * pow(2.0, i) * t;
            cout<<"Dla i równego: "<<i<<", przybliżenie pi wynosi: "<<pi<<endl;
        }
        else
        {
            t =  t / (sqrt(t * t + 1.0) + 1.0) ;
            pi = 6 * pow(2.0, i) * t;
            cout << "Dla i rownego: " << i << ", przybliżenie pi wynosi: " << pi << endl;
        }

    }
    return 0;
}



int main()
{   
    cout << "Ciąg obliczony przy pomocy metody a:" << endl;
    metoda_a(); // przy metodzie a przy początkowych i ostatnich wartościach występuje rozstrzał od oczekiwanego wyniku
    cout << "Ciąg obliczony przy pomocy metody b:" << endl;
    metoda_b(); // przy metodzie b tylko przy początkowych wartościach to odejście od oczekiwanego wyniku występuje
    return 0;
}