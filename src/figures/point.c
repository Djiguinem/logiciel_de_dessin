#include"point.h"


void detruire_point(void * point){
  point_t * p = point;
  free(p);
}


void afficher_point(SDL_Renderer * rendu, void * point){
  point_t * p = point;
  SDL_SetRenderDrawColor(rendu, p->couleur.rouge,
			 p->couleur.vert, p->couleur.bleu, 255);
  SDL_RenderDrawPoint(rendu, p->x, p->y);
}
void coordonne_point(void * point, int * liste) {
  point_t * p = point;
  liste[0] = p->x;
  liste[1] = p->y;
  liste[2] = p->couleur.rouge;
  liste[3] = p->couleur.vert;
  liste[4] = p->couleur.bleu;
}

char * get_type_point() {
  return "point";
}

point_t * creer_point(unsigned int x, unsigned int y, couleur_t c){
  point_t * p = malloc(sizeof(point_t));
  p->detruire = detruire_point;
  p->afficher = afficher_point;
  p->coordonne = coordonne_point;
  p->get_type = get_type_point;
  p->x = x;
  p->y = y;
  p->couleur = c;
  return p;
}



