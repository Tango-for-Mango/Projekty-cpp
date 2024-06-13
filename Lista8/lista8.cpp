#include <iostream>
#include <vector>
#include <complex>
#include <chrono>
#include "timer.h"

// Szablon operatora strumieniowego wyjścia dla std::vector
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

// Implementacja funkcji
int silnia(int n) {
    if (n == 0)
        return 1;
    return n * silnia(n - 1);
}

int fibonacci(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    Timer timer;

    // Testowanie operatora strumieniowego wyjścia dla std::vector
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    std::vector<double> double_vec = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<std::complex<double>> complex_vec = {{1, 1}, {2, 2}, {3, 3}};

    // Zamiast std::endl użyj "\n"
    std::cout << int_vec << "\n";
    std::cout << double_vec << "\n";
    std::cout << complex_vec << "\n";

    // Pomiar czasu dla funkcji silnia
    timer.start();
    for (int i = 0; i <= 30; i++)
        std::cout << i << "! = " << silnia(i) << "\n"; // Zamiast std::endl użyj "\n"
    double silnia_time = timer.get_elapsed_seconds();
    std::cout << "Czas wykonania funkcji silnia: " << silnia_time << " sekund" << std::endl;

    // Pomiar czasu dla funkcji fibonacci
    timer.start();
    for (int i = 0; i <= 45; i++)
        std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << "\n"; // Zamiast std::endl użyj "\n"
    double fibonacci_time = timer.get_elapsed_seconds();
    std::cout << "Czas wykonania funkcji fibonacci: " << fibonacci_time << " sekund" << std::endl;

    // Czas wykonania programu przy użyciu biblioteki timer
    Timer program_timer;
    double total_time = silnia_time + fibonacci_time; // Całkowity czas ( czas silni jest bardzo mały w porównaniu z fibonaccim)
    std::cout << "Czas wykonania programu: " << total_time << " sekund" << std::endl;

    return 0;
}

/*
a. Zastąpienie std::endl napisem "\n" w powyższym kodzie nie zmienia działania programu w 
zauważalny sposób, ponieważ std::endl = "\n" + std::flush, co oznacza, że dodaje nową linię 
i opróżnia bufor strumienia (flush). W przypadku mniejszych programów różnica jest niewielka, ale w 
większych, intensywnie operujących na strumieniach danych, może mieć wpływ na wydajność.

b. Implementacja funkcji silnia jest poprawna, jednak dla wartości powyżej 12, wynik może 
przekraczać zakres typu int, co prowadzi do błędnych wyników. Poprawić można poprzez użycie 
typu większego zakresu, np. long long:
long long silnia(int n) {
    if (n == 0)
        return 1;
    return n * silnia(n - 1);
}

c. Funkcja fibonacci działa znacznie wolniej od funkcji silnia, ponieważ implementacja jest 
rekurencyjna i dla każdego wywołania wywołuje dwie kolejne instancje funkcji. Jest to 
widoczne w debugerze. Funkcja silnia wywołuje się jednokrotnie rekurencyjnie, a funkcja fibonacci
wywołuje się wielokrotnie, tworząc wiele 
poziomów wywołań na stosie.

d. Biblioteczka timer.h i timer.cpp została użyta do pomiaru czasu wykonania się programu. 
Kod main.cpp załącza timer.h i wykorzystuje klasę Timer do pomiaru czasu. Wszystkie pliki 
muszą być skompilowane razem.

e. Uruchomienie programu w trybie Debug pozwala na dokładne śledzenie działania programu, 
wyświetlanie zmiennych i stosu wywołań, co pomaga w znalezieniu błędów. Tryb Release jest 
optymalizowany pod kątem wydajności, co może prowadzić do szybszego działania programu, 
ale trudniejszego debugowania, ponieważ niektóre zmienne mogą być usuwane lub przenoszone. 
Różnice w czasie wykonywania wynikają z tych optymalizacji.
*/
