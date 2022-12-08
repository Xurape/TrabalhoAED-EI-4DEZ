/**
 *
 * @name aplicacoesInserir
 * @brief Esta função irá gerar o menu para inserir uma aplicação
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void aplicacoesInserir()
{
    char temp[20];
    int id = aplicacoes_id + 1;
    int i;

    limparJanela();

    enviarTitulo("      INSERIR UMA APLICAÇÃO      ", 1);

    if(equipamentos_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Inserir Aplicação\n");

    printf(COR_Green"\n  A inserir aplicação com ID: "COR_Cyan"[ %d ]\n\n"COR_Default, id);
    
    printf(COR_Cyan " ■ ID do equipamento a associar a aplicação " COR_Green "→ "); scanf("%d", &aplicacoes[id].id);

    while (aplicacoes[id].id < 0 || aplicacoes[id].id > equipamentos_id) {
        printf(COR_Red"\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        printf(COR_Cyan " ■ ID do equipamento a associar a placa " COR_Green "→ ");
        scanf("%d", &rede[id].id);
    }
    printf(COR_Cyan " ■ Nome do Aplicativo " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&aplicacoes[id].designacao);
    printf(COR_Cyan " ■ Versão do Aplicativo " COR_Green "→ "); fflush(stdin); gets(&aplicacoes[id].versao);
    printf(COR_Cyan " ■ Validade da licença " COR_Green "→ "); scanf("%d/%d/%d", &aplicacoes[id].validade.dia, &aplicacoes[id].validade.mes, &aplicacoes[id].validade.ano);
    
    aplicacoes_id++;
}

/**
 *
 * @name aplicacoesMostrar
 * @brief Esta função irá gerar o menu com a lista dos aplicacoes
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void aplicacoesMostrar()
{
    int opt;
    int id = aplicacoes_id + 1;

    limparJanela();

    enviarTitulo("       MENU DE APLICAÇÕES         ", 1);

    if (aplicacoes_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira uma aplicação primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuAplicacoes();
    }

    gerarTabela(2, 0);

    printf(COR_Cyan "\n\n ■ Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);
}

/**
 *
 * @name aplicacoesEliminar
 * @brief Esta função irá gerar o menu para eliminar aplicacoes
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void aplicacoesEliminar()
{
    int idEliminar, Confirmacao;
    char null[20] = {"\0"};

    limparJanela();

    enviarTitulo("       MENU DE APLICAÇÕES         ", 1);

    if (aplicacoes_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira uma aplicação primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuAplicacoes();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Eliminar aplicação\n");

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan " ■ ID da aplicação a eliminar " COR_Green "→ "); guardarCursor();
    scanf("%d", &idEliminar);

    while (idEliminar < 0 || idEliminar > aplicacoes_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\nEssa aplicação não existe, por favor insira uma aplicação válida..\n\n"); restaurarCursor();
        scanf("%d", &idEliminar);
    }

    printf(COR_Cyan" "TL"────────────────────────────────────────────────────────────"TR"\n");
    printf(COR_Red "\n        Deseja confirmar a eliminação da aplicação?\n\n                 "COR_Cyan"[1]"COR_Green" Sim "COR_Red"-"COR_Cyan" [0] "COR_LightRed"Não"COR_Cyan"\n\n     → "); guardarCursor();
    printf(COR_Cyan"\n\n "BL"────────────────────────────────────────────────────────────"BR);
    restaurarCursor();
    scanf("%d", &Confirmacao);

    if (Confirmacao == 1)
    {
        for (size_t i = idEliminar; i <= aplicacoes_id; i++)
        {
            aplicacoes[i] = aplicacoes[i + 1];
        }

        aplicacoes_id--;
    }
}

/**
 *
 * @name aplicacoesAlterar
 * @brief Esta função irá gerar o menu para eliminar um equipamento
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void aplicacoesAlterar()
{
    char temp[20];
    int i, id;

    limparJanela();

    enviarTitulo("       MENU DE APLICAÇÕES         ", 1);

    if (aplicacoes_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira uma aplicação primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuAplicacoes();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Alterar Aplicação\n");

    printf(COR_Green"\n  A alterar aplicação com ID: "COR_Cyan"[ ");

    guardarCursor();

    printf("  ]\n\n"COR_Default, id);

    restaurarCursor();

    scanf("%d", &id);

    while (id < 0 || id > aplicacoes_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\nEssa aplicação não existe, por favor insira uma aplicação válida..\n\n");
        restaurarCursor();
        scanf("%d", &id);
    }

    printf(COR_Cyan " ■ ID do equipamento a associar a aplicação " COR_Green "→ "); scanf("%d", &aplicacoes[id].id);

    while (aplicacoes[id].id < 0 || aplicacoes[id].id > equipamentos_id) {
        printf(COR_Red"\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        printf(COR_Cyan " ■ ID do equipamento a associar a placa " COR_Green "→ ");
        scanf("%d", &rede[id].id);
    }

    printf(COR_Cyan " ■ Nome do Aplicativo " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&aplicacoes[id].designacao);
    printf(COR_Cyan " ■ Versão do Aplicativo " COR_Green "→ "); fflush(stdin); gets(&aplicacoes[id].versao);
    printf(COR_Cyan " ■ Validade da licença " COR_Green "→ "); scanf("%d/%d/%d", &aplicacoes[id].validade.dia, &aplicacoes[id].validade.mes, &aplicacoes[id].validade.ano);
    
    quebrarLinhas(1);
}