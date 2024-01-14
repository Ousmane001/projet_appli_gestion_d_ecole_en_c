#include "sauvegarde.h"


/*-----------------------------------------------------------------------*/
void attendre_utilisateur(void){
  // on vide d'abord le tampon stdin :
  fflush(stdin);
  printf("\n\n\nTapez un caractere quelconque pour continuer : ");
  getchar();
  return;
}
/*-----------------------------------------------------------------------*/
  int recup_choix_utilisateur(void){
    int choix;

    choix = saisir_entier("\n\n\n Faites votre choix en tapant le numero associe a votre requete : ");
    printf("\n\n\n");
    return choix;
  }
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
int creer_un_dossier(char* nom_dossier){
  char nom_concatenee[TAILLE_MAX];

  snprintf(nom_concatenee,TAILLE_MAX,"mkdir %s",nom_dossier);
  printf("%s \n",nom_concatenee);

  return system(nom_concatenee);
}
/*-----------------------------------------------------------------------------------------*/
int sauvergarder_donnees(type_ecole* ecole){
  FILE* fichier_ecole = NULL;
  char chaine_concatenation[TAILLE_MAX] = "";
  char compteur_niveau = 0;
  char num_niveau[TAILLE_CONCAT] = "";
  maillon_niveau* niveau_x = (maillon_niveau*) malloc(sizeof(maillon_niveau));

  // creation d'un nouveau repertoire de base_de_donnee:
  creer_un_dossier(ecole->nom_ecole);
  strcat(chaine_concatenation,ecole->nom_ecole);
  strcat(chaine_concatenation,nom_fichier_ecole);
  // sauvegarde des infos de l'ecole
  fichier_ecole = fopen(chaine_concatenation,"w");
    fprintf(fichier_ecole,"%s \n%d %d %d \n%d %d %d \n%d \n",ecole->nom_ecole,ecole->debut_cours->jour,ecole->debut_cours->mois,ecole->debut_cours->annee,ecole->fin_cours->jour,ecole->fin_cours->mois,ecole->fin_cours->annee,ecole->nb_niveaux);
    
  fclose(fichier_ecole);

  // sauvegarde des infos des niveau :
  niveau_x = ecole->liste_niveaux;
  for(compteur_niveau = ECOLE_VIDE; compteur_niveau < ecole->nb_niveaux; compteur_niveau++){
    // on remet a 0 notre chaine de concatenation :
    memset(chaine_concatenation,CHAINE_VIDE,sizeof(chaine_concatenation));
    // on concatene l'addresse du repertoire de sauvegarde :
    strcat(chaine_concatenation,ecole->nom_ecole);
    strcat(chaine_concatenation,niveau_concat);
    // on ajoute le numero du niveau correspondant :
    sprintf(num_niveau,"%d",niveau_x->niveau_x->niveau_d_etude);
    strcat(chaine_concatenation,num_niveau);printf("\n\t%s\n",chaine_concatenation);
    creer_un_dossier(chaine_concatenation);
    
    niveau_x = niveau_x->niveau_suivant;

  }

  return SAUVEGARDER;

}