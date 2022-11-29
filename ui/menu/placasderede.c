/**
 *
 * @name placasderedeInserir
 * @brief Esta função irá gerar o menu para inserir uma placa de rede
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void placasderedeInserir()
{
    char temp[20];
    int id = placasderede_id + 1;
    int i, opt;

    limparJanela();

    //! TODO 
    /**
     * 
     * Colocar esta função ativa no fim.
     * 
    */

    if(equipamentos_id == 0) {
        printf(COR_Cyan"\n\n\
        Por favor, insira um equipamento primeiro.\n\n\
        Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("\tMENU DE PLACAS DE REDE\n");

    printf(COR_Green "[SELECIONADO]" COR_Blue " Inserir Placa de Rede\n");
    printf(COR_Green"\n***********************************\n\nA inserir placa de rede com ID: [ %d ]", id);

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan "> ID do equipamento a associar a placa " COR_Green "~> "); scanf("%d", &rede[id].id);

    while (rede[id].id < 0 || rede[id].id > equipamentos_id) {
        printf(COR_Red"\n\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        printf(COR_Cyan "> ID do equipamento a associar a placa " COR_Green "~> ");
        scanf("%d", &rede[id].id);
    }

    printf(COR_Cyan "> Endereço IP " COR_Green "~> "); fflush(stdin); scanf("%c", &temp); gets(rede[id].ip);
    printf(COR_Cyan "> Máscara de Rede " COR_Green "~> "); gets(rede[id].netmask);
    printf(COR_Cyan "> Endereço de broadcast " COR_Green "~> "); gets(rede[id].broadcast); quebrarLinhas(1);

    placasderede_id++;
}

/**
 *
 * @name placasderedeMostrar
 * @brief Esta função irá gerar o menu com a lista das placas de rede
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void placasderedeMostrar()
{
    int opt;
    int id = placasderede_id + 1;

    limparJanela();

    if(equipamentos_id == 0) {
        printf(COR_Cyan"\n\n\
        Por favor, insira um equipamento primeiro.\n\n\
        Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    // enviarTitulo("\tLISTA DE EQUIPAMENTOS\n");

    gerarTabela(3, 0);

    printf(COR_Cyan"\n\n\
    Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);
}

/**
 *
 * @name placasderedeFiltrar
 * @brief Esta função irá gerar o menu para filtrar equipamentos
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
// void placasderedeFiltrar()
// {
//     int filtro, opt;
//     char filtro_data[50];

//     limparJanela();

//     enviarTitulo("\tMENU DE PLACAS DE REDE\n");

//     printf(COR_Green "[SELECIONADO]" COR_Blue " Filtar placas de rede\n");
//     printf("\n***********************************\n");

//     printf("\n\tO que deseja filtrar?\n\n");

//     printf(COR_Cyan "[1] Placa por Endereço IP\n");
//     printf(COR_Cyan "[2] Placa por Máscara de Rede\n");
//     printf(COR_Cyan "[3] Placa por Endereço de Broadcast\n\n");

//     printf("\nFiltrar ~> ");
//     scanf("%d", &filtro);

//     printf("\nProcurar por ~> ");
//     scanf("%s", filtro_data);

//     quebrarLinhas(2);

//     gerarTabela(2, filtro, filtro_data);

//     printf(COR_Cyan"\n\n\
//     Insira qualquer número para voltar atrás.. ");

//     scanf("%d", &opt);

//     abrirMenu(1);
// }

/**
 *
 * @name placasderedeAlterar
 * @brief Esta função irá gerar o menu para alterar uma placa de rede
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void placasderedeAlterar()
{
    char temp[20];
    int id, id_equipamento;

    limparJanela();

    if(equipamentos_id == 0) {
        printf(COR_Cyan"\n\n\
        Por favor, insira um equipamento primeiro.\n\n\
        Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("\tMENU DE PLACAS DE REDE\n");

    printf(COR_Green "[SELECIONADO]" COR_Blue " Alterar Placa de Rede\n");
    printf("\n***********************************\n\nA alterar placa de rede com ID: ");
    scanf("%d", &id);

    printf("\n\tPor favor, insira:\n\n");
    
    printf(COR_Cyan "\tID do equipamento a associar a placa " COR_Green "~> ");
    scanf("%d", &id_equipamento);

    // printf(COR_Cyan "\tEndereço IP " COR_Green "~> ");
    // fflush(stdin);
    // scanf("%c", &temp);
    // gets(&equipamento[id_equipamento].rede[id].ip);

    // printf(COR_Cyan "\tMáscara de Rede " COR_Green "~> ");
    // fflush(stdin);
    // scanf("%c", &temp);
    // gets(&equipamento[id_equipamento].rede[id].netmask);

    // printf(COR_Cyan "\tEndereço de broadcast " COR_Green "~> ");
    // fflush(stdin);
    // scanf("%c", &temp);
    // gets(&equipamento[id_equipamento].rede[id].broadcast);

    quebrarLinhas(1);
}

/**
 *
 * @name placasderedeEliminar
 * @brief Esta função irá gerar o menu para eliminar uma placa de rede
 * @author João Ferreira & Gabriel Gavino
 *
 * @param null Sem parametros
 *
 * @return Sem return
 *
 */
void placasderedeEliminar()
{
    int idEliminarEquip, idEliminarPlaca, Confirmacao;
    char null[20] = { "\0" };

    limparJanela();

    if(equipamentos_id == 0) {
        printf(COR_Cyan"\n\n\
        Por favor, insira um equipamento primeiro.\n\n\
        Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    enviarTitulo("\tMENU DE PLACAS DE REDE\n");

    // printf(COR_Green "[SELECIONADO]" COR_Blue " Eliminar Placa de Rede\n");
    // printf("\n***********************************");

    // printf("\n\tPor favor, insira:\n\n");
    
    // printf(COR_Cyan "\tID do equipamento ao qual a placa vai ser eliminada " COR_Green "~> ");
    // scanf("%d", &idEliminarEquip);
    
    // printf(COR_Cyan "\tID da placa a ser eliminada " COR_Green "~> ");
    // scanf("%d", &idEliminarPlaca);

    // printf(COR_Red "\tDeseja confirmar a eliminação da placa de rede Nº %d?\n\n[1] Sim - [0] Não\n\n~> ", idEliminarPlaca);

    // scanf("%d", &Confirmacao);

    printf(COR_Cyan);
}