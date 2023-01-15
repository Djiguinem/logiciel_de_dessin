/**
 * @file test_triangle.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de la figure triangle
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/triangle.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s\n",ROUGE);

  point_t * p1 = creer_point(10, 10, creer_couleur(125, 0, 210));
  point_t * p2 = creer_point(0, 0, creer_couleur(125, 0, 210));
  point_t * p3 = creer_point(5, 0, creer_couleur(125, 0, 210));
  couleur_t c  = creer_couleur(100, 0, 100);
  triangle_t * triangle = creer_triangle(p1,p2,p3,c);
  assert(triangle->detruire !=NULL );
  assert(triangle->afficher !=NULL );
  assert(triangle->get_type !=NULL );
  assert(triangle->coordonne !=NULL );
  assert(strcmp(triangle->get_type(triangle),"triangle")==0);
  assert(triangle->couleur.bleu==c.bleu && triangle->couleur.rouge==c.rouge && triangle->couleur.vert==c.vert);
  assert(triangle->point1 == p1);
  assert(triangle->point2 == p2);
  assert(triangle->point3 == p3);
  triangle->detruire(triangle);

  printf("%stest_triangle a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
