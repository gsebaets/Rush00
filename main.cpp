
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>

int main() {
    WINDOW * space;
    timeout(250);

    initscr();
    noecho();
    // cbreak();
    srand(time(NULL));
	curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    space = newwin(yMax, xMax, 0, 0);
    refresh();
    wrefresh(space);

    
    Player * p = new Player(space, 5, 10, '8');
    Enemy * _enemy0 = new Enemy(space, '*');
    Enemy * _enemy1 = new Enemy(space, '*');
    box(space,0,0);
    while(true)
    {
        _enemy0->updatePos();
        _enemy1->updatePos();
        usleep(300000);
        _enemy0->display();
        _enemy1->display();

        if (_enemy0->getY() == yMax) {
            delete _enemy0;
            _enemy0 = new Enemy(space, '*');
        }

        if (_enemy1->getY() == yMax) {
            delete _enemy1;
            _enemy1 = new Enemy(space, '*');
            _enemy1->setPosition(_enemy1->getX(), -5);
        }

        // p->display();
        refresh();
        wrefresh(space);
    }
    getch();
    endwin();
    
    return 0;
}