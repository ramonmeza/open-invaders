// Copyright 2022 open-invaders
// Author: Ramon Meza

#include "config/config.h"
#include "core/player.h"

// implementation struct
struct core::Player::Impl {
    Impl() {
    }

    ~Impl() {
    }

   void Init() {
   }
};

// default constructor
core::Player::Player() :
    impl_(std::make_unique<core::Player::Impl>()) {
}

// delete destructor
core::Player::~Player() = default;

// implement pimpl interface methods
void core::Player::Init() {
    impl_->Init();
}
