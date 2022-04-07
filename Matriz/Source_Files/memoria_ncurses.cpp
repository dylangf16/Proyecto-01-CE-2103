#include <iostream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

int mostrar_mem(int x){
initscr();

printw("Memoria usada: ");
cout << x << endl;
refresh();
usleep(10000);
for (int n = 0; x < 50; n++){
   mvaddch(0,n,'=');
   refresh();
   usleep(10000);
}
printw(" ");
printw("memoria usada");
refresh();
getch();
endwin();
return 0;

}