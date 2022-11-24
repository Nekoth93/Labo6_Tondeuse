//---------------------------------------------------------
// Demo             :
// Fichier          : tondeuse.h
// Auteur(s)        : CARBONARA Nicolas, DELÉTRAZ Alexandre
// Date de création : 2022-11-24
// But              : -
// Modifications    : -
// Remarque(s)      : -
//---------------------------------------------------------
#ifndef LABO6_TONDEUSE_TONDEUSE_H
#define LABO6_TONDEUSE_TONDEUSE_H
#include <vector>

#include "annexe.h"

typedef std::vector<int> Tondeuse;

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pas, const bool affichParPas);

#endif  // LABO6_TONDEUSE_TONDEUSE_H
