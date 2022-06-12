/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SDL2
*/

#include "SDL2.hpp"

/**
 * @brief Retourne un objet SDL2.
 * Extern "C" pour l'ouvrir facilement depuis un dlsym
 *
 */
extern "C" std::shared_ptr<ILibrary> createLib()
{
    return std::make_shared<SDL2>();
}
/**
 * @brief Construct a new SDL2::SDL2 object
 *
 */
SDL2::SDL2()
    : name("lib/arcade_sdl2.so"), frameStart(SDL_GetTicks()), FPS(20), frameDelay(1000 / FPS), window(nullptr), renderer(nullptr),
      font(nullptr), currentMusic("")
{
}

/**
 * @brief Destroy the SDL2::SDL2 object
 *
 */
SDL2::~SDL2() noexcept
{
    deleteWindow();
}

/**
 * @brief Création d'une fenetre de jeu
 *
 * @return bool Echec/réussite de la création
 */
bool SDL2::createWindow() noexcept
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG]INIT > %s", SDL_GetError());
        return false;
    }
    window   = nullptr;
    renderer = nullptr;
    if (TTF_Init() != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG]TTF > %s", SDL_GetError());
        return false;
    }
    font = nullptr;

    // if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
    //     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG]IMG > %s", SDL_GetError());
    //     return false;
    // }

    if (SDL_CreateWindowAndRenderer(1470, 840, SDL_WINDOW_SHOWN, &window, &renderer) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG]WIN_REND > %s", SDL_GetError());
        SDL_Quit();
        return false;
    }
    font = TTF_OpenFont("assets/fonts/visitor.ttf", 25);
    SDL_SetWindowTitle(window, "Arcade [SDL2]");
    return true;
}

/**
 * @brief Destruction d'une fenetre de jeu
 *
 */
void SDL2::deleteWindow() noexcept
{
    if (renderer) SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    if (window) SDL_DestroyWindow(window);
    window = nullptr;
    if (font) TTF_CloseFont(font);
    font = nullptr;
    TTF_Quit();
    // IMG_Quit();
    SDL_Quit();
}

/**
 * @brief Récupère la touche appuyée sous forme d'Arcade::Key
 *
 * @return Arcade::Key
 */
Arcade::Key SDL2::getInput() noexcept
{
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) return Arcade::Key::QUIT_EVENT;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_DOWN: return Arcade::Key::DOWN;
            case SDLK_LEFT: return Arcade::Key::LEFT;
            case SDLK_RIGHT: return Arcade::Key::RIGHT;
            case SDLK_UP: return Arcade::Key::UP;
            case SDLK_c: return Arcade::Key::PREVIOUS_LIB;
            case SDLK_v: return Arcade::Key::NEXT_LIB;
            case SDLK_b: return Arcade::Key::PREVIOUS_GAME;
            case SDLK_n: return Arcade::Key::NEXT_GAME;
            case SDLK_SPACE: return Arcade::Key::POWER;
            case SDLK_f: return Arcade::Key::POWER2;
            case SDLK_RETURN: return Arcade::Key::SWITCH_STATE;
            case SDLK_ESCAPE: return Arcade::Key::QUIT_EVENT;
            case SDLK_x: return Arcade::Key::ADVANCED;
            case SDLK_r: return Arcade::Key::RESTART;
            default: return Arcade::Key::NONE;
            }
        }
    }
    return Arcade::Key::NONE;
}

/**
 * @brief Supprime tous les élément à l'écran avant d'afficher la couleur donnée en paramêtre
 *
 * @param color Couleur de fond (non utilisée par Ncurses)
 */
void SDL2::clearLib(const Arcade::Color &color) noexcept
{
    SDL_Color colors[] = { { 255, 0, 0, 255 },     { 0, 255, 0, 255 },    { 0, 0, 255, 255 },   { 0, 0, 0, 255 },
                           { 255, 255, 255, 255 }, { 163, 129, 67, 255 }, { 255, 0, 255, 255 }, { 0, 255, 255, 255 } };

    if (renderer) SDL_SetRenderDrawColor(renderer, colors[color].r, colors[color].g, colors[color].b, 255);
    if (renderer) SDL_RenderClear(renderer);
}

/**
 * @brief Actualise l'affichage de la lib
 *
 */
void SDL2::refreshLib() noexcept
{
    if (renderer) SDL_RenderPresent(renderer);
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
}

/**
 * @brief Affiche le Text donné en parametre
 *
 * @param txt {str, color, x, y, underline}
 */
void SDL2::putText(const Text &txt) noexcept
{
    SDL_Color colors[] = { { 255, 0, 0, 255 }, { 0, 255, 0, 255 }, { 0, 0, 255, 255 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 } };

    SDL_Color    color       = colors[txt.color];
    SDL_Surface *surfaceText = TTF_RenderText_Blended(font, txt.str.c_str(), color);
    SDL_Texture *text        = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_Rect     rect;

    rect.x = txt.x * 21;
    rect.y = txt.y * 21;
    rect.w = txt.str.length() * 15;
    rect.h = 24;

    if (txt.underline) {
        SDL_SetRenderDrawColor(renderer, colors[txt.color].r, colors[txt.color].g, colors[txt.color].b, 255);
        for (unsigned int i = 0; i < txt.str.length() / 3 + txt.str.length() / 3; ++i)
            for (int j = 0; j < 21; ++j) SDL_RenderDrawPoint(renderer, (txt.x + i) * 21 + j, (txt.y + 1) * 21);
    }

    SDL_RenderCopy(renderer, text, NULL, &rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(surfaceText);
}

/**
 * @brief Affiche le Sprite donné en parametre
 *
 * @param sprite {filePath, color, x, y}
 */
void SDL2::putSprite(const Sprite &sprite)
{
    SDL_Surface *s_sprite;
    SDL_Texture *t_sprite;

    if ((s_sprite = IMG_Load(sprite.spritePath.c_str())) == nullptr) return;
    if ((t_sprite = SDL_CreateTextureFromSurface(renderer, s_sprite)) == nullptr) return;

    SDL_Rect dest{ (int)sprite.x * 21, (int)sprite.y * 21, s_sprite->w, s_sprite->h };
    SDL_Rect src{ 0, 0, 0, 0 };

    SDL_QueryTexture(t_sprite, nullptr, nullptr, &src.w, &src.h);
    SDL_RenderCopy(renderer, t_sprite, nullptr, &dest);
    SDL_DestroyTexture(t_sprite);
    SDL_FreeSurface(s_sprite);
}

/**
 * @brief Getter pour name
 *
 * @return std::string
 */
std::string SDL2::getName() const noexcept
{
    return name;
}

void SDL2::playSound(const std::string &sound) noexcept
{
    (void)sound;
}

void SDL2::cleanSound() noexcept {}