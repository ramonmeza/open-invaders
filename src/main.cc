// Copyright 2022 open-invaders
// Author: Ramon Meza

#include <iostream>

#include "core/game.h"

int main(int argc, char* argv[]) {
    core::Game game;
    game.Init();
    game.Run();

    return 0;
}
