#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char nome[100];
double nota[3];
double media;
} Taluno;

int main(){
    FILE *arq=fopen("alunos.dat", "w");
    Taluno aluno;

    while(scanf("%s", aluno.nome)!='\n');
    printf("Qual é o nome do aluno?\n");
    scanf("%s", aluno.nome);
    printf("Quais são as notas?\n");
    scanf("%lf lf lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
    aluno.media= (aluno.nota[0]+ aluno.nota[1]+ aluno.nota[2])/3;

    printf("nome: %s média: %ls\n", aluno.nome, &aluno.media);
    }
    fclose(arq);
    return 0;
}