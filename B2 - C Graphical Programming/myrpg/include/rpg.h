/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

// ****************************************************************************
// *                                   LIB                                    *
// ****************************************************************************

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

// ****************************************************************************
// *                                 DEFINE                                   *
// ****************************************************************************

// ________________________________SETTINGS_____________________________________
#define FPS             240
#define MAX_FPS         600
#define MIN_FPS         10
#define WIN_W           960
#define WIN_H           540

// __________________________________BOOL______________________________________
#define TRUE            1
#define FALSE           0

// _________________________________SCENE______________________________________
#define NB_SCENE        7

#define HOME            0
#define GAME            1
#define FIGHT           2
#define END_FIGHT       3
#define MAP             4
#define INVENTORY       5
#define PARAM           6

// _________________________________ITEMS______________________________________
#define POTION_HEAL     10
#define POTION_PRICE    30

#define START_POTION    5
#define START_LVL       1
#define START_GOLD      250
#define START_ATT       1
#define START_HP        25
#define START_KEY       0
#define FLY             5

//_________________________________TILE________________________________________

#define HERBE           "tiles/herbe.png"
#define GASON           "tiles/gason.png"
#define SABLE           "tiles/sable.png"
#define TERRE           "tiles/terre.png"
#define P_FLEUR         "tiles/petites_fleurs.png"

// _____________________________PLAYER_STATE___________________________________
#define IDLE            0
#define IDLE2           1
#define ATT             2
#define ATT2            3
#define HURT            4
#define DEAD            5
#define RUN             6

// _____________________________PLAYER_MAP_STATE_______________________________
#define FACE            0
#define BACK            1
#define SIDE1           2
#define SIDE2           3

#define FIRST_MAP       "save/corentin.save"
#define SECOND_MAP      "save.map1.save"
#define THIRD_MAP       "save/map2.save"
#define PLAYER_SPD      0.5
#define SPAWN_FIGHT     100

// _____________________________ENNEMIS_STATE__________________________________
#define IDLE_ENN        0
#define ATT_ENN         1
#define HURT_ENN        2
#define DEAD_ENN        3

// ________________________________ENNEMIS_____________________________________
#define EMPTY           0
#define VIKING          1
#define PIRATE          2
#define NINJA           3

// ___________________________BACKGROUND_SPEED_________________________________
#define SPEED1          -0.013
#define SPEED2          -0.017
#define SPEED3          -0.02

// ______________________________FIGHT_TURN____________________________________
#define PLAYER          0
#define ENNEMI          1
#define VICTORY         2
#define DEFEAT          3


// ****************************************************************************
// *                               STRUCTURE                                  *
// ****************************************************************************

// Structure d'un texte
typedef struct s_txt
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    int value;
} txt_t;

// Structure avec tous les textes du jeu
typedef struct s_all_txt
{
    txt_t *fight_turn;
    txt_t *fight_result;
    txt_t *fight_gains;
    txt_t *potion;
    txt_t *key;
    txt_t *lvl;
    txt_t *max_life;
    txt_t *att;
    txt_t *gold;
    txt_t *life;
    txt_t *slash;
} all_txt_t;

// Structure d'un horloge
typedef struct s_clock
{
    sfClock *clock;
    float limit;
} clocks_t;

// Structure avec toutes les horloges du jeu
typedef struct all_clock
{
    clocks_t *dtime;
    clocks_t *player;
    clocks_t *player_map;
    clocks_t *particule;
    clocks_t *ennemi;
    clocks_t *fade;
    clocks_t *reset_rand;
} all_clock_t;

// Structure classique d'un sprite
typedef struct s_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f move;
    sfVector2f pos;
    sfIntRect rect;
    int state;
} sprite_t;

// Element de la liste  [Changer le type de value pour les particules]
typedef struct s_dlistnode
{
    sprite_t *particle;
    struct s_dlistnode *back;
    struct s_dlistnode *next;
} dlistnode_t;

// Liste
typedef struct s_dlist
{
    int len;
    struct s_dlistnode *begin;
    struct s_dlistnode *end;
} *dlist_t;

typedef struct s_part_param
{
    sfVector2f origin;
    sfColor color;
    sfVector2f move;
    char *shape;
} part_param_t;

// Structure avec tous les sprites du jeu
typedef struct s_all_sprites
{
    sprite_t *mouse;
    sprite_t *ground;
    sprite_t *slash;
    sprite_t *punch;
    sprite_t *f_att;
    sprite_t *f_run;
    sprite_t *chest;
    sprite_t *inventory;
} all_sprite_t;

// Structure d'un ennemi
typedef struct s_ennemi
{
    int life;
    int state;
    int att;
    int type;
    int miss;
    sprite_t *idle;
    sprite_t *attack;
    sprite_t *hurt;
    sprite_t *dead;
    txt_t *life_txt;
} ennemi_t;

// Structure d'un combat
typedef struct s_fight
{
    ennemi_t *enn1;
    ennemi_t *enn2;
    ennemi_t *enn3;
    int state;
    int turn;
} fight_t;


typedef struct s_background
{
    sprite_t *bg1;
    sprite_t *bg2;
    sprite_t *bg3;
    sprite_t *bg1_b;
    sprite_t *bg2_b;
    sprite_t *bg3_b;
} bg_t;

// Structure avec les infos du joueur et ses animations
typedef struct s_player
{
    int max_life;
    int life;
    int lvl;
    int att;
    int state;
    int xp;
    int gold;
    int potion;
    int key;
    sprite_t *idle;
    sprite_t *idle2;
    sprite_t *attack;
    sprite_t *attack2;
    sprite_t *hurt;
    sprite_t *dead;
    sprite_t *run;
    txt_t *life_txt;
} player_t;

// Structure avec les spirtes du joueur sur la map
typedef struct s_player_map
{
    int state;
    float move;
    int is_move;
    int nxt_lvl;
    sfVector2f pos;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
    sprite_t *idle_down;
    sprite_t *idle_up;
    sprite_t *idle_left;
    sprite_t *idle_right;
    sprite_t *walk_up;
    sprite_t *walk_down;
    sprite_t *walk_left;
    sprite_t *walk_right;
} player_map_t;
// Structure d'un son
typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buff;
} sound_t;

// Structure avec tous les sons du jeu (avec les musiques)
typedef struct s_all_sound
{
    sfMusic *music;
    sound_t *hud;
    sound_t *knife;
    sound_t *punch;
} all_sound_t;

// Structure avec les settings du jeu
typedef struct s_settings
{
    int fullscreen;
    int volume;
    int fps;
} settings_t;

// Structure d'un bouton (modifier avec un sfIntRect)
typedef struct s_btn
{
    int x;
    int y;
    int height;
    int width;
} btn_t;

// Structure d'un bouton avec un sprite (pour list chainée)
typedef struct sbtn_s
{
    sfIntRect pos;
    sprite_t *s;
    struct sbtn_s *next;
    char *type;
} sbtn_t;

typedef struct s_button
{
    sprite_t *s;
    sfIntRect pos;
} button_t;

//structure d'une tile
typedef struct tile_s
{
    sfVector2f pos;
    sprite_t *s;
    char *id;
    struct tile_s *next;
} tile_t;

typedef struct s_map
{
    char *type;
    sfVector2f pos;
    sprite_t *s;
    tile_t *clone;
    sbtn_t *b;
    int state;
    button_t *save_button;
    int size;
} map_t;
// Valeurs des limites/steps des animations des ennemis
typedef struct s_anime
{
    int idle;
    int att;
    int hurt;
    int dead;
} anime_t;

typedef struct s_fade
{
    float in;
    float out;
    float circle_fade;
    sprite_t *fade_in;
    sprite_t *fade_out;
    sprite_t *circle;
} fade_t;

typedef struct s_infos_fight
{
    int state;
    int nb_win;
} infos_fight_t;

typedef struct s_menu
{
    sprite_t *bg;
    sprite_t *play;
    sprite_t *exit;
    sprite_t *param;
    sprite_t *sound;
    sprite_t *frame;
    txt_t *txt_sound;
    txt_t *txt_frame;
} menu_t;

// Structure principale du jeu
typedef struct s_rpg
{
    int scene;
    int is_load;
    float dtime;
    char *current_map;
    settings_t *settings;
    sfRenderWindow *window;
    all_clock_t *clocks;
    all_sprite_t *sprites;
    all_sound_t *sounds;
    all_txt_t *txts;
    tile_t *tiles;
    map_t *map;
    player_t *player;
    player_map_t *player_map;
    fight_t *fight;
    bg_t *bg;
    dlist_t particle;
    fade_t *fade;
    infos_fight_t *infos_fight;
    menu_t *menu;
} rpg_t;


// ****************************************************************************
// *                                 PROTOS                                   *
// ****************************************************************************

all_clock_t *init_all_clock(void);
all_sound_t *init_sounds(void);
all_sprite_t *init_sprites(void);
all_txt_t *init_txt(void);
player_t *init_player(void);
player_map_t *init_player_map(void);
fight_t *init_fight(void);
bg_t *init_background(void);
void init_window(rpg_t *rpg);
fade_t *init_fade(void);
txt_t *new_txt(sfVector2f pos, char *txt, int size, int value);
sprite_t *new_sprite(char *file, sfIntRect rect, sfVector2f move,
                                                sfVector2f pos);
clocks_t *new_clock(float limit);
dlist_t new_dlist(void);
int is_empty_dlist(dlist_t li);
int dlist_len(dlist_t li);
dlist_t push_back_dlist(dlist_t li, sprite_t *x);
dlist_t push_front_dlist(dlist_t li, sprite_t *x);
dlist_t pop_back_dlist(dlist_t li);
dlist_t pop_front_dlist(dlist_t li);
void print_dlist(dlist_t li);
dlist_t clear_dlist(dlist_t li);
int is_over(rpg_t *rpg, btn_t coord);
void draw_sprite(rpg_t *rpg, sprite_t *sprite);
void draw_txt(rpg_t *rpg, txt_t *txt);
void destroy(rpg_t *rpg);
int check_usage(char **argv);
int help(void);
void move_cursor(rpg_t *rpg);
void animation(rpg_t *rpg);
int anime_sprite(sprite_t *sprite, int step, int limit);
void draw(rpg_t *rpg);
void move(rpg_t *rpg, sfClock *dclock);
void set_fullscreen(rpg_t *rpg);
void set_volume(rpg_t *rpg);
sbtn_t *new_button(sfIntRect rect, char *path, sfVector2f pos, sbtn_t *b);
void display_map(rpg_t *r, map_t *m);
void free_sprite(sprite_t *s);
int my_rand(void);
int randomize(void);
void delet_sprite(sprite_t *spr);
int anime(clocks_t *clock);
void set_txt(txt_t *txt, int new_value);
void switch_music(rpg_t *rpg, char *music);
float RandomFloat(float a, float b);
void set_dtime(rpg_t *rpg);
void init(rpg_t *rpg, int argc, char **argv);
int gameloop(rpg_t *rpg);
void home(rpg_t *rpg);
void home_event(rpg_t *rpg, int scene);
void game(rpg_t *rpg);
void map(rpg_t *rpg);
void draw_map(rpg_t *rpg, map_t *m);
void map_event(rpg_t *rpg, map_t *m);
tile_t *create_tile(tile_t *t, char *path, sfVector2f pos);
void destroy_tiles(rpg_t *rpg);
void destroy_tile(map_t **t, int place);
void free_tile(tile_t *t);
void delete_middle(tile_t *t, int pos);
void delete_first(tile_t **t);
void display_map(rpg_t *r, map_t *m);
map_t *init_map(tile_t *t, int id);
void save_map(map_t *map);
void movement(rpg_t *rpg, sfKeyEvent *e, map_t *m);
void map_deplacement(rpg_t *rpg, map_t *m, sfVector2f mov, char type);
void handle_click(sfMouseButtonEvent e, map_t *m);
void handle_click_remove(sfMouseButtonEvent e, map_t *m);
void draw_current_map(rpg_t *rpg);
void player_map(rpg_t *rpg);
void draw_player_map(rpg_t *rpg);
void event_player_map(rpg_t *rpg);
void move_sprite_player_map(rpg_t *rpg, sfVector2f move);
void anime_player_map(rpg_t *rpg);
map_t *load_map(char *path, rpg_t *rpg);
char *get_name_from_id(int id);
void load_event(rpg_t *rpg);
void switch_map(rpg_t *rpg, char *map);
button_t *init_simple_button(sfVector2f pos, char *path);
void game_event(rpg_t *rpg);
void fight(rpg_t *rpg);
void fight_event(rpg_t *rpg);
void end_fight(rpg_t *rpg);
void end_fight_event(rpg_t *rpg);
void anime_player(rpg_t *rpg);
void anime_ennemis(rpg_t *rpg);
void free_fight(rpg_t *r);
void set_parallax(rpg_t *rpg);
void draw_parallax(rpg_t *rpg);
void launch_fight(rpg_t *rpg);
void attack(rpg_t *rpg, int cible);
void anime_hurt(rpg_t *rpg, int state, int cible);
void my_wait(rpg_t *rpg, float time);
void fight_draw(rpg_t *rpg);
void draw_enn(rpg_t *rpg);
void fight_move(rpg_t *rpg);
void update_hud(rpg_t *rpg);
void fight_menu(rpg_t *rpg, sfEvent *event);
int select_ennemis_menu(rpg_t *rpg, sfEvent *event);
void fight_end(rpg_t *rpg);
int reset_menu(rpg_t *rpg);
void ennemis_event(rpg_t *rpg);
ennemi_t *null(int i);
ennemi_t *ninja(int i);
ennemi_t *pirate(int i);
ennemi_t *viking(int i);
void run_fight(rpg_t *rpg);
dlist_t show_particles(rpg_t *rpg, dlist_t particles);
dlist_t new_particle(dlist_t list, part_param_t param);
int circle_animation(rpg_t *rpg);
int fade_in(rpg_t *rpg);
int fade_out(rpg_t *rpg);
void anime_end(rpg_t *rpg);
void inventory(rpg_t *rpg);
void inventory_event(rpg_t *rpg);
void go_to_inventory(rpg_t *rpg);
void use_potion(rpg_t *rpg);
void buy_potion(rpg_t *rpg);
menu_t *init_menu(void);
sfVector2i get_mouse(rpg_t *rpg);
sfVector2f get_mouse_2f(rpg_t *rpg);
int get_buttons_home(rpg_t *rpg);
void param_event(rpg_t *rpg, int param);
void param(rpg_t *rpg);
int get_buttons_param(rpg_t *rpg);
void set_fps(rpg_t *rpg, int step, char type);

#endif