//---------------------------------------------------------
// Demo             :
// Fichier          : annexe.h
// Auteur(s)        : CARBONARA Nicolas, DELÉTRAZ, Alexandre
// Date de création : 2022-11-24
// But              :
// Modifications    :
// Remarque(s)      : -
//---------------------------------------------------------
#ifndef LABO6_TONDEUSE_ANNEXE_H
#define LABO6_TONDEUSE_ANNEXE_H

#include <vector>

using Lignes = std::vector<char>;
using Terrain = std::vector<Lignes>;

const char L = '#';
const char X = 'X';
const char H = '~';
const char T = '.';

int aleatoire();
void afficherTerrain(const Terrain& terrain, bool afficherPas);

#endif  // LABO6_TONDEUSE_ANNEXE_H
