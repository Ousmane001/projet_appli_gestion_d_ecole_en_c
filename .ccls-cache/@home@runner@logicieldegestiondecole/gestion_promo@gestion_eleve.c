#include "gestion_eleve.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
/*------------------------------------------------------------------------*/
eleve* definir_un_eleve(void){
  return (eleve*)malloc(sizeof(eleve));
}

void saisir_info_eleve(eleve* eleve_x) {
  eleve_x->nom = saisir_chaine("Entrez le nom de l'élève: ");
  eleve_x->prenom = saisir_chaine("Entrez le prénom de l'élève: ");
  eleve_x->email = saisir_chaine("Entrez l'email de l'élève: ");
  eleve_x->age = saisir_entier("Entrez l'âge de l'élève: ");
  eleve_x->num_telephone = saisir_entier("Entrez le numéro de téléphone de l'élève: ");
}