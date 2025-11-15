#include <stdio.h>
#include <string.h>

typedef struct
{
  int dia;
  int mes;
  int ano;
} data;

typedef struct
{
  char nome[30];
  int qnt;
  float preco;
  data validade;
} produto;

produto produtos[100];
int posicao = 0;

bool validade_passou(data hoje, data validade)
{
  if (hoje.ano * 365 + hoje.mes * 30 + hoje.dia >
      validade.ano * 365 + validade.mes * 30 + validade.dia)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void inserir_produto()
{
  if (posicao >= 100)
  {
    printf("Banco de dados cheio.\n");
    return;
  }
  printf("Digite o nome do produto: ");
  scanf("%s", produtos[posicao].nome);
  printf("Digite a quantidade do produto: ");
  scanf("%d", &produtos[posicao].qnt);
  printf("Digite o preco do produto: ");
  scanf("%f", &produtos[posicao].preco);
  printf("Digite a validade do produto (dd/mm/aaaa): ");
  scanf("%d/%d/%d", &produtos[posicao].validade.dia,
        &produtos[posicao].validade.mes,
        &produtos[posicao].validade.ano);
  posicao++;
}

void buscar(char nome[])
{
  for (int i = 0; i < posicao; i++)
  {
    if (strcmp(nome, produtos[i].nome) == 0)
    {
      printf("Nome: %s\n", produtos[i].nome);
      printf("Quantidade: %d\n", produtos[i].qnt);
      printf("Preco: R$ %.2f\n", produtos[i].preco);
      printf("Validade: %d/%d/%d\n", produtos[i].validade.dia,
             produtos[i].validade.mes, produtos[i].validade.ano);
      return;
    }
  }
  printf("Produto nao encontrado\n");
}

float total_vendas = 0;
void vender(char nome[], int quantidade)
{
  data hoje;
  hoje.dia = 16;
  hoje.mes = 8;
  hoje.ano = 2024;

  for (int i = 0; i < posicao; i++)
  {
    if (strcmp(nome, produtos[i].nome) == 0)
    {
      if (quantidade <= produtos[i].qnt)
      {
        if (!validade_passou(hoje, produtos[i].validade))
        {
          float valor_venda = quantidade * produtos[i].preco;
          total_vendas += valor_venda;
          printf("Total da venda: R$ %.2f\n", valor_venda);
          produtos[i].qnt -= quantidade;
          return;
        }
        else
        {
          printf("Produto vencido\n");
          return;
        }
      }
      else
      {
        printf("Quantidade insuficiente\n");
        return;
      }
    }
  }
  printf("Produto nao encontrado\n");
}

float calcular_total()
{
  float total = 0;
  for (int i = 0; i < posicao; i++)
  {
    total += produtos[i].preco * produtos[i].qnt; // total = total + produtos[i].preco * produtos[i].qnt;
  }
  return total;
}

int menu()
{
  int opc;
  printf("\n\n======= MENU =======\n");
  printf("1 - Inserir produto\n");
  printf("2 - Buscar produto\n");
  printf("3 - Vender produto\n");
  printf("4 - Total no estoque\n");
  printf("0 - Sair\n");
  printf("\nDigite a opcao: ");
  scanf("%d", &opc);
  return opc;
}

int main(int argc, char const *argv[])
{
  char nome[30];
  float total = 0;
  int opc = -1;
  while (opc != 0)
  {
    opc = menu();

    switch (opc)
    {
    case 1:
      inserir_produto();
      break;

    case 2:
      printf("Digite o nome do produto: ");
      scanf("%s", nome);
      buscar(nome);
      break;

    case 3:
      int qunt;
      printf("Digite o nome do produto: ");
      scanf("%s", nome);
      printf("Digite a quantidade do produto: ");
      scanf("%d", &qunt);
      vender(nome, qunt);
      break;

    case 4:
      total = calcular_total();
      printf("O total no estoque e R$ %.2f\n", total);
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