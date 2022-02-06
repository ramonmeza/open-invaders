// Copyright 2022 open-invaders
// Author: Ramon Meza

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "core/game.h"

float core::Game::DeltaTime = 0.0f;

struct core::Game::GameImpl {
    GameImpl() :
        window_(sf::VideoMode(800, 600), "Open Invaders") {
    }

    ~GameImpl() {
    }

    void Init() {
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

    sf::RenderWindow window_;
    sf::Event window_event_;
    sf::Clock delta_clock_;
};

// default constructors
core::Game::Game() :
    impl_(new GameImpl) {
}

core::Game::~Game() = default;

void core::Game::Init() {
    impl_->Init();
}

void core::Game::Run() {
    impl_->Run();
}
