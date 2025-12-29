#ifndef WEAPON_BONUS_H
#define WEAPON_BONUS_H

#include "game.h"


typedef struct s_gun
{
    t_img img;

}t_gun;


void load_gun(t_game *game);
void draw_gun(t_game *game);

#endif