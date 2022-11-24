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
    int posXTondeuse = tondeuse.at(0);
    int posYTondeuse = tondeuse.at(1);
    terrain.at(posXTondeuse).at(posYTondeuse) = T;

    for (int nbPas = 0; nbPas < pasMax; ++nbPas) {
        if (estNouvellePosValide) {
            terrain.at(tondeuse.at(0)).at(tondeuse.at(1)) = T;
            afficherTerrain(terrain, affichParPas);
            continue;
        }
        --nbPas;
    }
}

bool estNouvellePosValide(Tondeuse& t, const Terrain& terrain) {
    static const int MAXALEA = 2;
    bool choix = genererIntAleatoire(MAXALEA);
    // Si choix = 0, on fait un déplacement vertical. Si 1, horizontale.
    if (choix) {
        choix = genererIntAleatoire(MAXALEA);
        // Si 0 on va à gauche, si 1, à droite.
        if (choix and terrain.at(t.at(0) + 1).at(t.at(1)) == H) {
            t.at(0) += 1;
            return 1;
        } else if (terrain.at(t.at(0) - 1).at(t.at(1)) == H) {
            t.at(0) -= 1;
            return 1;
        } else {
            return 0;
        }
    } else {
        choix = genererIntAleatoire(MAXALEA);
        // Si 0 on va à monte, si 1, on descend.
        if (choix and terrain.at(t.at(0)).at(t.at(1) + 1) == H) {
            t.at(1) += 1;
            return 1;
        } else if (terrain.at(t.at(0)).at(t.at(1) - 1) == H) {
            t.at(1) -= 1;
            return 1;
        } else {
            return 0;
        }
    }
}
