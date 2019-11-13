/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyList.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:22:43 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:18:33 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYLIST_HPP
# define ENEMYLIST_HPP

# include "Enemy.hpp"

struct EnemyNode
{
    Enemy* enemy;
    EnemyNode* next;
};

class EnemyList {

    public:
        EnemyList(void);
        EnemyList(EnemyList const & src);

        ~EnemyList(void);

        EnemyList & operator=(EnemyList const & rhs);

        EnemyNode* createNode(Enemy* enemy);
        void addNode(Enemy* enemy);
        void delNode(EnemyNode* node);

        EnemyNode* getHead(void) const;
        void setHead(EnemyNode* head);
        EnemyNode* getNext(void) const;
        void setNext(EnemyNode* next);

    private:
        EnemyNode* _head;
        EnemyNode* _next;
};

#endif