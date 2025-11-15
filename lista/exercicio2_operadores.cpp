// Atividade - DATA: 12/04

/* 1. QUESTAO: Assinale V ou F para as afirmacoes abaixo.
a. (F) Os operadores logicos sao utilizados para realizar operacoes matematicas, como adicao, subtracao, multiplicacao e divisao.
b. (V) Os operadores de atribuicao sao usados para atribuir valores a variaveis, como o operador "=" em linguagens de programacao.
c. (F) Os operadores aritmeticos sao utilizados para comparar valores e expressoes, como ">", "<", ">=" e "<=".
d. (V) Os operadores logicos sao utilizados para combinar ou alterar a logica de expressoes booleanas, como "AND", "OR" e "NOT".
*/

// 2. QUESTAO -> DICA PARA A MATERIA: usar float;
#include <stdio.h>
#include <math.h>
    float num1;
int main(){
    printf("Insira um valor em graus Fahrenheit: ");
    scanf("%f",&num1);
    
    printf("A soma: %.2f",((num1-32)*5)/9);
    return 0;
}
//3. QUESTAO:
#include <stdio.h>
#include <math.h>
    float num1;
    float num2;
int main(){
    printf("Insira um numero: \n");
    scanf("%f",&num1);
    printf("Insira o segundo numero: \n");
    scanf("%f",&num2);
    	if(num1>num2){
			printf("%.2f",num1);
		}
		if(num1<num2){
			printf("%.2f",num2);
		}
		if(num1==num2){
			printf("Valores iguais");
		}
	return 0;
}
//4. QUESTAO: SENO = sin(), COSENO = cos();
#include <stdio.h>
#include <math.h>
    float num1;
    float num2;
int main(){
    printf("Insira um numero: \n");
    scanf("%f",&num1);
    printf("Insira outro numero: \n");
    scanf("%f",&num2);

    printf("Numero 0 - FALSE, 1 - TRUE\nA: %.2f \n",num1 + num2);
    printf("B: %.2f \n",num1 * pow(num2,2));
    printf("C: %.2f \n",pow(num1,2));
    printf("D: %.2f \n",sqrt(pow(num1,2) + pow(num2,2)));
    printf("E: %.2f \n",sin(num1 - num2));
    printf("F: %.2f \n",abs(num1));

    return 0;
}