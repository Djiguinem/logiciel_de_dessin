/**
 * @file test_liste_figure.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste des structures de type figure
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/liste_figure.h"
#include"../src/figures/point.h"

#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
    printf("%s \n",ROUGE);
    point_t * p = creer_point(10, 10, creer_couleur(125, 0, 210));
    maillon_figure_t * m= creer_maillon(p);
    assert( m->figure !=NULL );
    assert( m->suivant ==NULL );
    detruire_maillon(m);
    printf("%smaillon_figure_t a passé les tests avec succès\n", VERT);

    printf("%s \n",ROUGE);
    liste_figure_t * l = creer_liste();
    assert(liste_taille(l) ==  0);
    assert( l->premier ==NULL );
    assert( l->dernier ==NULL );
    detruire_liste(l);
    printf("%sliste_figure_t a passé les tests avec succès\n", VERT);
    
    printf("%s \n",ROUGE);
    l = creer_liste();
    assert(liste_est_vide(l)==1);
    liste_inserer_debut(l,creer_point(10, 10, creer_couleur(125, 0, 210)));
    assert(liste_est_vide(l)==0);
    liste_inserer_fin(l,creer_point(10, 10, creer_couleur(125, 55, 210)));
    assert(liste_est_vide(l)==0);
    liste_extraire_debut(l);
    liste_extraire_debut(l);
    assert(liste_est_vide(l)==1);
    detruire_liste(l);
    printf("%sla fonction liste_est_vide a passé les tests avec succès\n", VERT);

    printf("%s \n",ROUGE);
    l = creer_liste();
    assert(liste_taille(l) ==  0);
    liste_inserer_debut(l,creer_point(10, 10, creer_couleur(125, 55, 210)));
    assert(liste_taille(l) == 1);
    liste_inserer_fin(l,creer_point(10, 10, creer_couleur(125, 55, 210)));
    assert(liste_taille(l) == 2);
    liste_extraire_debut(l);
    assert(liste_taille(l) == 1);
    liste_extraire_debut(l);
    assert(liste_taille(l) == 0);
    detruire_liste(l);
    printf("%sla fonction liste_taille a passé les tests avec succès\n", VERT);

    printf("%s \n",ROUGE);
    l = creer_liste();
    point_t * p1 = creer_point(10, 10, creer_couleur(125, 55, 210));
    liste_inserer_debut(l,p1);
    assert(l->taille==1);
    assert(l->premier->figure==p1);
    point_t * p2 = creer_point(10, 10, creer_couleur(125, 9, 210));
    liste_inserer_debut(l,p2);
    assert(l->taille==2);
    assert(l->premier->figure==p2);
    detruire_liste(l);
    printf("%sla fonction liste_inserer_debut a passé les tests avec succès\n", VERT);

    printf("%s \n",ROUGE);
    l = creer_liste();
    p1 = creer_point(10, 10, creer_couleur(125, 55, 210));
    liste_inserer_fin(l,p1);
    assert(l->taille==1);
    assert(l->dernier->figure==p1);
    p2 = creer_point(10, 10, creer_couleur(125, 9, 210));
    liste_inserer_fin(l,p2);
    assert(l->taille==2);
    assert(l->dernier->figure==p2);
    detruire_liste(l);
    printf("%sla fonction liste_inserer_fin a passé les tests avec succès\n", VERT);
    
    printf("%s \n",ROUGE);
    l = creer_liste();
    assert(liste_extraire_debut(l)==NULL);
    p2 = creer_point(10, 10, creer_couleur(125, 0, 210));
    liste_inserer_debut(l,p2);
    m = liste_extraire_debut(l);
    assert(m->figure==p2);
    detruire_liste(l);
    printf("%sla fonction liste_extraire_debut a passé les tests avec succès\n", VERT); 
    
    // detruire_liste(l);

    printf("%s",DEFAUT);
return EXIT_SUCCESS;
}