#include "menu.h"

void menus(bool* in_menus, bool* changing_menu) {
    char choix;
    Menu menu = HOMEPAGE;
    while (*in_menus) {
        //changing_menu?printf("yes\n\n"):printf("no\n\n");

        if (*changing_menu) {
            draw_menu(menu);
            *changing_menu = false;
        }
        else {
            if (menu == HOMEPAGE) {
                choix = getch();
                if (choix == 's' || choix == 'S') {
                    *in_menus = false;
                }
            }

            if (menu == USERNAME) {
                menu = DEATH;
            }

            if (menu == DEATH) {
                choix = getch();
                if (choix == 'g' || choix == 'G') {
                    *in_menus = false;
                }
            }
        }
    }

}

void draw_menu(Menu menu) {
    FILE *file;
    char filename[20] = "homepage.txt";
    char line[50];

    file = fopen(filename, "r");
    if (file == NULL) {
        wprintf(L"Error: Could not open file %s\n", filename);
    }
    //clear();
    while (fgets(line, sizeof(line), file) != NULL) {
        wprintf(L"%s", line);
    }
    fclose(file);
}


