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
int acceder_a_repetoire(char* repertoire){
  char nom_concatenee[TAILLE_MAX];

  snprintf(nom_concatenee,TAILLE_MAX,"cd %s",repertoire);
  return system(nom_concatenee);
}
/*-----------------------------------------------------------------------------------------*/
int sauvergarder_donnees(type_ecole* ecole){
  FILE* fichier_ecole = NULL;
  char chaine_concatenation[TAILLE_MAX] = "";
  int compteur_niveau = 0,compeur_promo,compteur_matiere,compteur_date,compteur_eleve;
  char num_niveau[TAILLE_CONCAT] = "";
  maillon_niveau* niveau_x = (maillon_niveau*) malloc(sizeof(maillon_niveau));
  maillon_promo* promo_X = (maillon_promo*)malloc(sizeof(maillon_promo));
  maillon_eleve* eleve_x = (maillon_eleve*)malloc(sizeof(maillon_eleve));

  // creation d'un nouveau repertoire de base_de_donnee portant le nom de l'ecole :
  mkdir(ecole->nom_ecole);
  strcat(chaine_concatenation,ecole->nom_ecole);
  strcat(chaine_concatenation,nom_fichier_ecole);
  // sauvegarde des infos de l'ecole
  fichier_ecole = fopen(chaine_concatenation,"w");
    fprintf(fichier_ecole,"%s \n%d %d %d \n%d %d %d \n%d \n",ecole->nom_ecole,ecole->debut_cours->jour,ecole->debut_cours->mois,ecole->debut_cours->annee,ecole->fin_cours->jour,ecole->fin_cours->mois,ecole->fin_cours->annee,ecole->nb_niveaux);
    niveau_x = ecole->liste_niveaux;
    for(compteur_niveau = ECOLE_VIDE; compteur_niveau < ecole->nb_niveaux; compteur_niveau++){
      fprintf(fichier_ecole,"%d ",niveau_x->niveau_x->niveau_d_etude);
      niveau_x = niveau_x->niveau_suivant;
    }

    
  fclose(fichier_ecole);
  // on accede au dossier portant le nom de notre ecole : 
  chdir(ecole->nom_ecole);
  // sauvegarde des infos des niveau :
  niveau_x = ecole->liste_niveaux;
  for(compteur_niveau = ECOLE_VIDE; compteur_niveau < ecole->nb_niveaux; compteur_niveau++){

    // on remet a 0 notre chaine de concatenation :
    memset(chaine_concatenation,CHAINE_VIDE,sizeof(chaine_concatenation));
    strcat(chaine_concatenation,niveau_concat);
    // on ajoute le numero du niveau correspondant :
    sprintf(num_niveau,"%d",niveau_x->niveau_x->niveau_d_etude);
    strcat(chaine_concatenation,num_niveau);
    printf("\t%s\n",chaine_concatenation);
    mkdir(chaine_concatenation);

    // on accede au dossier qu'on vient de creer :
    chdir(chaine_concatenation);

    // on cree un fichier contenant les infos du niveau :
    fichier_ecole = fopen(NOM_DOC_NIVEAU,"w");
      fprintf(fichier_ecole,"%d %d\n",niveau_x->niveau_x->nb_promo,niveau_x->niveau_x->niveau_d_etude);
      promo_X = niveau_x->niveau_x->liste_promo;
      for(compeur_promo = PROMO_VIDE; compeur_promo < niveau_x->niveau_x->nb_promo; compeur_promo++){
        fprintf(fichier_ecole,"%s ",promo_X->promo_x->intitule_de_promo);
        promo_X = promo_X->promo_suivant;
      }
    fclose(fichier_ecole);

    // on cree un dossier pour chaque promo :
    promo_X = niveau_x->niveau_x->liste_promo;
    for(compeur_promo = PROMO_VIDE; compeur_promo < niveau_x->niveau_x->nb_promo; compeur_promo++){
      mkdir(promo_X->promo_x->intitule_de_promo);

      // on accede au dossier promo qu'on vient de creer :
        chdir(promo_X->promo_x->intitule_de_promo);

        fichier_ecole = fopen(NOM_DOC_PROMO,"w");
        fprintf(fichier_ecole,"%d %d %d\n",promo_X->promo_x->nombre_d_etudiants,promo_X->promo_x->nb_matiere,promo_X->promo_x->nb_note_pour_chaque_matiere);

        for(compteur_matiere = AUCUNE; compteur_matiere < promo_X->promo_x->nb_matiere; compteur_matiere++){
          fprintf(fichier_ecole,"%s %d %d\n",promo_X->promo_x->intitule_des_matieres[compteur_matiere],promo_X->promo_x->coefficients[compteur_matiere],promo_X->promo_x->nb_eval_passee[compteur_matiere]);
          
          /*for(compteur_date = AUCUNE; compteur_date < promo_X->promo_x->nb_eval_passee[compteur_matiere]; compteur_date++){
            fprintf(fichier_ecole,"")
          }*/

        }
        
        fclose(fichier_ecole);
        // on stocke les infos de tous les eleves dans un fichier:
        eleve_x = promo_X->promo_x->liste_des_eleves;
        fichier_ecole = fopen(NOM_DOC_ELEVES,"w");
          for(compteur_eleve = PROMO_VIDE; compteur_eleve < promo_X->promo_x->nombre_d_etudiants; compteur_eleve++){
            fprintf(fichier_ecole,"%s %s %s ",eleve_x->eleve_x->nom,eleve_x->eleve_x->prenom,eleve_x->eleve_x->email);
            fprintf(fichier_ecole,"%d %d ",eleve_x->eleve_x->age,eleve_x->eleve_x->num_telephone);
            fprintf(fichier_ecole,"%s %s\n",eleve_x->eleve_x->matricule,eleve_x->eleve_x->email_scolaire);
            eleve_x = eleve_x->eleve_suivant;
          }
    
        fclose(fichier_ecole);
        // on sort du dossier promo :
        chdir("..");

      promo_X = promo_X->promo_suivant;
    }
    // on sort du dossier :
    chdir("..");
    niveau_x = niveau_x->niveau_suivant;

  }

  // on sort du dossier portant le nom de notre ecole :
  chdir("..");
  free(niveau_x);
  free(promo_X);
  free(eleve_x);


  return SAUVEGARDER;

}