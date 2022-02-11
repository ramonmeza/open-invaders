// Copyright 2022 open-invaders
// Author: Ramon Meza

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <LeksysINI/iniparser.hpp>

#include "config/config.h"
#include "core/game.h"
#include "core/settings.h"

#define SETTINGS_PATH "data/settings.ini"

// initialize static vars
float core::Game::DeltaTime = 0.0f;

// implementation struct
struct core::Game::Impl {
    Impl() {
    }

    ~Impl() {
    }

    void Init() {
        InitSettings();
        InitWindow();
    }

    void InitSettings() {
        settings_.Load(SETTINGS_PATH);
    }

    void InitWindow() {
        if (window_.isOpen()) {
            window_.close();
        }

        window_.create(
            sf::VideoMode(
                settings_["Display"]->GetValue("width", 800).AsInt(),
                settings_["Display"]->GetValue("height", 600).AsInt()),
            "Open Invaders v" + 
            std::to_string(open_invaders_VERSION_MAJOR) + "." + 
            std::to_string(open_invaders_VERSION_MINOR));
    }

    void Run() {
        while (window_.isOpen()) {
            core::Game::DeltaTime = delta_clock_.restart().asSeconds();
            HandleWindowEvents();
            Update();
            Render();
        }
    }

    void Quit() {
        window_.close();
    }

    void HandleWindowEvents() {
        while (window_.pollEvent(window_event_)) {
            if (window_event_.type == sf::Event::Closed) {
                Quit();
            }
        }
    }

    void Update() {
    }

    void Render() {
        window_.clear();
        window_.display();
    }

    core::Settings settings_;
    sf::RenderWindow window_;
    sf::Event window_event_;
    sf::Clock delta_clock_;
};

// default constructor
core::Game::Game() :
    impl_(std::make_unique<core::Game::Impl>()) {
}

// delete destructor
core::Game::~Game() = default;

// implement pimpl interface methods
void core::Game::Init() {
    impl_->Init();
}

void core::Game::Run() {
    impl_->Run();
}
