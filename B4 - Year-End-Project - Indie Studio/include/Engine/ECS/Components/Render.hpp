/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Render.cpp
*/

#pragma once

#include <memory>
#include <string_view>

#include "Animation.hpp"
#include "Color.hpp"
#include "Model3D.hpp"
#include "Transform3D.hpp"
#include "Vector.hpp"

enum class RenderType {
    R_3DMODEL,
    R_3DMODEL_ROTATE,
    R_ANIMATE,
    R_NONE,
};

class Render : public Component
{
  public:
    Render(Model3D& model) noexcept;
    Render(const Render& other) noexcept = default;
    Render(Render&& other) noexcept      = default;
    ~Render() noexcept                   = default;

    Render& operator=(const Render& rhs) noexcept = delete;
    Render& operator=(Render&& rhs) noexcept = delete;

    void          display(const Transform3D& transform) noexcept;
    void          setRenderType(const RenderType& type) noexcept;
    void          setColor(const std::array<unsigned char, 3>& color) noexcept;
    RenderType    getRenderType() const noexcept;
    ComponentType getComponentType() const noexcept;
    Animation&    getAnimation() noexcept;
    Model3D&      getModel() noexcept;
    void          show(bool show) noexcept;
    bool          isShow() const noexcept;

    void displayModel(const Transform3D& transform, const Vector3D& pos) noexcept;
    void displayModelV(const Transform3D& transform,
        const Vector3D&                   pos,
        const Vector3D&                   axis,
        float                             angle) noexcept;

    static constexpr ComponentType TYPE = ComponentType::RENDER;

  private:
    RenderType   type = RenderType::R_NONE;
    Model3D&     model_;
    ColorManager color_ = Colors::C_WHITE;
    Animation    animation_;
    bool         show_ = true;
};
