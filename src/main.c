#include "main.h"

int main() {
    bool in_menus = true;
    bool changing_menu = true;
    setlocale(LC_ALL, "");
    wprintf(L"\e[9;1t");
    system("xdotool getactivewindow windowstate --add fullscreen");
    system("osascript -e 'tell application \"Terminal\" to activate' -e 'tell application \"System Events\" to keystroke \"f\" using {command down, control down}'");
    wprintf(L"\033[?25l");
    clear();
    //SDL_Init(SDL_INIT_AUDIO);
    //Mix_Music* music = init_music("assets/music/music.mp3");
    //play_music(music);
    int run = true;
    while (run) {
        if (in_menus) {
            menus(&in_menus, &changing_menu);
        }
        else {
            game(&in_menus);
        }
    }
}