// Libraries principais
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

// Database
#include "./database/data.h"

// Utilidades
#include "./utils/main.h"

// UI
#include "./ui/main.h"

/*
|--------------------------------------------------------------------------
| Função principal
|--------------------------------------------------------------------------
|
| Esta função será a primeira e única função
| a ser executada de origem após a iniciação
| do programa pelo utilizador.
|
*/
void main(int argc, char *argv[])
{
    /*
     -> TODO
        => Fazer o sistema para inserir, alterar, eliminar equipamentos;
        => Fazer o sistema para inserir, alterar, eliminar aplicações;
        => Fazer o sistema para inserir, alterar, eliminar placas de rede;

     -> OTHER
        => Pesquisar
        => Listar
        => Detetar problemas
        => Detetar se os computadores
        estão na mesma rede.
    */
    if (obterSO() == "LINUX")
        system("clear");
    else if (obterSO() == "WIN")
        system("cls");
    else if (obterSO() == "MAC")
        system("clear");
        
    printf("Sistema operativo detetado: %s\n", obterSO());
}