/**
 * 
 * Menu principal
 * 
*/

void mostrarMenuEntrada()
{
    initscr();
    cbreak();
    noecho();

    mvaddch(0, 0, '+');
    mvaddch(LINES - 1, 0, '-');
    mvaddstr(10, 30, "press any key to quit");
    refresh();

    getch();

    endwin();
}