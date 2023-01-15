/**
 * @file fichiers_images.c
 * @author Abdoulaye Djibril Diallo 22112788
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"fichiers_images.h"
#include "couleur.h"
#include "figures/polygone.h"
#include"liste_figure.h"
#include"figures/point.h"
#include"figures/rectangle.h"
#include"figures/segment.h"
#include"figures/triangle.h"
#include"figures/cercle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_POINTE  "point"
#define TYPE_TRIANGLE  "triangle"
#define TYPE_CERCLE  "cercle"
#define TYPE_SEGMENT  "segment"
#define TYPE_RECTANGLE  "rectangle"
#define TYPE_POLYGONE  "polygone"



void sauvegarder_liste_figures(char * chemin, liste_figure_t * l) {
  FILE *f = NULL;
  f = fopen(chemin, "w");
  if (f == NULL) {
    exit(1);
  } else {
    int liste [100] = {0};
    maillon_figure_t * tmp = l->premier;
    while (tmp != NULL) {
      int taille = strlen(tmp->figure->get_type()) + 1;
      char type [taille];
      strcpy(type, tmp->figure->get_type());
      tmp->figure->coordonne(tmp->figure, liste);
      if (strcmp(type, TYPE_POINTE) == 0) {
        fprintf(f, "%s %d %d %d %d %d", type, liste[0], liste[1], liste[2], liste[3], liste[4]);
      } else if (strcmp(type, TYPE_TRIANGLE) == 0) {
        fprintf(f, "%s %d %d %d %d %d %d %d %d %d", type, liste[0], liste[1], liste[2], liste[3], liste[4], liste[5], liste[6], liste[7], liste[8]);
      } else if (strcmp(type, TYPE_CERCLE) == 0) {
        fprintf(f, "%s %d %d %d %d %d %d", type, liste[0], liste[1], liste[2], liste[3], liste[4], liste[5]);
      } else if (strcmp(type, TYPE_SEGMENT) == 0) {
        fprintf(f, "%s %d %d %d %d %d %d %d", type, liste[0], liste[1], liste[2], liste[3], liste[4], liste[5], liste[6]);
      } else if (strcmp(type, TYPE_RECTANGLE) == 0) {
        fprintf(f, "%s %d %d %d %d %d %d %d", type, liste[0], liste[1], liste[2], liste[3], liste[4], liste[5], liste[6]);
      } else if (strcmp(type, TYPE_POLYGONE) == 0) {
        char *data = malloc(liste[0]*35 * sizeof(char));
        sprintf(data, "%s %d", type, liste[0]); // new
        for (int ii = 1; ii <= liste[0]*5; ii++) {
            char d[4];
            sprintf(d, " %d", liste[ii]);
            strcat(data, d);
        }
        fprintf(f, "%s", data);
        free(data);
      }
      if (tmp->suivant != NULL) {
        fprintf(f, "\n");
      }
      tmp = tmp->suivant;
    }
    fclose(f);
  }
}

int charger_liste_figures(char * chemin, liste_figure_t * l) {
  FILE *f = NULL;
  f = fopen(chemin, "r");
  if (f != NULL) {
    unsigned int liste [15] = {0};
    char type [15];
    char ligne [1001];
    while (!feof(f)) {
      fgets(ligne, 1000, f);
      sscanf(ligne, "%s", type);
      if (strcmp(type, TYPE_POINTE) == 0) {
        sscanf(ligne, "%s %d %d %d %d %d", type, &liste[0], &liste[1], &liste[2], &liste[3], &liste[4]);
        liste_inserer_fin(l, creer_point(liste[0], liste[1], creer_couleur(liste[2], liste[3], liste[4])));
      } else if (strcmp(type, TYPE_TRIANGLE) == 0) {
        sscanf(ligne, "%s %d %d %d %d %d %d %d %d %d", type, &liste[0], &liste[1], &liste[2], &liste[3], &liste[4], &liste[5], &liste[6], &liste[7], &liste[8]);
        liste_inserer_fin(l, creer_triangle(creer_point(liste[0], liste[1], creer_couleur(liste[6], liste[7], liste[8])),
          creer_point(liste[2], liste[3], creer_couleur(liste[6], liste[7], liste[8])), creer_point(liste[4], liste[5], creer_couleur(liste[6], liste[7], liste[8])),
          creer_couleur(liste[6], liste[7], liste[8])
        ));
      } else if (strcmp(type, TYPE_CERCLE) == 0) {
        sscanf(ligne, "%s %d %d %d %d %d %d", type, &liste[0], &liste[1], &liste[2], &liste[3], &liste[4], &liste[5]);
        liste_inserer_fin(l, creer_cercle(creer_point(liste[0], liste[1], creer_couleur(liste[3], liste[4], liste[5])), liste[2], creer_couleur(liste[3], liste[4], liste[5])));
      } else if (strcmp(type, TYPE_SEGMENT) == 0) {
        sscanf(ligne, "%s %d %d %d %d %d %d %d", type, &liste[0], &liste[1], &liste[2], &liste[3], &liste[4], &liste[5], &liste[6]);
        liste_inserer_fin(l, creer_segment(creer_point(liste[0], liste[1], creer_couleur(liste[4], liste[5], liste[6])),
          creer_point(liste[2], liste[3], creer_couleur(liste[4], liste[5], liste[6])), creer_couleur(liste[4], liste[5], liste[6])
        ));
      } else if (strcmp(type, TYPE_RECTANGLE) == 0) {
        sscanf(ligne, "%s %d %d %d %d %d %d %d", type, &liste[0], &liste[1], &liste[2], &liste[3], &liste[4], &liste[5], &liste[6]);
        liste_inserer_fin(l, creer_rectangle(
          creer_point(liste[0], liste[1], creer_couleur(liste[4], liste[5], liste[6])), creer_point(liste[2], liste[3], creer_couleur(liste[4], liste[5], liste[6])),
          creer_couleur(liste[4], liste[5], liste[6])
        ));
      } else if (strcmp(type, TYPE_POLYGONE) == 0) {
        char char_taille[3];
        sscanf(ligne, "%s %s", type, char_taille);
        int taille = atoi(char_taille);
        point_t * list_points[taille+1];
        const char * separators = " \n";
        char * sub_ligne = strtok(ligne, separators);
        int z = 0;
        int t = 0;
        int index = 0;
        int px, py, r, g, b;
        while (sub_ligne != NULL) {
          if (t > 1) {
            if (z == 0) {
              px = atoi(sub_ligne);
            } else if (z == 1) {
              py = atoi(sub_ligne);
            } else if (z == 2) {
              r = atoi(sub_ligne);
            } else if (z == 3) {
              g = atoi(sub_ligne);
            } else {
              b = atoi(sub_ligne);
              list_points[index] = creer_point(px, py, creer_couleur(r, g, b));
              z = -1;
              index++;
            }
            z++;
          }
          t++;
          sub_ligne = strtok(NULL, separators);
        }
        liste_inserer_fin(l, creer_polygone(list_points, taille, creer_couleur(r, g, b)));
      } 
    }
    fclose(f);
    return 1;
  } 
  return 0;
}

void sauvegarder_image(char * chemin, liste_figure_t * l) {
  const int row = 1000;
  const int col = 1000;
  const int p = 250;
  const int color_max = 255;
  const char default_color [] = "255 255 255"; 
  FILE *f = NULL;
  f = fopen(chemin, "w");
  if (f == NULL) {
    exit(1);
  } else {
    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n", col, row);
    fprintf(f, "%d\n", color_max);
    int i,j;
    maillon_figure_t * tmp = l->premier;
    int liste [100] = {0};
    char ***data;
    data = malloc(row * sizeof(char **));
    for (i = 0; i < row; i++) {
        data[i] = malloc(col * sizeof(char *));
        for (j = 0; j < col; j++) {
            data[i][j] = malloc(p);
            strcpy(data[i][j], default_color);
        }
    }
    i = 0;
    while (tmp != NULL) {
      tmp->figure->coordonne(tmp->figure, liste);
      char value [100];
      int taille;
      if (strcmp(tmp->figure->get_type(), TYPE_POINTE) == 0) {
        sprintf(value, "%d %d %d", liste[2], liste[3], liste[4]);
        if (liste[1] < row && liste[0] < col) {
          strcpy(data[liste[1]][liste[0]], value);
        }
      } else if (strcmp(tmp->figure->get_type(), TYPE_SEGMENT) == 0) {
        coordonne_t * pt =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(pt, liste[0], liste[1], liste[2], liste[3]);
        sprintf(value, "%d %d %d", liste[4], liste[5], liste[6]);
        for (int ii = 0; ii < taille; ii++) {
          if (pt[ii].x < row && pt[ii].y < col) {
            strcpy(data[pt[ii].x][pt[ii].y], value);
          }
        }
        free(pt);
      } else if (strcmp(tmp->figure->get_type(), TYPE_RECTANGLE) == 0) {
        coordonne_t * seg1 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg1, liste[0], liste[1], liste[2], liste[1]);
        sprintf(value, "%d %d %d", liste[4], liste[5], liste[6]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg1[ii].x < row && seg1[ii].y < col) {
            strcpy(data[seg1[ii].x][seg1[ii].y], value);
          }
        }
        free(seg1);
        coordonne_t * seg2 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg2, liste[0], liste[1], liste[0], liste[3]);
        sprintf(value, "%d %d %d", liste[4], liste[5], liste[6]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg2[ii].x < row && seg2[ii].y < col) {
            strcpy(data[seg2[ii].x][seg2[ii].y], value);
          }
        }
        free(seg2);
        coordonne_t * seg3 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg3, liste[2], liste[1], liste[2], liste[3]);
        sprintf(value, "%d %d %d", liste[4], liste[5], liste[6]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg3[ii].x < row && seg3[ii].y < col) {
            strcpy(data[seg3[ii].x][seg3[ii].y], value);
          }
        }
        free(seg3);
        coordonne_t * seg4 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg4, liste[0], liste[3], liste[2], liste[3]);
        sprintf(value, "%d %d %d", liste[4], liste[5], liste[6]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg4[ii].x < row && seg4[ii].y < col) {
            strcpy(data[seg4[ii].x][seg4[ii].y], value);
          }
        }
        free(seg4);
      } else if (strcmp(tmp->figure->get_type(), TYPE_TRIANGLE) == 0) {
        coordonne_t * seg1 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg1, liste[0], liste[1], liste[2], liste[3]);
        sprintf(value, "%d %d %d", liste[6], liste[7], liste[8]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg1[ii].x < row && seg1[ii].y < col) {
            strcpy(data[seg1[ii].x][seg1[ii].y], value);
          }
        }
        free(seg1);
        coordonne_t * seg2 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg2, liste[0], liste[1], liste[4], liste[5]);
        sprintf(value, "%d %d %d", liste[6], liste[7], liste[8]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg2[ii].x < row && seg2[ii].y < col) {
            strcpy(data[seg2[ii].x][seg2[ii].y], value);
          }
        }
        free(seg2);
        coordonne_t * seg3 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg3, liste[2], liste[3], liste[4], liste[5]);
        sprintf(value, "%d %d %d", liste[6], liste[7], liste[8]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg3[ii].x < row && seg3[ii].y < col) {
            strcpy(data[seg3[ii].x][seg3[ii].y], value);
          }
        }
        free(seg3);
      } else if (strcmp(tmp->figure->get_type(), TYPE_CERCLE) == 0) {
        coordonne_t * pt =  malloc(3000 * sizeof(coordonne_t));
        taille = get_cercles(pt, liste[0], liste[1], liste[2]);
        sprintf(value, "%d %d %d", liste[3], liste[4], liste[5]);
        for (int ii = 0; ii < taille; ii++) {
          if (pt[ii].x < row && pt[ii].y < col) {
            strcpy(data[pt[ii].x][pt[ii].y], value);
          }
        }
        free(pt);
      } else if (strcmp(tmp->figure->get_type(), TYPE_POLYGONE) == 0) {
        j = 0;
        for (size_t i = 0; i < liste[0]-1; i++) {
          coordonne_t * seg =  malloc(1450 * sizeof(coordonne_t));
          taille = get_points(seg, liste[j+1], liste[j+2], liste[j+6], liste[j+7]);
          sprintf(value, "%d %d %d", liste[3], liste[4], liste[5]);
          for (int ii = 0; ii < taille; ii++) {
            strcpy(data[seg[ii].x][seg[ii].y], value);
          }
          free(seg);
          j += 5;
        }
        j -= 5;
        coordonne_t * seg =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg, liste[1], liste[2], liste[j+6], liste[j+7]);
        sprintf(value, "%d %d %d", liste[3], liste[4], liste[5]);
        for (int ii = 0; ii < taille; ii++) {
          strcpy(data[seg[ii].x][seg[ii].y], value);
        }
        free(seg);
      }
      i++;
      tmp = tmp->suivant;
    }
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        if (j+1 != col) {
          fprintf(f, "%s\t", data[i][j]);
        } else {
          fprintf(f, "%s\n", data[i][j]);
        }
      }
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
    fclose(f);
  }
}



int charger_image(char * chemin, bitmap_t * b) {
  FILE *f = NULL;
  int i,row,col,z;
  f = fopen(chemin, "r");
  if (f != NULL) {
    int taille_ligne = 10000;
    char * ligne = malloc(taille_ligne * sizeof(char));
    const char * separators = " \t\n";
    i = 0;
    row = 0;
    col = 0;
    z = 0;
    while (fgets(ligne, taille_ligne, f)) {
      if (i < 3) {
        if (i == 0) {
          if (strcmp("P3\n", ligne) != 0) {
            printf("Vous avez un mauvais format\n");
            fclose(f);
            return 0;
          }  
        } else if (i == 1) {
          char * sub_ligne = strtok(ligne, separators);
          z = 0;
          while (sub_ligne != NULL) {
              if (z == 0) {
                b->col = atoi(sub_ligne);
              } else {
                b->row = atoi(sub_ligne);
              }
              sub_ligne = strtok(NULL, separators);
              z++;
          }
        } else {
          b->max_color = atoi(ligne);
          b->pixels = malloc(b->row * sizeof(couleur_t *));
          for (int ii = 0; ii < b->row; ii++) {
            b->pixels[ii] = malloc(b->col * sizeof(couleur_t));
            for (int jj = 0; jj < b->col; jj++) {
              b->pixels[ii][jj].rouge = b->max_color;
              b->pixels[ii][jj].vert = b->max_color;
              b->pixels[ii][jj].bleu = b->max_color;
            }
          }
        }
      } else {
        char * sub_ligne = strtok(ligne, separators);
        while (sub_ligne != NULL) {
          if (z == 0) {
            b->pixels[col][row].rouge = atoi(sub_ligne);
          } else if (z == 1) {
            b->pixels[col][row].vert = atoi(sub_ligne);
          } else {
            b->pixels[col][row].bleu = atoi(sub_ligne);
            col++;
            z = -1;
            if (col == b->col) {
              col = 0;
              row++;
            }
          }
          sub_ligne = strtok(NULL, separators);
          z++;
        }
      }
      i++;
    }
    fclose(f);
    return 1;
  } 
  return 0;
}

bitmap_t * creer_bitmap(liste_figure_t * l, couleur_t c, int row, int col) {
  bitmap_t * resultat = malloc(sizeof(bitmap_t));
  resultat->detruire = detruire_bitmap;
  resultat->get_type = get_type_bitmap;
  resultat->row = row;
  resultat->col = col;
  resultat->max_color = fmax(c.rouge, fmax(c.vert, c.bleu));
  resultat->pixels =(couleur_t **) malloc(row*sizeof(couleur_t*));
  for (int i = 0; i < row; i++) {
    resultat->pixels[i] = (couleur_t *) malloc(col * sizeof(couleur_t));
    for (int j = 0; j < resultat->col; j++) {
      resultat->pixels[i][j].rouge = c.rouge;
      resultat->pixels[i][j].vert = c.vert;
      resultat->pixels[i][j].bleu = c.bleu;
    }
  }
  maillon_figure_t * tmp = l->premier;
  while (tmp != NULL) {
    char type [50];
    strcpy(type, tmp->figure->get_type());
    int liste [150] = {0};
    int taille;
    tmp->figure->coordonne(tmp->figure, liste);
    if (liste[0] < row && liste[1] < col) {  
      if (strcmp(type, TYPE_POINTE) == 0) {
        resultat->pixels[liste[1]][liste[0]].rouge = liste[2];
        resultat->pixels[liste[1]][liste[0]].vert = liste[3];
        resultat->pixels[liste[1]][liste[0]].bleu = liste[4];
      } else if (strcmp(type, TYPE_TRIANGLE) == 0) {
        coordonne_t * seg1 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg1, liste[0], liste[1], liste[2], liste[3]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg1[ii].x < row && seg1[ii].y < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[6];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[7];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[8];
          }
        }
        free(seg1);
        coordonne_t * seg2 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg2, liste[0], liste[1], liste[4], liste[5]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg2[ii].x < row && seg2[ii].y < col) {
            resultat->pixels[seg2[ii].y][seg2[ii].x].rouge = liste[6];
            resultat->pixels[seg2[ii].y][seg2[ii].x].vert = liste[7];
            resultat->pixels[seg2[ii].y][seg2[ii].x].bleu = liste[8];
          }
        }
        free(seg2);
        coordonne_t * seg3 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg3, liste[2], liste[3], liste[4], liste[5]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg3[ii].x < row && seg3[ii].y < col) {
            resultat->pixels[seg3[ii].y][seg3[ii].x].rouge = liste[6];
            resultat->pixels[seg3[ii].y][seg3[ii].x].vert = liste[8];
            resultat->pixels[seg3[ii].y][seg3[ii].x].bleu = liste[9];
          }
        }
       free(seg3);
      } else if (strcmp(type, TYPE_CERCLE) == 0) {
        coordonne_t * pts =  malloc(3000 * sizeof(coordonne_t));
        taille = get_cercles(pts, liste[0], liste[1], liste[2]);
        for (int ii = 0; ii < taille; ii++) {
          if (pts[ii].y < row && pts[ii].x < col) {
            resultat->pixels[pts[ii].y][pts[ii].x].rouge = liste[3];
            resultat->pixels[pts[ii].y][pts[ii].x].vert = liste[4];
            resultat->pixels[pts[ii].y][pts[ii].x].bleu = liste[5];
          }
        }
        free(pts);
      } else if (strcmp(type, TYPE_SEGMENT) == 0) {
        coordonne_t * seg =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg, liste[0], liste[1], liste[2], liste[3]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg[ii].y < row && seg[ii].x < col) {
            resultat->pixels[seg[ii].y][seg[ii].x].rouge = liste[4];
            resultat->pixels[seg[ii].y][seg[ii].x].vert = liste[5];
            resultat->pixels[seg[ii].y][seg[ii].x].bleu = liste[6];
          }
        }
       free(seg);
      } else if (strcmp(type, TYPE_RECTANGLE) == 0) {
        coordonne_t * seg1 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg1, liste[0], liste[1], liste[2], liste[1]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg1[ii].y < row && seg1[ii].x < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[4];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[5];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[6];
          }
        }
       free(seg1);
        coordonne_t * seg2 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg2, liste[0], liste[1], liste[0], liste[3]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg2[ii].y < row && seg2[ii].x < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[4];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[5];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[6];
          }
        }
       free(seg2);
        coordonne_t * seg3 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg3, liste[2], liste[1], liste[2], liste[3]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg3[ii].y < row && seg3[ii].x < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[8];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[9];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[10];
          }
        }
       free(seg3);
        coordonne_t * seg4 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg4, liste[0], liste[3], liste[2], liste[3]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg4[ii].y < row && seg4[ii].x < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[8];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[9];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[10];
          }
        }
       free(seg4);
      } else if (strcmp(type, TYPE_POLYGONE) == 0) {
        int j = 0;
        for (size_t i = 0; i < liste[0]-1; i++) {
          coordonne_t * seg =  malloc(1450 * sizeof(coordonne_t));
          taille = get_points(seg, liste[j+1], liste[j+2], liste[j+6], liste[j+7]);
          for (int ii = 0; ii < taille; ii++) {
            if (seg[ii].y < row && seg[ii].x < col) {
              resultat->pixels[seg[ii].y][seg[ii].x].rouge = liste[3];
              resultat->pixels[seg[ii].y][seg[ii].x].vert = liste[4];
              resultat->pixels[seg[ii].y][seg[ii].x].bleu = liste[5];
            }
          }
         free(seg);
          j += 5;
        }
        j -= 5;
        coordonne_t * seg1 =  malloc(1450 * sizeof(coordonne_t));
        taille = get_points(seg1, liste[1], liste[2], liste[j+6], liste[j+7]);
        for (int ii = 0; ii < taille; ii++) {
          if (seg1[ii].y < row && seg1[ii].x < col) {
            resultat->pixels[seg1[ii].y][seg1[ii].x].rouge = liste[3];
            resultat->pixels[seg1[ii].y][seg1[ii].x].vert = liste[4];
            resultat->pixels[seg1[ii].y][seg1[ii].x].bleu = liste[5];
          }
        }
       free(seg1);
      }
    }
    tmp = tmp->suivant;
  }
  resultat->afficher = afficher_bitmap;
  return resultat;
}

void detruire_bitmap(void * bitmap){
  bitmap_t * b = bitmap;
  for (int i = 0; i < b->row; i++) {
    free(b->pixels[i]);
  }
  free(b->pixels);
  free(b);
}

void afficher_bitmap(SDL_Renderer * rendu, void * bitmap) {
  bitmap_t * b = bitmap;
  for (int i = 0; i < b->row; i++) {
    for (int j = 0; j < b->col; j++) {
      SDL_SetRenderDrawColor(rendu, b->pixels[i][j].rouge, b->pixels[i][j].vert, b->pixels[i][j].bleu, 255);
      SDL_RenderDrawPoint(rendu, i, j);
    }
  }
}

char * get_type_bitmap() {
  return "bitmap";
}

int get_points(coordonne_t * points, int y1, int x1, int y2, int x2) {
	int x, y, Dx, Dy, xincr, yincr, erreur, i, taille;
	xincr = 0;
	yincr = 0;
  taille = 0;
	Dx = abs(x2-x1);
  Dy = abs(y2-y1);
	if (x1 < x2)
		xincr = 1;
	else if (x1 > x2)
		xincr = -1;
	if (y1 < y2)
		yincr = 1;
	else if (y1 > y2)
		yincr = -1;
	x = x1;
  y = y1;
  if(Dx>Dy) {
    erreur = Dx/2;
    for(i=0;i<Dx;i++) {
      x += xincr;
      erreur += Dy;
      if(erreur>Dx) {
        erreur -= Dx;
        y += yincr;
      }
      points[taille].x = x;
      points[taille].y = y;
      taille++;
    }
  } else {
    erreur = Dy/2;
    for(i=0;i<Dy;i++) {
      y += yincr;
      erreur += Dx;
      if(erreur>Dy) {
        erreur -= Dy;
        x += xincr;
      }
      points[taille].x = x;
      points[taille].y = y;
      taille++;
    }
  }
  points[taille].x = x1;
  points[taille].y = y1;
  taille++;
  points[taille].x = x2;
  points[taille].y = y2;
  return ++taille;
}

int get_cercles(coordonne_t * points, int centre_y, int centre_x, int rayon) {
	int x, y, m, taille;
	x = 0;
	y = rayon;
	m = 5 - (4 * rayon);
	taille = 0;
	while( x <= y){
    points[taille].x = x + centre_x;
    points[taille].y = y + centre_y;
    taille++;
    points[taille].x = y + centre_x;
    points[taille].y = x + centre_y;
    taille++;
    points[taille].x = -x + centre_x;
    points[taille].y = y + centre_y;
    taille++;
    points[taille].x = -y + centre_x;
    points[taille].y = x + centre_y;
    taille++;
    points[taille].x = x + centre_x;
    points[taille].y = -y + centre_y;
    taille++;
    points[taille].x = y + centre_x;
    points[taille].y = -x + centre_y;
    taille++;
    points[taille].x = -x + centre_x;
    points[taille].y = -y + centre_y;
    taille++;
    points[taille].x = -y + centre_x;
    points[taille].y = -x + centre_y;
    taille++;
		if( m > 0 ){
			y-=1;
			m-=8*y;
		}
		x+=1;
		m+=((8*x)+4);
	}
  return taille;
}
