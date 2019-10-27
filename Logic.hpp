/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:30:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/26 20:48:26 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_HPP
# define LOGIC_HPP

# include <ncurses.h>
# include "Player.hpp"
# include <stdlib.h>
# include <string>

class Logic {
public:
    /* Constructors */
    Logic(void);
	Logic(WINDOW* win, Player* player);
    Logic(Logic const & src);

    /* Destructor */
    ~Logic(void);

    /* Operator */
    Logic &operator=(Logic const & rhs);

    int checkPlayerColision(void);
    int checkInput(void);
    void displayAll(void) const;

	Player *getPlayer(void) const;
	void setPlayer(Player* player);
	int getMaxx(void) const;
	void setMaxx(int maxx);
	int getMaxy(void) const;
	void setMaxy(int maxy);
	int getMinx(void) const;
	void setMinx(int minx);
	int getMiny(void) const;
	void setMiny(int miny);
	WINDOW* getWin(void) const;
	void setWin(WINDOW* win);

protected:

private:
    Player *_player;
	WINDOW *_win;
	int _maxx;
	int _maxy;
	int _minx;
	int _miny;
	void _displayMenu(void);
};

#endif