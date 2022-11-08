// Libraries principais
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>

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
main()
{
    configuracaoInicial();

    mainUI();

    finalizarMenu();
}