/**
 * 
 * @name obterSO
 * @brief Esta função detetará o sistema operativo onde o utilizador está a correr o programa
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param null Sem parametros
 * 
 * @return Sistema operativo
 * 
*/
char* obterSO() 
{
    #ifdef _WIN32
        return "Windows";
    #elif linux
        return "Linux";
    #elif __APPLE__
        return "MacOS";
    #else
        return "Desconhecido";
    #endif
}

/**
 * 
 * @name truncateString
 * @brief Esta função irá verificar e encurtar a string
 * @author João Ferreira & Gabriel Gavino
 * 
 * @param char String
 * @param int Máximo de tamanho
 * 
 * @return Sistema operativo
 * 
*/

char truncateString(char *str, int pos)
{
    return str - pos;
}