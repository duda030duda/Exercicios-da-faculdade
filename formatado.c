#include <stdio.h>
#include <string.h>

void gravar_txt(FILE *ft){
    char texto[100];
    printf("Qual é o nome do aluno, nota da P1, nota da P2 e do trabalho?\n");
    fgets(texto, 99, stdin);
    texto[strlen(texto)-1]='\0';
    fprintf(ft,"%s\n" ,texto);
}

void media(FILE *ft, FILE *ft2){
    rewind(ft);
    char nome[15];
    float p1, p2, t;

    fscanf(ft, "%[A-Z a-z] %f %f %f", nome, &p1, &p2, &t);
    float media = (((p1+p2)/2)*0.8)+(t*0.2);

    fprintf(ft2, "%s %f", nome, media);
    
}


int main(){
    char arqt[100];
    printf("Qual é o nome do arquivo de entrada?\n");
    fgets(arqt, 99, stdin);
    arqt[strlen(arqt)-1]='\0';

    FILE *ft=fopen(arqt, "r+");
    if(ft==NULL) return-1;

gravar_txt(ft);

    char arqt2[100];
    printf("Qual é o nome do arquivo de saída?\n");
    fgets(arqt2, 99, stdin);
    arqt2[strlen(arqt2)-1]='\0';

    FILE *ft2= fopen(arqt2, "w");
    if(ft2==NULL)return -1;

    

    
    media(ft, ft2);


    fclose(ft);
    fclose(ft2);


    return 0;
}