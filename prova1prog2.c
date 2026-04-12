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


int main(){
    data matematica={10, 2000};
    data quimica={1, 1990};
    data comp={7, 1985};
    data fisica={7, 1970};

    curso mat={"Matemática", matematica, 400};
    curso quim={"Química", quimica, 600};
    curso com={"Ciência da Computação", comp, 700};
    curso fis={"Física", fisica, 800};

    long int negress=45;
    altera_curso(&mat, negress);

    printf("Alunos totais: %d\n", mat.egressos);

    int *tempo= dif_ano(2026, &matematica);

    printf("O curso de %s existe há %d anos.", mat.nome, *tempo);
   

    return 0;
}