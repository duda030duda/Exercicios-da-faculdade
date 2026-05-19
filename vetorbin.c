#include <stdio.h>
#include <string.h>



int main(){
char frase[80];
char comp[80];
int i=0;
scanf("%s", frase);
FILE *arq=fopen("arq.txt","r");

while(fscanf(arq, "%[A-Z a-z]^'\n", comp)==1){
    if(strcmp(frase,comp)==0) return 1;
    i++;
}
printf("Está na linha %d", i);

    return 0;
}