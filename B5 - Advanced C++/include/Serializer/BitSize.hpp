#pragma once
#include <cstdint>
#include <string_view>

static constexpr unsigned int     ESCAPE        = 120;
static constexpr unsigned int     WINDOW_CLOSE  = 36;
static constexpr unsigned int     CLOSE_VALUE   = 255;
static constexpr unsigned int     PACKET_SIZE   = 16;
static constexpr unsigned int     MAX_TIMEOFF   = 5;
static constexpr unsigned int     PING          = 1;
static constexpr unsigned int     PONG          = 2;
static constexpr unsigned int     MAX_PLAYERS   = 4;
static constexpr unsigned int     MUSIC_NB      = 6;
static constexpr std::string_view PATH_BG_MUSIC = "./assets/audio/loading.wav";

/**
 * @brief This enum class is used to process the packets received from the server in order.
 */
typedef enum PacketName {
    X1        = 0,
    X2        = 1,
    Y1        = 2,
    Y2        = 3,
    XPOSITIVE = 4,
    YPOSITIVE = 5,
    ID_SPRITE = 6,
    WIDTH     = 7,
    HEIGHT    = 8,
    SCALE_X   = 9,
    SCALE_Y   = 10,
    OFFSET_X  = 11,
    OFFSET_Y  = 12,
    ID1       = 13,
    ID2       = 14,
    DESTROYED = 15
} PacketName;

/**
 * @brief This struct is used to process the data received from the server.
 */
struct GamePacket {
    int          x;
    int          y;
    std::uint8_t idSprite;
    std::uint8_t width;
    std::uint8_t height;
    float        scaleX;
    float        scaleY;
    std::uint8_t offsetX;
    std::uint8_t offsetY;
    std::uint8_t id;
    std::uint8_t destroyed;
};

/**
 * @brief This enum defines all sounds handled in our game
 */
typedef enum RTypeSounds { EXPLOSION_SOUND, HEAL_SOUND, HURT_SOUND, MENU_SOUND, PIOU_SOUND, POWERUP_SOUND } RTypeSounds;
