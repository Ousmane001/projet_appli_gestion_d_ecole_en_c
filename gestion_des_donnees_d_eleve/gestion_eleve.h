#ifndef  GESTION_ELEVE_H
#define GESTION_ELEVE_H

#include "../fonction_de_gestion/fonctions.h"
//#include "../gestion_de_notes/notes.h"
//cette bib n'est pas à inclure /!\  #include "../gestion_promo/gestion_promo.h"

#define NB_MAX_CONCATENTION 5
#define NB_MAX_TAILLE_MATRICULE 10
#define NB_MAX_TAILLE_EMAIL_ETU 30

/*------------------un type eleve-----------------------*/
typedef struct eleve{

    char* nom;
    char* prenom;
    char* email;
    char* matricule;
    char* email_scolaire;
    //char matricule[NB_MAX_TAILLE_MATRICULE];
    //char email_scolaire[NB_MAX_TAILLE_EMAIL_ETU];
    int age;
    int num_telephone;
    struct t_note* note;
}eleve;

/*----------------------prototype-------------------------*/
eleve* definir_un_eleve(void);
void saisir_info_eleve(eleve* eleve_x);
void afficher_un_eleve(eleve* eleve_x);
void supprimer_info_eleve(eleve* eleve_x);


#endif
