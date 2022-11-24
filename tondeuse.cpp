
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "tondeuse.h"

int random();

void nouvellePos(Tondeuse& t,const Terrain& terrain);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pas, const bool
affichParPas) {
   for(Lignes l : terrain) {

   }
}

void nouvellePos(Tondeuse& t,const Terrain& terrain) {

}

int random() {
   static bool first = true;
   if (first) {
      srand ((unsigned)time (NULL));
      first = false;
   }

   return rand()%2;

}