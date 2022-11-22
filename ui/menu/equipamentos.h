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
    char temp[20];
    int id = equipamentos_id + 1;
    int i;

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Inserir equipamento\n");
    printf("\n\t\t***********************************\n\n\t\tA inserir equipamento com ID: [ %d ]", id);

    printf("\n\t\t\tPor favor, insira:\n\n");

    printf(COR_Cyan "\tCaso seja um computador [1] ou servidor [2] " COR_Green "~> ");
    scanf("%d", &equipamento[id].tipo);
    // printf("\n---\nTIpo: %d\n----", equipamento[id].tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "\t\tData de aquisição " COR_Green "~> ");
    scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano);
    // printf("\n---\nAQuisiçõum: %d/%d/%d\n----", equipamento[id].aquisicao.dia, equipamento[id].aquisicao.mes, equipamento[id].aquisicao.ano);

    quebrarLinhas(1);

    printf(COR_Cyan "\tDepartamento " COR_Green "~> ");
    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].departamento);
    // printf("\n---\nDepart: %s\n----", equipamento[id].departamento);

    quebrarLinhas(1);

    printf(COR_Cyan "\tGarantia (em meses) " COR_Green "~> ");
    scanf("%d", &equipamento[id].garantia);
    // printf("\n---\nGarantia: %d\n----", equipamento[id].garantia);

    quebrarLinhas(1);
    
    printf(COR_Cyan "\tCPU " COR_Green "~> ");

    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].cpus.cpu);
    // printf("\n---\nCPU: %s\n----", equipamento[id].cpus.cpu);

    quebrarLinhas(1);

    printf(COR_Cyan "\tFrequência de CPU (em GHz) " COR_Green "~> ");
    scanf("%f", &equipamento[id].cpus.ghz);
    // printf("\n---\nVelocidade: %f\n----", equipamento[id].cpus.ghz);

    quebrarLinhas(1);

    printf(COR_Cyan "\tTipo de disco (SSD/SAS/HDD) " COR_Green "~> ");

    // scanf("%s", &equipamento[id].discos.tipo);
    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].discos.tipo);
    // printf("\n---\nDisco_tipo: %s\n----", equipamento[id].discos.tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "\tNome do disco (Ex.: Kingston <Modelo>) " COR_Green "~> ");
    
    fflush(stdin);
    gets(&equipamento[id].discos.nome);
    // printf("\n---\nDisco_nome: %s\n----", equipamento[id].discos.nome);

    quebrarLinhas(1);

    fflush(stdin);

    printf(COR_Cyan "\tCapacidade do disco em GB (Ex.: 500) " COR_Green "~> ");
    scanf("%d", &equipamento[id].discos.capacidade);
    // printf("\n---\nDisco_capacidade: %d\n----", equipamento[id].discos.capacidade);

    quebrarLinhas(1);

    printf(COR_Cyan "\tQuantidade de memória RAM em GB (Ex.: 8) " COR_Green "~> ");
    scanf("%d", &equipamento[id].ram);
    // printf("\n---\nRAM: %d\n----", equipamento[id].ram);

    quebrarLinhas(1);
    
    fflush(stdin);

    printf(COR_Cyan "\tSistema operativo (Ex.: Windows 11) " COR_Green "~> ");
    
    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].sistemaoperativo);
    // printf("\n---\nSistema operativo: %s\n----", equipamento[id].sistemaoperativo);

    quebrarLinhas(1);

    equipamentos_id++;
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
    int opt;
    int id = equipamentos_id + 1;

    limparJanela();

    // enviarTitulo("\t\t\tLISTA DE EQUIPAMENTOS\n");

    gerarTabela(1, 0, "\0");

    printf(COR_Cyan"\
    Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);

    abrirMenu(1);
}

/**
 *
 * @name equipamentosFiltrar
 * @brief Esta função irá gerar o menu para filtrar equipamentos
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosFiltrar()
{
    int filtro;

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Filtar equipamentos\n");
    printf("\n\t\t***********************************\n");

    printf("\n\t\t\tO que deseja filtrar?\n\n");

    printf(COR_Cyan "\t\t[1] Equipamento por Sistema Operativo\n");
    printf(COR_Cyan "\t\t[2] Equipamento por Rede\n");
    printf(COR_Cyan "\t\t[3] Equipamento por Aplicação\n\n\n\t\t~> ");
    scanf("%d", &filtro);
}

/**
 *
 * @name equipamentosPesquisar
 * @brief Esta função irá gerar o menu para pesquisar equipamentos
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosPesquisar()
{
    char *pesquisa;

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Pesquisar equipamentos\n");
    printf("\n\t\t***********************************\n");

    printf("\n\t\t\tO que deseja pesquisar?\n\n");

    printf(COR_Cyan "\t\t[1] Equipamento por Sistema Operativo\n");
    printf(COR_Cyan "\t\t[2] Equipamento por Rede\n");
    printf(COR_Cyan "\t\t[3] Equipamento por Aplicação\n\n\n\t\t~> ");
    scanf("%s", &pesquisa);
}