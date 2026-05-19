#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFILE, int N){
    int num=0;
    int cont=0;
    for(int i=0; i<N; i++){
        fwrite(&num+i,sizeof(int),1, pFILE);
        cont++;
    }
    return cont;
}

void *recupera(FILE *pFILE){
    int *vetor=malloc(sizeof(int)*N);
    fread(&num+i, )
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
if (!pFile){
printf("Erro na criacao do arquivo...");
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
printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: ");
scanf("%d",&M);
mod=modifica(pFile,M);
if(mod==-1){
printf("Valor de M fora do intervalo permitido...");
return -1;
}
if(mod!=M){
printf("Erro de leitura e/ou gravacao no arquivo...");
return -1;
}
recupera_exibe(pFile);
fclose (pFile);
return 0;
}