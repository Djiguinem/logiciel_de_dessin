#include"liste_figure.h"

maillon_figure_t * creer_maillon(void * figure){
  maillon_figure_t * resultat = malloc(sizeof(maillon_figure_t));
  resultat->figure = figure;
  resultat->suivant = NULL;
  return resultat;
}

void detruire_maillon(maillon_figure_t * m){
  m->figure->detruire(m->figure);
  free(m);
}

liste_figure_t * creer_liste(){
  liste_figure_t * resultat = malloc(sizeof(liste_figure_t));
  resultat->taille = 0;
  resultat->premier = NULL;
  resultat->dernier = NULL;
  return resultat;
}

int liste_est_vide(liste_figure_t * l){
  return l->taille == 0;
}

int liste_taille(liste_figure_t * l){
  return l->taille;
}


void detruire_liste(liste_figure_t * l){
  while(!liste_est_vide(l))
    detruire_maillon(liste_extraire_debut(l));
  free(l);
}

void liste_inserer_debut(liste_figure_t * l, void * figure){
  maillon_figure_t * nouveau = creer_maillon(figure);
  nouveau->suivant = l->premier;
  l->premier = nouveau;
  if( l->taille == 0 )
    l->dernier = nouveau;
  l->taille++;
}

void liste_inserer_fin(liste_figure_t * l, void * figure){
  maillon_figure_t * nouveau = creer_maillon(figure);
  if( l->taille == 0 ){
    l->dernier = nouveau;
    l->premier = nouveau;
  }
  else{
    l->dernier->suivant = nouveau;
    l->dernier = nouveau;
  }
  l->taille++;
}

  
maillon_figure_t * liste_extraire_debut(liste_figure_t * l){
  maillon_figure_t * resultat = l->premier;
  if(l->taille > 0){
    l->premier = l->premier->suivant;
    resultat->suivant = NULL;
    l->taille--;
  }
  return resultat;
}
