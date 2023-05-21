#ifndef ALLENEMY_HPP
#define ALLENEMY_HPP
#include "Enemy.hpp"

class RedNormalEnemy : public Enemy {
public:
    RedNormalEnemy(int x, int y);
};

class DiceEnemy : public Enemy {
public:
    DiceEnemy(int x, int y);
};

#endif // ALLENEMY_HPP
