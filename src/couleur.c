#include"couleur.h"


couleur_t creer_couleur(unsigned int rouge, unsigned int vert, unsigned int bleu){
  couleur_t resultat;
  resultat.rouge = rouge;
  resultat.vert = vert;
  resultat.bleu = bleu;
  return resultat;
}
