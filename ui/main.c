#include "./functions.c"
#include "./data.c"
#include "./menus.c"
#include "./menu/equipamentos.c"
#include "./menu/aplicacoes.c"
#include "./menu/placasderede.c"

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

        limparJanela();

        enviarTitulo("GESTÃO DE REDE INFORMÁTICA\n");

        // Opções
        printf(COR_Cyan "   [1]" COR_Default " Equipamentos\n");
        printf(COR_Cyan "   [2]" COR_Default " Aplicações\n");
        printf(COR_Cyan "   [3]" COR_Default " Placas de Rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "   [0]" COR_Default " Sair");

    
    do
    {
        printf(COR_Green "\n\n\n"TL LINE TR"\n");
        printf("\n       Selecione uma opção: ");
        saveCursor();
        
        char temp;
        scanf(" %c", &temp);
        opcao = temp - '0';
        
        restoreCursor();
        printf("\e[0J");
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        limparJanela();

    abrirMenu(opcao);
}