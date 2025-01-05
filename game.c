#include "game.h"
#include "player.c"
#include "board.c"
#include <sys/time.h>

#define clear() printf("\033[H\033[J")

void game () {
    board = init_board(ROW, COL, board[ROW][COL]);
    // Time variables
    double refresh_rate = 0.06;
    struct timeval last, now; 
    gettimeofday(&last, NULL);

    ///boucle principale ----------------------------------------------------
    int run = true ;
    while (run) {
        int n  = getch();
        gettimeofday(&now, NULL);
        double time_taken = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) * 1e-6;
        if (time_taken > refresh_rate) {
            last = now;
            move_player(player, n);
            print_board(ROW, COL, board);
        }




        usleep(5000); 
    }
}