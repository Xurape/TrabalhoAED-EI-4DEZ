/*
|--------------------------------------------------------------------------
| Gerar o menu de entrada
|--------------------------------------------------------------------------
|
| Esta função irá gerar o menu de entrada
|
*/
void menuInicial()
{
    limparJanela();
    printf(COR_Yellow);
    printf(" ______   ________  ____    ____     ____   ____  _____  ____  _____  ______      ___\n|_   _ \\ |_   __  ||_   \\  /   _|   |_  _| |_  _||_   _||_   \\|_   _||_   _ `.  .'   `.  \n  | |_) |  | |_ \\_|  |   \\/   | ______\\ \\   / /    | |    |   \\ | |    | | `. \\/  .-.  \\ \n  |  __'.  |  _| _   | |\\  /| ||______|\\ \\ / /     | |    | |\\ \\| |    | |  | || |   | | \n _| |__) |_| |__/ | _| |_\\/_| |_        \\ ' /     _| |_  _| |_\\   |_  _| |_.' /\\  `-'  / \n|_______/|________||_____||_____|        \\_/     |_____||_____|\\____||______.'  `.___.'  \n\n");
    printf(COR_Default "             Desenvolvido por: " COR_Cyan "João Ferreira " COR_Default "& " COR_Cyan "Gabriel Gavino\n\n");
}

/*
|--------------------------------------------------------------------------
| Iniciar um menu
|--------------------------------------------------------------------------
|
| Esta função irá gerar um menu à escolha
|
*/
void iniciarMenu(int menu)
{
    int opcao;

    switch (menu)
    {
        case 0: 
            finalizarMenu();
            break;

        case 750:
            menuInformacoes();
            break;

        case 256:
            limparJanela();

            menuInicial();

            printf(COR_Yellow"    <-----------------=[ -- -=| |=- -- ]=----------------->");

            quebrarLinhas(2);

            printf(COR_Cyan "> Ações iniciais: \n");

            for (size_t i = 0; i < NUMERO_DE_OPCOES_INICIAIS; i++)
            {
                printf(COR_LightCyan "   [%d]" COR_Default " %s\n", i + 1, opcoesIniciais[i]);
            }

            quebrarLinhas(2);

            printf(COR_Cyan "> Ações adicionais: \n");

            printf(COR_LightCyan "   [750]" COR_Default " Informações\n");
            printf(COR_LightCyan "   [0]  " COR_Default " Saír\n\n");

            printf(COR_Yellow"    <-----------------=[ -- -=| |=- -- ]=----------------->");

            quebrarLinhas(2);

            printf("Por favor, insira uma "COR_Green"opção:"COR_Default"\n "COR_Red"> "COR_Green);

            scanf("%d", &opcao);

            iniciarMenu(opcao);
        
            break;
        default:
            throwErro("A opção inserida não foi encontrada!");
            break;
    }
}