/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyList.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:22:39 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:18:33 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyList.hpp"

EnemyList::EnemyList(void) {
	this->_head = NULL;
	this->_next = NULL;
    return ;
}

EnemyList::EnemyList(EnemyList const & src) {
    *this = src;
    return ;
}

EnemyList::~EnemyList(void) {
    return ;
}

EnemyList & EnemyList::operator=(EnemyList const & rhs) {
    if (this != &rhs) {
		this->_head = rhs.getHead();
		this->_next = rhs.getNext();
	}
    return *this;
}

EnemyNode* EnemyList::createNode(Enemy* enemy) {
	EnemyNode* tmp = new EnemyNode;
	tmp->enemy = enemy;
	tmp->next = NULL;
	return (tmp);
}

void EnemyList::addNode(Enemy* enemy) {
	EnemyNode* tmp = this->createNode(enemy);
	EnemyNode* run = this->_head;
	if (this->_head == NULL) {
		this->_head = tmp;
	} else {
		while(run->next)
			run = run->next;
		run->next = tmp;
	}
}

void EnemyList::delNode(EnemyNode* node) {
	EnemyNode* current;
	EnemyNode* previous;
	EnemyNode* tmp;

	if (this->_head == NULL)
		return;
	if (/*this->_head->next == NULL && */this->_head == node) {
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

EnemyNode* EnemyList::getHead(void) const{
    return this->_head;
}

void EnemyList::setHead(EnemyNode* head) {
    this->_head = head;
}
EnemyNode* EnemyList::getNext(void) const{
    return this->_next;
}

void EnemyList::setNext(EnemyNode* next) {
    this->_next = next;
}