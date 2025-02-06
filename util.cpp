#include "util.h"
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <iomanip>
#include <limits>

using namespace std ;
using namespace Eigen ;

void ecrit(const string& nomFichier, const VectorXf& h, const VectorXf& delta) {
    ofstream fichier(nomFichier);
    fichier << fixed << setprecision(7);

    //Calcul des valeurs extrêmes des abscisses et ordonnées
    float h_min = h.minCoeff();
    float h_max = h.maxCoeff();
    float delta_min = delta.minCoeff();
    float delta_max = delta.maxCoeff();

    //Écriture de l'entête avec les valeurs extrêmes
    fichier << "# Entête avec les valeurs extrêmes des abscisses et ordonnées\n";
    fichier << "# Abscisses : min = " << h_min << ", max = " << h_max << "\n";
    fichier << "# Ordonnées : min = " << delta_min << ", max = " << delta_max << "\n";
    fichier << "# \n";

    for (size_t i = 0; i < h.size(); ++i) {
        fichier << h[i] << "\t" << delta[i] << "\n";
    }

    fichier.close() ;
}