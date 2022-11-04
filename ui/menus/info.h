// Incluir as cores
#include "../../utils/colors.h"

/*
|--------------------------------------------------------------------------
| Gerar o menu de informações
|--------------------------------------------------------------------------
|
| Esta função irá gerar o menu de informações
|
*/
void menuInformacoes()
{
    time_t t;
    time(&t);

    limparJanela();

    printf(COR_Yellow);
    printf("             _____  _______  ____   ____   ______  \n");
    printf("            |_   _||_   __ \\|_  _| |_  _|.' ___  | \n");
    printf("              | |    | |__) | \\ \\   / / / .'   \\_| \n");
    printf("              | |    |  ___/   \\ \\ / /  | |        \n");
    printf("             _| |_  _| |_       \\ ' /   \\ `.___.'\\ \n");
    printf("            |_____||_____|       \\_/     `.____ .'\n\n");
    printf("                         www.ipvc.pt");

    quebrarLinhas(2);

    printf(COR_Default "        Desenvolvido por: " COR_Cyan "João Ferreira " COR_Default "& " COR_Cyan "Gabriel Gavino\n");

    quebrarLinhas(1);

    printf(COR_Yellow"    <-----------------=[ -- -=| |=- -- ]=----------------->");

    quebrarLinhas(2);

    printf("> "COR_Default"Informações sobre o "COR_Green"programa"COR_Default":\n\n");
    printf(" "COR_LightPurple"- "COR_Default"Aplicação desenvolvida em ambiente "COR_Red"C"COR_Default" por " COR_Cyan "João Ferreira " COR_Default "& " COR_Cyan "Gabriel Gavino.\n");
    printf(" "COR_LightPurple"- "COR_Cyan"Compilador:"COR_Default" GNU Compiler Collection "COR_Green"(GCC)\n\n");
    
    printf(COR_Cyan"> "COR_Default"Informações sobre o "COR_Yellow"sistema"COR_Default":\n\n");
    printf(" "COR_LightPurple"- "COR_Cyan"Sistema operativo:"COR_Default" %s\n", obterSO());
    printf(" "COR_LightPurple"- "COR_Cyan"Data atual:"COR_Default" %s\n", ctime(&t));

    printf(COR_Yellow"    <-----------------=[ -- -=| |=- -- ]=----------------->");

    quebrarLinhas(2);

    printf(COR_Gray"        -- Pressione qualquer tecla para voltar atrás --");
    

    // iniciarMenu(256);
}