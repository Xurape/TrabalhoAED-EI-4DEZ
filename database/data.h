#define MAX_EQUIPAMENTOS 50000
#define MAX_APLICACOES   50000
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
    char sistemaoperativo[100];

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

    struct Rede
    {
        char ip[50];
        char netmask[50]; // Máscara de rede
        char gateway[50]; // Broadcast address
    } rede;

} Equipamento;

Equipamento equipamento[MAX_EQUIPAMENTOS] = { '\0' };