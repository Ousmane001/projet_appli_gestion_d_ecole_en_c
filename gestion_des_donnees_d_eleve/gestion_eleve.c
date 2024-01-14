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
  eleve_x->nom = saisir_chaine("Entrez le nom de l'eleve : ");
  eleve_x->prenom = saisir_chaine("saisissez son prenom : ");
  eleve_x->email = saisir_chaine("Entrez l'email personnel de l'eleve : ");
  eleve_x->age = saisir_entier("Entrez son age : ");
  eleve_x->num_telephone = saisir_entier("Entrez le numero de telephone de l'eleve : ");
}

/*------------------------------------------------------------------------*/
void afficher_un_eleve(eleve* eleve_x){
  printf("\n\n------------------------------------------\n");
  printf("Nom : %s\n", eleve_x->nom);
  printf("Prenom : %s\n", eleve_x->prenom);
  printf("Email perso : %s\n", eleve_x->email);
  printf("Age : %d\n", (int)eleve_x->age);
  printf("Numero de telephone : %d\n", (int)eleve_x->num_telephone);
  printf("Email scolaire : %s\n", eleve_x->email_scolaire);
  printf("Numero matricule : %s\n", eleve_x->matricule);
  printf("------------------------------------------\n");
}

/*------------------------------------------------------------------------*/

void supprimer_info_eleve(eleve* eleve_x){
  // attention il faut supprimer les notes de l'eleve avant : car sinon il y aura des erreurs  de segmentation !
  /*free((eleve_x)->email);
  free((eleve_x)->nom);
  free((eleve_x)->prenom);
  free((eleve_x)->matricule);
  free((eleve_x)->email_scolaire);*/
  free((eleve_x));
  printf("eleve supprimee avec succes\n");
}

/*------------------------------------------------------------------------*/