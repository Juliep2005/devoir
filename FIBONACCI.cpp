#include <iostream>

int fibonacci(int n) {
    if (n <= 1)
        return n;  // Cas de base : F(0) = 0 et F(1) = 1
    else
        return fibonacci(n-1) + fibonacci(n-2);  // Cas récursif : F(n) = F(n-1) + F(n-2)
}

int main() {
    int n;
    std::cout << "Entrez le nombre d'éléments dans la suite de Fibonacci : ";
    std::cin >> n;

    std::cout << "Suite de Fibonacci : ";
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i) << " ";  // Appel de la fonction pour chaque valeur de 0 à n-1
    }

    std::cout << std::endl;

    return 0;
}
