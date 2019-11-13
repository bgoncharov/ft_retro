/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:22:10 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:04:58 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

Enemy::Enemy(void) {
    return ;
}

Enemy::Enemy(int posx, int posy, WINDOW *win) {
    this->_posx = posx;
    this->_posy = posy;
    this->_win = win;
    return ;
}

Enemy::Enemy(Enemy const & src) {
    *this = src;
    return ;
}

Enemy::~Enemy(void) {
    return ;
}

Enemy & Enemy::operator=(Enemy const & rhs) {
    if (this != &rhs) {
        this->_posx = getPosx();
        this->_posy = getPosy();
        this->_win = getWin();
    }
    return *this;
}

void Enemy::mv(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posx -= 1;
}

void Enemy::displ(void) const {
    mvwaddch(this->_win, this->_posy, this->_posx, '@');
}

int Enemy::getPosx(void) const{
    return this->_posx;
}

void Enemy::setPosx(int posx) {
    this->_posx = posx;
}

int Enemy::getPosy(void) const{
    return this->_posy;
}

void Enemy::setPosy(int posy) {
    this->_posy = posy;
}

WINDOW* Enemy::getWin(void) const{
    return this->_win;
}

void Enemy::setWin(WINDOW* win) {
    this->_win = win;
}