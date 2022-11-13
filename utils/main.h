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