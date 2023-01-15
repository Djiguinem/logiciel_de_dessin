#ifndef __LISTE_FIGURE_H__
#define __LISTE_FIGURE_H__
#include <SDL2/SDL.h>


typedef struct figure_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
  void (*coordonne)(void *, int *);
  char * (*get_type)();
}figure_t;

typedef struct maillon_figure_s{
  figure_t * figure;
  struct maillon_figure_s * suivant;
}maillon_figure_t;


typedef struct liste_figure_s{
  int taille;
  maillon_figure_t * premier;
  maillon_figure_t * dernier;
}liste_figure_t;


/**
   @brief Cette fonction initialise un maillon d'une liste de figures.
   
   @param figure est un pointeur vers une figure
   @require figure de type maillon figure 
   @ensure un maillon (adresse)
   @ensures resultat->figure == figure
   @ensures resultat->suivant == NULL 
   @return un pointeur vers un maillon d'une liste de figures.
*/
maillon_figure_t * creer_maillon(void * figure);

/**
   @brief Libère l'espace mémoire réservé par un maillon et la figure qu'il contient.
   @param m est un pointeur sur un maillon d'une liste de figure.
   @require m a été initialisé par creer_maillon
*/
void detruire_maillon(maillon_figure_t * m);

/**
   @brief Cette fonction initialise une liste de figures, vide.  
   @ensures resultat->taille ==0.
   @ensures resultat->premier == l->dernier == null
   @return un pointeur vers une liste vide.
*/
liste_figure_t * creer_liste();

/**
   @brief Libère l'espace mémoire utilisée par une liste, les maillons 
    et les figures qu'elle contient.
   @param l est un pointeur vers la liste à libérer.
   @require l a été initialisé par creer_liste.
*/
void detruire_liste(liste_figure_t * l);

/**
   @brief Vérifie si la liste passée en entrée est vide.
   
   @param l est un pointeur vers une  liste figure.
   @require l a été initialisé par creer_liste.
   @ensures si resultat == 1, l->taille == 0 && l->premier == l->dernier == NULL.
   @ensures si resultat == 0, 0 < l->taille.
   @return 1 si la liste est vide, 0 sinon.
 */
int liste_est_vide(liste_figure_t * l);

/**
   @brief Renvoie le nombre de maillon contenu dans la liste.
   
   @param l est un poitneur vers une liste de figures.
   @require l a été initialisé par creer_liste.
   @ensures resultat >= 0
   @ensures liste_taille(l)+1 == liste_taille(liste_inserer_debut(l,figure)).
   @return le nombre de maillon contenu dans la liste.
*/
int liste_taille(liste_figure_t * l);

/**
   @brief Crée un maillon pour stocker la figure passée en argument et l'insère au début de la liste de figures
   
   @param l est un pointeur vers une liste de figures.
   @param figure est un pointeur vers une figure a ajouter.
   @require figure pointe sur une figure.
   @require l a été initialisé par creer_liste.
   @ensures liste_taille(resultat) == liste_taille(l) + 1.
   @ensures l->premier->figure == figure
   @ensures liste_taille(resultat)==1 alors l->dernier->figure == figure
 */
void liste_inserer_debut(liste_figure_t * l, void * figure);

/**
   @brief Crée un maillon pour stocker la figure passée en argument et l'insère à la fin de la liste de figures
   
   @param l est un pointeur vers une liste de figures
   @param figure est un pointeur vers une figure.
   @require l a été initialisé par creer_liste.
   @require figure pointe sur une figure.
   @require l a été initialisé par creer_liste.
   @ensures liste_taille(resultat) == liste_taille(l) + 1.
   @ensures l->dernier->figure == figure.
   @ensures liste_taille(resultat)==1 alors l->premier->figure == figure

*/
void liste_inserer_fin(liste_figure_t * l, void * figure);

/**
   @brief Extrait un maillon du début d'une liste de figure.
   
   @param l est un pointeur vers une liste de figures.
   @require l a été initialisé par creer_liste.
   @ensures liste_taille(resultat) == liste_taille(l) - 1.
   @ensures l->premier == liste_extraire_debut(l).
   @return un pointeur vers le maillon d'une liste de figures.
*/
maillon_figure_t * liste_extraire_debut(liste_figure_t * l);


#endif
