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

    enviarTitulo("MENU DE EQUIPAMENTOS INFORMÁTICOS", 1);

    printf(COR_Green "[SELECIONADO]" COR_Blue " Inserir equipamento\n");
    printf(COR_Green"\n***********************************\n\nA inserir equipamento com ID: [ %d ]", id);

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan "> Caso seja um computador [1] ou servidor [2] " COR_Green "~> "); scanf("%d", &equipamento[id].tipo); quebrarLinhas(1);
    printf(COR_Cyan "> Data de aquisição " COR_Green "~> "); scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano); quebrarLinhas(1);
    printf(COR_Cyan "> Departamento " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].departamento); quebrarLinhas(1);
    printf(COR_Cyan "> Garantia (em meses) " COR_Green "~> "); scanf("%d", &equipamento[id].garantia); quebrarLinhas(1);
    printf(COR_Cyan "> CPU " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].cpus.cpu); quebrarLinhas(1);
    printf(COR_Cyan "> Frequência de CPU (em GHz) " COR_Green "~> "); scanf("%f", &equipamento[id].cpus.ghz); quebrarLinhas(1);
    printf(COR_Cyan "> Tipo de disco (SSD/SAS/HDD) " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].discos.tipo); quebrarLinhas(1);
    printf(COR_Cyan "> Nome do disco (Ex.: Kingston <Modelo>) " COR_Green "~> "); fflush(stdin); gets(&equipamento[id].discos.nome); quebrarLinhas(1); fflush(stdin); 
    printf(COR_Cyan "> Capacidade do disco em GB (Ex.: 500) " COR_Green "~> "); scanf("%d", &equipamento[id].discos.capacidade); quebrarLinhas(1);
    printf(COR_Cyan "> Quantidade de memória RAM em GB (Ex.: 8) " COR_Green "~> "); scanf("%d", &equipamento[id].ram); quebrarLinhas(1); fflush(stdin);
    printf(COR_Cyan "> Sistema operativo (Ex.: Windows 11) " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].sistemaoperativo); quebrarLinhas(1);

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

    enviarTitulo("MENU DE EQUIPAMENTOS", 1);

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n\
 Por favor, insira um equipamento primeiro.\n\n\
 Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    gerarTabela(1, 0);

    printf(COR_Cyan "\n\n\
+ Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);
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

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n\
 Por favor, insira um equipamento primeiro.\n\n\
 Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("MENU DE EQUIPAMENTOS", 1);

    printf(COR_Green "[SELECIONADO]" COR_Blue " Filtar equipamentos\n");
    printf("\n***********************************\n");

    printf("\n  O que deseja filtrar?\n\n");

    printf(COR_Cyan "[1] "COR_Default"Equipamento por Sistema Operativo\n");
    printf(COR_Cyan "[2] "COR_Default"Equipamento por Rede\n");
    printf(COR_Cyan "[3] "COR_Default"Equipamento por Aplicação\n\n");
    printf(COR_Cyan "[4] "COR_Default"Equipamento por Garantia Expirada\n\n");

    printf("\nFiltrar ~> ");
    scanf("%d", &filtro);

    // if(filtro != 4) {
    //     scanf("%s", filtro_data);
    //     printf("\nProcurar por ~> ");
    // } else {
    //     strcpy(filtro_data, NULL);
    // }

    quebrarLinhas(2);

    gerarTabela(1, filtro);

    printf(COR_Cyan "\n\n\
 Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);
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
    char null[20] = {"\0"};

    limparJanela();

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n\
 Por favor, insira um equipamento primeiro.\n\n\
 Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("MENU DE EQUIPAMENTOS", 1);

    printf(COR_Green "[SELECIONADO]" COR_Blue " Eliminar Equipamento\n");
    printf("\n***********************************");

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan "   ID do equipamento a eliminar " COR_Green "~> ");
    scanf("%d", &idEliminar);

    printf(COR_Red "    Deseja confirmar a eliminação do equipamento?\n\n[1] Sim - [0] Não\n\n~> ");

    scanf("%d", &Confirmacao);

    if (Confirmacao == 1)
    {
        for (size_t i = idEliminar; i <= equipamentos_id; i++)
        {
            equipamento[i] = equipamento[i + 1];
        }

        equipamentos_id--;
    }
}

/**
 *
 * @name equipamentosAlterar
 * @brief Esta função irá gerar o menu para eliminar um equipamento
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void equipamentosAlterar()
{
    char temp[20];
    int i, id;

    limparJanela();

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n\
 Por favor, insira um equipamento primeiro.\n\n\
 Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("MENU DE EQUIPAMENTOS", 1);

    printf(COR_Green "[SELECIONADO]" COR_Blue " Alterar equipamento\n");
    printf("\n***********************************\n\nA editar equipamento com ID: ");
    scanf("%d", &id);

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan "   Caso seja um computador [1] ou servidor [2] " COR_Green "~> "); scanf("%d", &equipamento[id].tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "   Data de aquisição " COR_Green "~> "); scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano);

    quebrarLinhas(1);

    printf(COR_Cyan "   Departamento " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].departamento);

    quebrarLinhas(1);

    printf(COR_Cyan "   Garantia (em meses) " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); scanf("%d", &equipamento[id].garantia);

    quebrarLinhas(1);

    printf(COR_Cyan "   CPU " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].cpus.cpu);

    quebrarLinhas(1);

    printf(COR_Cyan "   Frequência de CPU (em GHz) " COR_Green "~> "); scanf("%f", &equipamento[id].cpus.ghz);

    quebrarLinhas(1);

    printf(COR_Cyan "   Tipo de disco (SSD/SAS/HDD) " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].discos.tipo);

    quebrarLinhas(1);

    printf(COR_Cyan "   Nome do disco (Ex.: Kingston <Modelo>) " COR_Green "~> "); fflush(stdin); gets(&equipamento[id].discos.nome);

    quebrarLinhas(1);

    fflush(stdin);

    printf(COR_Cyan "   Capacidade do disco em GB (Ex.: 500) " COR_Green "~> ");
    scanf("%d", &equipamento[id].discos.capacidade);

    quebrarLinhas(1);

    printf(COR_Cyan "   Quantidade de memória RAM em GB (Ex.: 8) " COR_Green "~> ");
    scanf("%d", &equipamento[id].ram);

    quebrarLinhas(1);

    fflush(stdin);

    printf(COR_Cyan "   Sistema operativo (Ex.: Windows 11) " COR_Green "~> ");

    fflush(stdin);
    scanf("%c", &temp);
    gets(&equipamento[id].sistemaoperativo);

    quebrarLinhas(1);
}