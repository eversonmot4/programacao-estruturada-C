/*Calcule a soma dos dígitos de um número inteiro positivo.
(Ex: para o número 123 a soma é 6, pois 1+2+3=6.)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num;
    int soma = 0;
    
    printf("Digite os dígitos: ");
     scanf("%d",&num);
     
    int num_temporario = num;
  
    while(num_temporario > 0){
        soma += num_temporario % 10; //(somo = soma + num_temporario) % 10;
        num_temporario /= 10;
    }
    printf("A soma dos digitos de %d e %d.\n", num, soma);
    
return 0;
}