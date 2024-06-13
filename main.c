/**
 * @file main.c
 * @author ARMAGAN OMER-ALI / YANG TIANYI
 *
 *
 * @fn int main
 * @brief Initialisation de la grille à partir du fichier "level1.txt"
 * et on affiche la grille initiale et on deplace le joueur a l'aide des touches z,q,s,d
 * Quand la touche 'a' est saisie, c'est la fin de la boucle et la mémoire allouée est libérée pour la grille
 * @return 0 si pas d'erreur
 *
 *
 * @date 03/2023
 * @copyright Copyright (c) 2023
 */

#include "grid.h"
#include "player.h"
#include "sdl2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	void (*handle_init)();
	Event (*handle_event)(void);
	void (*handle_display)(struct Grid * grid);

	int ModeGraphique = 1, ModeConsole = 1;
	if (argc > 1)
	{
		ModeConsole = strcmp(argv[1], "--console");
		ModeGraphique = strcmp(argv[1], "--sdl2");
	}

	if (argc == 1 || ModeConsole == 0)
	{
		handle_init = console_init;
		handle_event = event;
		handle_display = display;
	}

	else if (ModeGraphique == 0)
	{
		handle_init = sdl_init;
		handle_event = event_sdl2;
		handle_display = display_sdl2;
	}
	else
	{
		printf("Les commandes correctes sont:\n --sdl2 (mode graphiques)\n --console (mode console)\n");
		exit(EXIT_FAILURE);
	}

	struct Grid g;
	init_level("level1.txt", &g);
	handle_init();
	bool run = true;
	while (run) // z pour top, q pour gauch, s pour bottom, d pour droite, a pour quitter le jeu console
	{
		handle_display(&g);
		Event action = handle_event();
		switch (action)
		{
		case NON:
			break;
		case UP:
		{
			move_player(&g, top);
			handle_display(&g);
			break;
		}
		case LEFT:
		{
			move_player(&g, left);
			handle_display(&g);
			break;
		}
		case DOWN:
		{
			move_player(&g, bottom);
			handle_display(&g);
			break;
		}
		case RIGHT:
		{
			move_player(&g, right);
			handle_display(&g);
			break;
		}
		case QUIT:
		{
			run = false;
			break;
		}
		}
		if (g.box_goal_number == g.goal_number)
			run = false;
	}

	freetab(&g);
	return 0;
}
