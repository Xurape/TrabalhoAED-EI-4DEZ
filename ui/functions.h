// Incluir as cores
#include "../utils/colors.h"

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

void enviarTitulo(char* titulo)
{
    printf(COR_Red);
    printf(COR_Red);

    printf(COR_Blue "\n***********************************\n\n"COR_Cyan);
    printf(titulo);
    printf(COR_Blue "\n***********************************\n\n");
}

/*
|--------------------------------------------------------------------------
| Abrir menus
|--------------------------------------------------------------------------
|
| Esta função irá abrir um menu selecionado
|
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
    default:
        exit(1);
        break;
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