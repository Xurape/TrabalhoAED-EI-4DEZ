#define MAX_EQUIPAMENTOS 50000
#define MAX_APLICACOES 50000
#define MAX_PLACASDEREDE 50000

int equipamentos_id = 0;
int aplicacoes_id = 0;
int placasderede_id = 0;

/**
 *
 * @brief Este ficheiro define-nos a estrutura de dados que será utilizada para guardar o dados inseridos pelo utilizador.
 *
 */
typedef struct Equipamentos
{
    int tipo;
    int garantia;
    int ram;

    char departamento[100];
    char sistemaoperativo[50];

    struct Aquisicao
    {
        int dia;
        int mes;
        int ano;
    } aquisicao;

    struct CPUs
    {
        char cpu[50];
        float ghz;
    } cpus;

    struct Discos
    {
        char nome[50];
        char tipo[10];
        int capacidade;
    } discos;

} Equipamento;

typedef struct Rede
{
    int id;
    char ip[255];
    char netmask[255];   
    char broadcast[255]; 
} Rede;

typedef struct Aplicacoes
{
    int id;
    char designacao[50];
    char versao[50];

    struct Validade
    {
        int dia;
        int mes;
        int ano;
    } validade;

} Aplicacoes;

Equipamento equipamento[MAX_EQUIPAMENTOS] = {'\0'};
Rede rede[MAX_PLACASDEREDE] = {'\0'};
Aplicacoes aplicacoes[MAX_APLICACOES] = {'\0'};