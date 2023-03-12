/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundManager
*/

#include <Error/Error.hpp>
#include <Lib/SoundManager.hpp>
#include <algorithm>
#include <iostream>

void SoundManager::addSoundBuffer(const std::string_view& path) noexcept
{
    try {
        buffers_.emplace_back(Buffer(path));
        buffersPaths_.push_back(path);
    } catch (const Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

unsigned int SoundManager::getBufferIdFromPath(const std::string_view& path) const
{
    auto it = std::find(buffersPaths_.begin(), buffersPaths_.end(), path);

    unsigned int id = 0;

    if (it != buffersPaths_.end()) {
        id = it - buffersPaths_.begin();
    } else {
        throw Error("Impossible to find the required buffer in the Sound Manager with the path given.");
    }
    return (id);
}

Buffer& SoundManager::getBufferFromPath(const std::string_view& path)
{
    return (buffers_[getBufferIdFromPath(path)]);
}