/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:44:18 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/28 12:47:36 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "BulletList.hpp"
#include "Enemy.hpp"
#include "EnemyList.hpp"
#include "Logic.hpp"
#include "Player.hpp"
#include <time.h>
#include <string>
#include <iostream>

void mainMenu(WINDOW * win)
{
	std::string menuString = "* Press any key *";
	int choice = -1;
	int highlight = 0;
	int x = 50 / 2;
	int y = 30 / 2;

	box(win, 0, 0);
	refresh();
	wrefresh(win);

	while (choice == -1)
	{
		mvwprintw(win, y / 2, x / 2, menuString.c_str());
		choice = wgetch(win);
	}
}

int main(void) {
    clock_t ticks;
    clock_t score;
    int createFlag = 0;
    int mvFlag = 0;

	initscr();
    noecho();
    cbreak();
    curs_set(0);

    WINDOW* win = newwin(30, 50, 1, 0);
    box(win, '?', 0);
    refresh();
    wrefresh(win);
    keypad(win, true);
    nodelay(win, true);
    Player* p = new Player('>', win);
    Logic* l = new Logic(win, p);
	mainMenu(win);
    while (1) {
        box(win, 0, 0);
        ticks = clock() / (CLOCKS_PER_SEC / 32);
        score = clock() / CLOCKS_PER_SEC * 10;
        mvprintw(0, 0, "Score: %i\tTime: %i\tLifes: %i", score, score / 10, p->getLifes());
        refresh();
        l->displAll();
        if (!l->checkInput())
            break;
        if (ticks % 2 == 0 && createFlag == 0) {
            l->createEnemy();
            createFlag = 1;
        }
        if (ticks % 2 == 0 && mvFlag == 0) {
            l->mvAll();
            if (!l->checkPlayerColision())
                break;
            l->checkOB();
            l->checkBulletCollision();

            mvFlag = 1;
        }

        if (ticks % 2 == 1) {
            createFlag = 0;
            mvFlag = 0;
        }
    }
    nodelay(win, false);
    erase();
    werase(win);
    mvprintw(0,0, "GAME OVER! (DOUBLE TAP TO EXIT)");
    refresh();
    wrefresh(win);
    wgetch(win);
    wgetch(win);
    endwin();
}