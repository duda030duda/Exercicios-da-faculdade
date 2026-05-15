#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFILE, int N){
    
        for(int i=0; i<N; i++){
            int valor=i+1;
            fwrite(&valor, sizeof(int), 1, pFILE);
        }
return N;
}

int *recupera(FILE *pFILE){
    fseek(pFILE, 0, SEEK_END);
    long pos=ftell(pFILE);
    rewind(pFILE);

    int *v=malloc(1*pos);
    fread(v, sizeof(int), pos, pFILE);

    return v;
}

void exibe_vetor(int *vetor, int N){
    for (int i=0; i<N; i++){
        printf("[%d] ", vetor[i]);
    }
}

int modifica(FILE *pFILE, int M){
    rewind(pFILE);
    fseek(pFILE, -M*sizeof(int), SEEK_END);
    
    for(int i=0; i<M; i++){
        int num;
        fread(&num, sizeof(int), 1, pFILE);
        if(num%2==0){
            num*=2;
        fseek(pFILE, -1*sizeof(int), SEEK_CUR);
        fwrite(&num, sizeof(int), 1, pFILE);
        }

    } return M;
}

void recupera_exibe(FILE *pFILE){
    fseek(pFILE, 0, SEEK_END);
    long pos=ftell(pFILE);
    rewind(pFILE);

    int *v=malloc(1*pos);
    fread(v, sizeof(int), pos, pFILE);

    for (int i=0; i<pos/sizeof(int); i++){
        printf("[%d] ", v[i]);
    }
    printf("\n");
}


int main()
{
FILE *pFile;
int i, N, M, num, mod, *vetor;
char nome_arquivo[100];
printf("Informe o nome do arquivo a ser criado: ");
fgets(nome_arquivo, sizeof(nome_arquivo),stdin);
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
printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: "); 
scanf("%d",&M);
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