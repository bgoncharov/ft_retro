/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:44:18 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/26 20:51:01 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <time.h>
#include "Player.hpp"
#include "Logic.hpp"

int main(void) {
    clock_t ticks;
    clock_t score;
    int createFlag = 0;
    int moveFlag = 0;

	initscr();
    noecho();
    cbreak();
    curs_set(0);

    WINDOW* win = newwin(30, 50, 1, 0); // (window size, window location)
    box(win, '?', 0);
    refresh();
    wrefresh(win);
    keypad(win, true);
    nodelay(win, true);
    Player *p = new Player('>', win);
    Logic *l = new Logic(win, p);
    while (1) {
        box(win, 0, 0);
        ticks = clock() / (CLOCKS_PER_SEC / 32);
        score = clock() / CLOCKS_PER_SEC * 10;
        
        mvprintw(0, 0, "Score: %i\tTime: %i\tLifes: %i", score, score / 10, p->getLifes());
        refresh();
        if (!l->checkInput())
            break;
        if (ticks % 2 == 0 && createFlag == 0) {
            createFlag = 1;
        }
        if (ticks % 2 == 0 && moveFlag == 0) {
            if (!l->checkPlayerColision())
                break;

            moveFlag = 1;
        }

        if (ticks % 2 == 1) {
            createFlag = 0;
            moveFlag = 0;
        }
    }
    nodelay(win, false);
    erase();
    werase(win);
    refresh();
    wrefresh(win);
    wgetch(win);
    wgetch(win);
    endwin();
}