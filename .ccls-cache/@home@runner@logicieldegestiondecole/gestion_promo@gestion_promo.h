#ifndef GESTION_PROMO_H
#define GESTION_PROMO_H

#include "../fonction_de_gestion/fonctions.h"
#include "../gestion_des_donnees_d_eleve/gestion_eleve.h"

#define AUCUN_ETUDIANT_INSCRIT 0


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
maillon_eleve* creer_maillon_eleve(void);
void inscrire_un_etudiant(type_promo* promo,maillon_eleve** liste_eleves, maillon_eleve* nouvel_eleve);
void rechercher_un_etudiant(maillon_eleve** liste_eleves);
void virer_un_etudiant(maillon_eleve** liste_eleves);
void afficher_les_infos_de_la_promo(maillon_eleve* liste_eleves);
void ajout_automatique_du_matricule_eleve(eleve* eleve_x, type_promo* promo_x);
void creation_automatique_email_eleve(eleve* eleve_x, type_promo* promo_x, char* nom_de_l_ecole);

#endif
