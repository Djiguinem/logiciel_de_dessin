/**
 * @file test_polygone.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de la figure polygone
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/polygone.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s\n",ROUGE);

  point_t * p1 = creer_point(10, 10, creer_couleur(125, 0, 210));
  point_t * p2 = creer_point(0, 0, creer_couleur(125, 0, 210));
  point_t * p3 = creer_point(5, 0, creer_couleur(125, 0, 210));
  couleur_t c  = creer_couleur(100, 0, 100);
  point_t *liste_points[3];
  liste_points[0]=p1;
  liste_points[1]=p2;
  liste_points[2]=p3;
  polygone_t * polygone = creer_polygone(liste_points,3,c);
  assert(polygone->detruire !=NULL );
  assert(polygone->afficher !=NULL );
  assert(polygone->get_type !=NULL );
  assert(polygone->coordonne !=NULL );
  assert(strcmp(polygone->get_type(polygone),"polygone")==0);
  assert(polygone->couleur.bleu==c.bleu && polygone->couleur.rouge==c.rouge && polygone->couleur.vert==c.vert);
  assert(polygone->points[0] == p1);
  assert(polygone->points[1] == p2);
  assert(polygone->points[2] == p3);
  polygone->detruire(polygone);

  printf("%stest_polygone a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
