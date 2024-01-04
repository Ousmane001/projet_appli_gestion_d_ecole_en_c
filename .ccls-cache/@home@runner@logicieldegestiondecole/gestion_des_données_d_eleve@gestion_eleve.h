#ifndef  GESTION_ELEVE_H
#define GESTION_ELEVE_H

#include "../gestion_de_notes/notes.h"
#include "../fonction_de_gestion/fonctions.h"

/*------------------un type eleve-----------------------*/
typedef struct {

char* nom;
char* prenom;
char* email;
char* matricule;
unsigned int age;
unsigned int num_telephone;
t_note* note;
}eleve;


/*----------------------prototype-------------------------*/
eleve* definir_un_eleve(void);
void saisir_info_eleve(eleve* eleve_x);
void afficher_un_eleve(eleve* eleve_x);


#endif
