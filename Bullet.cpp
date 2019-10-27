/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:03:33 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/26 21:18:41 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(void) {
    return ;
}

Bullet::Bullet(int posx, int posy, WINDOW *win) {
    this->_posx = posx;
    this->_posy = posy;
    this->_win = win;
    return ;
}

Bullet::Bullet(Bullet const & src) {
    *this = src;
    return ;
}

Bullet::~Bullet(void) {
    return ;
}

Bullet & Bullet::operator=(Bullet const & rhs) {
    if (this != &rhs) {
	    this->_posx = getPosx();
	    this->_posy = getPosy();
	    this->_win = getWin();
	}
    return *this;
}

void Bullet::move(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posx += 1;
}

void Bullet::displ(void) const {
    mvwaddch(this->_win, this->_posy, this->_posx, '-');
}

int Bullet::getPosx(void) const{
    return this->_posx;
}

void Bullet::setPosx(int posx) {
    this->_posx = posx;
}

int Bullet::getPosy(void) const{
    return this->_posy;
}

void Bullet::setPosy(int posy) {
    this->_posy = posy;
}

WINDOW *Bullet::getWin(void) const{
    return this->_win;
}

void Bullet::setWin(WINDOW* win) {
    this->_win = win;
}