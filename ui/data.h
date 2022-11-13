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
    int opcao;

    /**
     * Tipos:
     *   1 - Equipamentos
     *   2 - Aplicações
     *   3 - Placas de rede
     */

    if (tipo == 1)
    {
        printf(COR_Yellow"\
    +----+-------------+--------------+----------+-------------+------------+-------+-----+----------------+\n\
    | ID | Adquirido   | Departamento | Garantia |     CPU     | Velocidade | Disco | RAM | Sistema Opera. |\n\
    +----+-------------+--------------+----------+-------------+------------+-------+-----+----------------+\n");

    for (size_t i = 1; i <= equipamentos_id; i++)
    {
        printf("\
    |  %1d  | %1d/%1d/%1d | %s | %1d anos | %s | %.2f | %s %s %d | %s | %s\n", i, 
        equipamento[i].aquisicao.dia, equipamento[i].aquisicao.mes, equipamento[i].aquisicao.ano,
        equipamento[i].departamento, equipamento[i].garantia,
        equipamento[i].cpus.cpu, equipamento[i].cpus.ghz,
        equipamento[i].discos.tipo, equipamento[i].discos.nome, equipamento[i].discos.capacidade,
        equipamento[i].ram, equipamento[i].sistemaoperativo);
    }
    
    printf("\
    +----+-------------+--------------+----------+-------------+------------+-------+-----+----------------+");

        quebrarLinhas(2);
    }
    else if (tipo == 2)
    {
    }
    else
    {
    }
}