#include<stdio.h>

void gerenciarClientes()
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
        printf("Voce chegou na pagina de Cadastro de cliente\n");
        break;
    case 'L':
    case 'l':
        system("cls");
        printf("Voce chegou na pagina de Lista de clientes\n");
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
        gerenciarClientes();
    }
    return 0;
}

void gerenciarContas()
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
        printf("Voce chegou na pagina de Cadastro de conta para um cliente\n");
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
        gerenciarContas();
    }
    return 0;
}

void sair()
{
    printf("Voce escolheu sair do do programa. Ate mais.\n");
    return 0;
}


int main()
{
    char opcaoMenu='X';

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
            gerenciarClientes();
            break;
        case 'T':
        case 't':
            system("cls");
            gerenciarContas();
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
