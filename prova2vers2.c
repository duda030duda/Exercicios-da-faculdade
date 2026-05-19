#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
int mes;
int ano; } DATA;
typedef struct {
char nome[MAX];
DATA criacao;
long int egressos; } CURSO;

void altera_curso(CURSO *c, long int egr){
    c->egressos+=egr;
}

int *dif_ano(int ano_atual, DATA *anterior){
    int *exis= malloc(sizeof(int)*1);
    *exis= ano_atual - anterior->ano;
    return exis;
}

int recupera_txt(FILE *ft, CURSO *c){
    return fscanf(ft, "%A-Z - %d/ %d %ld", c->nome, &c->criacao.mes, &c->criacao.ano, &c->egressos);
}
int grava_bin_txt(FILE *ft, FILE *fb){
    CURSO c;
    int i=0;
    while(recupera_txt(ft, &c)==4){
        fwrite(&c, sizeof(CURSO), 1, fb);
        i++;
    } return i;
}

int grava_curso_alterado(FILE *fb, int pos, long int egr){
    CURSO c;
    fseek(fb, pos*(sizeof(CURSO)), SEEK_SET);
    if((fread(&c, sizeof(CURSO), 1, fb))!=1)return 0;
    altera_curso(&c, egr);
    fseek(fb, pos*(sizeof(CURSO)), SEEK_SET);
    if((fwrite(&c, sizeof(CURSO), 1, fb))!=1)return 0;

    return 1;
}
void exibe_bin(FILE *fb, int ano_atual){
    rewind(fb);
    CURSO c;
    while(fread(&c,sizeof(CURSO), 1, fb)){
        int *exis=dif_ano(ano_atual, &c.criacao);
        printf("Curso: %s - Criação: %d/%d (%d anos de existência) - Egressos: %ld", c.nome, c.criacao.mes, c.criacao.ano, *exis, c.egressos);
        free(exis);
    }
    
}


int main()
{
FILE *ft, *fb;
char arqt[MAX], arqb[MAX];
int calt;
long int negress;
printf("Nome do arquivo de entrada: ");
fgets(arqt,MAX-1,stdin);
arqt[strlen(arqt)-1]='\0';
ft=fopen(arqt,"r");
if(ft==NULL)
return -1;
printf("Nome do arquivo de saida: ");
fgets(arqb,MAX-1,stdin);
arqb[strlen(arqb)-1]='\0';
fb=fopen(arqb,"w+");
if(fb==NULL){
fclose(ft);
return -1; }
int res=grava_bin_txt(ft, fb);
if (res==0)
return -1;
else
printf("Total de cursos: %d\n",res);
printf("Posicao do curso a ser atualizado (iniciando em 0): ");
scanf("%d",&calt);
printf("Numero de novos egressos: ");
scanf("%ld",&negress);
res=grava_curso_alterado(fb, calt, negress);
if (res==1)
printf("Informacoes do curso atualizadas com sucesso\n");
else
printf("Erro, curso nao existe ou informacoes nao puderam ser atualizadas no arquivo\n");
exibe_bin(fb, 2026);
fclose(ft);
fclose(fb);
return 0;
}