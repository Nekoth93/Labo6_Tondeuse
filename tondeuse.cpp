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

bool estNouvellePosValide(Tondeuse& t, const Terrain& terrain);
void tondre(Terrain& terrain, Tondeuse& tondeuse, int pasMax, const bool affichParPas);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pasMax, const bool affichParPas) {
    int* ptrPosXTondeuse = &tondeuse.at(0);
    int* ptrPosYTondeuse = &tondeuse.at(1);

    terrain.at(*ptrPosXTondeuse).at(*ptrPosYTondeuse) = T;
    afficherTerrain(terrain);

    for (int nbPas = 0; nbPas < pasMax; ++nbPas) {
        if (estNouvellePosValide(tondeuse, terrain)) {
            terrain.at(*ptrPosXTondeuse).at(*ptrPosYTondeuse) = T;
            if (affichParPas) {
                afficherTerrain(terrain);
            }
        }
    }
    afficherTerrain(terrain);
}

bool estNouvellePosValide(Tondeuse& t, const Terrain& terrain) {
    static const int MAX_ALEA = 2;
    bool choix = genererIntAleatoire(MAX_ALEA);
    // Si choix = 0, on fait un déplacement vertical. Si 1, horizontale.
    if (choix) {
        choix = genererIntAleatoire(MAX_ALEA);
        // Si 0 on va à gauche, si 1, à droite.
        if (choix and
            (terrain.at((size_t)t.at(0) + 1).at((size_t)t.at(1)) == H or
             terrain.at((size_t)t.at(0) + 1).at((size_t)t.at(1)) == T)) {
            t.at(0) += 1;
            return true;
        } else if (terrain.at((size_t)t.at(0) - 1).at((size_t)t.at(1)) == H or
                   terrain.at((size_t)t.at(0) - 1).at((size_t)t.at(1)) == T) {
            t.at(0) -= 1;
            return true;
        } else {
            return false;
        }
    } else {
        choix = genererIntAleatoire(MAX_ALEA);
        // Si 0 on va à monte, si 1, on descend.
        if (choix and (terrain.at((size_t)t.at(0)).at((size_t)t.at(1) + 1) == H or
                       terrain.at((size_t)t.at(0)).at((size_t)t.at(1) + 1) == T)) {
            t.at(1) += 1;
            return true;
        } else if (terrain.at((size_t)t.at(0)).at((size_t)t.at(1) - 1) == H or
                   terrain.at((size_t)t.at(0)).at((size_t)t.at(1) - 1) == T) {
            t.at(1) -= 1;
            return true;
        } else {
            return false;
        }
    }
}
