// Copyright 2022 open-invaders
// Author: Ramon Meza

#include <filesystem>
#include <memory>

#include <iniparser.hpp>

#include "config/config.h"
#include "core/settings.h"

// implementation struct
struct core::Settings::Impl {
    Impl() {
    }

    ~Impl() {
    }

    void Load(const std::string& path) {
        if(!file_.Load(path))
        {
            throw;
        }
    }

    INI::Section* operator[](const std::string& section) {
        return file_.FindSection(section);
    }

    INI::File file_;
};

// default constructor
core::Settings::Settings() :
    impl_(std::make_unique<Impl>()) {
}

// delete destructor
core::Settings::~Settings() = default;

// implement pimpl interface methods
void core::Settings::Load(const std::string& path) {
    impl_->Load(path);
}

INI::Section* core::Settings::operator[](const std::string& section) {
    return (*impl_)[section];
}
