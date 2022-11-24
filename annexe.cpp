//---------------------------------------------------------
// Demo             :
// Fichier          : annexe.cpp
// Auteur(s)        : CARBONARA Nicolas
// Date de création : 2022-11-24
// But              :
// Modifications    :
// Remarque(s)      : -
//---------------------------------------------------------
#include "annexe.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int aleatoire() {
    static bool first = true;
    if (first) {
        srand((unsigned)time(NULL));
        first = false;
    }

    return rand() % 2;
}

void afficherTerrain(const Terrain& terrain, bool afficherPas) {
    if (afficherPas) {
        system("cls");
        system("clear");
    }
    cout << Terrain;
}