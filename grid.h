/**
 * @file grid.h
 * @author ARMAGAN OMER-ALI / YANG TIANYI
 * 
 * 
 *  @struct Casetype
 *	@brief Type énuméré qui a différents types de cases de la grille de jeu
 * * * * * * * * * * * * * * *
 *  @struct Player
 *  @brief Structure représentant la position du joueur sur la grille de jeu
 * * * * * * * * * * * * * * *
 *  @struct Grid
 *  @brief Cette structure contient les informations concernant la grille du jeu et son contenu
 * 
 * 
 * 
 * @date 03/2023
 * @copyright Copyright (c) 2023
 */

#ifndef GRID_HEADER
#define GRID_HEADER

enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	BOX_ON = '*',
	PLAYER_ON = '/',
	NONE = ' '
};

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */

struct Player{
	int x;
	int y;
};

struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
	int goal_number;
	int box_goal_number;
	struct Player position; ///Player current position
};

void init_level(const char* file_path,struct Grid* g);
void display(struct Grid* g);
void freetab(struct Grid* g);


#endif
