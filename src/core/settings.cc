// Copyright 2022 open-invaders
// Author: Ramon Meza

#include "config/config.h"
#include "core/settings.h"

// implementation struct
struct core::Settings::SettingsImpl {
    SettingsImpl() {
    }

    ~SettingsImpl() {
    }

   void SettingsImpl::Init() {
   }
};

// default constructor
core::Settings::Settings() :
    impl_(std::make_unique<SettingsImpl>()) {
}

// delete destructor
core::Settings::~Settings() = default;

// implement pimpl interface methods
void core::Settings::Init() {
    impl_->Init();
}
