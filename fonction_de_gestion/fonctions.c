#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

/*-----------------------------------------------------------------------------*/
char* saisir_chaine(char* question){
  char* chaine = (char*)malloc(sizeof(char)*MAX_SIZE);
  
  do{
  printf("%s", question);
  scanf("%s", chaine);
  }while(strlen(chaine)>MAX_SIZE);
  
  return chaine;
}
/*-----------------------------------------------------------------------------*/
unsigned int saisir_entier(char* question){
  unsigned int nombre;
  
  do{
  printf("%s",question);
  scanf("%d", &nombre);
  }while(nombre < 0);

  return nombre;
}
/*-----------------------------------------------------------------------------*/
 float saisir_float(char* question){
  float nombre;
do{
  printf("%s", question);
  scanf("%f", &nombre);
  
}while(nombre < 0);
  return nombre;
}

