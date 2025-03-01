#include "game.h"

            

void game (bool* in_menus) {
    setlocale(LC_ALL, "");
    // Time variables
    double refresh_rate = 0.06;
    struct timeval last, now;
    gettimeofday(&last, NULL);
    Player player = {20, 20};
    Board* board = init_board(40, 80);
    default_chunk(board);
    Map* map = create_map();

    ///boucle principale ----------------------------------------------------
    int run = true ;
    while (run) {
        int n  = getch();
        gettimeofday(&now, NULL);
        double time_taken = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) * 1e-6;
        if (time_taken > refresh_rate) {
            last = now;
            switch (n) {
                case 'p':
                    run = false;
                    *in_menus = true;
                    break;
                case NORTH:
                case SOUTH:
                case WEST:
                case EAST:
                    move_player(&player, n, board, map);
                    break;
                case 'c':
                    interact(&player, board);
                    break;
            }
            render_screen(board);
        }




        usleep(10000); 
    }
}