// Libraries principais
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>
#include <math.h>

// Database
#include "./database/data.h"

// Utilidades
#include "./utils/main.h"

// UI
#include "./ui/main.h"

/**
 * 
 * @name main
 * @brief Esta função será a primeira e única função a ser executada de origem após a iniciação do programa pelo utilizador.
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void main()
{

    // const char *myword = "grandetamanho";
     
    // printf (">%-20s<\n", myword);
    // printf (">%20s<\n", myword);
    // printf (">%-*s<\n", 20, myword);
    // printf (">%-.2s<\n", myword);

    configuracaoInicial();

    mainUI();

    finalizarMenu();
}