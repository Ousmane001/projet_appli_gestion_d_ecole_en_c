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
maillon_eleve* creer_maillon_eleve(void){
  return (maillon_eleve*)malloc(sizeof(maillon_eleve));
}
/*-----------------------------------------------------------------------------------------------------*/
void inscrire_un_etudiant(type_promo* promo,maillon_eleve** liste_eleves, maillon_eleve* nouvel_eleve){
  maillon_eleve* temp_ptr = *liste_eleves;
  maillon_eleve* ptr_briseur = *liste_eleves;

    // on incremente avant tout le nombre d'etudiant de la promo 
    promo->nombre_d_etudiants++;
  
    // si la liste est vide : 
    if(*liste_eleves == NULL){
      //ajouter_contact_fin(liste_eleves);
      *liste_eleves = nouvel_eleve;
      nouvel_eleve->eleve_suivant = NULL;
    }else if (temp_ptr->eleve_suivant == NULL){
      // s'il n'y a qu'un seul contact enregistré
      if(temp_ptr == *liste_eleves){
        // si le nouveau contact est superieur par ordre alphabetique :
        if(strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0){
          *liste_eleves = nouvel_eleve;
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
      if((temp_ptr == *liste_eleves) && (strcmp(nouvel_eleve->eleve_x->nom, temp_ptr->eleve_x->nom) <= 0)){
        // le premier maillon se decale au profit du nouveau 
        nouvel_eleve->eleve_suivant = *liste_eleves;
        *liste_eleves = nouvel_eleve;
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

void rechercher_un_etudiant(maillon_eleve** liste_eleves);
void virer_un_etudiant(maillon_eleve** liste_eleves);
void afficher_les_infos_de_la_promo(maillon_eleve* liste_eleves);