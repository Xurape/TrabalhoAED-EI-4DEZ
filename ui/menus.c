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
    int opc;

    do
    {
        limparJanela();

        enviarTitulo("MENU DE EQUIPAMENTOS", 1);

        printf(COR_Cyan "   [1]" COR_Default " Inserir equipamento\n");
        printf(COR_Cyan "   [2]" COR_Default " Alterar equipamento\n");
        printf(COR_Cyan "   [3]" COR_Default " Eliminar equipamento\n");
        printf(COR_Cyan "   [4]" COR_Default " Mostrar equipamentos\n");
        printf(COR_Cyan "   [5]" COR_Default " Filtrar equipamentos\n");

        quebrarLinhas(2);

        printf(COR_Cyan "   [0]" COR_Default " Voltar");

        printf(COR_Green "\n\n"TL LINE TR"\n"VL"\t\t\t\t    "VL"\n");
        printf(VL" %s", "Selecione uma opção: "); guardarCursor();
        printf("            "VL"\n");
        printf(COR_Green VL"\t\t\t\t    "VL "\n" BL LINE BR"\n\n");

        scanf("%d", &opc);
        
        restaurarCursor();
    } while (opc < 0 || opc > 6);

    if(opc == 0)
        mainUI();
    else   
        abrirMenu(opc + 30);
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

        enviarTitulo("       MENU DE APLICAÇÕES        ", 1);

        // Opções
        printf(COR_Cyan "   [1]" COR_Default " Inserir aplicações\n");
        printf(COR_Cyan "   [2]" COR_Default " Alterar aplicações\n");
        printf(COR_Cyan "   [3]" COR_Default " Eliminar aplicações\n");
        printf(COR_Cyan "   [4]" COR_Default " Mostrar aplicações\n");

        quebrarLinhas(2);

        printf(COR_Cyan "   [0]" COR_Default " Voltar");

        printf(COR_Green "\n\n"TL LINE TR"\n"VL"\t\t\t\t    "VL"\n");
        printf(VL" %s", "Selecione uma opção: "); guardarCursor();
        printf("            "VL"\n");
        printf(COR_Green VL"\t\t\t\t    "VL "\n" BL LINE BR"\n\n");

        scanf("%d", &opcao);
        
        restaurarCursor();
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
    else   
        abrirMenu(opcao + 40);
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

        enviarTitulo("MENU DE PLACAS DE REDE", 1);

        // Opções
        printf(COR_Cyan "   [1]" COR_Default " Inserir placa de rede\n");
        printf(COR_Cyan "   [2]" COR_Default " Alterar placa de rede\n");
        printf(COR_Cyan "   [3]" COR_Default " Eliminar placa de rede\n");
        printf(COR_Cyan "   [4]" COR_Default " Mostrar placas de rede\n");

        quebrarLinhas(2);

        printf(COR_Cyan "   [0]" COR_Default " Voltar");

        printf(COR_Green "\n\n"TL LINE TR"\n"VL"\t\t\t\t    "VL"\n");
        printf(VL" %s", "Selecione uma opção: "); guardarCursor();
        printf("            "VL"\n");
        printf(COR_Green VL"\t\t\t\t    "VL "\n" BL LINE BR"\n\n");

        scanf("%d", &opcao);
        
        restaurarCursor();
    } while (opcao < 0 || opcao > 7);

    if(opcao == 0)
        mainUI();
    else   
        abrirMenu(opcao + 50);
}