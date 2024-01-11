#include <stdio.h>

#include "gestion_ecole/gestion_ecole.h"
//#include "./gestion_des_donnees_d_eleve/gestion_eleve.h"
//#include "./gestion_promo/gestion_promo.h"

/*pour compiler et executer directement le programme :
gcc main.c fonction_de_gestion/fonctions.c gestion_de_notes/notes.c
gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c  -o
prog  && clear && ./prog */

/*oubien juste compiler le programme :
gcc -Wall fonction_de_gestion/fonctions.c gestion_de_notes/notes.c
gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c main.c
-o prog   */

int main(void) {

  printf("\033[1;35m\n");
  system("figlet -f slant Logiciel de gestion d_ecole ");
  printf("\n\n");
  printf("\033[0m\n");
  
  type_ecole *ecole = creer_saisir_info_ecole();
  type_niveau *niveau = creer_et_saisir_info_niveau();
  type_promo *ma_promo = creat_intituler_promo();
  type_date* date = creer_une_date();
  
  saisir_intituler_promo(ma_promo);

  //inscrire_un_etudiant(ma_promo, creer_maillon_eleve(ma_promo, ecole->nom_ecole));


  ajouter_une_promo(niveau, ma_promo);
  ajouter_un_niveau_detude(ecole, creer_maillon_niveau(niveau));
  afficher_info_ecole(ecole);
  
  afficher_info_niveau(niveau);

  inscrire_un_etudiant(ma_promo, creer_maillon_eleve(ma_promo, ecole->nom_ecole));
  saisir_une_date(date);
  reporter_note_promo(ma_promo, date);
  afficher_les_notes_de_la_promo(ma_promo);
  printf("\nbien executé\n");
  return 0;
}
