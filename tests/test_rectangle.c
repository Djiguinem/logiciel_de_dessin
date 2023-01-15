/**
 * @file test_rectangle.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de la figure rectangle
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/rectangle.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s\n",ROUGE);

  point_t * p1 = creer_point(10, 6, creer_couleur(125, 0, 210));
  point_t * p2 = creer_point(5, 9, creer_couleur(125, 0, 210));

  couleur_t c  = creer_couleur(100, 0, 100);
  rectangle_t * rectangle = creer_rectangle(p1,p2,c);
  assert(rectangle->detruire !=NULL );
  assert(rectangle->afficher !=NULL );
  assert(rectangle->get_type !=NULL );
  assert(rectangle->coordonne !=NULL );
  assert(strcmp(rectangle->get_type(rectangle),"rectangle")==0);
  assert(rectangle->couleur.bleu==c.bleu && rectangle->couleur.rouge==c.rouge && rectangle->couleur.vert==c.vert);
  assert(rectangle->point1 == p1 && rectangle->point2 == p2);
  rectangle->detruire(rectangle);

  printf("%stest_rectangle a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
