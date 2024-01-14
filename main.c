#include <stdio.h>

//#include "gestion_ecole/gestion_ecole.h"
#include "gestion_sauvegarde_et_menu/sauvegarde.h"
//#include "./gestion_des_donnees_d_eleve/gestion_eleve.h"
//#include "./gestion_promo/gestion_promo.h"

/*pour compiler et executer directement le programme :
gcc main.c fonction_de_gestion/fonctions.c gestion_de_notes/notes.c gestion_promo/gestion_promo.c gestion_des_niveaux/niveau.c gestion_ecole/gestion_ecole.c gestion_des_donnees_d_eleve/gestion_eleve.c  gestion_sauvegarde_et_menu/sauvegarde.c -o prog  */

/*oubien juste compiler le programme :
gcc -Wall fonction_de_gestion/fonctions.c gestion_de_notes/notes.c
gestion_promo/gestion_promo.c gestion_des_donnees_d_eleve/gestion_eleve.c main.c
-o prog   */

int main(void) {

  int menu_courant = MENU_PRINCIPALE;
  int choix = OUI;
  maillon_niveau* niveau_a_rechercher = creer_maillon_niveau(NULL);
  type_promo* promo_a_rechercher = creat_intituler_promo();
  maillon_eleve* maillon_eleve_courant = NULL;
  eleve* eleve_a_rechercher = definir_un_eleve();
  
  type_ecole *ecole = creer_saisir_info_ecole(); 
  afficher_menu_principale(ecole);
  do{
    

    switch(menu_courant){
      case MENU_PRINCIPALE:
        afficher_menu_principale(ecole);
        choix = recup_choix_utilisateur();
        
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
        choix = recup_choix_utilisateur();
        
        switch(choix){
          case RETOUR :
            menu_courant = MENU_PRINCIPALE;
            break;
          case AFFICHER:
            afficher_info_ecole(ecole);
            attendre_utilisateur();
            break;
          case AJOUTER:
            ajouter_un_niveau_detude(ecole, creer_maillon_niveau(creer_et_saisir_info_niveau()));
            attendre_utilisateur();
            break;
          case RECHERCHER:
           afficher_info_niveau(rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau que vous souhaitez rechercher : "))->niveau_x);
           attendre_utilisateur();
          break;
          case SUPPRIMER:
            supprimer_un_niveau_detude(ecole,rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau que vous souhaitez supprimer : ")));
            attendre_utilisateur();
          break;
          default:
            break;
        }
        
      break;
      case MENU_GESTION_NIVEAU:

        afficher_menu_gestion_niveau(ecole);
        choix = recup_choix_utilisateur();

        switch(choix){

          case RETOUR:
            menu_courant = MENU_PRINCIPALE;
            break;
          
          case AFFICHER:
            afficher_info_niveau(rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau que vous souhaitez rechercher : "))->niveau_x);
            attendre_utilisateur();
            break;
          case AJOUTER:
          niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau d'etude auquel vous souhaitez ajouter une promo : "));
            ajouter_une_promo(niveau_a_rechercher->niveau_x,creer_maillon_promo());
            attendre_utilisateur();
            break;
          case RECHERCHER:
          niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau d'etude auquel vous souhaitez rechercher une promo : "));
           afficher_les_infos_de_la_promo(rechercher_promo(niveau_a_rechercher->niveau_x,saisir_chaine("saisissez l'intitule de la promo a afficher"))->promo_x);
           attendre_utilisateur();
          break;
          case SUPPRIMER:
            niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau d'etude auquel vous souhaitez supprimer une promo : "));
            supprimer_une_promo(niveau_a_rechercher->niveau_x,rechercher_promo(niveau_a_rechercher->niveau_x,saisir_chaine("saisissez l'intitule de la promo a supprimer : ")));
            attendre_utilisateur();
          break;
          default:
            break;
        }
        break;
      
      case MENU_GESTION_PROMO:
        afficher_menu_gestion_promo(ecole);
        choix = recup_choix_utilisateur();
        
        switch(choix){
          case RETOUR:
            menu_courant = MENU_PRINCIPALE;
            break;
          case AFFICHER:
              niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("saisissez le niveau d'etude auquel vous souhaitez rechercher une promo : "));
              afficher_les_infos_de_la_promo(rechercher_promo(niveau_a_rechercher->niveau_x, saisir_chaine("saisissez l'intitule de la promo a afficher : "))->promo_x);
              break;
          case AJOUTER:
            niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("\nsaisissez le niveau d'etude dans lequel se trouve la promo de l'etudiant : "));
            promo_a_rechercher = rechercher_promo(niveau_a_rechercher->niveau_x, saisir_chaine("saisissez l'intitule de la promo de l'etudiant : "))->promo_x;
            maillon_eleve_courant = creer_maillon_eleve(promo_a_rechercher,ecole->nom_ecole);
            
            inscrire_un_etudiant(promo_a_rechercher,maillon_eleve_courant);
            ajout_automatique_du_matricule_eleve(maillon_eleve_courant->eleve_x,promo_a_rechercher);
            creation_automatique_email_eleve(maillon_eleve_courant->eleve_x,promo_a_rechercher,ecole->nom_ecole);
            printf("\n\n\n Eleve inscrit avec succes\n\n");
            afficher_un_eleve(maillon_eleve_courant->eleve_x);
            attendre_utilisateur();
            break;
          case RECHERCHER:
            niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("\nsaisissez le niveau d'etude dans lequel se trouve la promo de l'etudiant : "));
            promo_a_rechercher = rechercher_promo(niveau_a_rechercher->niveau_x, saisir_chaine("saisissez l'intitule de la promo de l'etudiant a rechercher : "))->promo_x;
            eleve_a_rechercher = rechercher_un_etudiant(&(promo_a_rechercher->liste_des_eleves),saisir_chaine("saisissez une information concernant cet eleve (nom, prenom ou email ...) : "));
            afficher_un_eleve(eleve_a_rechercher);
            break;
          case SUPPRIMER:
            niveau_a_rechercher = rechercher_un_niveau(ecole, saisir_entier("\nsaisissez le niveau d'etude dans lequel se trouve la promo de l'etudiant : "));
            promo_a_rechercher = rechercher_promo(niveau_a_rechercher->niveau_x, saisir_chaine("saisissez l'intitule de la promo de l'etudiant a virer : "))->promo_x;
            virer_un_etudiant(promo_a_rechercher,saisir_chaine("saisissez le matricule, nom ou prenom de l'eleve a virer : "));
            break;

          default:
            break;
        }
        break;
      
      default:
        break;
    }

    
  }while( (choix != QUITTER));


  
  printf("\nbien execute\n");
  
  return 0;
}
