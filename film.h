#ifndef FILM_H
#define FILM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMS 10
#define MAX_TITRE 10
#define MAX_REALISATEUR 10
#define MAX_GENRE 10

struct Film {
  char titre[MAX_TITRE];
  int annee;
  char realisateur[MAX_REALISATEUR];
  char genre[MAX_GENRE];
};

// Prototypes des fonctions pour la gestion des films

// Sauvegarde un film dans un fichier
void sauvegarderFilm(struct Film film, FILE *fichier);

// Sauvegarde tous les films dans un fichier CSV
void sauvegarderFilms(struct Film *films);

// Affiche les détails d'un film
void afficherFilm(struct Film film);

// Affiche tous les films
void afficherFilms(struct Film *films);

// Ajouter un film par une interface interactive de manière textuel
void ajouterFilm(struct Film *films, int nbFilms);

#endif