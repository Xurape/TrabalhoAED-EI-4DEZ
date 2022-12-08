// Libraries principais
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <unistd.h>
#include <locale.h>
#include <time.h>
#include <math.h>

// Database
#include "./database/data.h"

// UI
#include "./ui/main.h"
#include "./ui/main.c"

/**
 * 
 * @name main
 * @brief Esta função será a primeira e única função a ser executada de origem após a iniciação do programa pelo utilizador.
 * @author João Ferreira & Gabriel Gavina
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
int main()
{
    limparJanela();

    configuracaoInicial();

    mainUI();

    finalizarMenu();

    return 0;
}
