/**
 * @file grid.c
 * @author ARMAGAN OMER-ALI / YANG TIANYI
 *
 *
 * @fn void init_level
 * @brief Initialise le niveau avec les informations contenues dans le fichier spécifié
 * @param file_path Le chemin du fichier à lire
 * @param g Un pointeur vers la grille du jeu
 * @return Rien (Il s'agit juste d'une modification de l'etat de la grille de jeu)
 * * * * * * * * * * * * * * *
 * @fn void display
 * @brief Affichage du contenu de la grille de jeu
 * @param g Pointeur vers la grille du jeu
 * @return Rien
 * * * * * * * * * * * * * * *
 * @fn void freetab
 * @brief Libèration de la mémoire allouée pour la grille de jeu
 * @param g Pointeur vers la grille de jeu
 * @return Rien
 *
 *
 * @date 03/2023
 * @copyright Copyright (c) 2023
 */

#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void init_level(const char *file_path, struct Grid *g)
{
	// ouverture du fichier en mode lecture
	FILE *file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0;	   /// nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	g->column_number = number_column; // remplir grid* g
	g->row_number = number_row;
	g->game_grid = malloc(g->row_number * sizeof(enum CaseType *));
	for (int i = 0; i < g->row_number; i++)
	{
		g->game_grid[i] = malloc(g->column_number * sizeof(enum CaseType *));
	}
	int current_row = 0;

	int current_goal = 0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while (fgets(line, 100, file) != NULL)
	{
		char *buffer = line;
		int current_column = 0;
		while (*buffer && *buffer != '\n')
		{
			g->game_grid[current_row][current_column] = *buffer;
			if (*buffer == '@') // set current position
			{
				g->position.x = current_row;	// x = ligne
				g->position.y = current_column; // y = colonne
			}
			if (*buffer == '.')
			{
				current_goal++;
			}
			current_column += 1;
			buffer += 1;
		}
		current_row += 1;
	}
	g->goal_number = current_goal;
	g->box_goal_number = 0;
	// fermeture du fichier
	fclose(file);
}

void display(struct Grid *g)
{
	for (int i = 0; i < g->row_number; i++)
	{
		for (int j = 0; j < g->column_number; j++)
		{
			printf("%c", g->game_grid[i][j]);
		}
		printf("\n");
	}
}


void freetab(struct Grid *g)
{
	for (int i = 0; i < g->row_number; i++)
	{
		free(g->game_grid[i]);
	}
	free(g->game_grid);
}
