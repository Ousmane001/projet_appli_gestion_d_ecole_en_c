#ifndef GESTION_ECOLE_H
#define GESTION_ECOLE_H

#include "../gestion_des_niveaux/niveau.h"

#define ECOLE_VIDE 0
#define ANNEE_SUIVANTE 1 
 // structure d'un maillon niveau d'études :

typedef struct maillon_niveau{
  type_niveau* niveau_x;
  struct maillon_niveau* niveau_suivant;
}maillon_niveau;


// structure represantant une ecole :

typedef struct{
  char* nom_ecole;
  int nb_niveaux;
  type_date* debut_cours;
  type_date* fin_cours;
  maillon_niveau* liste_niveaux;
}type_ecole;


// prototypes des fonctions :

type_ecole* creer_saisir_info_ecole(void);
maillon_niveau* creer_maillon_niveau(type_niveau* niveau);
void afficher_info_ecole(type_ecole* ecole);
void ajouter_un_niveau_detude(type_ecole* ecole, maillon_niveau* nouveau_niveau);
maillon_niveau* rechercher_un_niveau(type_ecole* ecole, unsigned int niveau);
void supprimer_un_niveau_detude(type_ecole* ecole, maillon_niveau* niveau_a_supp);

#endif