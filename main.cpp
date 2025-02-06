#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>

//entêtes personnelles
#include "methode.h" //La méthode : tabulation
#include "fcts.h" //Les fonctions test
#include "util.h" //Ecriture dans un fichier

using namespace std ;
using namespace Eigen ;

extern float k ;

int main () {
    k =  1.0f ;
    float hmin, hmax, pas ;
    int n, choix, estim ;
    // Saisie des paramètres
    cout << "Entrer hmin, hmax et le nb de pts" << endl ;
    cin >> hmin >> hmax >> n ;

    //Affichage du menu pour choisir la fonction
    cout << "Choisissez la fonction à dériver :\n";
    cout << "1. Fonctiony sinus \n";
    cout << "2. Fonction exponentielle \n";
    cout << "Votre choix (1-2) : ";
    cin >> choix;

    //Affichage du menu pour choisir l'estimation'
    cout << "Choisissez l'estimation' :\n";
    cout << "1. Estimation décentrée à droite \n";
    cout << "2. Estimation décentrée à gauche \n";
    cout << "3. Estimation centrée \n";
    cout << "Votre choix (1-3) : ";
    cin >> estim; 

    VectorXf h(n); //Vecteur d'abscisses
    VectorXf delta(n); //Vecteur d'ordonnées

    pas = pow((hmax/hmin),1./(n-1)) ;

    //Sélection de la fonction en fonction du choix de l'utilisateur
    switch (choix) {
        case 1:
            cout << "Dérivée de la fonction sin " << h(0) << " et " << h(n - 1) << endl;

            if (estim == 3) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = M_PI/4 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tdd(sinf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("sin.txt", h, delta ) ;
                }
            }

            if (estim == 4) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = M_PI/4 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tdg(sinf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("sin.txt", h, delta ) ;
                }
            }

            if (estim == 5) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = M_PI/4 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tc(sinf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("sin.txt", h, delta ) ;
                }
            }

            cout << "Résultats écrits dans 'sin.txt'." << endl;
            break;

        case 2:
            cout << "Dérivée de la fonction exp " << h(0) << " et " << h(n - 1) << endl;

            if (estim == 3) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = 0 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tdd(expf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("exp.txt", h, delta ) ;
                }
            }

            if (estim == 4) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = 0 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tdg(expf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("exp.txt", h, delta ) ;
                }
            }

            if (estim == 5) {
                for(int i=0; i<n; i++){ //Création grille des abscisses
                    float t0_ = 0 ;
                    h(i) = hmin * pow(pas, i) ;
                    delta(i) = abs(deriv2tc(expf, t0_, h(i)) - derivSinAna(t0_)) ;
                    ecrit("exp.txt", h, delta ) ;
                }
            }

            cout << "Résultats écrits dans 'exp.txt'." << endl;
            break;

    }
}