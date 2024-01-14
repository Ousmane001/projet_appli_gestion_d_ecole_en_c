#ifndef NIVEAU_H
#define NIVEAU_H

#include "../gestion_promo/gestion_promo.h"

#define PROMO_VIDE 0
#define PROMO_TROUVEE 0
// Définition de la structure Niveau d'etudes 

typedef struct maillon_promo{
  type_promo* promo_x;
  struct maillon_promo* promo_suivant;
} maillon_promo;


typedef struct{

unsigned int nb_promo;
unsigned int niveau_d_etude;
maillon_promo* liste_promo;

}type_niveau;

// prototype des fonctions :
type_niveau* creer_et_saisir_info_niveau(void);
void afficher_info_niveau(type_niveau* niveau);
maillon_promo* creer_maillon_promo(void);
void ajouter_une_promo(type_niveau* niveau, maillon_promo* nouveau_maillon);
maillon_promo* rechercher_promo(type_niveau* niveau, char* intitule_promo); 
void supprimer_une_promo(type_niveau* niveau, maillon_promo* promo_a_supprimer);

#endif