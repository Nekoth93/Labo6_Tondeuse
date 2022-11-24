//---------------------------------------------------------
// Demo             :
// Fichier          : annexe.cpp
// Auteur(s)        : CARBONARA Nicolas
// Date de création : 2022-11-24
// But              : -
// Modifications    : -
// Remarque(s)      : -
//---------------------------------------------------------
#include "annexe.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//-------------------------------------------------------------
// Déclaration Fonction & Opérateur
//-------------------------------------------------------------
ostream& operator<<(ostream& os, const Terrain& terrain);
ostream& operator<<(ostream& os, const Lignes& ligne);

//-------------------------------------------------------------
// Initialisation des fonctions
//-------------------------------------------------------------
int genererIntAleatoire(const int valMax) {
    static bool first = true;
    if (first) {
        srand((unsigned)time(NULL));
        first = false;
    }

    return rand() % valMax;
}

void afficherTerrain(const Terrain& terrain) {
#if defined(__linux__)  // Or #if __linux__
    system("clear");
#elif _WIN32
    system("CLS");
#else
    system("clear");
#endif
    cout << terrain;
}

//-------------------------------------------------------------
// Initialisation des Opérateurs
//-------------------------------------------------------------
ostream& operator<<(ostream& os, const Lignes& ligne) {
    for (size_t i = 0; i < ligne.size(); ++i) {
        if (i)
            os << " ";
        os << ligne[i];
    }
    return os;
}

ostream& operator<<(ostream& os, const Terrain& terrain) {
    for (const Lignes& ligne : terrain)
        os << ligne << endl;
    return os;
}