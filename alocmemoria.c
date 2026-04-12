#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
char *concatena(char *s1, char *s2){ //Concatenar duas strigs em uma nova
    int t1=0;
    int t2=0;
    int i=0;
    int j=0;
    int f=0;

while(*(s1+i)!='\0'){
 t1++;
 i++;
}
while(*(s2+j)!='\0'){
 t2++;
 j++;
}

    char *novastr=calloc((t1 + t2 +1), sizeof(char));
    if(novastr==NULL){
        return NULL;
    }

    for(int i=0; i<t1; i++){
        if(*(s1+i)!='\0'){
         *(novastr+i)=*(s1+i);
        }
          f+=1;
    }

    for(int j=0; j<t2; j++){
        if(*(s2+j)!='\0'){
            *(novastr+f+j)=*(s2+j);
        }
    }


return novastr;

}

int main(){

    char s3[]="Nada ";
    char s4[]="Minha Bala";

    char *p;
    p=concatena(s3, s4);

    for(int i=0; *(p+i)!='\0'; i++){
        printf("%c", *(p+i));
    }
        free(p);

    return 0;
}*/
/*
typedef struct _func{
        char nome[40];
        int ano_nasc;
        float renda;
}Tfunc;

void * inicializa (Tfunc *v, int f){
  v=malloc(f*(sizeof(Tfunc)));

    for (int i=0; i<f; i++){
        printf("Qual é o nome do funcionário? ");
        scanf("%s", &v[i].nome);

        printf("Qual é o ano de nascimento? ");
        scanf("%d", &v[i].ano_nasc);
     

        printf("Qual é a renda? ");
        scanf("%f", &v[i].renda);
      

    }
    return v;
}
void * inclui_novos (Tfunc *v, int f, int a){
    Tfunc*temp = realloc(v, (a+f)*(sizeof(Tfunc)));
        if(temp!=NULL){
            v=temp;
        }
        else printf("NULL");
      

        for (int i=f; i<a+f; i++){
        printf("Qual é o nome do funcionário? ");
        scanf("%s", &v[i].nome);

        printf("Qual é o ano de nascimento? ");
        scanf("%d", &v[i].ano_nasc);
     

        printf("Qual é a renda? ");
        scanf("%f", &v[i].renda);
      

    }
    return v;
}
void imprime (Tfunc *v, int a, int f){
    for(int i=0; i<f+a; i++){
        printf("Nome: %s\n", v[i].nome);
        printf("Ano de nascimento: %d\n", v[i].ano_nasc);
        printf("Renda: %f\n", v[i].renda);
    }

}

int main(){
    Tfunc *cadastro;
    int funcionarios, adicionais;
    printf("Quantos funcionários? ");
    scanf("%d", &funcionarios);
    cadastro=inicializa(cadastro, funcionarios);
    if (!cadastro)
        return -1;
    printf("Quantos funcionários a mais deseja adicionar? ");
    scanf("%d", &adicionais);
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro)
        return -1;
    imprime(cadastro, adicionais, funcionarios);
    
    free (cadastro);
    
    return 0;
}*/

int **aloca_linhas(int l){
   int **vp= malloc (sizeof(int *)*l);
     
return vp;
}
void aloca_colunas (int **vp, int l, int c){
    for(int i=0; i<l; i++){
        *(vp+i)=malloc(c*sizeof(int));
    }
}
void le_dados(int **vp, int l, int c){
    for(int i=0; i<l; i++){
        for (int j=0; j<c; j++){
            scanf("%d", &vp[i][j]);
        }
    }
}
void imprime_matriz(int **vp, int l, int c){
     for(int i=0; i<l; i++){
        for (int j=0; j<c; j++){
            printf("%d ", vp[i][j]);
        }
        printf("\n");
    }
}
void troca_linhas(int **vp, int l1, int l2){
    int *temp;
       temp=vp[l1];
       vp[l1]=vp[l2];
       vp[l2]=temp;
}

int main(){
    int **matriz;
    int lin, col;
    int linha1, linha2;
    puts("Qual o número de linhas? ");
    scanf("%d", &lin);
    matriz = aloca_linhas(lin);
    puts("Qual é o número de colunas? ");
    scanf("%d", &col);
    aloca_colunas(matriz, lin, col);
    printf("Quais são os valores do vetor? ");
    le_dados(matriz, lin, col);
    imprime_matriz(matriz, lin, col);
    printf("Qual é a primeira linha a ser trocada? ");
    scanf("%d", &linha1);
    printf("Qual é a segunda linha a ser trocada? ");
    scanf("%d", &linha2);
    troca_linhas(matriz, linha1, linha2);
    imprime_matriz(matriz, lin, col);


    return 0;
}

