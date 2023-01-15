#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/couleur.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s",ROUGE);

  couleur_t rouge = creer_couleur(255, 0, 0);
  assert(rouge.rouge == 255 && rouge.vert == 0 && rouge.bleu == 0);
  couleur_t vert = creer_couleur(0, 255, 0);
  assert(vert.rouge == 0 && vert.vert == 255 && vert.bleu == 0);

  couleur_t bleu = creer_couleur(0, 0, 255);
  assert(bleu.rouge == 0 && bleu.vert == 0 && bleu.bleu == 255);


  printf("%stest_couleur a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
