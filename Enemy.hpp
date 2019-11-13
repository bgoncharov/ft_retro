/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:22:09 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:10:52 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <ncurses.h>

class Enemy {
    
    public:
        Enemy(void);
        Enemy(int posx, int posy, WINDOW *win);
        Enemy(Enemy const & src);

        ~Enemy(void);

        Enemy & operator=(Enemy const & rhs);

        void mv(void);
        void displ(void) const;

        int getPosx(void) const;
        void setPosx(int posx);
        int getPosy(void) const;
        void setPosy(int posy);
        WINDOW* getWin(void) const;
        void setWin(WINDOW* win);

    private:
        int _posx;
        int _posy;
        WINDOW* _win;
};

#endif