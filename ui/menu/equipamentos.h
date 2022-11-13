/**
 *
 * @name equipamentosInserir
 * @brief Esta função irá gerar o menu para inserir um equipamento
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosInserir()
{
    int opcao;
    int id = equipamentos_id + 1;

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Inserir equipamento\n");
    printf("\n\t\t***********************************\n\n\t\tA inserir equipamento com ID: %d", id);

    printf("\n\t\t\tPor favor, insira:\n\n");

    printf(COR_Cyan "\tCaso seja um computador [1] ou servidor [2] " COR_Green "~> ");
    scanf("%d", &equipamento[id].tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "\t\tData de aquisição " COR_Green "~> ");
    scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano);

    equipamentos_id++;

    printf(COR_Default); gerarProgressBar(2000);
}

/**
 *
 * @name equipamentosMostrar
 * @brief Esta função irá gerar o menu com a lista dos equipamentos
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosMostrar()
{
    int opcao;
    int id = equipamentos_id + 1;

    limparJanela();

    enviarTitulo("\t\t\tLISTA DE EQUIPAMENTOS\n");

    gerarTabela(1);

    printf(COR_Cyan"\
    Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opcao);

    abrirMenu(1);
}