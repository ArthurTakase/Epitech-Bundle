/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** model_3D
*/

#include "Model3D.hpp"

/**
 * It loads a model from a file and a texture from a file, and then sets the texture of the model to
 * the texture
 *
 * @param path The path to the model file.
 * @param texture_Path The path to the texture file.
 */
Model3D::Model3D(const std::string_view& path, const std::string_view& texture_Path) noexcept
    : model_(LoadModel(path.data()))
    , texture_(LoadTexture(texture_Path.data()))
{
    model_.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture_;
}

/**
 * The destructor of the Model3D class
 */
Model3D::~Model3D() noexcept
{
    this->unload();
}

/**
 * It unloads the model and texture from memory
 */
void Model3D::unload() noexcept
{
    if (!unloaded_) {
        UnloadTexture(texture_);
        UnloadModel(model_);
        unloaded_ = true;
    }
}

/**
 * Update the model's animation to the given animation and frame counter.
 *
 * @param pos The position of the model.
 * @param scale The scale of the model.
 * @param color_infos The color of the model.
 */
void Model3D::draw(const Vector3D&      pos,
    float                               scale,
    const std::array<unsigned char, 3>& color_infos) const noexcept
{
    Color color = { color_infos[0], color_infos[1], color_infos[2], 255 };
    DrawModel(model_, { pos.x, pos.y, pos.z }, scale, color);
}

/**
 * Update the model's animation to the given animation and frame counter.
 *
 * @param pos The position of the model.
 * @param rotation The rotation of the model.
 * @param rotation_angle The angle of rotation.
 * @param scale The scale of the model.
 * @param color_infos The color of the model.
 */
void Model3D::draw(const Vector3D&      pos,
    const Vector3D&                     rotation,
    float                               rotation_angle,
    float                               scale,
    const std::array<unsigned char, 3>& color_infos) const noexcept
{
    Color color = { color_infos[0], color_infos[1], color_infos[2], 255 };
    DrawModelEx(model_,
        { pos.x, pos.y, pos.z },
        { rotation.x, rotation.y, rotation.z },
        rotation_angle,
        { scale, scale, scale },
        color);
}

/**
 * "Update the model's animation to the given animation and frame counter."
 *
 * The first thing we do is check if the model has any animations. If it doesn't, we return
 *
 * @param animation The animation to update.
 * @param frame_counter The current frame of the animation.
 */
void Model3D::update(ModelAnimation animation, int frame_counter)
{
    UpdateModelAnimation(model_, animation, frame_counter);
}