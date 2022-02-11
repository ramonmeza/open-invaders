// Copyright 2022 open-invaders
// Author: Ramon Meza

#ifndef core_Game_H_
#define core_Game_H_

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
    class Impl;
    std::unique_ptr<Impl> impl_;
};

}  // namespace core

#endif  // core_Game_H_
