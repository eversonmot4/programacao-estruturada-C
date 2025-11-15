#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

typedef struct {
  char nome[30];
  char cpf[12];
  char sexo;
  data nascimento;
} pessoa;

pessoa cadastros[100];
int posicao = 0;

void inserir_registro() {
  if (posicao >= 100) {
    printf("Banco de dados cheio.\n");
    return;
  }
  printf("Digite o nome: ");
  scanf("%s", cadastros[posicao].nome);
  printf("Digite seu sexo(M para masculino e F para Feminino): ");
  scanf(" %c", &cadastros[posicao].sexo);
  printf("Digite o seu cpf (apenas os numeros): ");
  scanf("%s", cadastros[posicao].cpf);
  printf("Digite a data do seu nascimento (dd/mm/aaaa): ");
  scanf("%d/%d/%d", &cadastros[posicao].nascimento.dia,
                    &cadastros[posicao].nascimento.mes, 
                    &cadastros[posicao].nascimento.ano);
  posicao++;
}

void total_M_F() {
  int masculino = 0;
  int feminino = 0;

  for(int i = 0; i < posicao; i++){
    if(cadastros[i].sexo == 'M'){
      masculino++;
    }
    if(cadastros[i].sexo == 'F'){
      feminino++;
    }
  }
  printf("Quantidade de pessoas do sexo feminino e %d",feminino);
  printf("\nQuantidade de pessoas do sexo masculino e %d",masculino); 
}

void buscar(char cpf[]) {
  for(int i = 0; i < posicao; i++) {
    if (strcmp(cpf, cadastros[i].cpf) == 0) {
      printf("Nome: %s\n", cadastros[i].nome);
      printf("CPF: %s\n", cadastros[i].cpf);
      printf("Sexo: %c\n", cadastros[i].sexo);
      printf("Data de nascimento: %d/%d/%d\n", 
            cadastros[i].nascimento.dia,
            cadastros[i].nascimento.mes, 
            cadastros[i].nascimento.ano);
      return;
    }
  }
  printf("Pessoa nao foi encontrada.\n");
}

void buscarData() {
    data busc;

    printf("Digite a data que deseja para procurar as pessoas (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&busc.dia,
                     &busc.mes, 
                     &busc.ano);

    bool encontrou = false; 
    int busc_total = busc.ano * 365 + busc.mes * 30 + busc.dia;

    for(int i = 0; i < posicao; i++) {
        int nasc_total = cadastros[i].nascimento.ano * 365 
                       + cadastros[i].nascimento.mes * 30 
                       + cadastros[i].nascimento.dia;

        if(busc_total == nasc_total){
          printf("A pessoa e %s",cadastros[i].nome);
          encontrou = true;
        }
    }
    if (!encontrou){
      printf("Nenhuma pessoa com essa data de nascimento.\n");
    }
}   

void pessoas_entre_datas() {
    data antiga;
    data recente;
    int quantidade_p = 0;

    printf("Digite a data recente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&recente.dia,
                     &recente.mes, 
                     &recente.ano);

    printf("Digite a data antiga (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&antiga.dia,
                     &antiga.mes, 
                     &antiga.ano);

    int limite_antiga = antiga.ano * 365 + antiga.mes * 30 + antiga.dia;
    int limite_recente = recente.ano * 365 + recente.mes * 30 + recente.dia;

    for(int i = 0; i < posicao; i++){
        int nasc = cadastros[i].nascimento.ano * 365 +
                   cadastros[i].nascimento.mes * 30 +
                   cadastros[i].nascimento.dia;

        if (nasc >= limite_antiga && nasc <= limite_recente) {
            quantidade_p++;
        }
    }

    printf("Existem %d nascimentos entre as datas %d/%d/%d e %d/%d/%d\n", 
        quantidade_p, 
        antiga.dia, antiga.mes, antiga.ano, 
        recente.dia, recente.mes, recente.ano);
}

int menu() {
  int opc;
  printf("\n\n======= MENU =======\n");
  printf("1 - Registrar nascimento\n");
  printf("2 - Buscar CPF\n");
  printf("3 - Exiba o total de pessoas do sexo feminino e masculino\n");
  printf("4 - Procurar pessoa pela data de nascimento\n");
  printf("5 - Verificar numero de pessoas entre duas data\n");
  printf("0 - Sair\n");
  printf("\nDigite a opcao: ");
  scanf("%d", &opc);
  return opc;
}

int main(int argc, char const *argv[]){
  char cpf[12];
  int opc = -1;
  while(opc != 0) {
    opc = menu();

    switch (opc) {
      case 1:
        inserir_registro();
        break;
      case 2:
        printf("Digite o CPF que deseja encontrar: ");
        scanf("%s", cpf);
        buscar(cpf);
        break;
      case 3:
        total_M_F();
        break;
      case 4:
        buscarData();
        break;  
      case 5: 
        pessoas_entre_datas();
        break;  
      case 0:
        printf("Ate mais\n");
        break;
      default:
        printf("Opcao invalida\n");
        break;
    }
  }

  return 0;
}
