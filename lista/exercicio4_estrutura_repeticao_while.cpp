#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char nome[10];
    float nota1, nota2, nota3, media;
    char sair[] = "sair";

    while(1){
        printf("Digite o nome do aluno (ou 'sair' para encerrar): ");
        scanf("%s", nome);
        
        if(strcmp(nome, sair) == 0) {
            printf("Encerrado.");
            
            break;
        }
        printf("Digite a primeira nota: ");
         scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
         scanf("%f", &nota2);
        printf("Digite a terceira nota: ");
         scanf("%f", &nota3);

        media = (nota1 + nota2 + nota3) / 3;
        
        printf("\nNome do aluno: %s\nMédia das notas: %.2f\n\n", nome, media);
    }

    return 0;
}