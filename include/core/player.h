// Copyright 2022 open-invaders
// Author: Ramon Meza

#ifndef CORE_PLAYER_H_
#define CORE_PLAYER_H_

#include <memory>

namespace core {

class Player {
 public:
    Player();
    ~Player();

   void Init();

 private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

}  // namespace core

#endif  // CORE_PLAYER_H_
