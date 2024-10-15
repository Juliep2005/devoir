#include <iostream>
#include <cmath>
#include <fstream>

const int LARGEUR = 800;
const int HAUTEUR = 800;
const int MAX_ITER = 1000;

// Fonction pour générer la fractale de Mandelbrot
void genererMandelbrot(double xmin, double xmax, double ymin, double ymax, int max_iter) {
    std::ofstream fichier("mandelbrot.ppm");

    fichier << "P3\n" << LARGEUR << " " << HAUTEUR << "\n255\n";

    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            double cx = xmin + (xmax - xmin) * x / (LARGEUR - 1);
            double cy = ymin + (ymax - ymin) * y / (HAUTEUR - 1);

            double zx = 0.0;
            double zy = 0.0;
            int iter = 0;

            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                iter++;
            }

            // Couleur basée sur le nombre d'itérations
            if (iter == max_iter) {
                fichier << "0 0 0 "; // noir pour l'intérieur de l'ensemble de Mandelbrot
            } else {
                // Gradient de couleur pour l'extérieur
                int r = (iter % 256);
                int g = (iter * 5 % 256);
                int b = (iter * 9 % 256);
                fichier << r << " " << g << " " << b << " ";
            }
        }
        fichier << "\n";
    }

    fichier.close();
}

int main() {
    // Génère la fractale de Mandelbrot avec les coordonnées et la résolution souhaitées
    genererMandelbrot(-2.5, 1.5, -1.5, 1.5, MAX_ITER);
    std::cout << "Fractale de Mandelbrot générée dans 'mandelbrot.ppm'.\n";
    return 0;
}
