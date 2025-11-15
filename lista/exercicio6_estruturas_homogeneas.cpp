#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//--------------------------------------------------------------------------------------------------------------------------------
/*PRIMEIRA QUESTAO: 
int main(){
    int vetor[10]={0,0,0,0,0,0,0,0,0,0};
    
    for(int i = 0; i < 10; i++){
        printf("%d",vetor[i]);
    }
    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*SEGUNDA QUESTAO: 
int main(){
    int vetor[20];
    srand(time(NULL));
    
    for(int i = 0; i < 20; i++){
        int num_rand = rand() % 10 + 1;
        vetor[i] = num_rand;
        printf("%d ",vetor[i]);
    }
    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*TERCEIRA QUESTAO: 
int main(){
    char string[10];
        
    printf("Escreva um nome: ");
    scanf("%s",string);
    
    for(int i = 11; i > 0; --i){
        printf("%c",string[i]);
    }
    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*QUARTA QUESTAO: 
int main(){
    
    int vetor[5] = {5, 7, 9, 14, 18};
    bool crescente = true;

    for(int i = 0; i < 4; i++) {
        if(vetor[i] > vetor[i + 1]) {
            crescente = false;
            break;
        }
    }

    if(crescente) {
        printf("Esta em ordem crescente.\n");
    } else {
        printf("Nao esta em ordem crescente.\n");
    }
    
    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*QUINTA QUESTAO: 
int main(){
    
    int vetor[] = {0, 1, 1, 0, 1};
    int num_Zero = 0;
    int num_Um = 0;

    for(int i = 0; i < 5; i++) {
        if(vetor[i] == 0) {
            num_Zero++;
        } else if(vetor[i] == 1) {
            num_Um++;
        }
    }

    if(num_Zero > num_Um) {
        printf("0 aparece com mais frequencia.\n");
    } else if(num_Um > num_Zero) {
        printf("1 aparece com mais frequencia.\n");
    } else {
        printf("0 e 1 aparecem com a mesma frequencia.\n");
    }

    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*SEXTA QUESTAO:
int main(){
    int matriz[3][3];
    int soma = 0;


    printf("Digite os elementos da matriz 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            soma += matriz[i][j];
        }
    }
    printf("A soma e: %d\n", soma);

    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*SETIMA QUESTAO: 
int main(){
    int matriz[5][5];
    bool eIdentidade = true;

    printf("Digite os elementos da matriz 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j && matriz[i][j] != 1) {
                eIdentidade = false;
                break;
            } else if (i != j && matriz[i][j] != 0) {
                eIdentidade = false;
                break;
            }
        }
        if (!eIdentidade) {
            break;
        }
    }
    if (eIdentidade) {
        printf("A matriz e uma matriz identidade.\n");
    } else {
        printf("A matriz nao e uma matriz identidade.\n");
    }
    
    return 0;
}*/
//--------------------------------------------------------------------------------------------------------------------------------
/*OITAVA QUESTAO: */
int main(){
    int matriz1[3][3]; 
    int matriz2[3][3];
    int resultado[3][3];

    printf("Digite os elementos da primeira matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("Matriz resultante da multiplicação:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//--------------------------------------------------