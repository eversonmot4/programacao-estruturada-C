#include <stdio.h>
#include <string.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  char nome[30];
  char cpf[12];  
  char sexo;     
  Data nascimento;
} Pessoa;

void adicionar(Pessoa *pessoas, int *posicao) {
  printf("Digite o nome da pessoa: ");
  scanf("%s", pessoas[*posicao].nome);

  printf("Digite o CPF: ");
  scanf("%s", pessoas[*posicao].cpf);

  printf("Digite o Sexo: ");
  scanf(" %c", &pessoas[*posicao].sexo);

  printf("Digite a data de nascimento (dd/mm/aaaa): ");
  scanf("%d/%d/%d", &pessoas[*posicao].nascimento.dia,
        &pessoas[*posicao].nascimento.mes, &pessoas[*posicao].nascimento.ano);

  (*posicao)++;
}

void imprimir(Pessoa *pessoas, int *total) {
  printf("\nIMPRIMINDO\n");
  for (int i = 0; i < *total; i++) {
    printf("Nome: %s\n", pessoas[i].nome);
    printf("CPF: %s\n", pessoas[i].cpf);
    printf("Sexo: %c\n", pessoas[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", pessoas[i].nascimento.dia,
           pessoas[i].nascimento.mes, pessoas[i].nascimento.ano);
    printf("\n");
  }
}

int buscar(Pessoa *pessoas, int *total) {
  char cpf[12];
  printf("Digite o cpf para buscar: ");
  scanf("%s", cpf);

  for (int i = 0; i < *total; i++) {
    if (strcmp(cpf, pessoas[i].cpf) == 0) {
      return i;
    }
  }
  return -1;  
}

int compararDatas(Data d1, Data d2) {
  if (d1.ano > d2.ano) return -1;
  if (d1.ano < d2.ano) return 1;

  if (d1.mes > d2.mes) return -1;
  if (d1.mes < d2.mes) return 1;

  if (d1.dia > d2.dia) return -1;
  if (d1.dia < d2.dia) return 1;

  return 0;
}

void mais_velha_nova(Pessoa *pessoas, int *total) {
  int pos_velha = 0;
  int pos_nova = 0;

  for (int i = 0; i < *total; i++) {
    if (compararDatas(pessoas[pos_velha].nascimento, pessoas[i].nascimento) ==
        -1) {
      pos_velha = i;
    }

    if (compararDatas(pessoas[pos_nova].nascimento, pessoas[i].nascimento) ==
        1) {
      pos_nova = i;
    }
  }

  printf("A pessoa mais velha é %s.\n", pessoas[pos_velha].nome);
  printf("A pessoa mais nova é %s.\n", pessoas[pos_nova].nome);
}

void quantidade_aniversariantes(Pessoa *pessoas, int *total) {
  int qnt_aniversariantes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < *total; i++) {
    qnt_aniversariantes[pessoas[i].nascimento.mes - 1]++;
  }

  for (int i = 0; i < 12; i++) {
    printf("Existem %d aniversariantes no mes %d.\n", qnt_aniversariantes[i],
           i + 1);
  }
}

int main() {
  Pessoa pessoas[5];
  int quantidade = 0;
  adicionar(pessoas, &quantidade);
  adicionar(pessoas, &quantidade);
  imprimir(pessoas, &quantidade);
  int pos = buscar(pessoas, &quantidade);
  if (pos == -1) {
    printf("Cadastro não existe.\n");
  } else {
    adicionar(pessoas, &pos);
  }
}