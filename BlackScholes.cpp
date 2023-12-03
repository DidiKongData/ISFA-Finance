#include <iostream>
#include <cmath>

using namespace std;

// La distribution cumulative normale pour calculer N(d1) et N(d2)
double N(double x) {
    const double pi = 3.14159265358979323846;
    return 0.5 * erfc(-x / sqrt(2.0));
}

// Fonction Principale : Application directe de la formule de Black-Scholes
double blackScholes(double S0, double X, double t, double sigma, double r) {
    // fonctions simulant la courbe en cloche
    double d1 = (log(S0 / X) + (r + 0.5 * pow(sigma, 2)) * t) / (sigma * sqrt(t)); 
    double d2 = d1 - sigma * sqrt(t);

    // Ce que renvoie la fonction :
    double callOptionPrice = S0 * N(d1) - X * exp(-r * t) * N(d2);
    return callOptionPrice;
}

int main() {
    // Simulation avec certaines valeurs 
    double S0 = 100.0;       // Prix actuel de l'action
    double X = 100.0;     // Prix auquel l'action sera acheté si l'option est exercé
    double t = 1.0;    // Temps restant jusqu'à l'échéance  de l'otpion, en années
    double sigma = 0.2;        // Volatilité de l'option
    double r = 0.05;     // Taux sans risque

    // Calcul du prix de l'option d'achat
    double callOptionPrice = blackScholes(S0, X, t, sigma, r);

    // Affichage
    cout << "Le prix de l'option d'achat est : " << callOptionPrice << endl;

    return 0;
}
