
#include "Player.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include <cstdlib>
#include <unistd.h>

int main() {
    WINDOW * space;

    initscr();
    noecho();
    cbreak();
	curs_set(0);

    srand(time(0));
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    space = newwin(yMax - 2, xMax, 0, 0);
    refresh();
    wrefresh(space);
    
    Player * p = new Player(space, yMax, xMax/2, '^');
    Enemy  * _enemy = new Enemy(space, '*');
    Enemy  * _enemy0 = new Enemy(space, '#');
    Enemy  * _enemy1 = new Enemy(space, '0');
    box(space,0,0);
    p->display();
    p->moveDown();
    int i = 0;
	char c = p->getPlayerInput();
    while(c != 'q')
    {
        _enemy->updatePos();
        _enemy0->updatePos();
        _enemy1->updatePos();
		usleep(30000);
        _enemy->display();
        _enemy0->display();
        _enemy1->display();

        if (_enemy0->getY() == yMax - 1) {
            delete _enemy0;
            _enemy0 = new Enemy(space, '#');
        }
        if (_enemy1->getY() == yMax - 2) {
            delete _enemy1;
            _enemy1 = new Enemy(space, '0');
            _enemy1->setPosition(_enemy1->getX(), 3);
        }

        refresh();
        wrefresh(space);
        p->display();
		nodelay(space, true);
		c = p->getPlayerInput();

    }
    getch();
    endwin();
    
    return 0;
}
