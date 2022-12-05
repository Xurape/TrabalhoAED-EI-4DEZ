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

    enviarTitulo("     MENU DE PLACAS DE REDE", 1);

    if(equipamentos_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Inserir placa de rede\n");

    printf(COR_Green"\n  A inserir placa com ID: "COR_Cyan"[ %d ]\n"COR_Default, id);

    printf("\n  Por favor, insira:\n\n");

    printf(COR_Cyan " ■ ID do equipamento a associar a placa " COR_Green "→ "); scanf("%d", &rede[id].id);

    while (rede[id].id < 0 || rede[id].id > equipamentos_id) {
        printf(COR_Red"\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        printf(COR_Cyan " ■ ID do equipamento a associar a placa " COR_Green "→ ");
        scanf("%d", &rede[id].id);
    }

    printf(COR_Cyan " ■ Endereço IP " COR_Green "→ "); 
    fflush(stdin); 
    scanf("%c", &temp); 
    scanf("%d.%d.%d.%d", &rede[id].ip_pieces_1, &rede[id].ip_pieces_2, &rede[id].ip_pieces_3, &rede[id].ip_pieces_4);
    
    while(rede[id].ip_pieces_1 < 1 || rede[id].ip_pieces_1 > 254 || rede[id].ip_pieces_2 < 0 || rede[id].ip_pieces_2 > 254 || rede[id].ip_pieces_3 < 0 || rede[id].ip_pieces_3 > 254 || rede[id].ip_pieces_4 < 0 || rede[id].ip_pieces_4 > 254)
    {
        printf(COR_Red"\nIP inválido, por favor insira um endereço IP válido..\n\n");
        printf(COR_Cyan " ■ Endereço IP " COR_Green "→ "); 
        fflush(stdin); 
        scanf("%c", &temp); 
        scanf("%d.%d.%d.%d", &rede[id].ip_pieces_1, &rede[id].ip_pieces_2, &rede[id].ip_pieces_3, &rede[id].ip_pieces_4);
    }
    
    fflush(stdin); 
    scanf("%c", &temp);
    printf(COR_Cyan " ■ Máscara de Rede " COR_Green "→ "); gets(rede[id].netmask);
    printf(COR_Cyan " ■ Endereço de broadcast " COR_Green "→ "); gets(rede[id].broadcast); quebrarLinhas(1);

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
    
    enviarTitulo("     MENU DE PLACAS DE REDE", 1);

    if(equipamentos_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    if(placasderede_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira uma placa de rede primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuPlacasRede();
    }

    gerarTabela(3, 0);

    printf(COR_Cyan"\n\n ■ Insira qualquer número para voltar atrás.. ");

    scanf("%d", &opt);
}

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
    int id;

    limparJanela();
    
    enviarTitulo("     MENU DE PLACAS DE REDE", 1);

    if(equipamentos_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    if(placasderede_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira uma placa de rede primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuPlacasRede();
    }

    printf(COR_Green "  [SELECIONADO]" COR_Cyan " Alterar placa de rede\n");
    printf(COR_Green"\n  A alterar placa de rede com ID: "COR_Cyan"[ ");
    guardarCursor();
    printf("  ]\n\n"COR_Default, id);
    restaurarCursor();
    scanf("%d", &id);

    while (id < 0 || id > placasderede_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\nEssa placa de rede não existe, por favor insira um ID válido..\n\n");
        restaurarCursor();
        scanf("%d", &id);
    }

    printf(COR_Cyan " ■ ID do equipamento a associar a placa " COR_Green "→ "); guardarCursor(); scanf("%d", &rede[id].id);

    while (rede[id].id < 0 || rede[id].id > equipamentos_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\n\nEsse equipamento não existe, por favor insira um equipamento válido..\n\n");
        restaurarCursor();
        scanf("%d", &rede[id].id);
    }

    printf(COR_Cyan " ■ Endereço IP " COR_Green "→ ");
    fflush(stdin); 
    scanf("%c", &temp); 
    scanf("%d.%d.%d.%d", &rede[id].ip_pieces_1, &rede[id].ip_pieces_2, &rede[id].ip_pieces_3, &rede[id].ip_pieces_4);
    
    while(rede[id].ip_pieces_1 < 1 || rede[id].ip_pieces_1 > 254 || rede[id].ip_pieces_2 < 0 || rede[id].ip_pieces_2 > 254 || rede[id].ip_pieces_3 < 0 || rede[id].ip_pieces_3 > 254 || rede[id].ip_pieces_4 < 0 || rede[id].ip_pieces_4 > 254)
    {
        printf(COR_Red"\nIP inválido, por favor insira um endereço IP válido..\n\n");
        printf(COR_Cyan " ■ Endereço IP " COR_Green "→ "); 
        fflush(stdin); 
        scanf("%c", &temp); 
        scanf("%d.%d.%d.%d", &rede[id].ip_pieces_1, &rede[id].ip_pieces_2, &rede[id].ip_pieces_3, &rede[id].ip_pieces_4);
    }
    
    fflush(stdin); 
    scanf("%c", &temp);
    printf(COR_Cyan " ■ Máscara de Rede " COR_Green "→ "); gets(rede[id].netmask);
    printf(COR_Cyan " ■ Endereço de broadcast " COR_Green "→ "); gets(rede[id].broadcast); quebrarLinhas(1);

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

    enviarTitulo("     MENU DE PLACAS DE REDE", 1);

    if(equipamentos_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira um equipamento primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuEquipamentos();
    }

    if(placasderede_id == 0) {
        printf(COR_Cyan "\n\n Por favor, insira uma placa de rede primeiro.\n\n Insira qualquer número para voltar atrás.. ");

        int opt;
        scanf("%d", &opt);

        menuPlacasRede();
    }

    printf(COR_Cyan " ■ ID da placa a eliminar " COR_Green "→ "); guardarCursor();

    scanf("%d", &idEliminarPlaca);

    while (idEliminarPlaca < 0 || idEliminarPlaca > placasderede_id) {
        printf(COR_Red"\n\n\n\n\n\n\n\n\n\n\n\n\nEssa placa não existe, por favor insira um ID de placa válido..\n\n");
        restaurarCursor();
        scanf("%d", &idEliminarPlaca);
    }

    printf(COR_Cyan" "TL"────────────────────────────────────────────────────────────"TR"\n");
    printf(COR_Red "\n       Deseja confirmar a eliminação da placa de rede?\n\n                 "COR_Cyan"[1]"COR_Green" Sim "COR_Red"-"COR_Cyan" [0] "COR_LightRed"Não"COR_Cyan"\n\n     → "); guardarCursor();
    printf(COR_Cyan"\n\n "BL"────────────────────────────────────────────────────────────"BR);
    restaurarCursor();
    scanf("%d", &Confirmacao);

    if (Confirmacao == 1)
    {
        for (size_t i = idEliminarPlaca; i <= placasderede_id; i++)
        {
            rede[i] = rede[i + 1];
        }

        placasderede_id--;
    }

    printf(COR_Cyan);
}