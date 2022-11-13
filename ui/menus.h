/**
 * 
 * @name menuEquipamentos
 * @brief Esta função irá gerar um menu com as opções dos equipamentos
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void menuEquipamentos()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

        // Opções
        printf(COR_Cyan "\t\t[1]" COR_Blue " Inserir equipamento\n");
        printf(COR_Cyan "\t\t[2]" COR_Blue " Alterar equipamento\n");
        printf(COR_Cyan "\t\t[3]" COR_Blue " Eliminar equipamento\n");
        printf(COR_Cyan "\t\t[4]" COR_Blue " Mostrar equipamentos\n");

        quebrarLinhas(2);

        printf(COR_Cyan "\t\t[0]" COR_Blue " Voltar");

        printf("\n\n\t\t***********************************\n");

        printf("\n\t\tSelecione uma opção:\n\t\t > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}

/**
 * 
 * @name menuAplicações
 * @brief Esta função irá gerar um menu com as opções das aplicações
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void menuAplicacoes()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("\t\t\tMENU DE APLICAÇÕES\n");

        // Opções
        printf(COR_Cyan "\t\t[1]" COR_Blue " Inserir aplicações\n");
        printf(COR_Cyan "\t\t[2]" COR_Blue " Alterar aplicações\n");
        printf(COR_Cyan "\t\t[3]" COR_Blue " Eliminar aplicações\n");
        printf(COR_Cyan "\t\t[4]" COR_Blue " Mostrar aplicações\n");

        quebrarLinhas(2);

        printf(COR_Cyan "\t\t[0]" COR_Blue " Voltar");

        printf("\n\n\t\t***********************************\n");

        printf("\n\t\tSelecione uma opção:\n\t\t > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}

/**
 * 
 * @name menuPlacasRede
 * @brief Esta função irá gerar um menu com as opções das placas de rede
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void menuPlacasRede()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("\t\t\tMENU DE PLACAS DE REDE\n");

        // Opções
        printf(COR_Cyan "\t\t[1]" COR_Blue " Inserir placa de rede\n");
        printf(COR_Cyan "\t\t[2]" COR_Blue " Alterar placa de rede\n");
        printf(COR_Cyan "\t\t[3]" COR_Blue " Eliminar placa de rede\n");
        printf(COR_Cyan "\t\t[4]" COR_Blue " Mostrar placas de rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "\t\t[0]" COR_Blue " Voltar");

        printf("\n\n\t\t***********************************\n");

        printf("\n\t\tSelecione uma opção:\n\t\t > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}