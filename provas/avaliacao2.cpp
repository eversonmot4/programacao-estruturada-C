#include <stdio.h>
#include <stdlib.h>
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
    char cpf[12]; 
    char sexo;    
    data nascimento;
} pessoa;

void inserir_registro(pessoa *cadastros, int *posicao) 
{
    if ((*posicao) >= 100)
    {
        printf("\nBanco de dados cheio.");
        return;
    }
    printf("Digite o nome da pessoa: ");
    scanf("%s", cadastros[*posicao].nome);
    printf("Digite o CPF: ");
    scanf("%s", cadastros[*posicao].cpf);
    printf("Digite o Sexo (M/F): ");
    scanf(" %c", &cadastros[*posicao].sexo);
    printf("Digite a data de nascimento (dia/mes/ano): ");
    scanf("%d/%d/%d", &cadastros[*posicao].nascimento.dia,
          &cadastros[*posicao].nascimento.mes, &cadastros[*posicao].nascimento.ano);
    (*posicao)++;
}

void total_M_F(pessoa *cadastros, int *posicao) 
{
    int masculino = 0;
    int feminino = 0;

    for (int i = 0; i < *posicao; i++)
    {
        if (cadastros[i].sexo == 'M') 
        {
            masculino++;
        }
        if (cadastros[i].sexo == 'F') 
        {
            feminino++;
        }
    }
    printf("Quantidade de pessoas do sexo feminino e %d\n", feminino);
    printf("Quantidade de pessoas do sexo masculino e %d\n", masculino);
}

void buscar(char cpf[], pessoa *cadastros, int *posicao) 
{
    for (int i = 0; i < *posicao; i++)
    {
        if (strcmp(cpf, cadastros[i].cpf) == 0)
        {
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

void buscar_Data(pessoa *cadastros, int *posicao) 
{
    data busc;

    printf("Digite a data que deseja para procurar as pessoas (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &busc.dia,
          &busc.mes,
          &busc.ano);

    bool encontrou = false;
    for (int i = 0; i < *posicao; i++)
    {
        int data_bus = busc.ano * 365 + busc.mes * 30 + busc.dia;
        int data_nasc = cadastros[i].nascimento.ano * 365 + cadastros[i].nascimento.mes * 30 + cadastros[i].nascimento.dia;

        if (data_bus == data_nasc) 
        {
            printf("A pessoa e %s\n", cadastros[i].nome);
            encontrou = true;
        }
    }
    if (encontrou == false)
    {
        printf("Nenhuma pessoa com essa data de nascimento.\n");
    }
}

void pessoas_entre_datas(pessoa *cadastros, int *posicao) 
{
    data antiga;
    data recente;
    int quantidade_p = 0;

    printf("Digite a data antiga (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &antiga.dia,
          &antiga.mes,
          &antiga.ano);
    printf("Digite a data recente (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &recente.dia,
          &recente.mes,
          &recente.ano);

    for (int i = 0; i < *posicao; i++)
    {
        int data_antiga = antiga.ano * 365 + antiga.mes * 30 + antiga.dia;
        int data_recente = recente.ano * 365 + recente.mes * 30 + recente.dia;
        int data_nascimento = cadastros[i].nascimento.ano * 365 + cadastros[i].nascimento.mes * 30 + cadastros[i].nascimento.dia;

        if (data_nascimento >= data_antiga && data_nascimento <= data_recente)
        {
            quantidade_p++;
        }
    }
    printf("Existem %d nascimentos entre as datas %d/%d/%d e %d/%d/%d\n", quantidade_p, antiga.dia, antiga.mes,
           antiga.ano, recente.dia, recente.mes, recente.ano);
}

void editar_Cadastro(char cpf[], pessoa *cadastros, int *posicao) 
{
    for (int i = 0; i < *posicao; i++)
    {
        if (strcmp(cpf, cadastros[i].cpf) == 0)
        {
            printf("O cadastro encontrado foi: %s", cadastros[i].nome);
            printf("\nInsira o novo NOME: ");
            scanf("%s",cadastros[i].nome);
            printf("Insira o novo Sexo(M/F): ");
            scanf(" %c", &cadastros[i].sexo);
            printf("Insira a nova data de nascimento(dia/mes/ano): ");
            scanf("%d/%d/%d",
                  &cadastros[i].nascimento.dia,
                  &cadastros[i].nascimento.mes,
                  &cadastros[i].nascimento.ano);
            return;
        }
    }
    printf("Esse cadastro nao existe.\n");
}

void pessoa_mais_Velha_Nova(pessoa *cadastros, int *posicao) 
{
    if (*posicao == 0)
    {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }
    int indice_mais_nova = 0;
    int indice_mais_velha = 0;

    for (int i = 1; i < *posicao; i++)
    {
        int dias_mais_nova = cadastros[indice_mais_nova].nascimento.ano * 365 +
                             cadastros[indice_mais_nova].nascimento.mes * 30 +
                             cadastros[indice_mais_nova].nascimento.dia;

        int dias_mais_velha = cadastros[indice_mais_velha].nascimento.ano * 365 +
                              cadastros[indice_mais_velha].nascimento.mes * 30 +
                              cadastros[indice_mais_velha].nascimento.dia;

        int dias_atual = cadastros[i].nascimento.ano * 365 +
                         cadastros[i].nascimento.mes * 30 +
                         cadastros[i].nascimento.dia;

        if (dias_atual > dias_mais_nova)
        {
            indice_mais_nova = i;
        }
        if (dias_atual < dias_mais_velha)
        {
            indice_mais_velha = i;
        }
        if ((dias_atual == dias_mais_nova) && (dias_atual == dias_mais_velha))
        {
            printf("Todos nasceram no mesmo dia, mes e ano");
            return;
        }
    }

    printf("- Pessoa mais nova: %s\n", cadastros[indice_mais_nova].nome);
    printf("- Pessoa mais velha: %s\n", cadastros[indice_mais_velha].nome);
}

void quantidade_pessoas_mes(pessoa *cadastros, int *posicao) 
{
    int jan = 0, fev = 0, mar = 0, abr = 0, mai = 0, jun = 0, jul = 0, ago = 0, set = 0, out = 0, nov = 0, dez = 0;

    for (int i = 0; i < *posicao; i++)
    {
        switch (cadastros[i].nascimento.mes)
        {
        case 1:
            jan++;
            break;
        case 2:
            fev++;
            break;
        case 3:
            mar++;
            break;
        case 4:
            abr++;
            break;
        case 5:
            mai++;
            break;
        case 6:
            jun++;
            break;
        case 7:
            jul++;
            break;
        case 8:
            ago++;
            break;
        case 9:
            set++;
            break;
        case 10:
            out++;
            break;
        case 11:
            nov++;
            break;
        case 12:
            dez++;
            break;
        default:
            printf("Mes invalido para o registro: %s\n", cadastros[i].nome);
            break;
        }
    }
    printf("Quantidade de pessoas que aniversariam nos meses:\n");
    printf("- Janeiro: %d\n", jan);
    printf("- Fevereiro: %d\n", fev);
    printf("- Marco: %d\n", mar);
    printf("- Abril: %d\n", abr);
    printf("- Maio: %d\n", mai);
    printf("- Junho: %d\n", jun);
    printf("- Julho: %d\n", jul);
    printf("- Agosto: %d\n", ago);
    printf("- Setembro: %d\n", set);
    printf("- Outubro: %d\n", out);
    printf("- Novembro: %d\n", nov);
    printf("- Dezembro: %d\n", dez);
}

int menu() 
{
    int opc;
    printf("\n\n======= MENU =======\n");
    printf("1 - Registrar nascimento\n");
    printf("2 - Buscar CPF\n");
    printf("3 - Exiba o total de pessoas do sexo feminino e masculino\n");
    printf("4 - Procurar pessoa pela data de nascimento\n");
    printf("5 - Verificar numero de pessoas entre duas datas\n");
    printf("6 - Editar dados do cadastro\n");
    printf("7 - Exiba o nome da pessoa mais nova e da mais velha\n");
    printf("8 - Exiba a quantidade de pessoas que aniversariam em cada mes\n");
    printf("0 - Sair\n");
    printf("\nDigite a opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main(int argc, char const *argv[])
{
    pessoa cadastros[100];
    int posicao = 0;
    char cpf[12];
    int opc = -1;

    while (opc != 0)
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            inserir_registro(cadastros, &posicao);
            break;
        case 2:
            printf("Digite o CPF que deseja encontrar: ");
            scanf("%s", cpf);
            buscar(cpf, cadastros, &posicao);
            break;
        case 3:
            total_M_F(cadastros, &posicao);
            break;
        case 4:
            buscar_Data(cadastros, &posicao);
            break;
        case 5:
            pessoas_entre_datas(cadastros, &posicao);
            break;
        case 6:
            printf("Digite o CPF do cadastro que deseja editar: ");
            scanf("%s", cpf);
            editar_Cadastro(cpf, cadastros, &posicao);
            break;
        case 7:
            pessoa_mais_Velha_Nova(cadastros, &posicao);
            break;
        case 8:
            quantidade_pessoas_mes(cadastros, &posicao);
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