#include <string.h>
#include "ft_retro.hpp"

void    launch_screen3() {
    const char  *msg = "Déplacez vous avec les flèches GAUCHE et DROITE";
    const char  *msg2 = "Tirez avec ESPACE";
    const char  *msg3 = "Surveillez votre niveau de vie en haut ainsi que le temps restant";
    const char  *msg4 = "Appuyez sur une touche pour commencer";
    int         taille = strlen(msg);
    int         taille2 = strlen(msg2);
    int         taille3 = strlen(msg3);
    int         taille4 = strlen(msg4);

    while(1) {
        if (LINES < 40 || COLS < 100)
            check_term_size();
        clear();
        mvprintw(LINES/2 - 5, COLS/2 - taille/2, "%s", msg);
        mvprintw(LINES/2 - 4, COLS/2 - taille2/2, "%s", msg2);
        mvprintw(LINES/2 - 1, COLS/2 - taille3/2, "%s", msg3);
        mvprintw(LINES/2 + 4, COLS/2 - taille4/2, "%s", msg4);
        refresh();
        if(getch() != 410)
            start_game();
    }
}

void    launch_screen2() {
    const char  *msg = "ft_retro est un jeu de science-fiction dans l'espace";
    const char  *msg2 = "Votre but est de détruire les vaisseaux adverses";
    const char  *msg3 = "Vous devez faire attention à leurs missiles";
    const char  *msg4 = "Vous pourrez ramasser les bonus qui apparaissent sur votre route";
    const char  *msg5 = "Attention toutefois à ne pas entrer en contact avec une astéroïde";
    int         taille = strlen(msg);
    int         taille2 = strlen(msg2);
    int         taille3 = strlen(msg3);
    int         taille4 = strlen(msg4);
    int         taille5 = strlen(msg5);
    while(1) {
        if (LINES < 40 || COLS < 100)
            check_term_size();
        clear();
        mvprintw(LINES/2 - 5, COLS/2 - taille/2, "%s", msg);
        mvprintw(LINES/2 - 4, COLS/2 - taille2/2, "%s", msg2);
        mvprintw(LINES/2 -1, COLS/2 - taille3/2, "%s", msg3);
        mvprintw(LINES/2, COLS/2 - taille4/2, "%s", msg4);
        mvprintw(LINES/2 + 1, COLS/2 - taille5/2, "%s", msg5);
        mvprintw(LINES/2 + 4, COLS/2 - 11, "Appuyez sur une touche");
        refresh();
        if(getch() != 410)
            launch_screen3();
    }
}

void    launch_screen() {
    const char  *msg = "Vérification effectuée, votre expérience peut commencer";
    int         taille = strlen(msg);
    while(1) {
        if (LINES < 40 || COLS < 100)
            check_term_size();
        clear();
        mvprintw(LINES/2, COLS/2 - taille/2, "%s", msg);
        mvprintw(LINES/2 + 3, COLS/2 - 11, "Appuyez sur une touche");
        refresh();  
        if(getch() != 410)
            launch_screen2();
    }
}

void    check_term_size() {
    const char  *msg = "Merci d'agrandir votre terminal pour profiter";
    const char  *msg2= "d'une meilleur expérience de jeu";
    int         taille = strlen(msg);
    int         taille2 = strlen(msg2);
    while (LINES < 40 || COLS < 100) {
        clear();
        mvprintw(LINES / 2 - 2, COLS/2 - 26, 
                "Le terminal actuel comporte %d lignes et %d colonnes", LINES, COLS);
        mvprintw(LINES/2, COLS/2 - taille/2, "%s", msg);
        mvprintw(LINES/2 + 1, COLS/2 - taille2/2,  "%s", msg2);
        refresh();
        getch();
    }
    clear();
    launch_screen();
}