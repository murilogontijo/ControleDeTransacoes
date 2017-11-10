void sair();
void gerenciarClientes();
void gerenciarContas();

typedef struct Endereco{
    char logradouro[50];
    char complemento[50];
    int cep;
    char bairro[50];
    char cidade[50];
    char estado[2];
}T_Endereco;

typedef struct Cliente{
    int codigo;
    char nome[50];
    int cpfcnpj;
    int telefone;
    T_Endereco endereco;
}T_Cliente;

typedef struct Conta{
    int agencia;
    int codigo;
    T_Cliente cliente;
    double saldo;
}T_Conta;
