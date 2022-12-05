/**
 *
 * @name gerarTabela
 * @brief Esta função irá gerar uma tabela com dados
 * @author João Ferreira & Gabriel Gavino
 *
 * @param int Tipo de tabela a renderizar
 * @param bool Filtar elementos?
 * @param char Elementos a filtrar
 *
 * @return Sem return
 *
 */
void gerarTabela(int tipo, int filter)
{
    int temp1, temp2;
    char *temp;
    char filtroc[100];
    /**
     * Tipos:
     *   1 - Equipamentos
     *   2 - Aplicações
     *   3 - Placas de rede
     */

    /**
     * Filters:
     *   1 - Sistema operativo
     *   2 - Rede
     *   3 - Aplicação
     */

    /*

        TIPO 1

    */
    if (tipo == 1)
    {
        if(filter != 0 && filter != 4) {
            printf(COR_Cyan"■ "COR_Default"Procurar por → "); fflush(stdin); scanf("%c", &temp);gets(filtroc); quebrarLinhas(2);
        }

        fflush(stdin);
        printf(COR_Yellow "\
 ┌────┬─────────────┬──────────────┬──────────┬──────────────────┬──────────────────┬───────────────┬───────────────────┬─────────────────────────────────┬────────┐\n\
 │ ID │ Adquirido   │ Departamento │ Garantia │        CPU       │ Velocidade (GHz) │    RAM (GB)   │ Sistema Operativo │              Disco              │  Tipo  │\n\
 "MVL"────┼─────────────┼──────────────┼──────────┼──────────────────┼──────────────────┼───────────────┼───────────────────┼─────────────────────────────────┼────────"MVR"\n");

        switch (filter)
        {
        case 0:
            for (size_t i = 1; i <= equipamentos_id; i++)
            {
                printf("\
 │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                       i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                       equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                       equipamento[i].ram, equipamento[i].sistemaoperativo,
                       equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((tipo == 2) ? "Server" : "  PC  "));
            }

            break;

        /**
         *
         * Sistema operativo
         *
         */
        case 1:
            for (size_t i = 1; i <= equipamentos_id; i++)
            {
                if (strstr(equipamento[i].sistemaoperativo, filtroc))
                {
                    printf("\
 │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                       i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                       equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                       equipamento[i].ram, equipamento[i].sistemaoperativo,
                       equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((tipo == 2) ? "Server" : "  PC  "));
                }
            }
            break;

        /**
         *
         * Rede
         *
         */
        case 2:
            printf("\nProcurar por → ");
            for (size_t i = 1; i <= equipamentos_id; i++)
            {
                for (size_t ii = 0; i <= placasderede_id; i++)
                {
                    // if(strstr(equipamento[i].rede[ii].ip, filtroc) ││ strstr(equipamento[i].rede[ii].netmask, filtroc) ││ strstr(equipamento[i].rede[ii].broadcast, filtroc))
                    // {
                    printf("\
 │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                       i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                       equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                       equipamento[i].ram, equipamento[i].sistemaoperativo,
                       equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((tipo == 2) ? "Server" : "  PC  "));
                    // }
                }
            }
            break;

        /**
         *
         * Aplicações
         *
         */
        case 3:
            // char* filtroc_completa;
            for (size_t i = 1; i <= equipamentos_id; i++)
            {
                for (size_t ii = 0; i <= aplicacoes_id; i++)
                {
                    
                }
            }
            break;
        case 4:
            // equipamentos que já passou a filtroc de validade
            for (size_t i = 1; i <= equipamentos_id; i++)
            {
                    time_t now;
                    time(&now);    
                    struct tm *tempo = localtime(&now);
                    temp1 = 12*tempo->tm_year + tempo->tm_mon;
                    temp2 = 12*equipamento[i].aquisicao.ano + equipamento[i].aquisicao.mes;
                    if ((temp1 - temp2) > equipamento[i].garantia)   
                    {
                    printf("\
 │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                       i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                       equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                       equipamento[i].ram, equipamento[i].sistemaoperativo,
                       equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((tipo == 2) ? "Server" : "  PC  "));
                    }
            }
            break;

        case 5:
            // total da memória dos equipamentos
            break;
        }
        printf("\
"BL"────┴─────────────┴──────────────┴──────────┴──────────────────┴──────────────────┴───────────────┴───────────────────┴─────────────────────────────────┴────────"BR"\n");
    }

    /*
        TIPO 2
        - APLICAÇÕES -
    */
    else if (tipo == 2)
    {
        fflush(stdin);
        printf(COR_Yellow "\
 ┌────┬─────────────┬─────────────────────┬─────────────────────┬───────────────────────┐\n\
 │ ID │ Equipamento │     Designação      │        Versão       │  Validade da licença  │\n\
 "MVL"────┼─────────────┼─────────────────────┼─────────────────────┼───────────────────────"MVR"\n");

        switch (filter)
        {
        
            case 0:
                for (size_t i = 1; i <= aplicacoes_id; i++)
                {
                    printf("\
 │ %-2d │ %-11d │ %-19s │ %-19s │ %-.2d/%-.2d/%-.4d %-9s "VL"\n", i, aplicacoes[i].id, aplicacoes[i].designacao, aplicacoes[i].versao, aplicacoes[i].validade.dia, aplicacoes[i].validade.mes, aplicacoes[i].validade.ano, "");
                }   
                break;
        }
        printf("\
 └────┴─────────────┴─────────────────────┴─────────────────────┴───────────────────────┘");
    }

    /*
        TIPO 3
        - PLACAS -
    */
    else
    {
        fflush(stdin);
        printf(COR_Yellow "\
 ┌────┬─────────────┬─────────────────────┬─────────────────────┬───────────────────────┐\n\
 │ ID │ Equipamento │    Endereço IP      │   Máscara de Rede   │ Endereço de broadcast │\n\
 "MVL"────┼─────────────┼─────────────────────┼─────────────────────┼───────────────────────"MVR"\n");

        switch (filter)
        {
        
            case 0:
                for (size_t i = 1; i <= placasderede_id; i++)
                {
                    char endereço[50];
                    strcpy(endereço, rede[i].ip_pieces_1 + '0');
                    strcat(endereço, ".");
                    strcat(endereço, rede[i].ip_pieces_2 + '0');
                    strcat(endereço, ".");
                    strcat(endereço, rede[i].ip_pieces_3 + '0');
                    strcat(endereço, ".");
                    strcat(endereço, rede[i].ip_pieces_4 + '0');
                    printf("%s\n", endereço);
                    printf("\
 │ %-2d │ %-11d │ %d.%d.%d.%d │ %-19s │ %-20s "VL"\n", i, rede[i].id, rede[i].ip_pieces_1, rede[i].ip_pieces_2, rede[i].ip_pieces_3, rede[i].ip_pieces_4, rede[i].netmask, rede[i].broadcast);
                }   
                break;
        }
        printf("\
 └────┴─────────────┴─────────────────────┴─────────────────────┴───────────────────────┘");
    }
}