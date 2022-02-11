// Copyright 2022 open-invaders
// Author: Ramon Meza

#ifndef core_Settings_H_
#define core_Settings_H_

#include <memory>

namespace core {

class Settings {
 public:
    Settings();
    ~Settings();

   void Settings::Init();

 private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

}  // namespace core

#endif  // core_Settings_H_
