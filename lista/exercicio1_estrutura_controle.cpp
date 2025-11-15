//EXERCICIO - ESTRUTURA DE DADOS 16/04/24
#include <stdio.h>
#include <math.h>
    int valor1, valor2, num_mac, sexo;
    float altura, l1, l2, l3;
int main(){
    printf("GABARITO - 1 QUESTAO:");
    printf("\na: V;"); //TRUE
    printf("\nb: F;"); //FALSE
    printf("\nc: V;"); //TRUE
    printf("\nd: F."); //FALSE
//SEGUNDA QUESTAO:   
    printf("\nInsira um numero: ");
      scanf("%d",&valor1);
    printf("\nInsira um segundo numero: ");
      scanf("%d",&valor2);
         if(valor1 > valor2){
             printf("\nO numero %d e maior.",valor1);
         }else if(valor1<valor2){
             printf("\nO numero %d e maior.",valor2);
         } else{
             printf("\nValores iguais.");
         }
//TERCEIRA QUESTAO:        
    printf("\n\nBom dia, senhor.\nQuantas maças voce deseja comprar? ");
      scanf("%d",&num_mac);
        if(num_mac >= 12){
            printf("\nO preço total e R$%.2f",(0.25 * num_mac));
        }else{
            printf("\nO preço total e R$%.2f",(0.30 * num_mac));
        }
//QUARTA QUESTAO: 
    printf("\n\nVamos calcular seu IMC?\nMe diga sua altura? ");
      scanf("%f",&altura);
    printf("\nVoce e homem ou mulher?\n1• homem, \n2• mulher.\n- ");
      scanf("%d",&sexo);
    switch(sexo){
        case 1: printf("Seu peso ideal e %.2fkg.",((72.7 * altura) - 58));
            break;
        case 2: printf("Seu peso ideal e %.2fkg.",((62.1 * altura) - 44.7));
            break;
        default: printf("Informações invalidas!");
            break;
    }
//QUINTA QUESTAO:
    printf("\n\nVoce esta em dúvida o nome de um triangulo?\nInforme a medida dos lados;\nLado 1= ");
      scanf("%f",&l1);
    printf("\nLado 2= ");
      scanf("%f",&l2);
    printf("\nLado 3= ");  
      scanf("%f",&l3);
    if(l1==l2){
        printf("\nE um triangulo isocele.");
    } else if(l1==l2==l3){
        printf("\nE um triangulo e equilatero.");
    } else{
        printf("\nE um triangulo escaleno.");
    }
    printf("\n\nFim do exercicio.");
   return 0;
}