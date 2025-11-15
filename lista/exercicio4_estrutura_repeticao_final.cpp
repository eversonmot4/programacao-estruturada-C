#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//-----------------------------------------------------------------
/*PRIMEIRA QUESTAO:
int main(int argc, char const argv[]){
	for(int i = 1; i <= 10; i++){
		printf("\n%d",i);
	}
		
return 0;
}*/
//----------------------------------------------------------------
/*SEGUNDA QUESTAO:
int main(int argc, char const argv[]){
	int i = 1;
	
	while(i <= 10){
		printf("\n%d",i);
		
		i++;
	}

return 0;
}*/
//----------------------------------------------------------------
/*TERCEIRA QUESTAO
int main(int argc, char const argv[]){
	int i = 1;
	
	do{
		printf("\n%d",i);
	}while(i <= 10);

return 0;
}*/
//----------------------------------------------------------------
/*QUARTA QUESTAO:
int main(int argc, char const argv[]){
	int soma = 0;
	
	for(int i = 0; i <= 100; i++){
		soma += i;
	}
		printf("A soma dos numeros de 1 a 100 e %d.",soma);
return 0;
}*/
//----------------------------------------------------------------
/*QUINTA QUESTAO:
int main(int argc, char const argv[]){
	int soma = 0;
	int i;
	
	while(i <= 100){
		soma += i;
		i += 2;
	}
		printf("A soma dos numeros impares de 1 a 100 e: %d", soma);
return 0;	
}*/
//----------------------------------------------------------------
/*SEXTA QUESTAO:
int main(int argc, char const argv[]){
	for(int i = 1;  i <= 10; i++){
		int resul = i * 5;
		printf("\n%d * %d = %d",5,i,resul);
	}
return 0;	
}*/
//----------------------------------------------------------------
/*SETIMA QUESTAO:
int main(int argc, char const argv[]){
	int num;
	int soma = 0;
	
	do{
		printf("Digite um numero: ");
			scanf("%d",&num);
		if(num >= 0){
			soma += num;
		}	
	}while(num >= 0);
		printf("A soma dos numeros e: %d",soma);
		
return 0;		
}*/
//----------------------------------------------------------------
/*OITAVA QUESTAO:
int main(){
	int soma = 0;
    int num;
	
	for(int i = 1; i <= 10; i++){
		printf("Digite o %d� numero: ",i);
		 scanf("%d",&num);
         soma += num;
	}
	printf("A soma dos numeros e: %d",soma);
return 0;
}*/
//---------------------------------------------------------------
/*NONA QUESTAO: calcular um numero pow(x,2) - FOR
int main(){
    int base, exp;
    
    printf("Digite uma base: ");
     scanf("%d",&base);
    printf("Digite o expoente: ");
     scanf("%d",&exp);
     
    for(int i = 0; i == exp; i){
        base *= exp;
        
        printf("O resultado e: %d", base);
    }
return 0;    
}*/
//---------------------------------------------------------------
/*DECIMA QUESTAO:
int main(){
    int num;
    int factorial = 1;
    
    printf("Digite um numero positivo: ");
    scanf("%d", &num);
    
    if(num < 0){
        printf("Nao existe fatorial de um numero negativo.\n");
    }else{
        for(int i = 1; i <= num; i++){
            factorial *= i;
        }
        printf("Fatorial de %d = %d\n", num, factorial);
    }
    return 0;
}*/
//--------------------------------------------------------------
/*DECIMA PRIMEIRA QUESTAO:
int main(){
    int numeros[10];
    int i, maior, menor;
    
    printf("Digite 10 números:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    maior = menor = numeros[0];
    
    for (i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    printf("O maior número digitado e: %d\n", maior);
    printf("O menor número digitado e: %d\n", menor);
return 0;
}*/
//--------------------------------------------------------------
/*DECIMA SEGUNDA:
int main() {
    printf("Numeros de 1 a 100 que sao múltiplos de 3 e 5:\n");

    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%d\n", i);
        }
    }
return 0;
}*/
//--------------------------------------------------------------
/*DECIMA TERCEIRA QUESTAO:
int main(){
    int key = 8765;
    int attempt;
    
    while(1){
        printf("\nType your password: ");
         scanf("%d",&attempt);
        
        if(attempt == key){
            printf("\nCorrect password.");
            break;
        }else{ 
            printf("\nIncorrect password. Try again.\n");
        }
    }
return 0;
}*/
//---------------------------------------------------------------
/*DECIMA QUARTA QUESTAO:*/
int main() {
    int numero;
    int pares = 0;
    int impares = 0;
    
    printf("Digite uma série de números inteiros (digite 0 para parar):\n");
    while (1) {
        scanf("%d", &numero);
        if (numero == 0) {
            break;
        }
        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    printf("Quantidade de números pares: %d\n", pares);
    printf("Quantidade de números ímpares: %d\n", impares);
    
    return 0;
}

//---------------------------------------------------------------
/*DECIMA QUINTA QUESTAO:
int main(){
    srand(time(NULL));
    int type_num;
    int random_num = rand() % 100 + 1;

    while(1){
        printf("\nDigite um numero: ");
         scanf("%d",&type_num);
        
        if(type_num == random_num){
            printf("\nVoce acertou o numero.");
          break;
        }else if(type_num < random_num){
            printf("\nE um numero maior.");
        }else{
			printf("\nE um numero menor.");
		}
    }
return 0;
}*/