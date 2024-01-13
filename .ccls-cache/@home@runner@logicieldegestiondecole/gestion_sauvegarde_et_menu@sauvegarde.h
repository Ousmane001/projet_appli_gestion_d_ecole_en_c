#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

  #include "../gestion_ecole/gestion_ecole.h"
  #include <sys/wait.h>

  #define TAILLE_CONCATENATION 15
  #define MENU_PRINCIPALE 0
  #define MENU_GESTION_ECOLE 1
  #define MENU_GESTION_NIVEAU 2
  #define MENU_GESTION_PROMO 3
  #define MENU_SAUVEGARDE 4
  
  #define QUITTER 9
  #define RETOUR 0
  #define AFFICHER 1
  #define AJOUTER 2
  #define RECHERCHER 3
  #define SUPPRIMER 4


  void afficher_un_nom_en_gras(char *nom);
  void afficher_menu_principale(type_ecole* ecole);
  void afficher_menu_sauvegarde(type_ecole* ecole);
  void afficher_menu_gestion_ecole(type_ecole* ecole);
  void afficher_menu_gestion_niveau(type_ecole* ecole);
  void afficher_menu_gestion_promo(type_ecole* ecole);

#endif