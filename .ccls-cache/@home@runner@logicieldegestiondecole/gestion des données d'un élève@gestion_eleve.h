#ifndef GESTION_ELEVE_H
#define GESTION_ELEVE_H

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

