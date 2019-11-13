/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:11:32 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:18:35 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BulletList.hpp"

BulletList::BulletList(void) {
	this->_head = NULL;
	this->_next = NULL;
    return ;
}

BulletList::BulletList(BulletList const & src) {
    *this = src;
    return ;
}

BulletList::~BulletList(void) {
    return ;
}

BulletList & BulletList::operator=(BulletList const & rhs) {
    if (this != &rhs) {
		this->_head = rhs.getHead();
		this->_next = rhs.getNext();
	}
    return *this;
}

BulletNode* BulletList::createNode(Bullet* bullet) {
	BulletNode* tmp = new BulletNode;
	tmp->bullet = bullet;
	tmp->next = NULL;
	return (tmp);
}

void BulletList::addNode(Bullet* bullet) {
	BulletNode* tmp = this->createNode(bullet);
	BulletNode* run = this->_head;
	if (this->_head == NULL) {
		this->_head = tmp;
	} else {
		while(run->next)
			run = run->next;
		run->next = tmp;
	}
}

void BulletList::delNode(BulletNode* node) {
	BulletNode* current;
	BulletNode* previous;
	BulletNode* tmp;

	if (this->_head == NULL)
		return;
	if (/*this->_head->next == NULL && */node == this->_head) {
		tmp = this->_head->next;
		delete this->_head;
		this->_head = tmp;
		return ;
	}
	current = this->_head;
	while (current != node && current != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	delete current;
}

BulletNode* BulletList::getHead(void) const{
    return this->_head;
}

void BulletList::setHead(BulletNode* head) {
    this->_head = head;
}
BulletNode* BulletList::getNext(void) const{
    return this->_next;
}

void BulletList::setNext(BulletNode* next) {
    this->_next = next;
}