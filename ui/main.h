// Funções
#include "./functions.h"
#include "./menus.h"

int loading = true;

#define PROGRESSBAR_PROGRESSO0 "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PROGRESSBAR_PROGRESSO1 "////////////////////////////////////////////////////////////"
#define PROGRESSBAR_PROGRESSO2 "------------------------------------------------------------"
#define PROGRESSBAR_PROGRESSO3 "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PROGRESSBAR_PROGRESSO4 "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"

#define PROGRESSBAR_TAMANHO 60

/**
 * 
 * @name progressBar
 * @brief Esta função irá inserir uma barra de carregamento do programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param double Percentagem
 * 
 * @return Sem return
 * 
*/
void progressBar(double percentagem, int progress) 
{
    int valor = (int) (percentagem * 100);
    int tamanho = (int) (percentagem * PROGRESSBAR_TAMANHO);
    int progresso = PROGRESSBAR_TAMANHO - tamanho;
    if(progress == 1)
        printf("\r\t\t%3d%% [ %.*s%*s ]", valor, tamanho, PROGRESSBAR_PROGRESSO0, progresso, "");
    else if(progress == 2)
        printf("\r\t\t%3d%% [ %.*s%*s ]", valor, tamanho, PROGRESSBAR_PROGRESSO1, progresso, "");
    else if(progress == 3)
        printf("\r\t\t%3d%% [ %.*s%*s ]", valor, tamanho, PROGRESSBAR_PROGRESSO2, progresso, "");
    else if(progress == 4)
        printf("\r\t\t%3d%% [ %.*s%*s ]", valor, tamanho, PROGRESSBAR_PROGRESSO3, progresso, "");
    else
        printf("\r\t\t%3d%% [ %.*s%*s ]", valor, tamanho, PROGRESSBAR_PROGRESSO4, progresso, "");

    fflush(stdout);
}

/**
 * 
 * @name gerarProgressBar
 * @brief Esta função irá inserir uma barra de carregamento do programa com texto segundo o tempo dado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param useconds_t Segundos
 * 
 * @return Sem return
 * 
*/
void gerarProgressBar(useconds_t segundos) {
    int i = 0;
    
    printf("\n\n\n\t\t\t\t\t\tA carregar...\n\n");
    int progresso = 0;
    while(i <= 100)
    {
        usleep(segundos);
        // progressBar(i * 0.01, 4);
        progressBar(i * 0.01, progresso);
        
        if(progresso != 5)
            progresso++;
        else
            progresso = 0;

        i++;
    }
}

/**
 * 
 * @name abrirTerminalLoading
 * @brief Esta função irá inserir a tela de carregamento do programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void abrirTerminalLoading()
{
    limparJanela();

    printf(COR_Gray "A executar "COR_Default"/boot/iniciar...\n");
    usleep(500000);

    printf("[  " COR_Green "OK" COR_Default"  ] /boot/iniciar montado com sucesso.\n");
    // printf("        "COR_Gray"A iniciar "COR_Default"/boot/iniciar...\n\n");
    usleep(500000);

    // printf("        "COR_Gray"A criar "COR_Default"estrutura da base de dados...\n");;
    printf("[  " COR_Green "OK" COR_Default"  ] Estrutura da base de dados criada.\n");
    usleep(500000);

    printf("[  " COR_Green "OK" COR_Default"  ] Leitura da base de dados efetuada com sucesso.\n");

    // printf("        "COR_Gray"A inicializar "COR_Default"os menus...\n");
    usleep(500000);
    printf("[  " COR_Green "OK" COR_Default"  ] Menus lidos com sucesso.\n");

    usleep(500000);
    printf("[  " COR_Green "OK" COR_Default"  ] Menus otimizados com sucesso.\n");

    usleep(500000);
    printf("[  " COR_Green "OK" COR_Default"  ] Cores dos menus carregadas com sucesso.\n");

    printf("        "COR_Gray"A tirar "COR_Default"nota 20 no trabalho...\n");
    usleep(1500000);
    printf("[ " COR_Red "ERRO " COR_Default"] Nota %d atribuida com sucesso.\n", rand());

    // printf("        "COR_Gray"A carregar "COR_Default"funções...\n");
    usleep(500000);
    printf("[  " COR_Green "OK" COR_Default"  ] Funções carregadas com sucesso.\n");

    // printf("        "COR_Gray"A limpar "COR_Default"o sistema de inicialização...\n");
    usleep(500000);
    printf("[  " COR_Green "OK" COR_Default"  ] Sucesso!\n\n");
    
    usleep(500000);

    limparJanela();

    gerarProgressBar(60500);
    // gerarProgressBar(23500);

    sleep(1);

    loading = false;
}

/**
 * 
 * @name mainUI
 * @brief Esta função irá gerar o menu principal do programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void mainUI()
{
    int opcao;

    if(loading)
        abrirTerminalLoading();

    do
    {
        limparJanela();
        enviarTitulo("\t\t     GESTÃO DE REDE INFORMÁTICA\n");

        // Opções
        printf(COR_Cyan "\t\t[1]" COR_Blue " Equipamentos\n");
        printf(COR_Cyan "\t\t[2]" COR_Blue " Aplicações\n");
        printf(COR_Cyan "\t\t[3]" COR_Blue " Placas de Rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "\t\t[0]" COR_Blue " Sair");

        printf("\n\n\t\t***********************************\n");

        printf("\n\t\tSelecione uma opção:\n\t\t > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        limparJanela();

    abrirMenu(opcao);
}