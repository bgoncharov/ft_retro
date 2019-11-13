/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:20:41 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:18:34 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETLIST_HPP
# define BULLETLIST_HPP

# include "Bullet.hpp"

struct BulletNode
{
    Bullet* bullet;
    BulletNode* next;
};

class BulletList {
    
    public:
        BulletList(void);
        BulletList(BulletList const & src);

        ~BulletList(void);

        BulletList & operator=(BulletList const & rhs);

        BulletNode* createNode(Bullet* bullet);
        void addNode(Bullet* bullet);
        void delNode(BulletNode* node);

        BulletNode* getHead(void) const;
        void setHead(BulletNode* head);
        BulletNode* getNext(void) const;
        void setNext(BulletNode* next);

    private:
        BulletNode* _head;
        BulletNode* _next;
};

#endif