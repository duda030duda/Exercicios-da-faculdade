#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int mes;
    int ano;
}data;
typedef struct{
    char nome[MAX];
    data criacao;
    long int egressos;
}curso;

void altera_curso(curso *c, long int egr){
    c->egressos= c->egressos+egr;
}

int * dif_ano(int ano_atual, data *anterior){
    int *dif=malloc(sizeof (int));
    *dif= ano_atual - anterior->ano;

    return dif;
}

int recupera_txt(FILE *ft, curso *c){
     return fscanf(ft, "%[A-Z a-z]- %d/%d %ld", c->nome, &c->criacao.mes, &c->criacao.ano, &c->egressos);
    
    }

int grava_bin_txt(FILE *ft, FILE *fb){
    
    curso c;
    int temp = 0;
    while(recupera_txt(ft, &c)==4){
    fwrite(&c, sizeof(curso), 1, fb);
    temp++;
}
return temp;
}
 
int grava_curso_alterado(FILE *fb, int calt, long int egr){
    rewind(fb);
    curso c;
    
    fseek(fb, calt*sizeof(curso), SEEK_SET);
    fread(&c,sizeof(curso),1,fb);
    altera_curso(&c, egr);
    fseek(fb, calt*sizeof(curso), SEEK_SET);
    fwrite(&c, sizeof(curso), 1, fb);
    return 1;
}

void exibe_bin(FILE *fb, int ano_atual){
    curso c;

    fseek(fb, 0, SEEK_SET);
    while(fread(&c,sizeof(curso),1,fb)==1){
    int *exis= dif_ano(ano_atual, &c.criacao);

    printf("Curso: %s - Criacao: %d/%d (%d anos de existência) - Egressos: %ld", 
        c.nome, c.criacao.mes, c.criacao.ano, *exis, c.egressos);
        free(exis);
    }
}


int main(){
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
exibe_bin(fb, 2024);
fclose(ft);
fclose(fb);

    return 0;
}