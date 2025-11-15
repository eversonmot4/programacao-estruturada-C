//Atividade Extra - Operadores e Estruturas Condicionais 03/05/2024

/* //PRIMEIRA QUESTÃO-----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    float raio, n_pi = 3.14;
    
int main() {
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    printf("Diâmetro: %.2f\n", 2 * raio);
    printf("Perímetro: %.2f\n", 2 * n_pi * raio);
    printf("Área: %.2f\n", n_pi * raio * raio);

    return 0;
} */
/* //SEGUNDA QUESTÃO-----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    int a, b, c;
    
int main() {
    printf("Digite o primeiro cateto /(inteiro diferente de zero)/: ");
      scanf("%d", &a);
    printf("\nDigite o segundo cateto inteiro maior que o primeiro: ");
      scanf("%d", &b);
    printf("\nDigite a hipotenusa inteiro maior que os anteriores: ");
      scanf("%d", &c);

        if(a == 0 || b == 0 || c == 0) {
            printf("\nOs valores devem ser diferentes de zero.");
            return 1;
        } else if((a >= c) || (a >= b) || (b >= c)){
             printf("\nPor favor, informe corretamente os valores.");
             return 1;
        }
    if(a * a + b * b == c * c) {
        printf("Os valores %d, %d, %d formam um triângulo retângulo.\n", a, b, c);
          } else{
             printf("Os valores %d, %d, %d não formam um triângulo retângulo.\n", a, b, c);
    }
    return 0;
} */
/* //TERCEIRA QUESTÃO-------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota1, nota2, media;
    
    printf("Digite a nota da primeira prova: ");
      scanf("%f", &nota1);
    printf("Digite a nota da segunda prova: ");
      scanf("%f", &nota2);
      
    media = (nota1 + nota2) / 2;
    
    if (media >= 7) {
        printf("\nParabéns, você foi aprovado!");
    }  else if (media >= 4) {
        printf("\nVocê ficou de recuperação.");
    }  else {
        printf("\nQue pena, você foi reprovado."); // Corrigimos o texto para indicar reprovação
    }

    return 0;
} */
/*QUARTA QUESTÃO-------------------------------------------------------------------
a) Para alunos que tiverem mais de 15 anos e nota maior que 6,0:
    (idade > 15 && nota > 6.0)
b) Para alunos que tiverem mais de 17 anos, nota maior que 6,0, e pelo menos R$ 150,00 para gastar:
    (idade > 17 && nota > 6.0 && dinheiro >= 150.0)
c) Para alunos que tiverem mais de 15 anos ou pelo menos R$ 150,00 para gastar:     
    (idade > 15 || dinheiro >= 150.0)
d) Para alunos que tiverem pelo menos R$ 150,00 para gastar, além de terem mais de 17 anos ou nota maior que 7,0:
    (dinheiro >= 150.0 && (idade > 17 || nota > 7.0))
*/
/* //QUINTA QUESTÃO------------------------------------------------------------------
#include <stdio.h>
    int hora, minuto;
int main(){
    printf("Digite a hora de 0-23: ");
      scanf("%d", &hora);

    printf("Digite o minuto de 0-59: ");
      scanf("%d", &minuto);

    int hora_valida = (hora >= 0 && hora <= 23);
    int minuto_valida = (minuto >= 0 && minuto <= 59);

    if (hora_valida && minuto_valida) {
        printf("Hora e minuto válidos: %02d:%02d\n", hora, minuto);
    } else{
        if (!hora_valida) {
            printf("Hora inválida: %d. As horas devem estar entre 0 e 23.\n", hora);
        }
        if (!minuto_valida) {
            printf("Minuto inválido: %d. Os minutos devem estar entre 0 e 59.\n", minuto);
        }
    }
    return 0;
}*/
/* //SEXTA QUESTÃO----------------------------------------------------------------
#include <studio.h>
#include <stdlib.h>
    int dia, mes, ano;
int main() {
  printf("Digite o dia: ");
   scanf("%d", &dia);
  printf("Digite o mes: ");
   scanf("%d", &mes);
  printf("Digite o ano: ");
   scanf("%d", &ano);
  
  if(dia > 0 && dia <= 31){
    if(mes == 2){
      if(ano % 4 == 0){
        if(ano%100 != 0 || (ano%100 == 0 && ano%400 == 0)){
            if(dia <= 29){
              printf("Data valida");
            }else{
              printf("Data invalida");
            }
        }else{
          if(dia <= 28){
            printf("Data valida");
          }else{
            printf("Data invalida");
          }
        }
      }
      else{
        if(dia <= 28){
          printf("Data valida");
        }else{
          printf( "Data invalida");
        }
      }
    }
    else if(mes > 0 && mes <= 12){
      if(ano > 0){
        printf("Data válida %d/%d/%d", dia, mes, ano);
      }
    }
    else{
      printf("Mes Invalido");
    }
  }else{
    printf("Dia inválido");
  }
  return 0;
} */