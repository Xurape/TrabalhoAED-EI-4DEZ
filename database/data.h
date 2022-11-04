
/**
 *
 * Estrutura dos dados
 *
 */

typedef struct Equipamentos
{
    time_t datadeaquisicao;
    char *departamento;
    int garantia;

    struct CPUs
    {
        char *cpu;
        int ghz;
    };

    struct Discos
    {
        char *nome;
        char *tipo;
        int capacidade;
    };

    struct Rede
    {
        char *ip;
        char *netmask; // Máscara de rede
        char *gateway; // Broadcast address

    };

} Equipamento;