// Funções
#include "./functions.h"
#include "./menus.h"

int loading = 0;

void abrirTerminalLoading()
{
    limparJanela();
    printf(COR_Gray "A montar "COR_Default"/boot/iniciar...\n");
    sleep(1);
    printf("[  " COR_Green "OK" COR_Default"  ] /boot/iniciar montado com sucesso.\n");
    printf("        "COR_Gray"A iniciar "COR_Default"/boot/iniciar...\n\n");
    sleep(1);

    printf("        "COR_Gray"A criar "COR_Default"estrutura da base de dados...\n");;
    sleep(1);
    printf("[  " COR_Green "OK" COR_Default"  ] Estrutura da base de dados criada.\n\n");

    printf("        "COR_Gray"A inicializar "COR_Default"os menus...\n");
    sleep(1);
    printf("[  " COR_Green "OK" COR_Default"  ] Menus inicializados com sucesso.\n\n");

    printf("        "COR_Gray"A tirar "COR_Default"nota 20 no trabalho...\n");
    sleep(3);
    printf("[ " COR_Red "ERRO " COR_Default"] Nota %d atribuida com sucesso.\n\n", rand());

    printf("        "COR_Gray"A carregar "COR_Default"funções...\n");
    sleep(1);
    printf("[  " COR_Green "OK" COR_Default"  ] Funções carregadas com sucesso.\n\n");

    printf("        "COR_Gray"A limpar "COR_Default"o sistema de inicialização...\n");
    sleep(1);
    printf("[  " COR_Green "OK" COR_Default"  ] Sucesso!\n\n");
    
    sleep(2);

    loading = 1;
}

void mainUI()
{
    int opcao;

    if(loading == 0)
        abrirTerminalLoading();

    do
    {
        limparJanela();

        enviarTitulo("     GESTÃO DE REDE INFORMÁTICA\n");

        // Opções
        printf(COR_Cyan "    [1]" COR_Blue " Equipamentos\n");
        printf(COR_Cyan "    [2]" COR_Blue " Aplicações\n");
        printf(COR_Cyan "    [3]" COR_Blue " Placas de Rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "    [0]" COR_Blue " Sair");

        printf("\n\n***********************************\n");

        printf("\nSelecione uma opção:\n > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        limparJanela();

    abrirMenu(opcao);
}