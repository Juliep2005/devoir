#include <iostream>

// Fonction pour calculer le barycentre
pair<double, double> calculerBarycentre(double x1, double y1, double x2, double y2, double x3, double y3) {
    double x_h = (x1 + x2 + x3) / 3;
    double y_h = (y1 + y2 + y3) / 3;
    return {x_h, y_h};  // Renvoie les coordonnées du barycentre
}

int main() {
    // Coordonnées des lieux de braquage
    double x1, y1, x2, y2, x3, y3;

    std::cout << "Entrez les coordonnées du premier lieu de braquage (x1, y1) : ";
    std::cin >> x1 >> y1;
    std::cout << "Entrez les coordonnées du deuxième lieu de braquage (x2, y2) : ";
    std::cin >> x2 >> y2;
    std::cout << "Entrez les coordonnées du troisième lieu de braquage (x3, y3) : ";
    std::cin >> x3 >> y3;

    // Calcul du barycentre (habitat estimé)
    pair<double, double> habitat = calculerBarycentre(x1, y1, x2, y2, x3, y3);

    std::cout << "L'habitat estimé du brigand est aux coordonnées (" << habitat.first << ", " << habitat.second << ")" << std::endl;

    return 0;
}
