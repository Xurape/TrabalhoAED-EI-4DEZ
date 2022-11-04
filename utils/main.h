/*
|--------------------------------------------------------------------------
| Obter sistema operativo
|--------------------------------------------------------------------------
|
| Esta função detetará o sistema operativo
| onde o utilizador está a correr o programa.
|
*/
char* obterSO() 
{
    #ifdef _WIN32
        return "WIN";
    #elif linux
        return "LINUX";
    #elif __APPLE__
        return "MAC";
    #else
        return "UNKNOWN";
    #endif
}