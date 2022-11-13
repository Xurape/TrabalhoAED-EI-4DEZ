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

    char *departamento;
    char *sistemaoperativo;

    struct Aquisicao 
    {
        int dia;
        int mes;
        int ano;
    } aquisicao;

    struct CPUs
    {
        char *cpu;
        float ghz;
    } cpus;

    struct Discos
    {
        char *nome;
        char *tipo;
        int capacidade;
    } discos;

    struct Rede
    {
        char *ip;
        char *netmask; // Máscara de rede
        char *gateway; // Broadcast address
    } rede;

} Equipamento;

Equipamento equipamento[MAX_EQUIPAMENTOS] = { '\0' };