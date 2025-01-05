#include "getch.c"
#include "menu.h"

void menus(bool* in_menus) {
    Menu menu = HOMEPAGE;
    bool changing_menu = false;
    while (*in_menus) {
        //changing_menu?printf("yes\n\n"):printf("no\n\n");

        if (changing_menu) {
            draw_menu(menu);
            changing_menu = false;
        }
        else {
            if (menu == HOMEPAGE) {
                choix = getch();
                if (choix == 's' || choix == 'S') {
                    menu = USERNAME;
                    changing_menu = true;
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
        printf("Error: Could not open file %s\n", filename);
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    printf("\ni'm done\n\n");
    fclose(file);
}


