/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Animation
*/

#include "Animation.hpp"

#include <stdlib.h>

Animation::~Animation() noexcept
{
    if (!animations_) return;
    for (unsigned int i = 0; i < animations_count_; i++) UnloadModelAnimation(animations_[i]);
    RL_FREE(animations_);
}

void Animation::addAnimation(const std::string_view& path) noexcept
{
    animations_  = LoadModelAnimations(path.data(), &animations_count_);
    is_animated_ = true;
}

void Animation::updateAnimation(Model3D& model_) noexcept
{
    if (animations_ == nullptr) return;
    if (is_animated_ == false) return;

    frame_counter_ += 1.0f * skip_frame_;
    model_.update(animations_[animation_id_], frame_counter_);
    if (frame_counter_ >= animations_[animation_id_].frameCount) frame_counter_ = 0;
}

void Animation::setSkipFrame(int frame) noexcept
{
    skip_frame_ = frame;
}

void Animation::setAnimationId(int id) noexcept
{
    animation_id_ = id;
}