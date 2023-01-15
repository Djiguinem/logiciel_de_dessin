#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/point.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s",ROUGE);

  point_t * p = creer_point(10, 10, creer_couleur(125, 0, 210));

  assert( p->detruire !=NULL );
  assert( p->afficher !=NULL );
  assert(p->get_type !=NULL );
  assert(p->coordonne !=NULL );
  assert(strcmp(p->get_type(p),"point")==0);

  p->detruire(p);

  printf("%stest_point a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
