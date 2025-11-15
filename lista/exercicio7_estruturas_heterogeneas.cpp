#include <stdio.h>
#include <string.h>
/*CONDIÇÃO1: Informar o nome dos clientes maiores de idade.
  CONDIÇÃO2: Informar o nome dos clientes que moram no bairro Centro[6 caracteres].*/

typedef struct {
  int numero;
  char bairro[20];
  char rua[20];
  char cep[10];
} Endereco;

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  char nome[50];
  char cpf[12];
  char telefone[12];
  Data nascimento;
  Endereco endereco;
} Cliente;

int main(int argc, char const *argv[]) {
  Data hoje;
  hoje.dia = 9;
  hoje.mes = 8;
  hoje.ano = 2024;
  char condicao2[] = "Centro";

  Cliente clientes[2];
  for (int i = 0; i < 2; i++) {
    printf("\nDigite o nome do cliente %d: ",i + 1);
     scanf("%s", clientes[i].nome);
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
     scanf("%d/%d/%d", &clientes[i].nascimento.dia, 
          &clientes[i].nascimento.mes,
          &clientes[i].nascimento.ano);
    printf("Digite o nome do seu bairro:");
     scanf("%s", clientes[i].endereco.bairro);    
    printf("------------------------------------------------------");       
  }

  for (int i = 0; i < 2; i++) {
    int idade = hoje.ano - clientes[i].nascimento.ano;
    if (hoje.mes * 30 + hoje.dia <
        clientes[i].nascimento.mes * 30 + clientes[i].nascimento.dia) {
      idade = idade - 1;
      
      if (idade >= 18) {
        printf("\nO cliente %s e maior de idade.",clientes[i].nome);
      }
      if (strcmp(clientes[i].endereco.bairro, condicao2) == 0){
        printf("\nO cliente %s mora no Centro.",clientes[i].nome);
      }
      
    }
  }
  
return 0;
}