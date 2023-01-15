CFLAGS = -ggdb3 -O0 --std=c99 -Wall -lm `sdl2-config --libs --cflags` -lSDL2_image 

FIGURES = src/figures/point.o src/figures/segment.o src/figures/triangle.o src/figures/rectangle.o src/figures/cercle.o src/figures/polygone.o
 
all: main.o src/liste_figure.o src/couleur.o src/gestion_evenement.o src/dessin.o src/fichiers_images.o $(FIGURES)
	gcc main.o src/liste_figure.o src/couleur.o src/gestion_evenement.o src/dessin.o src/fichiers_images.o $(FIGURES) -o projet $(CFLAGS)

test_couleur: tests/test_couleur.o src/couleur.o
	gcc tests/test_couleur.o src/couleur.o -o tests/test_couleur
	./tests/test_couleur
	rm tests/test_couleur

test_point: tests/test_point.o src/figures/point.o src/couleur.o
	gcc tests/test_point.o src/figures/point.o src/couleur.o -o tests/test_point $(CFLAGS)
	./tests/test_point
	rm tests/test_point

test_liste_figure: tests/test_liste_figure.o src/liste_figure.o src/figures/point.o src/couleur.o
	gcc tests/test_liste_figure.o src/liste_figure.o src/figures/point.o src/couleur.o -o tests/test_liste_figure $(CFLAGS)
	./tests/test_liste_figure
	rm tests/test_liste_figure

test_segment: tests/test_segment.o src/figures/segment.o src/dessin.o src/figures/point.o src/couleur.o
	gcc tests/test_segment.o src/figures/segment.o src/dessin.o src/figures/point.o src/couleur.o -o tests/test_segment $(CFLAGS)
	./tests/test_segment
	rm tests/test_segment

test_triangle: tests/test_triangle.o src/figures/triangle.o src/dessin.o src/figures/point.o src/couleur.o
	gcc tests/test_triangle.o src/figures/triangle.o src/dessin.o src/figures/point.o src/couleur.o -o tests/test_triangle $(CFLAGS)
	./tests/test_triangle
	rm tests/test_triangle

test_rectangle: tests/test_rectangle.o src/figures/rectangle.o src/dessin.o src/figures/point.o src/couleur.o
	gcc tests/test_rectangle.o src/figures/rectangle.o src/dessin.o src/figures/point.o src/couleur.o -o tests/test_rectangle $(CFLAGS)
	./tests/test_rectangle
	rm tests/test_rectangle

test_polygone: tests/test_polygone.o src/figures/polygone.o src/dessin.o src/figures/point.o src/couleur.o
	gcc tests/test_polygone.o src/figures/polygone.o src/dessin.o src/figures/point.o src/couleur.o -o tests/test_polygone $(CFLAGS)
	./tests/test_polygone
	rm tests/test_polygone

test_cercle: tests/test_cercle.o src/figures/cercle.o src/dessin.o src/figures/point.o src/couleur.o
	gcc tests/test_cercle.o src/figures/cercle.o src/dessin.o src/figures/point.o src/couleur.o -o tests/test_cercle $(CFLAGS)
	./tests/test_cercle
	rm tests/test_cercle

test_fichiers_images: tests/test_fichiers_images.o src/liste_figure.o src/dessin.o src/fichiers_images.o  $(FIGURES)  src/couleur.o
	gcc tests/test_fichiers_images.o src/liste_figure.o src/dessin.o src/fichiers_images.o $(FIGURES) src/couleur.o -o tests/test_fichiers_images $(CFLAGS)
	./tests/test_fichiers_images
	rm tests/test_fichiers_images
	rm tests/fichier_liste_save.txt
	rm testimage.ppm


test: test_couleur test_point test_liste_figure test_segment test_triangle test_rectangle test_polygone test_cercle test_fichiers_images
