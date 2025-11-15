#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    float n1, n2, n3, media;
    char nome[20];

    for(int i = 0; i < 10; i++){
        printf("Digite o nome do aluno: ");
         scanf("%s",nome);
        printf("Digite a primeira nota: ");
         scanf("%f",&n1);
        printf("Digite a segunda nota: ");
         scanf("%f",&n2);
        printf("Digite a terceira nota: ");
         scanf("%f",&n3);

        media = (n1 + n2 + n3) / 3;
        
        printf("\nNome do aluno: %s\nMédia das notas: %.2f\n\n", nome, media);
    }

    return 0;
}