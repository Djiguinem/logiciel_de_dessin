/**
 * @file test_cercle.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de la figure cercle
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/cercle.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s\n",ROUGE);

  point_t * p1 = creer_point(10, 10, creer_couleur(125, 0, 210));
  couleur_t c  = creer_couleur(100, 0, 100);
  int r = 30;
  cercle_t * cercle = creer_cercle(p1,r,c);
  assert(cercle->detruire !=NULL );
  assert(cercle->afficher !=NULL );
  assert(cercle->couleur.bleu==c.bleu && cercle->couleur.rouge==c.rouge && cercle->couleur.vert==c.vert);
  assert(cercle->centre == p1);
  assert(cercle->rayon == r);
  cercle->detruire(cercle);

  p1 = creer_point(100, 106, creer_couleur(125, 0, 210));
  c  = creer_couleur(255, 0, 50);
  cercle = creer_cercle(p1,r,c);
  assert(cercle->couleur.bleu==c.bleu && cercle->couleur.rouge==c.rouge && cercle->couleur.vert==c.vert);
  assert(cercle->centre == p1);
  assert(cercle->rayon == r);
  cercle->detruire(cercle);


  printf("%stest_cercle a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
