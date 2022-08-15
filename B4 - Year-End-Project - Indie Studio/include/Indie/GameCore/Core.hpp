/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Core
*/

#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include "ACore.hpp"
#include "GameData.hpp"
#include "MyCameraman.hpp"
#include "Scene.hpp"
#include "Window.hpp"

class Core : public ACore
{
  public:
    Core() noexcept;
    Core(const Core& other) noexcept = delete;
    Core(Core&& other) noexcept      = delete;
    ~Core() noexcept;

    Core& operator=(const Core& rhs) noexcept = delete;
    Core& operator=(Core&& rhs) noexcept = delete;

    void           switchScene(const bomberman::SceneType& scene) noexcept;
    WindowManager& getWindow() noexcept;
    MyCameraman&   getCameraman() noexcept;
    void           run() noexcept final;
    void           displayScene() noexcept final;

  protected:
  private:
    // methods
    void checkCamera() noexcept final;
    void initGameModels() noexcept;
    void initScenes() noexcept final;
    void initSprites() noexcept;
    void checkExit() noexcept;

    // attributes
    MyCameraman                    camera_;
    std::unique_ptr<WindowManager> window_;
};
