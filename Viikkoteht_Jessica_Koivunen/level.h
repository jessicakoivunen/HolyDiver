#pragma once
#include "player.h"
#include "movingenemy.h"
#include "objects.h"
#include <list>

class Level
{
public:
    Player player = Player(0, 0);
    Map map = Map("level_0.txt");
    Light light = Light(map);
    list <MovingEnemy> enemies;
    Objects o;
    int max_treasure = 0;
    int level = 0;

    virtual void Reset() {};
};