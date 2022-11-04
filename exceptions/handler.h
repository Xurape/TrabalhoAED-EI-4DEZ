// Incluir as cores
#include "../utils/colors.h"

/*
|--------------------------------------------------------------------------
| Enviar uma exception
|--------------------------------------------------------------------------
|
| Esta função irá enviar uma mensagem de erro ao utilizador
|
*/
void throwErro(char *erro)
{
    limparJanela();

    printf(COR_Red " ________                               __  \n|_   __  |                          _ .' _| \n  | |_ \\_| _ .--.  _ .--.   .--.   (_)| |   \n  |  _| _ [ `/'`\\][ `/'`\\]/ .'`\\ \\  _ | |   \n _| |__/ | | |     | |    | \\__. | (_)| |_  \n|________|[___]   [___]    '.__.'     `.__| \n                                            ");
    quebrarLinhas(2);

    printf(COR_Red " %s", erro);

    quebrarLinhas(3);

    printf(COR_LightCyan "> A voltar ao menu principal em 3 segundos...");

    quebrarLinhas(1);

    sleep(3);

    limparJanela();

    iniciarMenu(256);
}