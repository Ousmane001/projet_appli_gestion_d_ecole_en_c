#include "gestion_promo.h"

/*-----------------------------------------------------------------------------------------------------*/
type_promo* creat_intituler_promo(void){
  return (type_promo*)malloc(sizeof(type_promo));
}
/*-----------------------------------------------------------------------------------------------------*/
void saisir_intituler_promo(type_promo* promo){
  promo->intitule_de_promo = saisir_chaine("saisir l'intituler de la promo (ex: CPI2 ou MT3 ...): ");
}
/*-----------------------------------------------------------------------------------------------------*/
void initialiser_nb_etudiant_promo(type_promo* promo){
  promo->nombre_d_etudiants = AUCUN_ETUDIANT_INSCRIT;
}
/*-----------------------------------------------------------------------------------------------------*/
maillon_eleve* creer_maillon_eleve(type_promo* promo, char *nom_de_l_ecole){
  maillon_eleve* nouveau_maillon = (maillon_eleve*)malloc(sizeof(maillon_eleve));

  // saisie des informations de l'etudiant contenue dans le maillon :
  nouveau_maillon->eleve_x = definir_un_eleve();
  nouveau_maillon->eleve_suivant = NULL;
  saisir_info_eleve(nouveau_maillon->eleve_x);

  // informations  complementaires ajoutees automatiquement:
  ajout_automatique_du_matricule_eleve(nouveau_maillon->eleve_x, promo);
  creation_automatique_email_eleve(nouveau_maillon->eleve_x, promo, nom_de_l_ecole);

  return nouveau_maillon;
}
/*-----------------------------------------------------------------------------------------------------*/
void supprimer_un_maillon_eleve(maillon_eleve* maillon_eleve_a_supprimer){
  supprimer_note_eleve((maillon_eleve_a_supprimer->eleve_x->note));
  supprimer_info_eleve((maillon_eleve_a_supprimer->eleve_x));
  free(maillon_eleve_a_supprimer);
  printf("maillon supprimee avec sucees\n");
}
/*-----------------------------------------------------------------------------------------------------*/
void inscrire_un_etudiant(type_promo* promo, maillon_eleve* nouvel_eleve){
  maillon_eleve* temp_ptr = promo->liste_des_eleves;
  maillon_eleve* ptr_briseur = promo->liste_des_eleves;

    // on incremente avant tout le nombre d'etudiant de la promo 
    promo->nombre_d_etudiants++;
  
    // si la liste est vide : 
    if(promo->liste_des_eleves == NULL){
      //ajouter_contact_fin(liste_eleves);
      promo->liste_des_eleves = nouvel_eleve;
      nouvel_eleve->eleve_suivant = NULL;
    }else if (temp_ptr->eleve_suivant == NULL){
      // s'il n'y a qu'un seul contact enregistré
      if(temp_ptr == promo->liste_des_eleves){
        // si le nouveau contact est superieur par ordre alphabetique :
        if(strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0){
          promo->liste_des_eleves = nouvel_eleve;
          nouvel_eleve->eleve_suivant = temp_ptr;
        }
        else{
          // sinon on rajoute simplement le nouveau maillon a la fin de la chaine
          temp_ptr->eleve_suivant = nouvel_eleve;
          nouvel_eleve->eleve_suivant = NULL;
        }

      }
      else{
        // s'il ya au minimum 2 contacts déjà enregistré : 
        if(strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0){
          // brisememt de l'ancien lien :
          while(ptr_briseur->eleve_suivant->eleve_suivant != NULL){
            ptr_briseur = ptr_briseur->eleve_suivant;
          }
          ptr_briseur->eleve_suivant = nouvel_eleve;
          // insertion du nouveau maillon:
          nouvel_eleve->eleve_suivant = temp_ptr;
        }
      }

    }
    else{
      // on va parcourir maillon par maillon jusqu'à trouver un endroit ou s'inserer
      while(temp_ptr->eleve_suivant != NULL){
      if((temp_ptr == promo->liste_des_eleves) && (strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0)){
        // le premier maillon se decale au profit du nouveau 
        nouvel_eleve->eleve_suivant = promo->liste_des_eleves;
        promo->liste_des_eleves = nouvel_eleve;
        printf("l'inversion sest fais ici 0");
        return;
      }
      else if((strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0) && (strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_suivant->eleve_x->nom) <= 0)){
            // si le nouveau contact doit s'inserer entre le contact actuelle (temp_ptr) et le contact precedent temp_ptr, alors :  
            ptr_briseur->eleve_suivant = nouvel_eleve;
            nouvel_eleve->eleve_suivant = temp_ptr;
            printf("l'inversion sest fait ici 1\n\n");
            return;
          }
          //temp_ptr = temp_ptr->eleve_suivant;
        ptr_briseur = temp_ptr;
        temp_ptr = temp_ptr->eleve_suivant;
        }
      // si on a pas trouver un endroit ou s'inserer, on rattache le nouveau contact comme dernier contact.
        if((temp_ptr->eleve_suivant == NULL) && (strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) >= 0)){
          temp_ptr->eleve_suivant = nouvel_eleve;
          nouvel_eleve->eleve_suivant = NULL;
          printf("on a ratache a la queue\n");
          return;
        }
      else{
        //sinon on intervertie nouvel_eleve et le dernier
        ptr_briseur->eleve_suivant = nouvel_eleve;
        nouvel_eleve->eleve_suivant = temp_ptr;
      }
      }
    // forcement une des conditions précédentes a ete utilisé; donc le programme n'arrive jamais ici !
    return;
}
/*------------------------------------------------------------------------*/
void ajout_automatique_du_matricule_eleve(eleve* eleve_x, type_promo* promo_x){
  maillon_eleve* temp_ptr = promo_x->liste_des_eleves;

  if(promo_x->liste_des_eleves != NULL){
  while(temp_ptr->eleve_suivant != NULL){
    temp_ptr = temp_ptr->eleve_suivant;
  }
  }
  // temp_ptr pointe sur le maillon de l'eleve dont on veut attribuer un matricule:
  // je vais donc concatener les 4 premiers caractere comme matricule suivi de ...
  strncat(eleve_x->matricule, promo_x->intitule_de_promo,NB_MAX_CONCATENTION);
  snprintf(eleve_x->matricule + strlen(eleve_x->matricule), sizeof(eleve_x->matricule)-strlen(eleve_x->matricule), "%05d", promo_x->nombre_d_etudiants);
}
  

/*-----------------------------------------------------------------------------------------------------*/
void creation_automatique_email_eleve(eleve* eleve_x, type_promo* promo_x, char* nom_de_l_ecole){
  // copier d'une partie du prénom et de la totalité du nom dans l'email scolaire
  strncat(eleve_x->email_scolaire, eleve_x->prenom, 1);
  strcat(eleve_x->email_scolaire, ".");
  //eleve_x->email_scolaire[strlen(eleve_x->email_scolaire)] = '.';
  strcat(eleve_x->email_scolaire, eleve_x->nom);
  // concatener le nom de l'ecole
  strcat(eleve_x->email_scolaire, "@");
  strcat(eleve_x->email_scolaire, nom_de_l_ecole);
  // concatener le nom de la promo
  strcat(eleve_x->email_scolaire, ".");
  strcat(eleve_x->email_scolaire, promo_x->intitule_de_promo);
  //ajouter le .fr a la fin de l'email:
  strcat(eleve_x->email_scolaire, ".fr");
  return;
}
/*-----------------------------------------------------------------------------------------------------*/

eleve* rechercher_un_etudiant(maillon_eleve** liste_eleves, char* info_eleve){
  maillon_eleve* temp_ptr = *liste_eleves;

  if((*liste_eleves == NULL) || (info_eleve == NULL)){
    printf("Erreur : argument de la fonction rechercher_un_etudiant est NULL");
    return NULL;
  }
  else{
    while(temp_ptr != NULL){
      if(strcmp(temp_ptr->eleve_x->matricule, info_eleve) == ELEVE_TROUVE){
        return  temp_ptr->eleve_x;
      }
      else if (strcmp(temp_ptr->eleve_x->nom, info_eleve) == ELEVE_TROUVE){
        return  temp_ptr->eleve_x;
      }
      else if (strcmp(temp_ptr->eleve_x->prenom, info_eleve) == ELEVE_TROUVE){
        return  temp_ptr->eleve_x;
      }
      else if (strcmp(temp_ptr->eleve_x->email_scolaire, info_eleve) == ELEVE_TROUVE){
        return  temp_ptr->eleve_x;
      }
      else if (strcmp(temp_ptr->eleve_x->email, info_eleve) == ELEVE_TROUVE){
        return  temp_ptr->eleve_x;
      }
      else{
        temp_ptr = temp_ptr->eleve_suivant;
      }
    }
    // si aucun eleve ne correspond a l'argument de la fonction, on retourne NULL
    return NULL;
  }
  
}

/*-----------------------------------------------------------------------------------------------------*/

void virer_un_etudiant(type_promo* promo, char* infos_eleve){
  maillon_eleve* temp_ptr = promo->liste_des_eleves;
  eleve* eleve_a_supprimer = rechercher_un_etudiant(&(promo->liste_des_eleves), infos_eleve);

  if((promo->liste_des_eleves == NULL) || (infos_eleve == NULL)){
    printf("Erreur : argument de la fonction virer_un_etudiant est NULL");
    return;
  }
  else if( eleve_a_supprimer == NULL){
    // si l'eleve n'est pas dans la liste :
    printf("Nous n'avons trouve aucun eleve correspondant a -> ' %s ' \n",infos_eleve);
  }
  else{
    // si l'eleve est dans la liste : on le supprime de la liste :
    promo->nombre_d_etudiants--;
    // si l'eleve est le premier de la liste :
    if(temp_ptr->eleve_x == eleve_a_supprimer){
      // si l'eleve est le seul de la liste :
      if(temp_ptr->eleve_suivant == NULL){
        supprimer_un_maillon_eleve(promo->liste_des_eleves);
        promo->liste_des_eleves = NULL;
        printf("vous avez supprimé le seul eleve de la liste\n");
        printf("promo vide ! \n");
        return;
      }
      else{
        // si l'eleve est le premier de la liste mais qu'il y a au moins un autre
        
        promo->liste_des_eleves = temp_ptr->eleve_suivant;
        supprimer_un_maillon_eleve(temp_ptr);
        printf("vous avez supprimé le premier eleve de la liste\n");
        return;
      }
      
    }
    else{
      // si l'eleve n'est pas le premier de la liste :
      // on parcourt la liste jusqu'au maillon precedent l'eleve a supprimer :
      while(temp_ptr->eleve_suivant->eleve_x != eleve_a_supprimer){
        temp_ptr = temp_ptr->eleve_suivant;
      }
      // on supprime le maillon de l'eleve a supprimer :
      // si l'eleve est le dernier de la liste :
      if(temp_ptr->eleve_suivant->eleve_suivant == NULL){
        supprimer_un_maillon_eleve(temp_ptr->eleve_suivant);
        temp_ptr->eleve_suivant = NULL;
        printf("dernier eleve de la liste supprimee\n");
        return;
      }
      else{
        // si l'eleve n'est pas le dernier de la liste :
        // ici on doit sauvegarder le maillon suivant l'eleve a supprimer :
        temp_ptr->eleve_suivant = temp_ptr->eleve_suivant->eleve_suivant;
        printf("l'eleve a ete supprime\n");
        return;
      }
    }
  }

  return;
}
//-------------------------------------------------------------------------------------------------------
void afficher_les_infos_de_la_promo(type_promo* promo){
  unsigned int compteur_eleve = 0;
  maillon_eleve* temp_ptr = promo->liste_des_eleves;
  
  printf("\n\n Informations concernant la promo : %s \n",promo->intitule_de_promo);
  printf("il ya %d eleves/etudiants en %s\n",promo->nombre_d_etudiants,promo->intitule_de_promo);

  
  for(compteur_eleve = 0; compteur_eleve < promo->nombre_d_etudiants; compteur_eleve++){
    afficher_un_eleve(temp_ptr->eleve_x);
    temp_ptr = temp_ptr->eleve_suivant;
  }
  return;
}