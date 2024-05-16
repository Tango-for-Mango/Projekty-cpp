#include <iostream>
#include <cmath>

using namespace std;

// Funkcja obliczająca pierwiastki równania f(x) = 0 na podanym przedziale z podaną tolerancją
double root(double (*f)(double), double a, double b, double tolerance = 1e-6) {
    double x1;
    while(abs(a - b) > tolerance) {
        x1 = (a + b) / 2;
        if (abs(f(x1)) <= tolerance) {
            return x1;
        } else if (f(x1) * f(a) < 0) {
            b = x1;
        } else {
            a = x1;
        }
    }
    return (a + b) / 2;
}

// Równanie: cos(x) - x
double rownanei1(double x) {
    return cos(x) - x;
}

// Równanie: cos(x) - 1/2
double rownanie2(double x) {
    return cos(x) - 0.5;
}

int main() {
    double root1 = root(rownanei1, 0, 2);
    double root2 = root(rownanie2, 0, 1.5);

    cout << "Pierwiastek rownania cos(x) = x w przedziale [0, 2]: " << root1 << endl;
    cout << "Pierwiastek rownania cos(x) = 1/2 w przedziale [0, 1.5]: " << root2 << endl;

    return 0;
}
