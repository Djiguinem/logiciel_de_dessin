#ifndef __COULEUR_H__
#define __COULEUR_H__

typedef struct couleur_s{
  unsigned int rouge;
  unsigned int vert;
  unsigned int bleu;
}couleur_t;

/**
   Cette fonction initialise une structure de type couleur_t, où une couleur
   est définie en fonction de trois valeurs, rouge, vert et bleu, toutes trois
   comprises entre 0 et 255.
   @requires rouge <= 255 && vert <= 255 && bleu <= 255
   @ensures resultat.rouge == rouge && resultat.vert == vert && resultat.bleu == bleu
 */
couleur_t creer_couleur(unsigned int rouge, unsigned int vert, unsigned int bleu);

#endif
