#include <stdio.h>

//#include "gestion_ecole/gestion_ecole.h"
#include "gestion_sauvegarde_et_menu/sauvegarde.h"
//#include "./gestion_des_donnees_d_eleve/gestion_eleve.h"
//#include "./gestion_promo/gestion_promo.h"

/*pour compiler et executer directement le programme :
gcc main.c fonction_de_gestion/fonctions.c gestion_de_notes/notes.c
gestion_promo/gestion_promo.c gestion_des_niveaux/niveau.c gestion_ecole/gestion_ecole.c gestion_des_donnees_d_eleve/gestion_eleve.c  -o
prog  && clear && ./prog */

/*oubien juste compiler le programme :
gcc -Wall fonction_de_gestion/fonctions.c gestion_de_notes/notes.c
gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c main.c
-o prog   */

int main(void) {
  int menu_courant = MENU_PRINCIPALE;
  int choix = OUI;
  
  type_ecole *ecole = creer_saisir_info_ecole(); 
  afficher_menu_principale(ecole);
  do{
    

    switch(menu_courant){
      case MENU_PRINCIPALE:
        afficher_menu_principale(ecole);
        choix = saisir_entier("\n\n\n Faites votre choix en tapant le numero associe a votre requete : ");
        
        switch(choix){
          case MENU_GESTION_ECOLE:
            menu_courant = MENU_GESTION_ECOLE;
            
            continue;
          case MENU_GESTION_PROMO:
            menu_courant = MENU_GESTION_PROMO;
            
              continue;
          case MENU_GESTION_NIVEAU:
            menu_courant = MENU_GESTION_NIVEAU;
            
              continue;
          default:
              continue;
        }
        break;
      
      case MENU_GESTION_ECOLE:
        
        afficher_menu_gestion_ecole(ecole);
        choix = saisir_entier("\n\n\n Faites votre choix en tapant le numero associe a votre requete : ");
        
        switch(choix){
          case RETOUR :
            menu_courant = MENU_PRINCIPALE;
            break;
          case AFFICHER:
            afficher_info_ecole(ecole);
            break;
          case AJOUTER:
            ajouter_un_niveau_detude(ecole, creer_maillon_niveau(creer_et_saisir_info_niveau()));
            break;
          case RECHERCHER:
           afficher_info_niveau(rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau que vous souhaitez rechercher : "))->niveau_x);
          break;
          case SUPPRIMER:
            supprimer_un_niveau_detude(ecole,rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau que vous souhaitez supprimer : ")));
          break;
          default:
            break;
        }
        
      break;
      case MENU_GESTION_NIVEAU:
        afficher_menu_gestion_niveau(ecole);
        choix = saisir_entier("\n\n\n Faites votre choix en tapant le numero associe a votre requete : ");
        switch(choix){
          case RETOUR:
            menu_courant = MENU_PRINCIPALE;
            break;
          default:
            break;
        }
        break;
      
      case MENU_GESTION_PROMO:
        afficher_menu_gestion_promo(ecole);
        choix = saisir_entier("\n\n\n Faites votre choix en tapant le numero associe a votre requete : ");
        
        switch(choix){
          case RETOUR:
            menu_courant = MENU_PRINCIPALE;
            break;
          default:
            break;
        }
        break;
      
      default:
        break;
    }

    
  }while( (choix != QUITTER));


  
  printf("\nbien executé\n");
  
  return 0;
}
