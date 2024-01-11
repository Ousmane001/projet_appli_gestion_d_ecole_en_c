#include "niveau.h"

/*------------------------------------------------------------------------------------*/
type_niveau* creer_et_saisir_info_niveau(void){
  type_niveau* niveau = (type_niveau*)malloc(sizeof(type_niveau));

  niveau->niveau_d_etude = saisir_entier("saisissez le niveau d'etude : exemple 1 pour 1ere annee : ");
  niveau->liste_promo = NULL;
  niveau->nb_promo = PROMO_VIDE;

  return niveau;
}
/*------------------------------------------------------------------------------------*/
void afficher_info_niveau(type_niveau* niveau){

  maillon_promo* courant = NULL;
  if(niveau == NULL){
    printf("niveau inexistant\n");
    return;
  }
  
  printf("\n\n -----------------%dem annee -----------------\n\n",niveau->niveau_d_etude);
  printf("Nombre total de promo : %d\n\n",niveau->nb_promo);

  if(niveau->nb_promo != PROMO_VIDE){
    courant = (maillon_promo*)malloc(sizeof(maillon_promo));
    courant = niveau->liste_promo;
    while(courant != NULL){
      printf("----------------------------------------------------------------\n\n");
      afficher_les_infos_de_la_promo(courant->promo_x);
      courant = courant->promo_suivant;
    }
    printf("\n\n--------------------------------------------------------------\n\n");
  }
  else{
    printf("Aucune promo en %d iem annee\n",niveau->niveau_d_etude);
  }
  return;
}
/*------------------------------------------------------------------------------------*/
void ajouter_une_promo(type_niveau* niveau, type_promo* nouvelle_promo){
  maillon_promo* nouveau_maillon;
  
  if((niveau == NULL) || (nouvelle_promo == NULL)) {
    printf("niveau inexistant dans ajouter_une_promo\n");
    return;
  }
  else{
    nouveau_maillon = (maillon_promo*)malloc(sizeof(maillon_promo));
    nouveau_maillon->promo_x = nouvelle_promo;
    saisir_notation_promo(nouvelle_promo);
    niveau->nb_promo++; 
    
    if(niveau->nb_promo == 0){
      niveau->liste_promo = nouveau_maillon;
      nouveau_maillon->promo_suivant = NULL;
    }
    else{
      nouveau_maillon->promo_suivant = niveau->liste_promo;
      niveau->liste_promo = nouveau_maillon;
    }
    return;
  }
  
}
/*------------------------------------------------------------------------------------*/
maillon_promo* rechercher_promo(type_niveau* niveau, char* intitule_promo){
  maillon_promo* courant = NULL;
  
  if((niveau == NULL) || (intitule_promo == NULL)){
    printf("niveau inexistant ou erreur intitule_promo dans rechercher_promo\n");
    return NULL;
  }
  else{
    
    courant = (maillon_promo*)malloc(sizeof(maillon_promo));
    courant = niveau->liste_promo;
    while(courant != NULL){
      
      if(strcmp(courant->promo_x->intitule_de_promo,intitule_promo) == PROMO_TROUVEE){
        printf("promo '%s' trouvee ! \n",intitule_promo);
        return courant;
      }
      courant = courant->promo_suivant;
    }
    printf("nous n'avons pas trouve la promo '%s'\n",intitule_promo);
    return NULL;
  }
}
/*------------------------------------------------------------------------------------*/
void supprimer_une_promo(type_niveau* niveau, maillon_promo* promo_a_supprimer){
  maillon_promo* courant = NULL;

  if(niveau == NULL){
    printf("niveau inexistant \n");
    return;
  }
  else if(promo_a_supprimer == NULL){
    printf("promo inexistant \n");
    return;
  }
  else{
    
    niveau->nb_promo--;
    courant = (maillon_promo*)malloc(sizeof(maillon_promo));
    courant = niveau->liste_promo;

    if(courant == promo_a_supprimer){
      niveau->liste_promo = courant->promo_suivant;
    }
    else{
      while(courant->promo_suivant != promo_a_supprimer){
        courant = courant->promo_suivant;
      }
      courant->promo_suivant = promo_a_supprimer->promo_suivant;
      free(promo_a_supprimer);
    }
    return;
  }
}
/*------------------------------------------------------------------------------------*/