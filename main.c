#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

T_Endereco enderecos[5000];
T_Cliente clientes[5000];
/** int *teste;
teste = (int*) malloc(5000*sizeof(int));  **/
T_Conta contas[5000];
int totalClientesCadastrados = 0;

void menuClientes()
{
    char opcaoCliente='X';
    printf("============ Gerenciar Clientes ============\n");
    printf("Digite um comando para prosseguir:\n");
    printf("C - Cadastrar um cliente\n");
    printf("L - Listar todos os clientes cadastrados\n");
    printf("B - Buscar cliente ja¡ cadastrado\n");
    printf("A - Atualizar um cliente cadastrado\n");
    printf("E - Excluir um cliente cadastrado\n");
    printf("V - Voltar\n");
    scanf(" %c", &opcaoCliente);

    switch(opcaoCliente)
    {
    case 'C':
    case 'c':
        system("cls");
        cadastrarCliente();
        break;
    case 'L':
    case 'l':
        system("cls");
        listarTodosClientes();
        break;
    case 'B':
    case 'b':
        system("cls");
        printf("Voce chegou na pagina de Busca de clientes\n");
        break;
    case 'A':
    case 'a':
        system("cls");
        printf("Voce chegou na pagina de Editar clientes\n");
        break;
    case 'E':
    case 'e':
        system("cls");
        printf("Voce chegou na pagina de Excluir de clientes\n");
        break;
    case 'V':
    case 'v':
        system("cls");
        main();
        break;
    default:
        printf("Digite uma opcao valida\n");
        menuClientes();
    }
    return 0;
}

void menuContas()
{
    char opcaoContas;
    printf("============== Gerenciar Contas ==============\n");
    printf("Digite um comando para prosseguir:\n");
    printf("R - Listagem de todas as contas cadastradas\n");
    printf("C - Cadastrar uma conta para um cliente\n");
    printf("L - Listar todas as contas de um cliente\n");
    printf("S - Realizar um saque em uma conta\n");
    printf("D - Realizar um deposito em uma conta\n");
    printf("T - Realizar transferencia entre contas\n");
    printf("E - Exibir extrato de uma conta\n");
    printf("V - Voltar\n");
    scanf(" %c", &opcaoContas);

    switch(opcaoContas)
    {
    case 'R':
    case 'r':
        system("cls");
        printf("Voce chegou na pagina de Listagem de todas as contas cadastradas\n");
        break;
    case 'C':
    case 'c':
        system("cls");
        cadastrarConta();
        break;
    case 'L':
    case 'l':
        system("cls");
        printf("Voce chegou na pagina de Listar todas as contas de um cliente\n");
        break;
    case 'S':
    case 's':
        system("cls");
        printf("Voce chegou na pagina de Realizar um saque em uma conta\n");
        break;
    case 'D':
    case 'd':
        system("cls");
        printf("Voce chegou na pagina de Realizar um deposito em uma conta\n");
        break;
    case 'T':
    case 't':
        system("cls");
        printf("Voce chegou na pagina de Realizar transferencia entre contas\n");
        break;
    case 'E':
    case 'e':
        system("cls");
        printf("Voce chegou na pagina de Exibir extrato de uma conta\n");
        break;
    case 'V':
    case 'v':
        system("cls");
        main();
        break;
    default:
        printf("Digite uma opcao valida.\n");
        menuContas();
    }
    return 0;
}

void sair()
{
    printf("Voce escolheu sair do do programa. Ate mais.\n");
    return 0;
}

void cadastrarClienteNoVetor(T_Cliente *clientes, int tamanho, T_Cliente cliente)
{
    if(totalClientesCadastrados >= tamanho)
    {
        clientes = realloc(clientes, tamanho+1);
    }
    clientes[totalClientesCadastrados] = cliente;
    totalClientesCadastrados++;
}

listarTodosClientes()
{
    FILE * arquivocliente;
    char linha [5000];
    int i;

    arquivocliente = fopen ("CadastroCliente.txt", "r+");
    if (arquivocliente == NULL) perror ("Deu penis ao abrir arquivo");
    else
    {
        while(!feof(arquivocliente)){
            fgets(linha, 5000, arquivocliente);
            printf("%s", linha);
        }
        printf("\n\n");
        fclose (arquivocliente);
    }
    menuClientes();
}


void cadastrarCliente()
{
    FILE *arquivocliente;
    srand(time(NULL));
    int i=1;
    int numeroClientes = 0;

    arquivocliente = fopen("CadastroCliente.txt","a+");

    printf ("\n===== CADASTRO DE CLIENTES ===== \n");
    printf ("\nQuantos clientes deseja cadastrar? ");
    scanf ("%d", &numeroClientes);

    if(arquivocliente != NULL)
    {
        for (i=1; i<=numeroClientes; i++)
        {

            clientes[i].codigoCliente = rand()%100000;
            printf ("NOME: ");
            scanf(" %[^\n]s",clientes[i].nome);
            printf ("CPF: ");
            scanf (" %[^\n]s",clientes[i].cpfcnpj);
            printf ("TELEFONE: ");
            scanf (" %[^\n]s", clientes[i].telefone);
            printf ("ENDERECO\n");
            printf ("Logradouro: ");
            scanf (" %[^\n]s", clientes[i].endereco.logradouro);
            printf ("Complemento: ");
            scanf (" %[^\n]s", clientes[i].endereco.complemento);
            printf ("CEP: ");
            scanf (" %[^\n]s", clientes[i].endereco.cep);
            printf ("BAIRRO: ");
            scanf (" %[^\n]s", clientes[i].endereco.bairro);
            printf ("CIDADE: ");
            scanf (" %[^\n]s", clientes[i].endereco.cidade);
            printf ("ESTADO(UF): ");
            scanf (" %[^\n]s", clientes[i].endereco.estado);

            fprintf(arquivocliente, "CODIGO: %d; NOME: %s;CPF: %s;TELEFONE: %s;Logradouro: %s;Complemento: %s;CEP: %s;BAIRRO: %s;CIDADE: %s;ESTADO(UF): %s;\n",
                    clientes[i].codigoCliente, clientes[i].nome, clientes[i].cpfcnpj, clientes[i].telefone, clientes[i].endereco.logradouro,
                    clientes[i].endereco.complemento, clientes[i].endereco.cep, clientes[i].endereco.bairro, clientes[i].endereco.cidade,
                    clientes[i].endereco.estado);

            printf ("\n*-- Cliente cadastrado com sucesso !!!--*\n\n");
        }
    }
    else
    {
        printf("Falha ao salvar cliente\n");
    }

    fclose(arquivocliente);


}

void cadastrarConta()
{
    FILE *arquivoconta;
    srand(time(NULL));
    int i=1;
    int numeroContas = 0;

    arquivoconta = fopen("CadastroConta.txt","a+");

    printf ("\n===== CADASTRO DE CONTAS ===== \n");
    printf ("\nQuantas contas deseja cadastrar? ");
    scanf ("%d", &numeroContas);

    for (i=1; i<=numeroContas; i++)
    {

        contas[i].codigoConta = rand()%100000;
        printf ("AGENCIA: ");
        scanf("%d", contas[i].agencia);
        printf ("SALDO: ");
        scanf("%f", contas[i].saldo);

        fprintf(arquivoconta, "AGENCIA: %d; CODIGO DA CONTA: %d;SALDO: %f;\n",
                contas[i].agencia,contas[i].codigoConta, contas[i].saldo);
    }
    fclose(arquivoconta);
    printf ("\n*-- Conta cadastrada com sucesso !!!--*\n\n");

}

int main()
{
    char opcaoMenu;

    do
    {
        printf("Digite um comando para prosseguir:\n");
        printf("C - Gerenciar Clientes\n");
        printf("T - Gerenciar Contas\n");
        printf("S - Sair\n");

        scanf(" %c", &opcaoMenu);

        switch(opcaoMenu)
        {
        case 'C':
        case 'c':
            system("cls");
            menuClientes();
            break;
        case 'T':
        case 't':
            system("cls");
            menuContas();
            break;
        case 'S':
        case 's':
            system("cls");
            sair();
            break;
        default:
            printf("Digite uma opcao valida.\n");
            main();
        }
    }
    while(opcaoMenu!='S' && opcaoMenu!='s');

    return 0;
}
