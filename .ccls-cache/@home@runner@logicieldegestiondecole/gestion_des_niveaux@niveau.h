#ifndef NIVEAU_H
#define NIVEAU_H

#include "../gestion_promo/gestion_promo.h"

// Définition de la structure Niveau d'etudes 

typedef struct{

unsigned int nb_promo;
unsigned int niveau_d_etude;
type_promo* promos_du_niveau;

}type_niveau;

// prototype des fonctions :
type_niveau* creer_et_saisir_info_niveau(void);
void afficher_info_niveau(type_niveau* niveau);
void ajouter_une_promo(type_niveau* niveau, type_promo* nouvelle_promo);
void supprimer_une_promo(type_niveau* niveau, type_promo* promo_a_supprimer);

#endif