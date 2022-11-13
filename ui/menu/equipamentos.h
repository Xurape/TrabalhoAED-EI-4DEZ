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

    quebrarLinhas(1);

    printf(COR_Cyan "\tDepartamento " COR_Green "~> ");
    gets(equipamento[id].departamento);

    quebrarLinhas(1);

    printf(COR_Cyan "\tGarantia (em anos) " COR_Green "~> ");
    scanf("%d", &equipamento[id].garantia);

    quebrarLinhas(1);

    // printf(COR_Cyan "\tCPU " COR_Green "~> ");
    // gets(equipamento[id].cpus.cpu);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tFrequência de CPU (em GHz) " COR_Green "~> ");
    // scanf("%f", &equipamento[id].cpus.ghz);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tTipo de disco (SSD/SAS/SSD) " COR_Green "~> ");
    // gets(equipamento[id].discos.tipo);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tNome do disco (Ex.: Kingston <Modelo>) " COR_Green "~> ");
    // gets(equipamento[id].discos.nome);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tCapacidade do disco (Ex.: 500GB) " COR_Green "~> ");
    // scanf("%d", &equipamento[id].discos.capacidade);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tQuantidade de memória RAM (Ex.: 8GB) " COR_Green "~> ");
    // scanf("%d", &equipamento[id].ram);

    // quebrarLinhas(1);

    // printf(COR_Cyan "\tSistema operativo (Ex.: Windows 11) " COR_Green "~> ");
    // gets(equipamento[id].sistemaoperativo);

    // quebrarLinhas(1);

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