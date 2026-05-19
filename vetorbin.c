#include<stdio.h>
#include <stdlib.h>



int grava(FILE *pFile , int N){
    int num=N;
    int cont=0;
    for(int i=0; i<N; i++){
        fwrite(&num, sizeof(int), 1, pFile);
        num--;
        cont++;
    } return cont;
}

int *recupera(FILE *pFile){
    int ler;
    fseek(pFile, 0, SEEK_END);
    int pos=ftell(pFile)/sizeof(int);
    rewind(pFile);

    int *v=malloc(sizeof(int)*pos);
 
        fread(v, sizeof(int)*pos, 1, pFile);
    
return v;
}

void exibe_vetor(int *v, int N){
    for(int i=0; i<N; i++){
        printf("[%d] ", *(v+i));
    }
}

int modifica(FILE *pFile, int M){
    int comp;
    int cont=0;
    fseek(pFile, 0, SEEK_END);
    int pos=ftell(pFile)/sizeof(int);

    if(M<0||M>pos)return -1;
    fseek(pFile, -M*sizeof(int), SEEK_END);
    while((fread(&comp, sizeof(int), 1, pFile))==1){
        if(comp%2==0){
            fseek(pFile, -1*sizeof(int), SEEK_CUR);
            comp=comp*2;
            fwrite(&comp, sizeof(int),1,pFile);
        }
        cont++;
    }return cont;
}

void recupera_exibe(FILE *pFile){
    int num;
    rewind(pFile);
    while(fread(&num, sizeof(int), 1, pFile)==1){
        printf("[%d] ", num);
    }
}

int main(){
FILE *pFile;
int i, N, M, num, mod, *vetor;
char nome_arquivo[100];
printf("Informe o nome do arquivo a ser criado: ");
gets(nome_arquivo);
printf("Informe um numero positivo: ");
scanf("%d",&N);
pFile = fopen (nome_arquivo , "wb+");
if (!pFile){ printf("Erro na criacao do arquivo...");
return -1;
}
if (grava(pFile, N)!=N){
printf("Erro na gravacao do arquivo...");
return -1;
}
vetor=recupera(pFile);
if(vetor==NULL){
printf("Erro na recuperacao de dados do arquivo...");
return -1;
}
exibe_vetor(vetor,N);
printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: "); scanf("%d",&M);
mod=modifica(pFile,M);
if(mod==-1){
printf("Valor de M fora do intervalo permitido...");
return -1;
}
if(mod!=M){ printf("Erro de leitura e/ou gravacao no arquivo...");
return -1;
}
recupera_exibe(pFile);
fclose (pFile);


    return 0;
}