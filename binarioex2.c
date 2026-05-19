#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome [100];
    double nota[3];
    double media;
}TAluno;




int main(){
    int q;
    FILE *arq=fopen("alunos.dat","wb+");
    printf("Quantos alunos são?\n");
    scanf("%d", &q);

    TAluno *v= malloc(sizeof(TAluno)*q);

    for(int i=0; i<q; i++){
        printf("Qual é o nome do aluno %d\n", i+1);
        scanf("%s", (v+i)->nome);
        printf("Quais são as notas?\n");
        scanf("%lf %lf %lf", &(v+i)->nota[0], &(v+i)->nota[1], &(v+i)->nota[2]);
        (v+i)->media= ((v+i)->nota[0]+ (v+i)->nota[1]+ (v+i)->nota[2])/3;
        fwrite((v+i),sizeof(TAluno), 1, arq);
    }
    free(v);
    fclose(arq);
    return 0;
}