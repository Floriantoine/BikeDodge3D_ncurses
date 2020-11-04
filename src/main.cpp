/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for Dante solver
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/main.hpp"
#include "../include/entityClass.hpp"
#include "../include/settingClass.hpp"
#include "../include/struct.hpp"
#define COLOR_BROWN 8

SettingClass setting;
EntityClass entity(setting);

int init_ncurses(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    nodelay(stdscr, true);
    if (has_colors() == FALSE) {
        printf("Your terminal does not support color\n");
        return (1);
    }
    start_color();
    init_color (COLOR_BROWN, 139, 69, 19);
    init_color (COLOR_BLACK, 93, 109, 126);
    init_pair(1, COLOR_GREEN, COLOR_BROWN);
    init_pair(2, COLOR_BROWN, COLOR_BROWN);
    return (0);
}

void initObj(obj_t *objInf) {
    objInf->y = 10;
    objInf->x_init = objInf->x;
    objInf->next = NULL;
}

int init(road_inf_t *roadInf, obj_t *objInf)
{
    roadInf->x = 0;
    roadInf->y = 5;
    roadInf->first_loop = 0;
    initObj(objInf);
    return 1;
}

int body(road_inf_t *roadInf, obj_t *objInf);

int main(void)
{
    srand(time(NULL));
    road_inf_t roadInf;
    obj_t objInf;
    init_ncurses();
    init(&roadInf, &objInf);
    return (body(&roadInf, &objInf));
}