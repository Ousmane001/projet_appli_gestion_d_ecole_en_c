#ifndef NOTES_H
#define NOTES_H

/*------------------declaration d'un type note-----------------------*/
typedef struct{
char* intitule_des_matieres;
unsigned int* coefficients;
float* notes_eleve;
}t_note;

/*------------------declaration d'un type de date-----------------------*/
typedef struct{
unsigned int jour;
unsigned int mois;
unsigned int annee;
}type_date;

/*prototypes des fonctions*/
t_note* creation_des_notes_pour_eleve(void);


#endif
