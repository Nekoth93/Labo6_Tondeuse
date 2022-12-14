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

bool estNouvellePosValide(int& posXTondeuse, int& posYTondeuse, const Terrain& terrain);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pasMax, const bool affichParPas) {
    int& posXTondeuse = tondeuse.at(0);
    int& posYTondeuse = tondeuse.at(1);

    terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse) = T;
    afficherTerrain(terrain);

    for (int nbPas = 0; nbPas < pasMax; ++nbPas) {
        if (estNouvellePosValide(posXTondeuse, posYTondeuse, terrain)) {
            terrain.at(posXTondeuse).at(posYTondeuse) = T;
            if (affichParPas) {
                afficherTerrain(terrain);
            }
        }
    }
    afficherTerrain(terrain);
}

bool estNouvellePosValide(int& posXTondeuse, int& posYTondeuse, const Terrain& terrain) {
    static const int MAX_ALEA = 2;
    bool choix = genererIntAleatoire(MAX_ALEA);
    // Si choix = 0, on fait un déplacement vertical. Si 1, horizontale.
    if (choix) {
        choix = genererIntAleatoire(MAX_ALEA);
        // Si 0 on va à gauche, si 1, à droite.
        if (choix and
            (terrain.at((size_t)posXTondeuse + 1).at((size_t)posYTondeuse) == H or
             terrain.at((size_t)posXTondeuse + 1).at((size_t)posYTondeuse) == T)) {
            posXTondeuse += 1;
            return true;
        } else if (terrain.at((size_t)posXTondeuse - 1).at((size_t)posYTondeuse) == H or
                   terrain.at((size_t)posXTondeuse - 1).at((size_t)posYTondeuse) == T) {
            posXTondeuse -= 1;
            return true;
        } else {
            return false;
        }
    } else {
        choix = genererIntAleatoire(MAX_ALEA);
        // Si 0 on va à monte, si 1, on descend.
        if (choix and (terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse + 1) == H or
                       terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse + 1) == T)) {
            posYTondeuse += 1;
            return true;
        } else if (terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse - 1) == H or
                   terrain.at((size_t)posXTondeuse).at((size_t)posYTondeuse - 1) == T) {
            posYTondeuse -= 1;
            return true;
        } else {
            return false;
        }
    }
}