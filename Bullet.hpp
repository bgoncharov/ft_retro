/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:57:16 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 20:57:57 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <ncurses.h>

class Bullet {

    public:
        Bullet(void);
        Bullet(int posx, int posy, WINDOW *win);
        Bullet(Bullet const & src);

        ~Bullet(void);

        Bullet & operator=(Bullet const & rhs);

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