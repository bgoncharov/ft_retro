/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:30:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/10/27 21:12:32 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_HPP
# define LOGIC_HPP

# include <ncurses.h>
# include "EnemyList.hpp"
# include "BulletList.hpp"
# include "Player.hpp"
# include <stdlib.h>
# include <string>

class Logic {
	public:
		Logic(void);
		Logic(WINDOW* win, Player* player);
		Logic(Logic const & src);

		~Logic(void);

		Logic & operator=(Logic const & rhs);

		void mvAll(void);
		void displAll(void) const;
		int checkPlayerColision(void);
		void checkBulletCollision(void);
		void checkOB(void);
		void createEnemy(void);
		int checkInput(void);
		void shot(void);

		EnemyList* getEList(void) const;
		void setEList(EnemyList* eList);
		BulletList* getBList(void) const;
		void setBList(BulletList* bList);
		Player* getPlayer(void) const;
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

	private:
		EnemyList* _eList;
		BulletList* _bList;
		Player* _player;
		WINDOW* _win;
		int _maxx;
		int _maxy;
		int _minx;
		int _miny;
		void _displMenu(void);
};

#endif