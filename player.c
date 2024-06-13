/**
 * @file player.c
 * @author ARMAGAN OMER-ALI / YANG TIANYI
 *
 *
 * @brief Deplacement du PLAYER dans la direction choisie
 * @param g Pointeur vers la structure Grid qui represente la grille de jeu
 * @param d Direction dans laquelle le joueur va se déplacer
 * @return void
 *
 *
 * @date 03/2023
 * @copyright Copyright (c) 2023
 */

#include "player.h"
#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(struct Grid *g, enum Direction d)
{
    int next_x = g->position.x; // initiale prochaine x égale current position x
    int next_y = g->position.y; // initiale prochaine y égale current position x
    if (d == top)
    {
        next_x -= 1;
    }
    if (d == left)
    {
        next_y -= 1;
    }
    if (d == right)
    {
        next_y += 1;
    }
    if (d == bottom)
    {
        next_x += 1;
    }
    if (g->game_grid[next_x][next_y] == NONE)
    { // si prochaine position est ' ' on remplir prochaine et reset player position
        if (g->game_grid[g->position.x][g->position.y] == PLAYER_ON)
        {
            g->game_grid[next_x][next_y] = PLAYER;
            g->game_grid[g->position.x][g->position.y] = GOAL;
            g->position.x = next_x;
            g->position.y = next_y;
        }
        else
        {
            g->game_grid[next_x][next_y] = PLAYER;
            g->game_grid[g->position.x][g->position.y] = NONE;
            g->position.x = next_x;
            g->position.y = next_y;
        }
    }

    if (g->game_grid[next_x][next_y] == BOX)
    {
        int box_x = (next_x - g->position.x) * 2 + g->position.x;
        int box_y = (next_y - g->position.y) * 2 + g->position.y;

        if (g->game_grid[box_x][box_y] == NONE)
        {
            if (g->game_grid[g->position.x][g->position.y] == PLAYER_ON)
            {
                g->game_grid[box_x][box_y] = BOX;
                g->game_grid[next_x][next_y] = PLAYER;
                g->game_grid[g->position.x][g->position.y] = GOAL;
                g->position.x = next_x;
                g->position.y = next_y;
            }
            else
            {
                g->game_grid[box_x][box_y] = BOX;
                g->game_grid[next_x][next_y] = PLAYER;
                g->game_grid[g->position.x][g->position.y] = NONE;
                g->position.x = next_x;
                g->position.y = next_y;
            }
        }

        if (g->game_grid[box_x][box_y] == GOAL)
        {
            g->game_grid[box_x][box_y] = BOX_ON;
            g->game_grid[next_x][next_y] = PLAYER;
            g->game_grid[g->position.x][g->position.y] = NONE;
            g->position.x = next_x;
            g->position.y = next_y;
            g->box_goal_number++;
        }
    }

    if (g->game_grid[next_x][next_y] == GOAL)
    {
        g->game_grid[next_x][next_y] = PLAYER_ON;
        g->game_grid[g->position.x][g->position.y] = NONE;
        g->position.x = next_x;
        g->position.y = next_y;
    }

    if (g->game_grid[next_x][next_y] == BOX_ON)
    {
        int boxon_x = (next_x - g->position.x) * 2 + g->position.x;
        int boxon_y = (next_y - g->position.y) * 2 + g->position.y;
        if (g->game_grid[boxon_x][boxon_y] == NONE)
        {
            g->game_grid[boxon_x][boxon_y] = BOX;
            g->game_grid[next_x][next_y] = PLAYER_ON;
            g->game_grid[g->position.x][g->position.y] = NONE;
            g->position.x = next_x;
            g->position.y = next_y;
            g->box_goal_number--;
        }
    }
}
