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
}