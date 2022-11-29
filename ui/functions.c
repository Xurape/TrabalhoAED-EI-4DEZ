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

void goHomeCursor() { printf("\e[H"); }
    
void lineStartCursor() { printf("\e[0G"); }

void moveCursor(int line, int column) { printf("\e[%d;%dH", line, column); }

void upCursor(int lines) { printf("\e[%dA", lines); }

void downCursor(int lines) { printf("\e[%dB", lines); }

void rightCursor(int columns) { printf("\e[%dC", columns); }

void leftCursor(int columns) { printf("\e[%dD", columns); }

void saveCursor() { printf("\e[s"); }

void restoreCursor() { printf("\e[u"); }


/**
 * 
 * @name quebrarLinhas
 * @brief Esta função irá mudar/quebrar as linhas indicadas
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param int Número de linhas
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
void enviarTitulo(char* titulo)
{
    time_t now;
    time(&now);    
    struct tm *tempo = localtime(&now);

    printf(COR_Default"\n  Bem-vindo!      Hora atual: "COR_Cyan"%d:%d\n"COR_Default, tempo->tm_hour, tempo->tm_min);

    printf(COR_Green "\n"TL LINE TR"\n\n");
    printf("      %s", titulo);
    printf(COR_Green "\n"BL LINE BR"\n\n");

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
            break;
        case 42:
            break;
        case 43:
            break;
        case 44:
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