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

    quebrarLinhas(1);

    printf(COR_Cyan "\t\tData de aquisição " COR_Green "~> ");
    scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano);

    quebrarLinhas(1);

    printf(COR_Cyan "\tDepartamento " COR_Green "~> ");
    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].departamento);

    quebrarLinhas(1);

    printf(COR_Cyan "\tGarantia (em meses) " COR_Green "~> ");
    scanf("%d", &equipamento[id].garantia);

    quebrarLinhas(1);
    
    printf(COR_Cyan "\tCPU " COR_Green "~> ");

    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].cpus.cpu);

    quebrarLinhas(1);

    printf(COR_Cyan "\tFrequência de CPU (em GHz) " COR_Green "~> ");
    scanf("%f", &equipamento[id].cpus.ghz);

    quebrarLinhas(1);

    printf(COR_Cyan "\tTipo de disco (SSD/SAS/HDD) " COR_Green "~> ");

    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].discos.tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "\tNome do disco (Ex.: Kingston <Modelo>) " COR_Green "~> ");
    
    fflush(stdin);
    gets(&equipamento[id].discos.nome);

    quebrarLinhas(1);

    fflush(stdin);

    printf(COR_Cyan "\tCapacidade do disco em GB (Ex.: 500) " COR_Green "~> ");
    scanf("%d", &equipamento[id].discos.capacidade);

    quebrarLinhas(1);

    printf(COR_Cyan "\tQuantidade de memória RAM em GB (Ex.: 8) " COR_Green "~> ");
    scanf("%d", &equipamento[id].ram);

    quebrarLinhas(1);
    
    fflush(stdin);

    printf(COR_Cyan "\tSistema operativo (Ex.: Windows 11) " COR_Green "~> ");

    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].sistemaoperativo);

    equipamento[id].eliminado = false;

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

    gerarTabela(1, 0, "\0");

    printf(COR_Cyan"\n\n\
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
    int filtro, opt;
    char filtro_data[50];

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Filtar equipamentos\n");
    printf("\n\t\t***********************************\n");

    printf("\n\t\t\tO que deseja filtrar?\n\n");

    printf(COR_Cyan "\t\t[1] Equipamento por Sistema Operativo\n");
    printf(COR_Cyan "\t\t[2] Equipamento por Rede\n");
    printf(COR_Cyan "\t\t[3] Equipamento por Aplicação\n\n");

    printf("\n\t\tFiltrar ~> ");
    scanf("%d", &filtro);

    printf("\n\t\tProcurar por ~> ");
    scanf("%s", filtro_data);

    quebrarLinhas(2);

    gerarTabela(1, filtro, filtro_data);

    printf(COR_Cyan"\n\n\
    Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);

    abrirMenu(1);
}

/**
 *
 * @name equipamentosEliminar
 * @brief Esta função irá gerar o menu para eliminar equipamentos
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosEliminar()
{
    int idEliminar, Confirmacao;
    char null[20] = { "\0" };

    limparJanela();

    enviarTitulo("\t\t\tMENU DE EQUIPAMENTOS\n");

    printf(COR_Green "\t\t[SELECIONADO]" COR_Blue " Eliminar Equipamento\n");
    printf("\n\t\t***********************************");

    printf("\n\t\t\tPor favor, insira:\n\n");
    
    printf(COR_Cyan "\tID do equipamento a eliminar " COR_Green "~> ");
    scanf("%d", &idEliminar);

    printf(COR_Red "\tDeseja confirmar a eliminação do equipamento?\n\n\t\
        [1] Sim - [0] Não\n\n");

    scanf("%d", &Confirmacao);

    if(Confirmacao == 1)
    {
        equipamento[idEliminar].eliminado = true;
        
        // Aquisição
        // equipamento[idEliminar].aquisicao.dia = '\0';
        // printf(COR_Green "Aquisição->Dia eliminado");
        // equipamento[idEliminar].aquisicao.mes = '\0';
        // printf(COR_Green "Aquisição->Mes eliminado");
        // equipamento[idEliminar].aquisicao.ano = '\0';
        // printf(COR_Green "Aquisição->Ano eliminado");

        // // Discos
        // strcpy(equipamento[idEliminar].discos.capacidade, null);
        // printf(COR_Green "Discos->Capacidade eliminado");
        // strcpy(equipamento[idEliminar].discos.nome, null);
        // printf(COR_Green "Discos->Nome eliminado");
        // strcpy(equipamento[idEliminar].discos.tipo, null);
        // printf(COR_Green "Discos->Tipo eliminado");

        // // CPUs
        // strcpy(equipamento[idEliminar].cpus.cpu, null);
        // printf(COR_Green "CPUs->cpu eliminado");
        // equipamento[idEliminar].cpus.ghz = '\0';
        // printf(COR_Green "CPUs->ghz eliminado");

        // // Departamento
        // strcpy(equipamento[idEliminar].departamento, null);
        // printf(COR_Green "Departamento eliminado");

        // // OS
        // strcpy(equipamento[idEliminar].sistemaoperativo, null);
        // printf(COR_Green "Sistema operativo eliminado");
        // // Outros

        // equipamento[idEliminar].garantia = null;
        // printf(COR_Green "Garantia eliminado");
        // equipamento[idEliminar].ram = null;
        // printf(COR_Green "RAM eliminado");
        // equipamento[idEliminar].tipo = null;
        // printf(COR_Green "Tipo eliminado");
        // equipamento[idEliminar].rede = null;
        // printf(COR_Green "Rede eliminado");
        // equipamento[idEliminar].aplicacoes = null;
        // printf(COR_Green "Aplicações eliminado");

        // printf("Equipamento eliminado com sucesso.");
    }

    sleep(2);

    mainUI();
}