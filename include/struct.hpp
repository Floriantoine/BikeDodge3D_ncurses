/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H
    #include <time.h>
    #include "./entityClass.hpp"
    #include "./settingClass.hpp"
typedef struct obj_t
{
    float x;
    float y;
    float x_init;
    struct obj_t *next;
}obj_t;

typedef struct {
    float x;
    float y;
    int first_loop;
}road_inf_t;

extern EntityClass entity;
extern SettingClass setting;
#endif
