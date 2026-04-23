#include <stdio.h>
#include <string.h>

void gravar_txt(FILE *ft){
    char texto[100];
    fgets(texto, 99, stdin);
    texto[strlen(texto)-1]='\0';
    fprintf(ft,"%s\n" ,texto);
}

int main(){
    char arqt[100];
    printf("Qual é o nome do arquivo?\n");
    fgets(arqt, 99, stdin);
    arqt[strlen(arqt)-1]='\0';

    FILE *ft=fopen(arqt, "w");
    if(ft==NULL) return-1;

    gravar_txt(ft);

    fclose(ft);


    return 0;
}