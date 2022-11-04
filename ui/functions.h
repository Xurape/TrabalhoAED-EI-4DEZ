// Incluir as cores
#include "../utils/colors.h"

// Incluir opções dos menus
#include "./options.h"

/*
|--------------------------------------------------------------------------
| Configurações iniciais do programa
|--------------------------------------------------------------------------
|
| Esta função irá correr a configuração inicial do programa
|
*/
void configuracaoInicial()
{
    setlocale(LC_ALL, "Portuguese");
}

/*
|--------------------------------------------------------------------------
| Limpar a janela
|--------------------------------------------------------------------------
|
| Esta função irá limpar a janela ao utilizador dependendo
| do sistema operativo a ser usado
|
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

/*
|--------------------------------------------------------------------------
| Quebra a quantidade de linhas indicada
|--------------------------------------------------------------------------
|
| Esta função irá mudar/quebrar as linhas indicadas
|
*/
void quebrarLinhas(int linhas)
{
    for (size_t i = 1; i <= linhas; i++)
    {
        printf("\n");
    }   
}

/*
|--------------------------------------------------------------------------
| Finalizar menu
|--------------------------------------------------------------------------
|
| Esta função irá finalizar os menus
|
*/
void finalizarMenu()
{
    printf("\n\n");
    exit(0);
}

// printf("Sistema operativo detetado: %s\n", obterSO());