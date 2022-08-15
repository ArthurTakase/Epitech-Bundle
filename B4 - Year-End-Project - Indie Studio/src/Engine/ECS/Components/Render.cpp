/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Render
*/

#include "Render.hpp"

/**
 * Render::Render(Model3D& model) noexcept
 *     : color_(Colors::C_WHITE)
 *     , model_(model)
 *     , animation_()
 * {
 * }
 *
 * @param model The model to render.
 */
Render::Render(Model3D& model) noexcept
    : color_(Colors::C_WHITE)
    , model_(model)
    , animation_()
{
}
/**
 * It draws the model, or the animation, or the model with rotation, or the
 * animation with rotation, or the model with rotation and animation, or the
 * animation with rotation and model, or the model with animation and rotation, or
 * the animation with model and rotation
 *
 * @param transform The transform of the object that the render is attached to.
 *
 * @return A reference to the Render object.
 */

/**
 * It draws the model at the position, rotation, and scale of the transform
 *
 * @param transform The transform of the object that the render is attached to.
 *
 * @return A reference to the Render object.
 */
void Render::display(const Transform3D& transform) noexcept
{
    if (!show_) return;

    auto     color = color_.getColor();
    Vector3D pos   = transform.getPosition();
    Vector3D rot   = transform.getRotationAxis();
    float    scale = transform.getScale();

    if (type == RenderType::R_3DMODEL) {
        model_.draw(pos, scale, color);
    } else if (type == RenderType::R_3DMODEL_ROTATE) {
        float rotationAngle = transform.getRotationAngle();
        model_.draw(pos, rot, rotationAngle, scale, color);
    } else if (type == RenderType::R_ANIMATE) {
        animation_.updateAnimation(model_);
        float rotationAngle = transform.getRotationAngle();
        model_.draw(pos, rot, rotationAngle, scale, color);
    }
}
/**
 * This function sets the render type to the given render type.
 *
 * @param type The type of render.
 */
void Render::setRenderType(const RenderType& type) noexcept
{
    this->type = type;
}

/**
 * It sets the color of the render object.
 *
 * @param color The color to set the renderer to.
 */
void Render::setColor(const std::array<unsigned char, 3>& color) noexcept
{
    color_.setColor(color);
}

/**
 * This function returns the type of render.
 *
 * @return The type of render.
 */
RenderType Render::getRenderType() const noexcept
{
    return (type);
}

/**
 * It returns the type of the component
 *
 * @return The component type.
 */
ComponentType Render::getComponentType() const noexcept
{
    return (TYPE);
}

/**
 * It displays a model at a given position, with a given rotation axis and angle
 *
 * @param transform The transform of the model.
 * @param pos The position of the model.
 */
void Render::displayModel(const Transform3D& transform, const Vector3D& pos) noexcept
{
    auto axis  = transform.getRotationAxis();
    auto angle = transform.getRotationAngle();

    displayModelV(transform, pos, axis, angle);
}

/**
 * It draws the model at the given position, with the given rotation, and with the
 * given scale
 *
 * @param transform The transform of the object.
 * @param pos The position of the model.
 * @param axis The axis of rotation.
 * @param angle the angle of rotation
 */
void Render::displayModelV(
    const Transform3D& transform, const Vector3D& pos, const Vector3D& axis, float angle) noexcept
{
    if (type == RenderType::R_ANIMATE) {
        std::array<unsigned char, 3> color = { 255, 255, 255 };
        model_.draw(pos, axis, angle, transform.getScale(), color);
    }
}

/**
 * It returns a reference to the animation object
 *
 * @return A reference to the animation_ member variable.
 */
Animation& Render::getAnimation() noexcept
{
    return animation_;
}

/**
 * This function returns a reference to the model_ member variable.
 *
 * @return A reference to the model_ member variable.
 */
Model3D& Render::getModel() noexcept
{
    return model_;
}

/**
 * It sets the show_ member variable to the value of the show parameter
 *
 * @param show Whether or not to show the window.
 */
void Render::show(bool show) noexcept
{
    show_ = show;
}

/**
 * `bool Render::isShow() const noexcept`
 *
 * The function returns a boolean value. The function is a member of the class
 * `Render`. The function is a constant function. The function does not throw an
 * exception
 *
 * @return A boolean value.
 */
bool Render::isShow() const noexcept
{
    return show_;
}