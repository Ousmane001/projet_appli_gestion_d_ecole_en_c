#include <stdio.h>

#include "./gestion_des_donnees_d_eleve/gestion_eleve.h"
#include "./gestion_promo/gestion_promo.h"

/*pour compiler et executer directement le programme :
gcc main.c fonction_de_gestion/fonctions.c gestion_de_notes/notes.c gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c  -o prog  && clear && ./prog */


/*oubien juste compiler le programme : 
gcc -Wall fonction_de_gestion/fonctions.c gestion_de_notes/notes.c gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c main.c -o prog   */

int main(void) {
  type_promo* ma_promo = creat_intituler_promo();
  saisir_intituler_promo(ma_promo);
  maillon_eleve* maillon_alpha = creer_maillon_eleve();
  maillon_alpha->eleve_x = definir_un_eleve();
  saisir_info_eleve(maillon_alpha->eleve_x);

  inscrire_un_etudiant(ma_promo, &(ma_promo->liste_des_eleves), maillon_alpha);

  ajout_automatique_du_matricule_eleve(maillon_alpha->eleve_x, ma_promo);
  
  

  maillon_eleve* maillon_beta = creer_maillon_eleve();
  maillon_beta->eleve_x = definir_un_eleve();
  saisir_info_eleve(maillon_beta->eleve_x);
  inscrire_un_etudiant(ma_promo, &(ma_promo->liste_des_eleves->eleve_suivant), maillon_beta);
  ajout_automatique_du_matricule_eleve(maillon_beta->eleve_x, ma_promo);
  afficher_un_eleve(ma_promo->liste_des_eleves->eleve_x);
  afficher_un_eleve(ma_promo->liste_des_eleves->eleve_suivant->eleve_x);
  printf("alpha --> %s\n",maillon_alpha->eleve_x->matricule);
  printf("beta --> %s\n",maillon_beta->eleve_x->matricule);

  creation_automatique_email_eleve(maillon_alpha->eleve_x, ma_promo, "uvsq");
  printf("email : %s\n",maillon_alpha->eleve_x->email_scolaire);
  
  

  printf("\nbien executé\n");
  return 0;
}
/*eleve* alpha = definir_un_eleve();
saisir_info_eleve(alpha);
afficher_un_eleve(alpha);*/