// Copyright 2022 open-invaders
// Author: Ramon Meza

#ifndef CORE_GAME_H_
#define CORE_GAME_H_

#include <memory>

namespace core {

class Game {
 public:
    Game();
    ~Game();

    void Init();
    void Run();
    void Quit();

    static float DeltaTime;

 private:
    class GameImpl;
    std::unique_ptr<GameImpl> impl_;
};

}  // namespace core

#endif  // CORE_GAME_H_
