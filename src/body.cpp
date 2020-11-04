#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/main.hpp"
#include "../include/struct.hpp"


int checkCol(int posX, int posY) {
    if((posX >= entity.getPlayerPosX() + entity.getPlayerSize())      // trop à droite
	    || (posX + 3 <= entity.getPlayerPosX()) // trop à gauche
	    || (posY >= entity.getPlayerPosY() + entity.getPlayerSize()) // trop en bas
	    || (posY + 5 <= entity.getPlayerPosY()))  // trop en haut
        return 0;
    else
        return 1;
}

void newObj(obj_t *objInf) {
    obj_t *tempo = objInf;
    obj_t *newObj = NULL;

    while (tempo->next != NULL) {
        tempo = tempo->next;
    }
    newObj = new obj_t;
    newObj->x = (setting.getWindowSizeX() / 2) + randy(-15, 15, 9);
    newObj->y = randy(-20, 10, 11);
    newObj->x_init = objInf->x;
    newObj->next = NULL;
    tempo->next = newObj;
}

bool drawTree(int posX, int posY) {
    if (checkCol(posX - 1, posY - 5)) {
        setting.setGameState(false);
        return false;
    }
    attron(COLOR_PAIR(2));
    mvaddch(posY, posX, '#');
    mvaddch(posY - 1, posX, '#');
    mvaddch(posY - 2, posX, '#');
    mvaddch(posY - 3, posX, '#');
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    mvaddch(posY - 3, posX - 1, '#');
    mvaddch(posY - 3, posX + 1, '#');
    mvaddch(posY - 4, posX - 1, '#');
    mvaddch(posY - 4, posX + 1, '#');
    mvaddch(posY - 4, posX + 2, '#');
    mvaddch(posY - 4, posX + 3, '#');
    mvaddch(posY - 5, posX - 1, '#');
    mvaddch(posY - 5, posX + 1, '#');
    mvaddch(posY - 5, posX + 3, '#');
    attroff(COLOR_PAIR(1));
    return true;
}

bool moveObj(obj_t *objInf)
{
    obj_t *tempo = objInf;

    while (tempo != NULL) {
        if (tempo->x > setting.getWindowSizeX() / 2 && tempo->y >= 10)
            tempo->x += 0.014 * (tempo->x_init - (setting.getWindowSizeX() / 2)) ;
        else if (tempo->y >= 10)
            tempo->x -= 0.014 * ((setting.getWindowSizeX() / 2) - tempo->x_init) ;
        tempo->y += 1;
        if (tempo->y >= 6)
            drawTree(tempo->x, tempo->y);
        if (tempo->y >= setting.getWindowSizeY()) {
            tempo->x = (setting.getWindowSizeX() / 2) + randy(-15, 15, 9);
            tempo->y = randy(-20, 10, 11);
            tempo->x_init = tempo->x;
        }
        tempo = tempo->next;
    }
    return true;
}

void drawRoad(road_inf_t *roadInf)
{
    int loop = roadInf->first_loop;
    int roadLoop = 0;

    while ((setting.getWindowSizeX() / 2) + roadLoop < setting.getWindowSizeX()) {
        if (loop == 0 || loop == 1 || loop == 2) {
            mvaddch(roadInf->y, (setting.getWindowSizeX() / 2) + roadInf->x + roadLoop + 20, '\\');
            mvaddch(roadInf->y, (setting.getWindowSizeX() / 2) + roadInf->x - roadLoop - 20, '/');
            loop++;
        } else if (loop == 3) {
            drawTree((setting.getWindowSizeX() / 2) + roadInf->x + roadLoop + 20, roadInf->y);
            drawTree((setting.getWindowSizeX() / 2) + roadInf->x - roadLoop - 20, roadInf->y);
            loop = 0;
        }
        roadInf->y++;
        roadLoop += (setting.getWindowSizeX() / 2 + 20) / setting.getWindowSizeY() ;
    }
    roadInf->first_loop += 1;
    if (roadInf->first_loop > 2)
        roadInf->first_loop = 0;
    roadInf->y = 5;
}

void playerInputMoveObj(obj_t *objInf, int xMove)
{
    obj_t *tempo = objInf;

    while (tempo != NULL) {
        tempo->x += xMove;
        tempo = tempo->next;
    }
}

int playerInput(road_inf_t *roadInf, obj_t *objInf) {
    int entry = getch();
    if (entry == -1)
        return 0;
    if (entry == 261) {
        roadInf->x--;
        playerInputMoveObj(objInf, -2);
    } else if (entry == 260) {
        roadInf->x++;
        playerInputMoveObj(objInf, 2);
    }
    return 0;
}

int body(road_inf_t *roadInf, obj_t *objInf) {
    int loop = 0;
    setting.setGameState(true);
    while (setting.getGameState()) {
        if (loop > 500000) {
            newObj(objInf);
            loop = 0;
        }
        if ((clock() - setting.getClock()) > 60000)  {
            clear();
            drawRoad(roadInf);
            entity.drawPlayer();
            moveObj(objInf);
            refresh();
            setting.restartClock();
        }
        playerInput(roadInf, objInf);
        loop++;
    }
    clear();
    endwin();
    return (0);
}