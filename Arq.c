#include <stdio.h>

/*void contaVogais(FILE *arq){ //CONTA A QUANTIDADE DE CADA VOGAL NO ARQUIVO
    int c;//Variável que guarda o valor de fgetc
    int a=0, e=0, i=0, o=0, u=0; //Variáveis que guardam a quantidade de vogais
    while((c=fgetc(arq))!=EOF){
        if(c=='a'|| c=='A') a+=1;
        if(c=='e'|| c=='E') e+=1;
        if(c=='i'|| c=='I') i+=1;
        if(c=='o'|| c=='O') o+=1;
        if(c=='u'|| c=='U') u+=1;
    }

    printf("a=%d\n e=%d\n i=%d\n o=%d\n u=%d\n", a, e, i, o, u);

}*/

void letraM(FILE *in, FILE *out){ //ESCREVE EM OUTRO ARQUIVO EM LETRA MAIUSCULA
    int c;
    while((c=fgetc(in))!=EOF){
        if(c>='a' && c<='z'){
            c-=32;
        }
        fputc(c, out);
    }

}

int main(){

    char nome[15]; //Variável para guardar o nome do arquivo dado pelo usuário
    printf("Digite o nome do arquivo que deseja abrir:\n");
    scanf("%s",nome);

    char nome2[15];
    printf("Digite o nome do arquivo de saída:\n");
    scanf("%s", nome2);

FILE *arq;
    arq = fopen(nome, "r"); 
    if(arq == NULL){
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }

FILE *out;
    out = fopen(nome2, "w"); 
    if(out == NULL){
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }


/*contaVogais(arq);*/
letraM(arq, out);



fclose(arq);
fclose(out);
return 0;
}