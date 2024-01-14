#include "gestion_ecole.h"


/*-------------------------------------------------------------------------------------------*/
type_ecole* creer_saisir_info_ecole(void){
  type_ecole* ecole = (type_ecole*)malloc(sizeof(type_ecole));

  // saisie des infos de l'ecole :
  printf("**************** Bienvenue dans l'espace de creation de votre Ecole ****************\n\n");
  ecole->nom_ecole = saisir_chaine("Quelle est le nom de l'ecole : ");
  ecole->nb_niveaux = ECOLE_VIDE;
  ecole->debut_cours = creer_une_date();
  ecole->fin_cours = creer_une_date();
  ecole->liste_niveaux = NULL;
  printf("\n\nInformations concernants le debut des cours à %s : \n",ecole->nom_ecole);
  saisir_une_date(ecole->debut_cours);
  ecole->debut_cours->annee = saisir_entier("Pour finir, saisissez l'annee scolaire (ex: 2023) : ");
  printf("\n\nInformations concernants la fin prevu des cours à %s : \n",ecole->nom_ecole);
  saisir_une_date(ecole->fin_cours);
  ecole->fin_cours->annee = ecole->debut_cours->annee + ANNEE_SUIVANTE;
  return ecole;
}
/*-------------------------------------------------------------------------------------------*/
maillon_niveau* creer_maillon_niveau(type_niveau* niveau){
  maillon_niveau* nouveau = (maillon_niveau*)malloc(sizeof(maillon_niveau));
  nouveau->niveau_x = niveau;
  nouveau->niveau_suivant = NULL;
  return nouveau;
}
  /*-------------------------------------------------------------------------------------------*/
void afficher_info_ecole(type_ecole* ecole){
  maillon_niveau* courant = NULL;
  if(ecole == NULL){
    printf("erreur argument invalide dans afficher_info_ecole\n");
    return;
  }
  
  printf("\n\n\t\t\t Ecole %s :\n\n",ecole->nom_ecole);
  printf("Debut des cours : %d/%d/%d\n", ecole->debut_cours->jour, ecole->debut_cours->mois, ecole->debut_cours->annee);
  printf("Fin des cours : %d/%d/%d\n", ecole->fin_cours->jour, ecole->fin_cours->mois, ecole->fin_cours->annee);
  printf("%s compte %d niveaux : \n",ecole->nom_ecole,ecole->nb_niveaux);

  if(ecole->nb_niveaux){
    courant = (maillon_niveau*)malloc(sizeof(maillon_niveau));
    courant = ecole->liste_niveaux;

    printf("On a entre autre : \n");
    while(courant != NULL){
      printf("%d em annee\n",courant->niveau_x->niveau_d_etude);
      courant = courant->niveau_suivant;
    }
  }
  else{
    printf("l'Ecole est vide, elle n'a aucun niveau scolaire\n");
  }
  
    
}
/*-------------------------------------------------------------------------------------------*/
void ajouter_un_niveau_detude(type_ecole* ecole, maillon_niveau* nouveau_niveau){
  maillon_niveau* courant = NULL;
  if((ecole == NULL) || (nouveau_niveau == NULL)){
    printf("erreur argument invalide dans ajouter_un_niveau_detude\n");
    return;
  }
  else{

    ecole->nb_niveaux++;
    
    if(ecole->nb_niveaux == 0){
      ecole->liste_niveaux = nouveau_niveau;
    }
    else{
      nouveau_niveau->niveau_suivant = ecole->liste_niveaux;
      ecole->liste_niveaux = nouveau_niveau;
    }
    return;
  }
}
/*-------------------------------------------------------------------------------------------*/
maillon_niveau* rechercher_un_niveau(type_ecole* ecole, unsigned int niveau){
  maillon_niveau* courant = NULL;
  
  if((ecole == NULL) || (niveau == 0)){
    printf("erreur argument invalide dans rechercher_un_niveau\n");
    return NULL;
  }
  else{
    courant = (maillon_niveau*)malloc(sizeof(maillon_niveau));
    courant = ecole->liste_niveaux;
    while(courant != NULL){
      if(courant->niveau_x->niveau_d_etude == niveau){
        return courant;
      }
      courant = courant->niveau_suivant;
    }
    printf("le niveau scolaire -> %d n'existe pas à %s\n",niveau,ecole->nom_ecole);
    return NULL;
  }
}
/*-------------------------------------------------------------------------------------------*/
void supprimer_un_niveau_detude(type_ecole* ecole, maillon_niveau* niveau_a_supp){
  maillon_niveau* courant = NULL;

  if(ecole == NULL){
    printf("erreur argument invalide dans supprimer_un_niveau_detude\n");
    return;
  }
  else if(niveau_a_supp == NULL){
    printf("Nous ne pouvons pas supprimer ce niveau d'etude car il n'existe pas : \n\n");
  }
  else{
    courant = (maillon_niveau*)malloc(sizeof(maillon_niveau));
    courant = ecole->liste_niveaux;
    if(courant == niveau_a_supp){
      ecole->liste_niveaux = courant->niveau_suivant;
      free(niveau_a_supp);
      ecole->nb_niveaux--;
      return;
    }
    else{
      while(courant->niveau_suivant != NULL){
        if(courant->niveau_suivant == niveau_a_supp){
          courant->niveau_suivant = niveau_a_supp->niveau_suivant;
          free(niveau_a_supp);
          ecole->nb_niveaux--;
          return;
        }
        courant = courant->niveau_suivant;
      }
      printf("le niveau scolaire -> %d n'existe pas à %s\n",niveau_a_supp->niveau_x->niveau_d_etude,ecole->nom_ecole);
      return;
    }
  }
}