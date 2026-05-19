#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct { 
char nome[30];
int idade;
} Tpessoa;

int grava(FILE *arq, int N){
    Tpessoa pessoa;
    int cont=0;
    for(int i=0; i<N; i++){
        scanf("%s %d", pessoa.nome, &pessoa.idade);
        if(fwrite(&pessoa, sizeof(Tpessoa), 1, arq)==1)
        cont+=1;
    }
    return cont;
}

int modifica(FILE *pFile, int   M, int idade){
    Tpessoa pessoa;
    fseek(pFile, 0, SEEK_END);
    int pos=(ftell(pFile)/sizeof(Tpessoa));

    if(pos<M||M<1)return-1;
    
    fseek(pFile, (M-1)*sizeof(Tpessoa), SEEK_SET);
    if(fread(&pessoa, sizeof(Tpessoa), 1, pFile)!=1)return 0;
    pessoa.idade=idade;
    fseek(pFile, (M-1)*sizeof(Tpessoa), SEEK_SET);
    if(fwrite(&pessoa, sizeof(Tpessoa), 1, pFile)!=1)return 0;
    return 1;
}

void exibe(FILE *pFile){
    Tpessoa pessoa;
    rewind (pFile);
    while(fread(&pessoa, sizeof(Tpessoa), 1, pFile)==1){
        printf("Nome: %s, idade: %d", pessoa.nome, pessoa.idade);
    }
}


int main()
{
FILE *pFile;
int N, M, mod, idade;
char nome_arquivo[101];
fgets(nome_arquivo,100,stdin); //nome do arquivo a ser criado
nome_arquivo[strlen(nome_arquivo)-1]='\0';
scanf("%d",&N); //numero de pessoas desejado
pFile = fopen (nome_arquivo , "wb+");
if (!pFile){ printf("Erro na criacao do arquivo...");
return -1;
}
if (grava(pFile,N)!=N){
printf("Erro na gravacao do arquivo...");
return -1;
}
scanf("%d",&M); //numero correspondente a ordem de entrada da pessoa que se deseja alterar a idade
scanf("%d",&idade); //valor da idade a ser atualizado para a M-ésima pessoa
mod=modifica(pFile,M,idade);
if(mod==-1){
printf("Valor de M fora do intervalo permitido...");
return -1;
}
if(mod==0){ printf("Erro de leitura e/ou gravacao no arquivo...");
return -1;
}
exibe(pFile);
fclose (pFile);
return 0;
}