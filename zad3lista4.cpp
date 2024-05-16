#include <iostream>
#include <vector>
#include <sstream>

std::string nimStrategia(const std::vector<int>& kupki)
{
    
    int xorSum = 0;
    for (int kupka : kupki)
    {
        xorSum ^= kupka;
    }
    // Gdy suma bitowego XOR liczb kamieni w rzędach wynosi zero,
    // gracz nie ma możliwości wygrania w jednym ruchu.
    if (xorSum == 0)
    {
        return "Nie istnieje ruch, zapewniajacy szybkie zwyciestwo.";
    }
    else
    {
    // W przeciwnym razie, iterujemy przez wszystkie rzędy kamieni.
        for (size_t i = 0; i < kupki.size(); ++i)
        {
        // Jeśli wykonanie operacji XOR na kamieniach w danym rzędzie daje mniejszą wartość niż oryginalna liczba kamieni w danym rzędzie,
        // to istnieje optymalny ruch.
            if ((kupki[i] ^ xorSum) < kupki[i])
            {
                std::ostringstream oss;
                oss << "z rzedu nr " << (i+1) << " zabierz " << (kupki[i] - (kupki[i] ^ xorSum)) << " kamieni(e)";
            // Zwracam wiadomość.
                return oss.str();
            }
        }
    }
return ""; // Informuje gdy wystąpił błąd, ten zwrot nie powinien być móc osiągnięty.
}

void Instrukcja() // Sposób korzystania z programu
{
    std::cout << "Program pomaga wygrac w gre nim." << std::endl;
    std::cout << "skladnia: .\\nazwa_programu.exe liczba_1,liczba_2..." << std::endl;
    std::cout << "gdzie liczba_1, liczba_2, ... to liczby kamieni w kolejnych rzedach" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || (std::string(argv[1]) == "--help") || (std::string(argv[1]) == "-h"))
    {
        // Jeślijeden z warunków jest spełniony, liczba argumentów mniejsza niż 2 lub wpisano -h lub --help, wywołuje funkcję Instrukcja(),
        // która wyświetla informacje o sposobie użycia programu.
        Instrukcja();
    }
    else
    {
        // Jeśli warunek nie jest spełniony (poprawnie wpisano zmienne), utwórz wektor 'piles', który będzie przechowywał liczby kamieni w poszczególnych rzędach.
        std::vector<int> kupki;
        // Przechodzi przez argumenty przekazane do programu, zaczynając od indeksu 1, ponieważ argv[0] zawiera jego nazwę.
        for (int i = 1; i < argc; ++i) {
            // Zamienia każdy argument na liczbę całkowitą i dodaje go do wektora 'piles'.
            kupki.push_back(std::stoi(argv[i]));
        }
        // Wywołuje funkcję nimGameStrategy(piles), aby znaleźć optymalny ruch w grze Nim
        // i wyświetla wynik na wyjściu standardowym.
        std::cout << nimStrategia(kupki) << std::endl;
    }
    return 0;
}