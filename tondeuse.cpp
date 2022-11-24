

#include "tondeuse.h"
#include "annexe.h"

using namespace std;


void nouvellePos(Tondeuse& t,const Terrain& terrain);

void tondre(Terrain& terrain, Tondeuse& tondeuse, int pas, const bool
affichParPas) {
   for(Lignes l : terrain) {

   }
}

void nouvellePos(Tondeuse& t,const Terrain& terrain) {

   bool choix = aleatoire();
   // Si choix = 0, on fait un déplacement vertical. Si 1, horizontale.
   if (choix) {
      choix = aleatoire();
      // Si 0 on va à gauche, si 1, à droite.
      if (choix) {
         t.at(0) += 1;
      }
      else {
         t.at(0) -= 1;
      }
   }
   else {
      choix = aleatoire();
      // Si 0 on va à monte, si 1, on descend.
      if(choix) {
         t.at(1) += 1;
      }
      else {
         t.at(1) -= 1;
      }
   }

}
