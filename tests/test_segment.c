/**
 * @file test_segment.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de la figure segment
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/segment.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s\n",ROUGE);

  point_t * p1 = creer_point(10, 10, creer_couleur(125, 0, 210));
  point_t * p2 = creer_point(0, 0, creer_couleur(125, 0, 210));
  couleur_t c  = creer_couleur(100, 0, 100);
  segment_t * segment = creer_segment(p1,p2,c);
  assert( segment->detruire !=NULL );
  assert( segment->afficher !=NULL );
  assert(segment->get_type !=NULL );
  assert(segment->coordonne !=NULL );
  assert(strcmp(segment->get_type(segment),"segment")==0);
  assert(segment->couleur.bleu==c.bleu && segment->couleur.rouge==c.rouge && segment->couleur.vert==c.vert);
  assert(segment->pointOxy == p1);
  assert(segment->pointAxy == p2);
  segment->detruire(segment);

  printf("%stest_segment a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
