
#include <cstdlib>
#include <ctime>
#include "annexe.h"

using namespace std;


int aleatoire() {
   static bool first = true;
   if (first) {
      srand ((unsigned)time (NULL));
      first = false;
   }

   return rand()%2;

}







