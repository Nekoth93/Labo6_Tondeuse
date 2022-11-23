
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "tondeuse.h"

bool random();

void nouvellePos(Tondeuse& t,const Terrain& terrain);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pas, const bool
affichParPas) {
   for(Lignes l : terrain) {

   }
}

void nouvellePos(Tondeuse& t,const Terrain& terrain) {

}

bool random() {
   srand(time(NULL));

   return rand()%1;

}