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
    int filtroC, filtroC_pieces_1, filtroC_pieces_2, filtroC_pieces_3;

    /**
     * * * * * * * * *
     * * LISTA TODO *
     * * * * * * * * *
     */

    //* [1] -> Equipamento por Sistema Operativo
    
    //? [2] -> Equipamento por Placa de Rede
    //! [3] -> Equipamento por Aplicação
    //* [4] -> Equipamento por Departamento

    //* [5] -> Equipamento por Garantia Expirada
    //* [6] -> Equipamento por Número de MIPS (Por departamento)
    //* [7] -> Equipamento por Memória (Exatamente o NRº fornecido)
    //* [8] -> Equipamento por Capacidade do disco duro (Exatamente o NRº fornecido)
    //* [9] -> Equipamento com menos de um determinado Nº de RAM
    //* [10] -> Equipamento por Aplicação com validade expirada
    //* [11] -> Equipamentos na mesma rede
    //? [12] -> Verificar se equipamentos com possibilidade de comunicação interna.
    //* [13] -> Equipamentos numa determinada rede

    if (tipo == 1)
    {
        if (filter != 0 && filter != 5 && filter != 10 && filter != 11 && filter != 12)
        {
            /** 
             * 
             * Ler departamento em vez de uma string 
             * 
            */
            if (filter == 6)
                printf(COR_Cyan " ■ " COR_Default "Departamento → ");
            else if (filter == 2)
                printf(COR_Cyan " ■ " COR_Default "ID da placa de rede (Ex.: 1) → ");
            else if (filter == 13)
                printf(COR_Cyan " ■ " COR_Default "Primeiros 3 digitos no IP da Rede (Ex.: 192.168.1) → ");
            else
                if(filter == 7 || filter == 8)
                    printf(COR_Cyan " ■ " COR_Default "Procurar por (Em GB, apenas o número) → ");
                else
                    printf(COR_Cyan " ■ " COR_Default "Procurar por → ");

            fflush(stdin);
            scanf("%c", &temp);

            /**
             * 
             * Leitura dos dados
             * 
            */
            if (filter == 2 | filter == 7 || filter == 8 || filter == 9)
                scanf("%d", &filtroC);
            else if(filter == 13)
                scanf("%d.%d.%d", &filtroC_pieces_1, &filtroC_pieces_2, &filtroC_pieces_3);
            else
                gets(filtroc);

            quebrarLinhas(2);
        }

        fflush(stdin);

        if (filter == 6)
            printf(COR_Yellow " ┌────┬─────────────┬──────────────┬──────────┬──────────────────┬──────────────────┬───────────────┬───────────────────┬─────────────────────────────────┬────────┬───────┐\n │ ID │ Adquirido   │ Departamento │ Garantia │        CPU       │ Velocidade (GHz) │    RAM (GB)   │ Sistema Operativo │              Disco              │  Tipo  │ MIPS  │\n " MVL "────┼─────────────┼──────────────┼──────────┼──────────────────┼──────────────────┼───────────────┼───────────────────┼─────────────────────────────────┼────────┼───────" MVR "\n");
        else
            printf(COR_Yellow " ┌────┬─────────────┬──────────────┬──────────┬──────────────────┬──────────────────┬───────────────┬───────────────────┬─────────────────────────────────┬────────┐\n │ ID │ Adquirido   │ Departamento │ Garantia │        CPU       │ Velocidade (GHz) │    RAM (GB)   │ Sistema Operativo │              Disco              │  Tipo  │\n " MVL "────┼─────────────┼──────────────┼──────────┼──────────────────┼──────────────────┼───────────────┼───────────────────┼─────────────────────────────────┼────────" MVR "\n");

        switch (filter)
        {
            case 0:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                        i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                        equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                        equipamento[i].ram, equipamento[i].sistemaoperativo,
                        equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
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
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            case 2:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t k = 1; i <= placasderede_id; i++)
                    {
                        if (rede[k].id == i)
                        {
                            if (k == filtroC)
                            {
                                printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                                    i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                                    equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                                    equipamento[i].ram, equipamento[i].sistemaoperativo,
                                    equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                            }
                        }
                    }
                }
                break;

            /**
             * TODO - ACABAR ESTA FUNÇÃO!!
             * TODO - ACABAR ESTA FUNÇÃO!!
             * Aplicação
             * TODO - ACABAR ESTA FUNÇÃO!!
             * TODO - ACABAR ESTA FUNÇÃO!!
             */
            case 3:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t ii = 0; i <= placasderede_id; i++)
                    {
                        // if(strstr(equipamento[i].rede[ii].ip, filtroc) ││ strstr(equipamento[i].rede[ii].netmask, filtroc) ││ strstr(equipamento[i].rede[ii].broadcast, filtroc))
                        // {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                        // }
                    }
                }
                break;
                
            /**
             *
             * Equipamentos com o departamento indicado
             *
             */
            case 4:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if (strstr(equipamento[i].departamento, filtroc))
                    {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            /**
             *
             * Equipamentos dos quais já passou o prazo de validade
             *
             */
            case 5:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    time_t now;
                    time(&now);
                    struct tm *tempo = localtime(&now);
                    temp1 = 12 * (tempo->tm_year + 1900) + tempo->tm_mon + 1;
                    temp2 = 12 * equipamento[i].aquisicao.ano + equipamento[i].aquisicao.mes;
                    if ((temp1 - temp2) > equipamento[i].garantia)
                    {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            /**
             * 
             * Equipamentos por departamento por MIPS
             * 
             */
            case 6:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if (strstr(equipamento[i].departamento, filtroc))
                    {
                        /* 1250 MIPS por GHz */
                        float mips = (float)equipamento[i].cpus.ghz * (float)1250;

                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │ %-5.0f │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "), mips);
                    }
                }
                break;

            /**
             *
             * Equipamentos por NR de memória fornecida
             *
             */
            case 7:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if (equipamento[i].ram == filtroC)
                    {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            /**
             *
             * Equipamentos por NRº de capacidade do disco rígido fornecido
             *
             */
            case 8:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if (equipamento[i].discos.capacidade == filtroC)
                    {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            /**
             *
             * Equipamentos com o departamento indicado
             *
             */
            case 9:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if (equipamento[i].ram < filtroC)
                    {
                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                    }
                }
                break;

            /**
             *
             * Equipamentos com validade expirada nas aplicações
             *  
             */
            case 10:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t j = 1; j <= aplicacoes_id; j++)
                    {
                        if (aplicacoes[j].id == i)
                        {
                            int ano_mes_atual, ano_mes_validade;
                            
                            time_t now;
                            time(&now);
                            struct tm *tempo = localtime(&now);

                            ano_mes_atual = 12 * (tempo->tm_year + 1900) + tempo->tm_mon + 1;
                            ano_mes_validade = 12 *  aplicacoes[j].validade.ano + aplicacoes[j].validade.mes;

                            if ((ano_mes_atual > ano_mes_validade) || ((ano_mes_atual == ano_mes_validade) && (tempo->tm_mday > aplicacoes[j].validade.dia)))
                            {
                                printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                                    i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                                    equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                                    equipamento[i].ram, equipamento[i].sistemaoperativo,
                                    equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                                j = 900;
                            }
                        }
                    }
                }
                break;
            
            /**
             *
             * Equipamentos na mesma rede
             *  
             */
            case 11:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t j = 1; j <= placasderede_id; j++)
                    {
                        if (rede[j].id == i)
                        {
                            for (size_t k = 1; k <= placasderede_id; k++)
                            {
                                if ((k != j) && (rede[j].id != rede[k].id))
                                {
                                    if ((rede[j].ip_pieces_1 == rede[k].ip_pieces_1) && (rede[j].ip_pieces_2 == rede[k].ip_pieces_2) && (rede[j].ip_pieces_3 == rede[k].ip_pieces_3))
                                    {
                                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                                      
                                        k = 900;
                                        j = 900;
                                    }   
                                }
                            }
                        }
                            
                    }
                }
                break;

            /**
             *
             * Equipamentos com o mesmo endereço de broadcast
             *  
             */
            case 12:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t j = 1; j <= placasderede_id; j++)
                    {
                        if (rede[j].id == i)
                        {
                            for (size_t k = 1; k <= placasderede_id; k++)
                            {
                                if ((k != j) && (rede[j].id != rede[k].id))
                                {
                                    if (strstr(rede[j].broadcast, rede[k].broadcast))
                                    {
                                        printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                                      
                                        k = 900;
                                        j = 900;
                                    }   
                                }
                            }
                        }
                            
                    }
                }
            break;

            case 13:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t k = 1; k <= placasderede_id; k++)
                    {
                        if (rede[k].id == i)
                        {
                            if ((rede[k].ip_pieces_1 == filtroC_pieces_1) && (rede[k].ip_pieces_2 == filtroC_pieces_2) && (rede[k].ip_pieces_3 == filtroC_pieces_3))
                            {
                                printf(" │ %-2d │ %-.2d/%-.2d/%-.4d  │ %-12s │ %-.2d meses │ %-16s │ %-12.2f GHz │ %-10.d GB │ %-17s │ %-3s %s %-25d │ %-6s │\n",
                                    i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                                    equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                                    equipamento[i].ram, equipamento[i].sistemaoperativo,
                                    equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade, ((equipamento[i].tipo == 2) ? "Server" : "  PC  "));
                            k = 900;
                            }
                        }
                    }
                }
            break;

        }
        if (filter == 6)
            printf(BL "────┴─────────────┴──────────────┴──────────┴──────────────────┴──────────────────┴───────────────┴───────────────────┴─────────────────────────────────┴────────┴───────" BR "\n");
        else
            printf(BL "────┴─────────────┴──────────────┴──────────┴──────────────────┴──────────────────┴───────────────┴───────────────────┴─────────────────────────────────┴────────" BR "\n");
    }


    /**
     * * * * * * * * *
     * * APLICAÇÕES *
     * * * * * * * * *
     */
    else if (tipo == 2)
    {
        fflush(stdin);
        printf(COR_Yellow " ┌────┬─────────────┬─────────────────────┬─────────────────────┬───────────────────────┐\n │ ID │ Equipamento │     Designação      │        Versão       │  Validade da licença  │\n " MVL "────┼─────────────┼─────────────────────┼─────────────────────┼───────────────────────" MVR "\n");

        switch (filter)
        {

        case 0:
            for (size_t i = 1; i <= aplicacoes_id; i++)
            {
                printf(" │ %-2d │ %-11d │ %-19s │ %-19s │ %-.2d/%-.2d/%-.4d %-9s " VL "\n", i, aplicacoes[i].id, aplicacoes[i].designacao, aplicacoes[i].versao, aplicacoes[i].validade.dia, aplicacoes[i].validade.mes, aplicacoes[i].validade.ano, "");
            }
            break;
        }
        printf(" └────┴─────────────┴─────────────────────┴─────────────────────┴───────────────────────┘");
    }

    /**
     * * * * * * * * * * *
     * * PLACAS DE REDE *
     * * * * * * * * * * *
     */
    else
    {
        fflush(stdin);
        printf(COR_Yellow " ┌────┬─────────────┬─────────────────────┬─────────────────────┬───────────────────────┐\n │ ID │ Equipamento │    Endereço IP      │   Máscara de Rede   │ Endereço de broadcast │\n " MVL "────┼─────────────┼─────────────────────┼─────────────────────┼───────────────────────" MVR "\n");

        switch (filter)
        {
        case 0:
            for (size_t i = 1; i <= placasderede_id; i++)
            {
                printf(" │ %-2d │ %-11d │ %d.%d.%d.%d %-10s │ %-19s │ %-20s " VL "\n",
                       i, rede[i].id, rede[i].ip_pieces_1, rede[i].ip_pieces_2, rede[i].ip_pieces_3, rede[i].ip_pieces_4, "", rede[i].netmask, rede[i].broadcast);
            }
            break;
        }
        printf(" └────┴─────────────┴─────────────────────┴─────────────────────┴───────────────────────┘");
    }
}