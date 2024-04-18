#include <iostream>
#include <cstdlib>
using namespace std;

// Funkcja, która wskazuje qsort jak sortować
int compare(const void *a, const void *b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;

    // Sprawdzenie, czy liczby są parzyste, przez sprawdzanie różnicy przy dzieleniu przez 2
    bool isNum1Even = num1 % 2 == 0;
    bool isNum2Even = num2 % 2 == 0;

    // Sortowanie
    if (isNum1Even && isNum2Even)
        return num1 - num2; // Rosnąco liczby parzyste, przy wartości ujemnej num1 powinna znajdować się przed num2, a przy dodatniej num2 przed num1
    else if (!isNum1Even && !isNum2Even)    //                         sortowanie rosnące                               sortowanie malejące
        return num2 - num1; // Malejąco liczby nieparzyste
    else if (isNum1Even && !isNum2Even)
        return -1; // Liczba parzysta przed nieparzystą, przy ujemnej num1 przed num2 (parzysta przed nieparzystą)
    else
        return 1; // Liczba nieparzysta przed parzystą
}

int main() {
    int arr[] = {1, 4, 7, 2, 5, 9, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sortowanie za pomocą qsort, korzystając z funkcji compare by wskazać dokładnie sposób i typ sortowania
    qsort(arr, n, sizeof(int), compare);

    // Wyświetlenie posortowanej tablicy
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    return 0;
}


