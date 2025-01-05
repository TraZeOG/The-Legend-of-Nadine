#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <termios.h>
#include <poll.h>
#include <string.h>
#include <unistd.h>

int acquisition_time;
int getch() { 
    int ch;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~ICANON;
    newattr.c_lflag &= ~ECHO;
    newattr.c_cc[VMIN] = 1;
    newattr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
    
    if( poll(&mypoll, 1, acquisition_time) )
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return ch; 
}