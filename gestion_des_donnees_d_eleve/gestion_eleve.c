#include "gestion_eleve.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
/*------------------------------------------------------------------------*/
eleve* definir_un_eleve(void){
  return (eleve*)malloc(sizeof(eleve));
}
/*------------------------------------------------------------------------*/
void saisir_info_eleve(eleve* eleve_x) {
  eleve_x->nom = saisir_chaine("Entrez le nom de l'élève : ");
  eleve_x->prenom = saisir_chaine("saisissez son prénom : ");
  eleve_x->email = saisir_chaine("Entrez l'email de l'élève : ");
  eleve_x->age = saisir_entier("Entrez l'âge de l'élève : ");
  eleve_x->num_telephone = saisir_entier("Entrez le numéro de téléphone de l'élève : ");
}

/*------------------------------------------------------------------------*/
void afficher_un_eleve(eleve* eleve_x){
  printf("\n\n------------------------------------------\n");
  printf("Nom : %s\n", eleve_x->nom);
  printf("Prénom : %s\n", eleve_x->prenom);
  printf("Email : %s\n", eleve_x->email);
  printf("Âge : %d\n", eleve_x->age);
  printf("Numéro de téléphone : %d\n", eleve_x->num_telephone);
  printf("------------------------------------------\n");
}