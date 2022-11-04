
/**
 * 
 * Estrutura da base de dados
 * 
*/

typedef struct Equipamentos {
    time_t datadeaquisicao;
    char *departamento;
    int garantia;

    typedef struct CPUs {
        char *cpu;
        int ghz;
    } CPU;

    typedef struct Discos {
        char *nome;
        char *tipo;
        int capacidade;
    } Disco;

} Equipamento;