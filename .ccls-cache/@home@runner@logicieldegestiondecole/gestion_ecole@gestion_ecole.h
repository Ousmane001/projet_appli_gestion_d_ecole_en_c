#ifndef GESTION_ECOLE_H
#define GESTION_ECOLE_H

#include "../gestion_des_niveaux/niveau.h"

// structure represantant une ecole : 

typedef struct{
  char* nom_ecole;
  unsigned int nb_niveaux;
  type_niveau* niveaux_d_etudes;
  type_date* debut_cours;
  type_date* fin_cours;
}type_ecole;


// prototypes des fonctions :

type_ecole* creer_saisir_info_ecole(void);
void afficher_info_ecole(type_ecole* ecole);
void ajouter_un_niveau_detude(type_ecole* ecole, type_niveau* niveau);
void supprimer_un_niveau_detude(type_ecole* ecole, type_niveau* niveau_a_supp);

#endif