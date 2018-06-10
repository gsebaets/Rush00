#ifndef ENEMY_HPP
#   define  ENEMY_HPP
#   include "Entity.hpp"
#   include <cstdlib>
#   include <ctime>

class   Enemy : public Entity {
    public:
        Enemy(WINDOW *, char);
        ~Enemy();
        Enemy & operator=(Enemy const & enemy);
        virtual void    display();
        void            updatePos();

        void            setWindow(WINDOW * win);
        void            setPosition(int x, int y);

        WINDOW * _win;
};

#endif