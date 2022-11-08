void menuEquipamentos()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("        MENU DE EQUIPAMENTOS\n");

        // Opções
        printf(COR_Cyan "    [1]" COR_Blue " Inserir equipamento\n");
        printf(COR_Cyan "    [2]" COR_Blue " Alterar equipamento\n");
        printf(COR_Cyan "    [3]" COR_Blue " Eliminar equipamento\n");
        printf(COR_Cyan "    [4]" COR_Blue " Mostrar equipamentos\n");

        quebrarLinhas(2);

        printf(COR_Cyan "    [0]" COR_Blue " Voltar");

        printf("\n\n***********************************\n");

        printf("\nSelecione uma opção:\n > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}

void menuAplicacoes()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("        MENU DE APLICAÇÕES\n");

        // Opções
        printf(COR_Cyan "    [1]" COR_Blue " Inserir aplicações\n");
        printf(COR_Cyan "    [2]" COR_Blue " Alterar aplicações\n");
        printf(COR_Cyan "    [3]" COR_Blue " Eliminar aplicações\n");
        printf(COR_Cyan "    [4]" COR_Blue " Mostrar aplicações\n");

        quebrarLinhas(2);

        printf(COR_Cyan "    [0]" COR_Blue " Voltar");

        printf("\n\n***********************************\n");

        printf("\nSelecione uma opção:\n > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}

void menuPlacasRede()
{
    int opcao;
    do
    {
        limparJanela();

        enviarTitulo("       MENU DE PLACAS DE REDE\n");

        // Opções
        printf(COR_Cyan "    [1]" COR_Blue " Inserir placa de rede\n");
        printf(COR_Cyan "    [2]" COR_Blue " Alterar placa de rede\n");
        printf(COR_Cyan "    [3]" COR_Blue " Eliminar placa de rede\n");
        printf(COR_Cyan "    [4]" COR_Blue " Mostrar placas de rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "    [0]" COR_Blue " Voltar");

        printf("\n\n***********************************\n");

        printf("\nSelecione uma opção:\n > ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
}