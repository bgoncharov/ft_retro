/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:22:11 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/26 19:05:47 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) {
    return ;
}

Player::Player(char c, WINDOW *win) {
    int x;
    int y;
    getmaxyx(win, y, x);
    this->_lifes = 3;
    this->_posx = x / 2;
    this->_posy = y / 2;
    this->_score = 0;
    this->_maxy = y - 1;
    this->_maxx = x - 1;
    this->_minx = 1;
    this->_miny = 1;
    this->_c = c;
    this->_win = win;
    return ;
}

Player::Player(Player const & src) {
    *this = src;
    return ;
}

Player::~Player(void){
    return ;
}

Player& Player::operator=(Player const & rhs) {
    if (this != &rhs) {
        this->_lifes = getLifes();
        this->_posx = getPosx();
        this->_posy = getPosy();
        this->_score = getScore();
        this->_maxy = getMaxy();
        this->_maxx = getMaxx();
        this->_minx = getMinx();
        this->_miny = getMiny();
        this->_c = getChar();
        this->_win = getWin();
    }
    return *this;
}

void Player::mvUp(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posy -= 1;
    if (this->_posy < this->_miny)
        this->_posy = this->_miny;
}

void Player::mvDown(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posy += 1;
    if (this->_posy > this->_maxy)
        this->_posy = this->_maxy;
}

void Player::mvLeft(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posx -= 1;
    if (this->_posx < this->_minx)
        this->_posx = this->_minx;
}

void Player::mvRight(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posx += 1;
    if (this->_posx > this->_maxx)
        this->_posx = this->_maxx;
}

void Player::displ(void) const {
    mvwaddch(this->_win, this->_posy, this->_posx, this->_c);
}


//Setter and getters
int Player::getLifes(void) const{
    return this->_lifes;
}

void Player::setLifes(int lifes) {
    this->_lifes = lifes;
}

int Player::getPosx(void) const{
    return this->_posx;
}

void Player::setPosx(int posx) {
    this->_posx = posx;
}

int Player::getPosy(void) const{
    return this->_posy;
}

void Player::setPosy(int posy) {
    this->_posy = posy;
}

int Player::getScore(void) const{
    return this->_score;
}

void Player::setScore(int score) {
    this->_score = score;
}
int Player::getMaxx(void) const{
    return this->_maxx;
}

void Player::setMaxx(int maxx) {
    this->_maxx = maxx;
}

int Player::getMaxy(void) const{
    return this->_maxy;
}

void Player::setMaxy(int maxy) {
    this->_maxy = maxy;
}

int Player::getMinx(void) const{
    return this->_minx;
}

void Player::setMinx(int minx) {
    this->_minx = minx;
}

int Player::getMiny(void) const{
    return this->_miny;
}

void Player::setMiny(int miny) {
    this->_miny = miny;
}

char Player::getChar(void) const{
    return this->_c;
}

void Player::setChar(char c) {
    this->_c = c;
}

WINDOW *Player::getWin(void) const{
    return this->_win;
}

void Player::setWin(WINDOW* win) {
    this->_win = win;
}