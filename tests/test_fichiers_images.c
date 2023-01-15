/**
 * @file test_fichiers_images.c
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de teste de manupalation fichiers (sauvegarde et restauration figures) 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/liste_figure.h"
#include"../src/fichiers_images.h"
#include"../src/figures/point.h"
#include"../src/figures/segment.h"

#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"
int fichierLines(char * chemin){
    FILE *fichier = fopen(chemin, "r");
    int nLignes=0;
    if (fichier != NULL) {
    char ligne [1001];
    while (!feof(fichier)) {
      fgets(ligne, 1000, fichier);
            nLignes++;
        }
        fclose(fichier);
    }else{
        printf("erreur d'ouverture du fichier\n");
    }
    return nLignes;
}
void testformat(char * chemin){
    FILE *fichier = fopen(chemin, "r");
    int nLignes=0;
    int nColonne=0;
    assert(fichier != NULL);
    char ligne [1001];
    int i;
    const char * sep_espace = " \n";
    i = 0;
     while (!feof(fichier)) {
        fgets(ligne, 1000, fichier);
        if (i < 3) {
            if (i == 0) {
                assert(strcmp("P3\n", ligne) == 0); 
            }else if (i ==1){
                int r = 0;
                char * sous_ligne = strtok(ligne, sep_espace);
                while (sous_ligne != NULL) {
                    if (r == 0) {
                        nColonne = atoi(sous_ligne);
                        assert(nColonne == 1000); 
                    } else {
                        nLignes = atoi(sous_ligne);
                        assert(nLignes == 1000);
                    }
                    sous_ligne = strtok(NULL, sep_espace);
                    r++;
                }
            }
        }
        i++;
        // printf("%s\n",ligne);
    }
    fclose(fichier);
}

int main(){
    printf("%s \n",ROUGE);
    point_t * p1 = creer_point(10, 10, creer_couleur(125, 0, 210));
    point_t * p2 = creer_point(100, 10, creer_couleur(125, 0, 210));
    point_t * p3 = creer_point(10, 500, creer_couleur(125, 0, 210));
    point_t * p4 = creer_point(10, 500, creer_couleur(125, 0, 210));
    segment_t * segment = creer_segment(p1,p2,creer_couleur(125, 0, 210));
    liste_figure_t * l1 = creer_liste();
    
    liste_inserer_debut(l1,p3);
    liste_inserer_debut(l1,segment);
    sauvegarder_liste_figures("tests/fichier_liste_save.txt",l1);
    assert(liste_taille(l1)==fichierLines("tests/fichier_liste_save.txt"));
    liste_inserer_debut(l1,p4);
    sauvegarder_liste_figures("tests/fichier_liste_save.txt",l1);
    assert(liste_taille(l1)==fichierLines("tests/fichier_liste_save.txt"));
    printf("%s la fonction  sauvegarder_liste_figures a passé les tests avec succès\n", VERT);
    printf("%s \n",ROUGE);
    liste_figure_t * l2 = creer_liste();
    charger_liste_figures("tests/fichier_liste_save.txt",l2);
    assert(liste_taille(l2) == fichierLines("tests/fichier_liste_save.txt"));
    printf("%s la fonction  charger_liste_figures a passé les tests avec succès\n", VERT);
    printf("%s \n",ROUGE);
    
    liste_figure_t * l3 = creer_liste();
    bitmap_t * bitmap1 = creer_bitmap(l3, creer_couleur(255, 0, 0),100, 120);
    assert(bitmap1->detruire !=NULL );
    assert(bitmap1->afficher !=NULL );
    assert(bitmap1->col ==120 );
    assert(bitmap1->row ==100 );

    for (int i=0; i<100; i++) {
        for (int j=0; j<120; j++) {
            assert(bitmap1->pixels[i][j].rouge == 255);
            assert(bitmap1->pixels[i][j].bleu == 0);
            assert(bitmap1->pixels[i][j].vert == 0);
        }
    }

    bitmap_t * bitmap2 = creer_bitmap(l3, creer_couleur(0, 255, 0),100, 100);
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            assert(bitmap2->pixels[i][j].rouge == 0);
            assert(bitmap2->pixels[i][j].vert == 255);
            assert(bitmap2->pixels[i][j].bleu == 0 );
        }
    }

    bitmap_t * bitmap3 = creer_bitmap(l3, creer_couleur(255, 0, 0),100, 100);
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            assert(bitmap3->pixels[i][j].rouge == 255);
            assert(bitmap3->pixels[i][j].bleu == 0);
            assert(bitmap3->pixels[i][j].vert == 0);
        }
    }
    printf("%s la fonction  creer_bitmap a passé les tests avec succès\n", VERT);
    printf("%s \n",ROUGE);

    sauvegarder_image("testimage.ppm", l1);
    /*cette fonction test l'existance du fichier 
        le parcour en testant le respect du format d'un fichier ppm
        il contien les serie d'assersion adequat
    */
    testformat("testimage.ppm");
    printf("%s la fonction  sauvegarder_image a passé les tests avec succès\n", VERT);
    printf("%s \n",ROUGE);

     bitmap_t * btest = creer_bitmap(creer_liste(), creer_couleur(255, 255, 255),100, 100);
    charger_image("testimage.ppm", btest);
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            assert(btest->pixels[i][j].rouge == 255);
            assert(btest->pixels[i][j].bleu == 255);
            assert(btest->pixels[i][j].vert == 255);
        }
    }

    bitmap1->detruire(bitmap1);
    bitmap2->detruire(bitmap2);
    bitmap3->detruire(bitmap3);
    detruire_liste(l1);
    detruire_liste(l2);

    printf("%s\ntest_fichiers_images a passé les tests avec succès\n", VERT);
    printf("%s\n",DEFAUT);
    return EXIT_SUCCESS;
}
