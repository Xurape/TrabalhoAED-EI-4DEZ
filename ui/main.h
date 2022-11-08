// Funções
#include "./functions.h"
#include "./menus.h"

void mainUI()
{
    int opcao;

    do
    {
        limparJanela();

        enviarTitulo("     GESTÃO DE REDE INFORMÁTICA\n");

        // Opções
        printf(COR_Cyan "    [1]" COR_Blue " Equipamentos\n");
        printf(COR_Cyan "    [2]" COR_Blue " Aplicalções\n");
        printf(COR_Cyan "    [3]" COR_Blue " Placas de Rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "    [0]" COR_Blue " Sair");

        printf("\n\n***********************************\n");

        printf("\nSelecione uma opção:\n > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    abrirMenu(opcao);
}