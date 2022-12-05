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

    enviarTitulo("     INSERIR UM EQUIPAMENTO", 1);

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Inserir equipamento\n");

    printf(COR_Green"\n  A inserir equipamento com ID: "COR_Cyan"[ %d ]\n\n"COR_Default, id);

    printf(COR_Cyan " ■ Caso seja um computador [1] ou servidor [2] " COR_Green "→ "); scanf("%d", &equipamento[id].tipo); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Data de aquisição " COR_Green "→ "); scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Departamento " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].departamento); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Garantia (em meses) " COR_Green "→ "); scanf("%d", &equipamento[id].garantia); //quebrarLinhas(1);
    printf(COR_Cyan " ■ CPU " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].cpus.cpu); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Frequência de CPU (em GHz) " COR_Green "→ "); scanf("%f", &equipamento[id].cpus.ghz); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Tipo de disco (SSD/SAS/HDD) " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].discos.tipo); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Nome do disco (Ex.: Kingston <Modelo>) " COR_Green "→ "); fflush(stdin); gets(&equipamento[id].discos.nome); //quebrarLinhas(1); fflush(stdin); 
    printf(COR_Cyan " ■ Capacidade do disco em GB (Ex.: 500) " COR_Green "→ "); scanf("%d", &equipamento[id].discos.capacidade); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Quantidade de memória RAM em GB (Ex.: 8) " COR_Green "→ "); scanf("%d", &equipamento[id].ram); //quebrarLinhas(1); fflush(stdin);
    printf(COR_Cyan " ■ Sistema operativo (Ex.: Windows 11) " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].sistemaoperativo); //quebrarLinhas(1);

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

    enviarTitulo("       MENU DE EQUIPAMENTOS", 1);

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    gerarTabela(1, 0);

    printf(COR_Cyan "\n\n ■ Insira qualquer número para voltar atrás.. ");

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

    enviarTitulo("       MENU DE EQUIPAMENTOS", 1);

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Filtrar equipamentos\n\n");

    printf(COR_Cyan "[1] "COR_Default"Equipamento por Sistema Operativo\n");
    printf(COR_Cyan "[2] "COR_Default"Equipamento por Placa de Rede\n");
    printf(COR_Cyan "[3] "COR_Default"Equipamento por Aplicação\n");
    printf(COR_Cyan "[4] "COR_Default"Equipamento por Departamento\n\n");

    printf(COR_Cyan "[5] "COR_Default"Equipamento por Garantia Expirada\n");
    printf(COR_Cyan "[6] "COR_Default"Equipamento por Número de MIPS (Por departamento)\n");
    printf(COR_Cyan "[7] "COR_Default"Equipamento por Memória (Por departamento)\n");
    printf(COR_Cyan "[8] "COR_Default"Equipamento por Capacidade do disco duro (Por departamento)\n");
    printf(COR_Cyan "[9] "COR_Default"Equipamento com menos de um determinado Nº de RAM\n");
    printf(COR_Cyan "[10] "COR_Default"Equipamento por Aplicação com validade expirada\n");
    printf(COR_Cyan "[11] "COR_Default"Equipamentos na mesma rede\n");
    printf(COR_Cyan "[12] "COR_Default"Verificar se equipamentos com possibilidade de comunicação interna.\n");

    printf(COR_Cyan"\n■"COR_Default" Filtrar → ");
    scanf("%d", &filtro);

    quebrarLinhas(2);

    gerarTabela(1, filtro);

    printf(COR_Cyan "\n\n ■ Insira qualquer número para voltar atrás.. ");

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

    enviarTitulo("       MENU DE EQUIPAMENTOS", 1);

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Eliminar equipamento\n");

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan " ■ ID do equipamento a eliminar " COR_Green "→ "); guardarCursor();
    scanf("%d", &idEliminar);

    while (idEliminar < 0 || idEliminar > equipamentos_id) {
        printf(COR_Red"\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n"); restaurarCursor();
        scanf("%d", &idEliminar);
    }

    printf(COR_Cyan" "TL"────────────────────────────────────────────────────────────"TR"\n");
    printf(COR_Red "\n        Deseja confirmar a eliminação do equipamento?\n\n                 "COR_Cyan"[1]"COR_Green" Sim "COR_Red"-"COR_Cyan" [0] "COR_LightRed"Não"COR_Cyan"\n\n     → "); guardarCursor();
    printf(COR_Cyan"\n\n "BL"────────────────────────────────────────────────────────────"BR);
    restaurarCursor();
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

    enviarTitulo("       MENU DE EQUIPAMENTOS", 1);

    if (equipamentos_id == 0)
    {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Alterar equipamento\n");

    printf(COR_Green"\n  A alterar equipamento com ID: "COR_Cyan"[ ");

    guardarCursor();

    printf("  ]\n\n"COR_Default, id);

    restaurarCursor();

    scanf("%d", &id);

    while (id < 0 || id > equipamentos_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        restaurarCursor();
        scanf("%d", &id);
    }

    printf(COR_Cyan " ■ Caso seja um computador [1] ou servidor [2] " COR_Green "→ "); scanf("%d", &equipamento[id].tipo); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Data de aquisição " COR_Green "→ "); scanf("%d/%d/%d", &equipamento[id].aquisicao.dia, &equipamento[id].aquisicao.mes, &equipamento[id].aquisicao.ano); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Departamento " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].departamento); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Garantia (em meses) " COR_Green "→ "); scanf("%d", &equipamento[id].garantia); //quebrarLinhas(1);
    printf(COR_Cyan " ■ CPU " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].cpus.cpu); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Frequência de CPU (em GHz) " COR_Green "→ "); scanf("%f", &equipamento[id].cpus.ghz); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Tipo de disco (SSD/SAS/HDD) " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].discos.tipo); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Nome do disco (Ex.: Kingston <Modelo>) " COR_Green "→ "); fflush(stdin); gets(&equipamento[id].discos.nome); //quebrarLinhas(1); fflush(stdin); 
    printf(COR_Cyan " ■ Capacidade do disco em GB (Ex.: 500) " COR_Green "→ "); scanf("%d", &equipamento[id].discos.capacidade); //quebrarLinhas(1);
    printf(COR_Cyan " ■ Quantidade de memória RAM em GB (Ex.: 8) " COR_Green "→ "); scanf("%d", &equipamento[id].ram); //quebrarLinhas(1); fflush(stdin);
    printf(COR_Cyan " ■ Sistema operativo (Ex.: Windows 11) " COR_Green "→ "); fflush(stdin); scanf("%c", &temp); gets(&equipamento[id].sistemaoperativo); //quebrarLinhas(1);

    quebrarLinhas(1);
}