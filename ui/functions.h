// Incluir as cores
#include "../utils/colors.h"

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
    printf(titulo);
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