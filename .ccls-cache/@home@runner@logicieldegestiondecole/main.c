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

  inscrire_un_etudiant(ma_promo, &(ma_promo->liste_des_eleves),creer_maillon_eleve(ma_promo, "uvsq"));

  

  inscrire_un_etudiant(ma_promo, &(ma_promo->liste_des_eleves),creer_maillon_eleve(ma_promo, "uvsq"));
 

 
  
  afficher_les_infos_de_la_promo(ma_promo);
  virer_un_etudiant(ma_promo, "alpha");
  printf("nb_etudiants  %d\n",ma_promo->nombre_d_etudiants);
  afficher_les_infos_de_la_promo(ma_promo);
  printf("\nbien executé\n");
  return 0;
}
/*eleve* alpha = definir_un_eleve();
saisir_info_eleve(alpha);
afficher_un_eleve(alpha);*/

/* if(rechercher_un_etudiant(&(ma_promo->liste_des_eleves), "alpha") != NULL){
  printf("eleve alpha trouvé\n");

}
else{
  printf("eleve alpha pas trouvé\n");
}
if(rechercher_un_etudiant(&(ma_promo->liste_des_eleves), "zeze") != NULL)
  printf("eleve zeze trouvé\n");
else{
  printf("eleve zeze pas trouvé\n");
}
supprimer_un_maillon_eleve(maillon_alpha);*/