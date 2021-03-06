#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "DirectoryHandler.h"
#include <dirent.h>


int MenuPrincipal(){
  int option;
  printf("¡Bienvenido a UNO!\n");
  printf("Elija la opcion a ejecutar\n");
  printf("1: Iniciar Juego\n");
  printf("0: Salir\n");
  scanf("%d", &option);
  printf("----------------------\n");
  return option;
}

int main(){

  //se crea el mazo
  CreateDirectoryIfNotExist();
  
  //crea las cartas de colores
  for (int i = 0; i < 4; i ++){
    char color[10];
    switch(i){
        case 0:
            strcpy(color, "verde");
            break;
        case 1:
            strcpy(color, "rojo");
            break;
        case 2:
            strcpy(color, "azul");
            break;
        case 3:
            strcpy(color, "amarillo");
            break;
    }
    for (int j = 0; j <= 12; j++){
      char buffer[260];
      char fileName[100];

      //crea los 0
      if (j == 0){
        sprintf(fileName, "%d ", j);
        strcat(fileName, color);
        snprintf(buffer, sizeof(buffer), "Mazo/%s.txt", fileName);
        FILE* file = fopen(buffer, "w");
        fclose(file);
      }

      //crea las cartas que son duplicadas
      else{
        for (int k = 1; k < 3; k++){
          if (j == 10){
            char rev[10] = "salto ";
            sprintf(fileName, "%s",rev);
            strcat(fileName, color);
          }
          else if (j == 11){
            char rev[10] = "reversa ";
            sprintf(fileName, "%s",rev);
            strcat(fileName, color);
          }
          else if (j == 12){
            char rev[5] = "+2 ";
            sprintf(fileName, "%s",rev);
            strcat(fileName, color);
          }
          else{
            sprintf(fileName, "%d ", j);
            strcat(fileName, color);
          }
          char temp[5];
          sprintf(temp, " (%d)", k);
          strcat(fileName, temp);

          snprintf(buffer, sizeof(buffer), "Mazo/%s.txt", fileName);
          FILE* file = fopen(buffer, "w");
          fclose(file);
          }
        }
    }
  }

  //crea las cartas negras
  for (int l = 0 ; l < 2 ; l++){
    char buffer[260];
    for (int i = 1; i < 5; i++ ){
      if(l == 0){
        snprintf(buffer, sizeof(buffer), "Mazo/cambio de color (%d).txt", i);
        FILE* file = fopen(buffer, "w");
        fclose(file);
      }
      else{
        snprintf(buffer, sizeof(buffer), "Mazo/+4 (%d).txt", i);
        FILE* file = fopen(buffer, "w");
        fclose(file);
      }
    }
  }

  int opcion = MenuPrincipal();
  if (opcion == 0){
    printf("Has salido del juego.\n");
    printf("----------------------\n");
    return 0;
  }
  printf("perdiste F\n");
  printf("----------------------\n");
  return 0;
}

