#include <stdio.h>  //Utilisation de la fonction d'affichage
#include <stdlib.h> //Pour srand() et rand() 
#include <time.h>   //initialisation de srand avec time()

//Pour Linux et/ou MacOS. Ne pas oublier de linker -lncurses
//compilation à l'aide de la commande 
//sous LINUX/MacOS/Cygwin : gcc -lncurses -o jeu jeuModeConsole_0.c
//sous Windows, MinGW : gcc -o jeu jeuModeConsole_0.c -lncurses
#include <ncurses.h>


//Linux
#define EMPTY_PAIR     1
#define PLAYER_PAIR    2
#define PLAYER    'X'
#define EMPTY     ' '

void gotoxy(int x, int y){
    move(x,y);
}

void mvaddcolorch(int x, int y, int colorpairnb, char chartoprint){
    attron(COLOR_PAIR(colorpairnb));
    mvaddch(y, x, chartoprint);
    attroff(COLOR_PAIR(colorpairnb));
    refresh();
}

void initjeu(){
    initscr(); //Initialise systeme pour utilisation d'un terminal en mode ncurses
    keypad(stdscr, TRUE);
    cbreak(); //enlève la temporisation (pas de buffer pour les entrées) mais 
              //conserve l'interpréation des signaux ^C ou ^Z
    noecho(); /* Don't echo() while we do getch */
    if (has_colors() == FALSE){ //On teste les possibilité d'affichage en couleur du terminal
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(EMPTY_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);
    clear(); //nettoyage du terminal

}

int main()
{
    int fin=0, res, x, y;
    int ch;
    //initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    initjeu();

    x = rand()%COLS; //On positionne le joueur au hasard sur la zone de jeu
    y = rand()%LINES; 

    //On positionne le curseur du joueur sur le terminal
    move(y, x);
    //On affiche sa position en couleur 
    mvaddcolorch(x,y,PLAYER_PAIR,PLAYER);

    do{
        //Pour avoir l'effet clignotant du curseur
        //On efface le joueur de la position ou il était
        mvaddcolorch(x,y,EMPTY_PAIR,EMPTY);

        //Lecture non blocante de la touche enfoncée
        ch = getch();
        
        switch (ch){
            case KEY_UP:
            case 72:
            case 'E':
            case 'e': y--; break;
            case KEY_DOWN:
            case 80:
            case 'C':
            case 'c': y++; break;
            case KEY_LEFT:
            case 75:
            case 'S':
            case 's': x--; break;
            case KEY_RIGHT:
            case 77:
            case 'F':
            case 'f': x++; break;
            case 224: break; //evacuer la touche combinée
            default: fin=1; break; //Autre touche, fin du programme
        }
        
        if (x<0) x=COLS;
        else{
            if (x>COLS) x=0;
        } 
        if (y<0) y=LINES;
        else{ if (y>LINES) y=0;}

         //On affiche sa position en couleur 
        mvaddcolorch(x,y,PLAYER_PAIR,PLAYER);
        napms(50);
        
    }while ((ch !='q') && (ch != 'Q'));

    
    endwin(); //Sortie de l'environnement curses et retour au contrôle de base
    exit(0);
}



