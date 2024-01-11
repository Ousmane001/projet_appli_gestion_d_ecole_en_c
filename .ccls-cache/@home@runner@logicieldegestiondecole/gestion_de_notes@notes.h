#ifndef NOTES_H
#define NOTES_H

#include "../gestion_des_donnees_d_eleve/gestion_eleve.h"
#include "../fonction_de_gestion/fonctions.h"

#define MOIS_DEBUT_DES_COURS 9
#define MOIS_FIN_DES_COURS 6
#define JANVIER 1
#define DECEMBRE 12
#define DERNIER_JOUR_DU_MOIS 31
#define PREMIER_JOUR_DU_MOIS 1
#define NOTE_VIDE -1
#define NOTE_ELEVE_ABSCENT_JUSTIFIEE -5
#define NOTE_ELEVE_ABSCENT_NON_JUSTIFIEE -10
/*------------------declaration d'un type de date-----------------------*/
typedef struct{
  unsigned int jour;
  unsigned int mois;
  unsigned int annee;
}type_date;
/*------------------declaration d'un type note-----------------------*/
typedef struct t_note{
  
  float* notes_eleve;
  

}t_note;


/*prototypes des fonctions*/
t_note* creation_des_notes_pour_eleve(void);
type_date* creer_une_date(void);
void saisir_une_date(type_date* date_a_saisir);
void saisir_une_note(float* note, char* matiere, type_date* date_deval);
void initialiser_les_notes(t_note* note);
void supprimer_note_eleve(t_note* note);


#endif
