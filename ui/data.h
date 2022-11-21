/**
 *
 * @name gerarTabela
 * @brief Esta função irá gerar uma tabela com dados
 * @author João Ferreira & Gabriel Gavino
 *
 * @param int Tipo de tabela a renderizar
 *
 * @return Sem return
 *
 */
void gerarTabela(int tipo)
{
    /**
     * Tipos:
     *   1 - Equipamentos
     *   2 - Aplicações
     *   3 - Placas de rede
     */

    if (tipo == 1)
    {
        fflush(stdin);
        printf(COR_Yellow"\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+\n\
    | ID | Adquirido   | Departamento | Garantia |        CPU       | Velocidade (GHz) |    RAM (GB)   | Sistema Operativo |              Disco              | \n\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+\n");

    for (size_t i = 1; i <= equipamentos_id; i++)
    {
        printf("\
    | %-2d | %-.2d/%-.2d/%-.4d  | %-12s | %-.2d meses | %-16s | %-12.2f GHz | %-10.d GB | %-17s | %-3s %s %d\n", 
        i, equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano, equipamento[i].departamento, equipamento[i].garantia,
        equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
        equipamento[i].ram, equipamento[i].sistemaoperativo,
        equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade);
    }
    
        printf("\
    +----+-------------+--------------+----------+------------------+------------------+---------------+-------------------+----------------+----------------+");

        quebrarLinhas(2);
    }
    else if (tipo == 2)
    {
    }
    else
    {
    }
}