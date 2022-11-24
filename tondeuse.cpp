//---------------------------------------------------------
// Demo             :
// Fichier          : tondeuse.cpp
// Auteur(s)        : CARBONARA Nicolas, DELÉTRAZ Alexandre
// Date de création : 2022-11-24
// But              : Tondre un terrain donné
// Modifications    :
// Remarque(s)      : -
//---------------------------------------------------------
#include "tondeuse.h"

#include "annexe.h"

using namespace std;

bool nouvellePos(Tondeuse& t, const Terrain& terrain);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pasMax, const bool affichParPas) {
    int posXTondeuse = tondeuse.at(0);
    int posYTondeuse = tondeuse.at(1);
    terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse) = T;

    for (int nbPas = 0; nbPas < pasMax; ++nbPas) {
        if (nouvellePos(tondeuse, terrain)) {
            terrain.at((size_t)tondeuse.at(0)).at((size_t)tondeuse.at(1)) = T;
            afficherTerrain(terrain, affichParPas);
            continue;
        }
        --nbPas;
    }
}

bool nouvellePos(Tondeuse& t, const Terrain& terrain) {
    bool choix = aleatoire();
    // Si choix = 0, on fait un déplacement vertical. Si 1, horizontale.
    if (choix) {
        choix = aleatoire();
        // Si 0 on va à gauche, si 1, à droite.
        if (choix and terrain.at((size_t)t.at(0) + 1).at((size_t)t.at(1)) == H) {
            t.at(0) += 1;
            return true;
        } else if (terrain.at((size_t)t.at(0) - 1).at((size_t)t.at(1)) == H) {
            t.at(0) -= 1;
            return true;
        } else {
            return false;
        }
    } else {
        choix = aleatoire();
        // Si 0 on va à monte, si 1, on descend.
        if (choix and terrain.at((size_t)t.at(0)).at((size_t)t.at(1) + 1) == H) {
            t.at(1) += 1;
            return true;
        } else if (terrain.at((size_t)t.at(0)).at((size_t)t.at(1) - 1) == H) {
            t.at(1) -= 1;
            return true;
        } else {
            return false;
        }
    }
}
