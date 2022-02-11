// Copyright 2022 open-invaders
// Author: Ramon Meza

#include <iniparser.hpp>

#include "config/config.h"
#include "core/settings.h"

// implementation struct
struct core::Settings::Impl {
    Impl() {
    }

    ~Impl() {
    }

   void Impl::Init() {
   }
};

// default constructor
core::Settings::Settings() :
    impl_(std::make_unique<Impl>()) {
}

// delete destructor
core::Settings::~Settings() = default;

// implement pimpl interface methods
void core::Settings::Init() {
    impl_->Init();
}
