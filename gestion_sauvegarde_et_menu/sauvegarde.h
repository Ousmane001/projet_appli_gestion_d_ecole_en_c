#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

  #include "../gestion_ecole/gestion_ecole.h"
  //#include <sys/wait.h>

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
  #define SAUVEGARDER 8
  #define TAILLE_MAX 75
  #define TAILLE_CONCAT 10
  #define CHAINE_VIDE 0
  #define SUPP_BASE_DE_DONNEE "rm -r base_de_donnee"
  #define BASE_DE_DONNEE "base_de_donnee"
  #define nom_fichier_ecole "/ecole.save"
  #define niveau_concat "niveau_"
  #define NOM_DOC_NIVEAU "info_niveau.data"
  #define NOM_DOC_PROMO "info_promo.data"
  #define NOM_DOC_ELEVES "info_eleves.data"

  void afficher_un_nom_en_gras(char *nom);
  void afficher_menu_principale(type_ecole* ecole);
  void afficher_menu_sauvegarde(type_ecole* ecole);
  void afficher_menu_gestion_ecole(type_ecole* ecole);
  void afficher_menu_gestion_niveau(type_ecole* ecole);
  void afficher_menu_gestion_promo(type_ecole* ecole);
  void attendre_utilisateur(void);
  int recup_choix_utilisateur(void);
  int creer_un_dossier(char* nom_dossier);
  int sauvergarder_donnees(type_ecole* ecole);
  int acceder_a_repetoire(char* repertoire);

#endif