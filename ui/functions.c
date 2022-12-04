#include "../utils/colors.h"
#include "../utils/characters.h"

/**
 * 
 * @name configuracaoInicial
 * @brief Esta função irá correr a configuração inicial do programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void configuracaoInicial() { setlocale(LC_ALL, "Portuguese"); }

/**
 * 
 * @name limparJanela
 * @brief Esta função irá limpar a janela ao utilizador dependendo do sistema operativo a ser usado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void limparJanela() { printf("\e[1;1H\e[2J"); }

/**
 * 
 * @name homeCursor
 * @brief Esta função irá colocar o cursor na posição home
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void homeCursor() { printf("\e[H"); }
    
/**
 * 
 * @name linhaInicialCursor
 * @brief Esta função irá colocar o cursor na posição inicial
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void linhaInicialCursor() { printf("\e[0G"); }

/**
 * 
 * @name moverCursor
 * @brief Esta função irá mover o cursor para a linha X e a coluna Y
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Linha
 * @param int Coluna
 * 
 * @return Sem return
 * 
*/
void moverCursor(int linha, int coluna) { printf("\e[%d;%dH", linha, coluna); }

/**
 * 
 * @name upCursor
 * @brief Esta função irá mover o cursor X linhas para cima
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Linhas
 * 
 * @return Sem return
 * 
*/
void upCursor(int linhas) { printf("\e[%dA", linhas); }

/**
 * 
 * @name downCursor
 * @brief Esta função irá mover o cursor X linhas para baixo
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Linhas
 * 
 * @return Sem return
 * 
*/
void downCursor(int linhas) { printf("\e[%dB", linhas); }

/**
 * 
 * @name rightCursor
 * @brief Esta função irá mover o cursor X colunas para a direita
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Colunas
 * 
 * @return Sem return
 * 
*/
void rightCursor(int colunas) { printf("\e[%dC", colunas); }

/**
 * 
 * @name leftCursor
 * @brief Esta função irá mover o cursor X colunas para a esquerda
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Colunas
 * 
 * @return Sem return
 * 
*/
void leftCursor(int colunas) { printf("\e[%dD", colunas); }

/**
 * 
 * @name guardarCursor
 * @brief Esta função irá guardar a posição atual do cursor
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void guardarCursor() { printf("\e[s"); }

/**
 * 
 * @name restaurarCursor
 * @brief Esta função irá fazer com que o cursor volte para a posição definida no guardarCursor()
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void restaurarCursor() { printf("\e[u"); }


/**
 * 
 * @name quebrarLinhas
 * @brief Esta função irá mudar/quebrar as linhas indicadas
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Linhas
 * 
 * @return Sem return
 * 
*/
void quebrarLinhas(int linhas) { for (size_t i = 1; i <= linhas; i++) { printf("\n"); } }

/**
 * 
 * @name enviarTitulo
 * @brief Esta função irá enviar print do título parameterizado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param char Título a enviar
 * 
 * @return Sem return
 * 
*/
void enviarTitulo(char* titulo, bool right)
{
    time_t now;
    time(&now);                             
    struct tm *tempo = localtime(&now);

    printf(COR_Default"\n  Bem-vindo!      Hora atual: "COR_Cyan"%d:%d\n"COR_Default, tempo->tm_hour, tempo->tm_min);

    printf(COR_Green "\n"TL LINE TR"\n"VL"\t\t\t\t    "VL"\n");
    if(right) 
        printf(VL" %-33s "VR"\n", titulo);
    else
        printf(VL" %-34s "VL"\n", titulo);
    printf(COR_Green VL"\t\t\t\t    "VL "\n" BL LINE BR"\n\n");
}

/**
 * 
 * @name abrirMenu
 * @brief Esta função irá abrir um menu selecionado
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Número do menu a abrir
 * 
 * @return Sem return
 * 
*/
void abrirMenu(int menu)
{
    switch (menu)
    {
        /**
         * 
         * Iniciais
         * 
        */
       
        case 0:
            exit(1);
            break;
        case 1:
            menuEquipamentos();
            break;
        case 2:
            menuAplicacoes();
            break;
        case 3:
            menuPlacasRede();
            break;

        /**
         * 
         * Equipamentos
         * 
        */

        case 31:
            equipamentosInserir();
            menuEquipamentos();
            break;
        case 32:   
            equipamentosAlterar();
            menuEquipamentos();
            break;
        case 33:
            equipamentosEliminar();
            menuEquipamentos();
            break;
        case 34:
            equipamentosMostrar();
            menuEquipamentos();
            break;
        case 35:
            equipamentosFiltrar();
            menuEquipamentos();
            break;

        /**
         * 
         * Aplicações
         * 
        */

        case 41:
            aplicacoesInserir();
            menuAplicacoes();
            break;
        case 42:
            aplicacoesAlterar();
            menuAplicacoes();
            break;
        case 43:
            aplicacoesEliminar();
            menuAplicacoes();
            break;
        case 44:
            aplicacoesMostrar();
            menuAplicacoes();
            break;
        
        /**
         * 
         * Placas de rede
         * 
        */

        case 51:
            placasderedeInserir();
            menuPlacasRede();
            break;
        case 52:
            placasderedeAlterar();
            menuPlacasRede();
            break;
        case 53:
            placasderedeEliminar();
            menuPlacasRede();
            break;
        case 54:
            placasderedeMostrar();
            menuPlacasRede();
            break;
        
        /**
         * 
         * Outros
         * 
        */

        default:
            exit(1);
            break;
    }
}

/**
 * 
 * @name finalizarMenu
 * @brief Esta função irá finalizar o programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sem return
 * 
*/
void finalizarMenu() { printf("\n\n"); exit(0); }