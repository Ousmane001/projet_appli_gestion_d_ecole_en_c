#include "notes.h"

/*--------------------------------------------------------------------------------------*/
t_note* creation_des_notes_pour_eleve(void){
  return (t_note*)malloc(sizeof(t_note));
}
/*--------------------------------------------------------------------------------------*/
type_date* creer_une_date(void){
  return (type_date*)malloc(sizeof(type_date));
}
/*--------------------------------------------------------------------------------------*/
void saisir_une_date(type_date* date_a_saisir){
  if(date_a_saisir == NULL){
    printf("Erreur :  date non allouee \n");
    exit(EXIT_FAILURE);
  }
  // saisie du jour de l'eval
  do{
    date_a_saisir->jour = saisir_entier("saisissez le jour ou a eu lieu l'evaluation : ");
  }while(date_a_saisir->jour > DERNIER_JOUR_DU_MOIS || date_a_saisir->jour < PREMIER_JOUR_DU_MOIS);
  // saisie du mois de l'eval
  do{
    date_a_saisir->mois = saisir_entier("saisissez le mois correspondant : ");
  }while((date_a_saisir->mois < JANVIER) || (date_a_saisir->mois > DECEMBRE) || (date_a_saisir->mois > MOIS_FIN_DES_COURS && date_a_saisir->mois < MOIS_DEBUT_DES_COURS));
}
/*--------------------------------------------------------------------------------------*/
void saisir_une_note(float* note, char* matiere, type_date* date_deval){
  printf("Evaluation de %s du %d/%d/%d \n",matiere,date_deval->jour,date_deval->mois,date_deval->annee);
 // printf("ELEVE :  %s\t\t%s\n",eleve_x->prenom,eleve_x->nom);
  do{
    *note = saisir_float("saisissez sa note : ");
  }while(*note < 0);
  return;
}
/*--------------------------------------------------------------------------------------*/
void initialiser_les_notes(t_note* note){
  int compteur_note;
  
  if(note == NULL){
    printf("erreur : notes non allouee\n");
    exit(EXIT_FAILURE);
  }
  for(compteur_note = 0; compteur_note < note->nb_matiere_pour_eleve; compteur_note++){
    (note->notes_eleve)[compteur_note] = NOTE_VIDE;
  }
}

/*--------------------------------------------------------------------------------------*/

void supprimer_note_eleve(t_note* note){
  unsigned int compteur_matiere;

  /*/for(compteur_matiere = 0; compteur_matiere < (*note)->nb_matiere_pour_eleve; compteur_matiere++)
    {
      free(((*note)->intitule_des_matieres)[compteur_matiere]);
    }
  free((*note)->intitule_des_matieres);
  free((*note)->dates_des_eval);
  free((*note)->coefficients);*/
  free(note);
  printf("note supprimee avec succes\n");
}

/*--------------------------------------------------------------------------------------*/