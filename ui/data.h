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
void gerarTabela(int tipo, int filter, char data[])
{
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
        fflush(stdin);
        printf(COR_Yellow"\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+\n\
    | ID | Adquirido   | Departamento | Garantia |        CPU       | Velocidade (GHz) |    RAM (GB)   | Sistema Operativo |              Disco              | \n\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+\n");

        switch (filter)
        {
            case 0:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    if(!equipamento[i].eliminado)
                    printf("\
    | %-2d | %-.2d/%-.2d/%-.4d  | %-12s | %-.2d meses | %-16s | %-12.2f GHz | %-10.d GB | %-17s | %-3s %s %d\n", 
                    i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                    equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                    equipamento[i].ram, equipamento[i].sistemaoperativo,
                    equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade);
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
                    if(strstr(equipamento[i].sistemaoperativo, data)) 
                    {
                        if(!equipamento[i].eliminado)
                           printf("\
    | %-2d | %-.2d/%-.2d/%-.4d  | %-12s | %-.2d meses | %-16s | %-12.2f GHz | %-10.d GB | %-17s | %-3s %s %d\n", 
                        i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                        equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                        equipamento[i].ram, equipamento[i].sistemaoperativo,
                        equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade);
                    }
                }
                break;

            /**
             * 
             * Rede
             * 
            */
            case 2:
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t ii = 0; i <= placasderede_id; i++) 
                    {
                        if(strstr(equipamento[i].rede[ii].ip, data) || strstr(equipamento[i].rede[ii].netmask, data) || strstr(equipamento[i].rede[ii].broadcast, data)) 
                        {
                            if(!equipamento[i].eliminado)
                                printf("\
    | %-2d | %-.2d/%-.2d/%-.4d  | %-12s | %-.2d meses | %-16s | %-12.2f GHz | %-10.d GB | %-17s | %-3s %s %d\n", 
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade);
                        }
                        
                    }
                }
                break;

            /**
             * 
             * Aplicações
             * 
            */
            case 3:
                char *data_completa;
                for (size_t i = 1; i <= equipamentos_id; i++)
                {
                    for (size_t ii = 0; i <= aplicacoes_id; i++)
                    {
                        strcpy(data_completa, equipamento[i].aplicacoes[ii].validade.dia);
                        strcat(data_completa, "/");
                        strcat(data_completa, equipamento[i].aplicacoes[ii].validade.mes);
                        strcat(data_completa, "/");
                        strcat(data_completa, equipamento[i].aplicacoes[ii].validade.ano);

                        if(strstr(equipamento[i].aplicacoes[ii].designacao, data) || strstr(data_completa, data) || strstr(equipamento[i].aplicacoes[ii].versao, data)) 
                        {
                            if(!equipamento[i].eliminado)
                                printf("\
        | %-2d | %-.2d/%-.2d/%-.4d  | %-12s | %-.2d meses | %-16s | %-12.2f GHz | %-10.d GB | %-17s | %-3s %s %d\n", 
                            i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
                            equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
                            equipamento[i].ram, equipamento[i].sistemaoperativo,
                            equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade);
                        }
                    }
                }
                break;
        }
        printf("\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+");
    }



    /* 
    
        TIPO 2
    
    */
    else if (tipo == 2)
    {
    }





    /* 
    
        TIPO 3
    
    */
    else
    {
    }
}