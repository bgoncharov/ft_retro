/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:30:08 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/26 20:50:20 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logic.hpp"

Logic::Logic(void) {
    return ;
}

Logic::Logic(WINDOW* win, Player* player) {
	int x;
    int y;
    getmaxyx(win, y, x);
	this->_maxy = y;
	this->_maxx = x;
	this->_minx = 0;
	this->_miny = 0;
	this->_player = player;
	this->_win = win;
    return ;
}

Logic::Logic(Logic const & src) {
    *this = src;
    return ;
}

Logic::~Logic(void) {
    return ;
}

Logic & Logic::operator=(Logic const & rhs) {
    if (this != &rhs) {
		this->_player = rhs.getPlayer();
		this->_maxy = getMaxy();
		this->_maxx = getMaxx();
		this->_minx = getMinx();
		this->_miny = getMiny();
		this->_win = getWin();

	}
    return *this;
}

void Logic::displayAll(void) const {
	this->_player->displ();
	wrefresh(this->_win);
}

int Logic::checkPlayerColision(void) {
	Player *player;

	player = this->_player;

	if (player->getLifes() <= 0)
		return (0);
	return (1);
}


int Logic::checkInput(void) {
    int choice = wgetch(this->_win);
    switch(choice)
    {
    case KEY_UP:
      	this->_player->mvUp();
      	break;
    case 'w':
      	this->_player->mvUp();
      	break;
    case KEY_DOWN:
      	this->_player->mvDown();
      	break;
    case 's':
      	this->_player->mvDown();
      	break;
    case KEY_LEFT:
       	this->_player->mvLeft();
      	break;
    case 'a':
       	this->_player->mvLeft();
      	break;
    case KEY_RIGHT:
      	this->_player->mvRight();
      	break;
    case 'd':
      	this->_player->mvRight();
      	break;
    case 32:
      	//this->shot();
      	break;
	case '\t':
		_displayMenu();
		break ;
    default:
      break;
    }
    if (this->checkPlayerColision())
        return (1);
    return (0);

}




Player* Logic::getPlayer(void) const{
    return this->_player;
}

void Logic::setPlayer(Player* player) {
    this->_player = player;
}

int Logic::getMaxx(void) const{
    return this->_maxx;
}

void Logic::setMaxx(int maxx) {
    this->_maxx = maxx;
}

int Logic::getMaxy(void) const{
    return this->_maxy;
}

void Logic::setMaxy(int maxy) {
    this->_maxy = maxy;
}

int Logic::getMinx(void) const{
    return this->_minx;
}

void Logic::setMinx(int minx) {
    this->_minx = minx;
}
int Logic::getMiny(void) const{
    return this->_miny;
}

void Logic::setMiny(int miny) {
    this->_miny = miny;
}

WINDOW *Logic::getWin(void) const{
    return this->_win;
}

void Logic::setWin(WINDOW* win) {
    this->_win = win;
}