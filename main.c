#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

int main() {
  struct Film films[MAX_FILMS];
  int nbFilms = 0;
  int choix;

  do {
    printf("----- Menu -----\n");
    printf("1. Ajouter un film\n");
    printf("2. Afficher tous les films\n");
    printf("3. Sauvegarder les films\n");
    printf("4. Quitter\n");
    printf("Faites votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      ajouterFilm(films,nbFilms);
      break;

    case 2:
      printf("----- Liste des films -----\n");
      afficherFilms(films);
      break;

    case 3:
      printf("Sauvegarde des films...\n");
      sauvegarderFilms(films);
      printf("Les films ont été sauvegardés dans le fichier 'films.csv'.\n");
      break;

    case 4:
      printf("Au revoir !\n");
      break;

    default:
      printf("Choix invalide. Veuillez réessayer.\n");
      break;
    }

    printf("\n");
  } while (choix != 4);

  return 0;
}

