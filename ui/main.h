// Funções
#include "./functions.h"
#include "./data.h"
#include "./menus.h"
#include "./menu/equipamentos.h"
#include "./menu/aplicacoes.h"
#include "./menu/placasderede.h"

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