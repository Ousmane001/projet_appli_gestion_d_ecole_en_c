#ifndef GESTION_PROMO_H
#define GESTION_PROMO_H

#include "../fonction_de_gestion/fonctions.h"
#include "../gestion_des_donnees_d_eleve/gestion_eleve.h"
#include "../gestion_de_notes/notes.h"

#define AUCUN_ETUDIANT_INSCRIT 0
#define ELEVE_TROUVE 0


/*------------------declaration d'un type liste_d'élèves-----------------------*/
typedef struct maillon_eleve{
  eleve* eleve_x;
  struct maillon_eleve* eleve_suivant;
}maillon_eleve;

/*------------------declaration d'un type promo-----------------------*/
typedef struct type_promo{
unsigned int nombre_d_etudiants;
  char* intitule_de_promo;
  maillon_eleve* liste_des_eleves;
}type_promo;


/*prototype des fonctions concernant une promo */
type_promo* creat_intituler_promo(void);
void dissoudre_une_promo(maillon_eleve** liste_eleves);
void saisir_intituler_promo(type_promo* promo);
void initialiser_nb_etudiant_promo(type_promo* promo);
maillon_eleve* creer_maillon_eleve(type_promo* promo, char *nom_de_l_ecole);
void supprimer_un_maillon_eleve(maillon_eleve* maillon_eleve_a_supprimer);
void inscrire_un_etudiant(type_promo* promo, maillon_eleve* nouvel_eleve);
eleve* rechercher_un_etudiant(maillon_eleve** liste_eleves, char* info_eleve);
void virer_un_etudiant(type_promo* promo, char* infos_eleve);
void afficher_les_infos_de_la_promo(type_promo* promo);
void ajout_automatique_du_matricule_eleve(eleve* eleve_x, type_promo* promo_x);
void creation_automatique_email_eleve(eleve* eleve_x, type_promo* promo_x, char* nom_de_l_ecole);

#endif
