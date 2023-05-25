#include "film.h"
#include <stdio.h>

// Fonction pour sauvegarder un film dans un fichier
void sauvegarderFilm(struct Film film, FILE *fichier) {
  fprintf(fichier, "%s;%d;%s;%s\n", film.titre, film.annee, film.realisateur,
          film.genre);
}

// Sauvegarde tous les films non vides dans un fichier CSV
void sauvegarderFilms(struct Film *films) {
  FILE *fichier = fopen("films.csv", "w");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }

  int i = 0;
  while (films[i].annee != -1) {
    sauvegarderFilm(films[i], fichier);
    i++;
  }

  fclose(fichier);
}

// Fonction pour afficher les films dans un tableau de films
void afficherFilms(struct Film *films) {
  int i = 0;
  while (films[i].annee != -1) {
    printf("Film %d :\n", i + 1);
    printf("Titre : %s\n", films[i].titre);
    printf("Année : %d\n", films[i].annee);
    printf("Réalisateur : %s\n", films[i].realisateur);
    printf("Genre : %s\n\n", films[i].genre);
    i++;
  }
}

// Fonction pour ajouter un film au tableau de films
void ajouterFilm(struct Film *films, int nbFilms) {
  if (nbFilms >= MAX_FILMS) {
    printf("Le tableau de films est plein.\n");
    return;
  }

  struct Film nouveauFilm;

  printf("----- Ajout d'un film -----\n");
  printf("Titre : ");
  scanf(" %[^\n]", nouveauFilm.titre);
  printf("Année : ");
  scanf("%d", &nouveauFilm.annee);
  printf("Réalisateur : ");
  scanf(" %[^\n]", nouveauFilm.realisateur);
  printf("Genre : ");
  scanf(" %[^\n]", nouveauFilm.genre);

  films[nbFilms] = nouveauFilm;
  nbFilms++; // Ajoute le film à la fin du tableau en incrémentant le nombre de films

  printf("Le film a été ajouté avec succès.\n");
}
