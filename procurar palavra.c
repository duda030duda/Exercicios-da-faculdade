#include <stdio.h>
#include <string.h>

int procurarp(FILE *ft){
    int contar = 0;

    char procurar[50];
    printf("Qual palavra deseja contar? ");
    fgets(procurar, 49, stdin);
    procurar[strlen(procurar)-1]='\0';

    char palavra[50];
    while(fscanf(ft, "%49s ", palavra)!=EOF){
    if(strcmp(palavra, procurar) == 0){
        contar++;
    }
   
    }
    return contar;
}

int main(){

    FILE *ft=fopen("entrada.txt", "r");
    if(ft==NULL){
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    
    int x=procurarp(ft);
    printf("O numero é: %d\n", x);


    fclose(ft);

    return 0;
}