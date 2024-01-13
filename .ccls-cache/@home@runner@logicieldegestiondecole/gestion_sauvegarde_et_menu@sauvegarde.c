#include "sauvegarde.h"




/*-----------------------------------------------------------------------*/
void afficher_menu_principale(type_ecole* ecole){

  if(ecole == NULL){
    printf("Impossible d'afficher le menu principal car l'ecole n'est pas initialisee\n");
  }
  else{
    system("clear");
    printf("*************************** %s ***************************\n\n",ecole->nom_ecole);
    printf("1- Afficher le menu de gestion de %s\n",ecole->nom_ecole);
    printf("2- Afficher le menu de gestion des niveaux d'etude de %s\n",ecole->nom_ecole);
    printf("3- Afficher le menu de gestion des promos de %s\n\n",ecole->nom_ecole);
    printf("0- Sauvegarder & Fermer le logiciel !\n");
  }
  return;
}
/*-------------------------------------------------------------------------*/
void afficher_menu_sauvegarde(type_ecole* ecole);
/*-------------------------------------------------------------------------*/
void afficher_menu_gestion_ecole(type_ecole* ecole){
  if(ecole == NULL){
    printf("Impossible d'afficher le menu principal car l'ecole n'est pas initialisee\n");
  }
  else{
    system("clear");
    printf("*************************** %s ***************************\n\n",ecole->nom_ecole);
    printf("0- Retour au menu principal\n");
    printf("1- Afficher les informations de %s\n",ecole->nom_ecole);
    printf("2- Ajouter un niveau d'etude a %s\n",ecole->nom_ecole);
    printf("3- Rechercher un niveau d'etude dans %s\n",ecole->nom_ecole);
    printf("4- Supprimer un niveau d'etude de %s\n",ecole->nom_ecole);
  }
}
/*-----------------------------------------------------------------------------------------*/
void afficher_menu_gestion_niveau(type_ecole* ecole){
  if(ecole == NULL){
    printf("Impossible d'afficher le menu principal car l'ecole n'est pas initialisee\n");
  }
  else{
    system("clear");
    printf("*************************** %s ***************************\n\n",ecole->nom_ecole);
    printf("0- Retour au menu principal\n");
    printf("1- Afficher les informations d'un niveau d'etude \n");
    printf("2- Ajouter une promotion  dans un niveau \n");
    printf("3- Rechercher une promotion \n");
    printf("4- Supprimer une promo dans un niveau d'etude\n");
  }
}
/*-----------------------------------------------------------------------------------------*/
void afficher_menu_gestion_promo(type_ecole* ecole){
  if(ecole == NULL){
    printf("Impossible d'afficher le menu principal car l'ecole n'est pas initialisee\n");
  }
  else{
    
    printf("0- Retour au menu principal\n");
    printf("1- Afficher les informations d'une promo \n");
    printf("2- Inscrire un etudiant ou eleve \n");
    printf("3- Rechercher un eleve dans une promo \n");
    printf("4- Virer un etudiant d'une promo\n");
    printf("5- Afficher les informations d'un etudiant ou eleve \n");
    printf("6- Reporter des notes d'une evalution pour toute une promo\n");
    printf("7- Afficher les notes d'une promo dans un matiere\n");
  }
}
/*-----------------------------------------------------------------------------------------*/