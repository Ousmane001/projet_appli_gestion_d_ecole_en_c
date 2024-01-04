#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

/*-----------------------------------------------------------------------------*/
char* saisir_chaine(char* question){
  char* chaine = (char*)malloc(sizeof(char)*MAX_SIZE);
do{
  printf("%s", question);
  scanf("%s",chaine);
}while(strlen(chaine)>MAX_SIZE || scanf("%s",chaine) < 'A');
  return chaine;
}
/*-----------------------------------------------------------------------------*/
unsigned int saisir_entier(char* question){
  unsigned int nombre;

  printf("saisissez %s",question);
  scanf("%d", &nombre);


  return nombre;
}
/*-----------------------------------------------------------------------------*/
 float saisir_float(char* struct_float){
  float nombre;

  printf("saisissez %s", struct_float);
  scanf("%f", &nombre);
   
  return nombre;
}

