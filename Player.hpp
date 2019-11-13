/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:22:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:21:55 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>

class Player {

    public:
        Player(void);
        Player(char c, WINDOW *win);
        Player(Player const & src);

        ~Player(void);

        Player &     operator=(Player const & rhs);

        void mvUp(void);
        void mvDown(void);
        void mvLeft(void);
        void mvRight(void);
        void displ(void) const;

        int getLifes(void) const;
        void setLifes(int lifes);
        int getPosx(void) const;
        void setPosx(int posx);
        int getPosy(void) const;
        void setPosy(int posy);
        int getScore(void) const;
        void setScore(int score);
        int getMaxx(void) const;
        void setMaxx(int maxx);
        int getMaxy(void) const;
        void setMaxy(int maxy);
        int getMinx(void) const;
        void setMinx(int minx);
        int getMiny(void) const;
        void setMiny(int miny);
        char getChar(void) const;
        void setChar(char c);
        WINDOW* getWin(void) const;
        void setWin(WINDOW* win);

    private:
        int _lifes;
        int _posx;
        int _posy;
        int _score;
        int _maxy;
        int _maxx;
        int _minx;
        int _miny;
        char _c;
        WINDOW *_win;
};

#endif