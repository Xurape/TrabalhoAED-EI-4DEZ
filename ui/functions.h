#include "../utils/colors.h"

#define PROGRESSBAR_PROGRESSO0 "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PROGRESSBAR_PROGRESSO1 "////////////////////////////////////////////////////////////"
#define PROGRESSBAR_PROGRESSO2 "------------------------------------------------------------"
#define PROGRESSBAR_PROGRESSO3 "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PROGRESSBAR_PROGRESSO4 "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"

#define PROGRESSBAR_TAMANHO 60

int loading = false;

/**
 * 
 * @name configuracaoInicial
 * @brief Esta função irá correr a configuração inicial do programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void configuracaoInicial()
{
    setlocale(LC_ALL, "Portuguese");
}


/**
 * 
 * @name limparJanela
 * @brief Esta função irá limpar a janela ao utilizador dependendo do sistema operativo a ser usado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void limparJanela()
{
    if (obterSO() == "Linux")
        system("clear");
    else if (obterSO() == "Windows")
        system("cls");
    else if (obterSO() == "MacOS")
        system("clear");
    else
        system("clear");
}


/**
 * 
 * @name quebrarLinhas
 * @brief Esta função irá mudar/quebrar as linhas indicadas
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Número de linhas
 * 
 * @return Sem return
 * 
*/
void quebrarLinhas(int linhas)
{
    for (size_t i = 1; i <= linhas; i++)
    {
        printf("\n");
    }
}

/**
 * 
 * @name enviarTitulo
 * @brief Esta função irá enviar print do título parameterizado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param char Título a enviar
 * 
 * @return Sem return
 * 
*/
void enviarTitulo(char* titulo)
{
    printf(COR_Red);
    printf(COR_Red);

    printf(COR_Blue "\n\t\t***********************************\n\n"COR_Cyan);
    printf("%s", titulo);
    printf(COR_Blue "\n\t\t***********************************\n\n");
}

/**
 * 
 * @name abrirMenu
 * @brief Esta função irá abrir um menu selecionado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Número do menu a abrir
 * 
 * @return Sem return
 * 
*/
void abrirMenu(int menu)
{
    switch (menu)
    {
        /**
         * 
         * Iniciais
         * 
        */
       
        case 0:
            exit(1);
            break;
        case 1:
            menuEquipamentos();
            break;
        case 2:
            menuAplicacoes();
            break;
        case 3:
            menuPlacasRede();
            break;

        /**
         * 
         * Equipamentos
         * 
        */

        case 31:
            equipamentosInserir();
            menuEquipamentos();
            break;
        case 32:
            break;
        case 33:
            break;
        case 34:
            equipamentosMostrar();
            break;
        
        /**
         * 
         * Aplicações
         * 
        */

        case 41:
            break;
        case 42:
            break;
        case 43:
            break;
        case 44:
            break;
        
        /**
         * 
         * Placas de rede
         * 
        */

        case 51:
            break;
        case 52:
            break;
        case 53:
            break;
        case 54:
            break;
        
        /**
         * 
         * Outros
         * 
        */

        default:
            exit(1);
            break;
    }
}

/**
 * 
 * @name finalizarMenu
 * @brief Esta função irá finalizar o programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void finalizarMenu()
{
    printf("\n\n");
    exit(0);
}

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

    gerarProgressBar(40500);
    // gerarProgressBar(23500);

    sleep(1);

    loading = false;
}