#pragma once

#include <ECS/Entity/Entity.hpp>
#include <NetworkLib/ISocket.hpp>
#include <Serializer/BitSize.hpp>
#include <bitset>
#include <memory>

/**
 * @brief class used to serialize objects for network
 */
class Serializer
{
  public:
    Serializer()           = delete;
    ~Serializer() noexcept = delete;

    Serializer(const Serializer& other)                = delete;
    Serializer(Serializer&& other) noexcept            = delete;
    Serializer& operator=(const Serializer& other)     = delete;
    Serializer& operator=(Serializer&& other) noexcept = delete;

    static RawData serialize(std::unique_ptr<Entity> const& entity) noexcept;
    static RawData serialize(int keyCode);
    static RawData serializeMusic(std::unique_ptr<Entity> const& entity) noexcept;

  protected:
  private:
};
