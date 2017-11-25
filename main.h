void sair();
void menuClientes();
void menuContas();
void cadastrarCliente();
listarTodosClientes();

typedef struct endereco{
    char logradouro[100];
    char complemento[100];
    char cep[8];
    char bairro[100];
    char cidade[100];
    char estado[2];
}T_Endereco;

typedef struct cliente{
    int codigoCliente;
    char nome[100];
    char cpfcnpj[14];
    char telefone[20];
    T_Endereco endereco;
} T_Cliente;

typedef struct Conta{
    int agencia;
    int codigoConta;
    int codigoCliente;
    double saldo;
}T_Conta;
