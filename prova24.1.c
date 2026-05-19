#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
char nome[MAX];
int gols;
}tTimeGols;

typedef struct {
tTimeGols time1;
tTimeGols time2;
} tPlacarJogo;

typedef struct {
char nome[MAX];
int jogos;
int saldo;
int pontos;
} tPontos;

int grava_pontos(FILE *parq2, tPontos time_grava){
    rewind(parq2);
    tPontos com;
     while(fread(&com, sizeof(tPontos),1,parq2)==1){
        if(strcmp(com.nome,time_grava.nome)==0){
            fseek(parq2, -sizeof(tPontos), SEEK_CUR);
            fwrite(&time_grava, sizeof(tPontos), 1, parq2);
        }

     }
     if(fread(&com, sizeof(tPontos),1,parq2)!=1){
        fwrite(&time_grava,sizeof(tPontos), 1, parq2);
     }
        return 0;
}

int contabiliza_pontuacao(tPlacarJogo *placar, tPontos *time_grava){
    if(strcmp(placar->time1.nome,time_grava->nome)==0){
    time_grava->jogos+=1;
    time_grava->saldo+=placar->time1.gols;
    if(placar->time1.gols>placar->time2.gols){s
        time_grava->pontos+=3;
    }
    if(placar->time1.gols==placar->time2.gols){
        time_grava->pontos+=1;
}
}
if(strcmp(placar->time2.nome,time_grava)==0){
    time_grava->jogos+=1;
    time_grava->saldo+=placar->time1.gols;
    if(placar->time1.gols<placar->time2.gols){
        time_grava->pontos+=3;
    }
    if(placar->time1.gols==placar->time2.gols){
        time_grava->pontos+=1;
}
}return 0;
}

int ler_gravar_resultados(FILE *parq, FILE *parq2, char *time_desejado){
    rewind(parq);
    tPlacarJogo placar;
    tPontos time_grava={0};
    while(fscanf(parq, "%s %d x %d %s", placar.time1.nome, &placar.time1.gols, placar.time2.nome, &placar.time2.gols)){
        if(strcmp(placar.time1.nome,time_desejado)==0||strcmp(placar.time2.nome, time_desejado)==0){
           
            if(contabiliza_pontuacao(&placar, &time_grava)==0){
                int x=grava_pontos(parq2, time_grava);
            }
        }
    }


    return 0;
}


void mostra_pontuacao_time(FILE *parq){
    tPontos gravado;
    rewind(parq);
    while(fread(&gravado, sizeof(tPontos),1,parq)){
        printf("time: %s - jogos: %d, saldo: %d, pontos: %d", gravado.nome, gravado.jogos, gravado.saldo, gravado.pontos);
    }

}

int main() {
FILE *parq, *parq2;
char time_buscado[MAX];
parq=fopen("jogos.txt","r");
if(parq==NULL);
return -1;
parq2=fopen("pontos.dat","w+");
if(parq2==NULL) {
fclose(parq);
return -1; }
printf("Digite o time desejado: ");
fgets(time_buscado,MAX,stdin);
while (time_buscado[0]!='\n') {
time_buscado[strlen(time_buscado)-1]='\0';
ler_gravar_resultados(parq, parq2, time_buscado);
mostra_pontuacao_time(parq2);
printf("Digite o time desejado: ");
fgets(time_buscado,MAX,stdin); }
fclose(parq);
fclose(parq2);
return 0; }