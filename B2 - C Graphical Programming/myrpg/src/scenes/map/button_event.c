/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_event
*/

#include "rpg.h"
#include <math.h>
#include "lib.h"

sfVector2f get_pos(sfMouseButtonEvent e, map_t *m)
{
    tile_t *tmp = m->clone;
    sfVector2f pos = {(int)(e.x / 48) * 48, (int)(e.y / 48) * 48};
    sfVector2f pos_c;

    while (tmp->next != NULL)
        tmp = tmp->next;
    pos_c = (sfVector2f){sfSprite_getGlobalBounds(tmp->s->sprite).left,
    sfSprite_getGlobalBounds(tmp->s->sprite).top};
    pos.x += pos_c.x - ((int)pos_c.x / 48) * 48;
    pos.y += pos_c.y - ((int)pos_c.y / 48) * 48;
    return pos;
}

static void button_click(sfMouseButtonEvent e, int *not_button, map_t *m)
{
    sfFloatRect tmp;
    sbtn_t *b = m->b;

    while (b != NULL) {
        tmp = sfSprite_getGlobalBounds(b->s->sprite);
        if (sfFloatRect_contains(&tmp, e.x, e.y)) {
            m->type = b->type;
            *not_button = 1;
        }
        b = b->next;
    }
}

void handle_click(sfMouseButtonEvent e, map_t *m)
{
    tile_t *t = m->clone;
    int not_button = 0;
    sfVector2f pos = get_pos(e, m);
    sfFloatRect tmp;

    button_click(e, &not_button, m);
    while (t != NULL) {
        if (sfSprite_getGlobalBounds(t->s->sprite).top == pos.y &&
        sfSprite_getGlobalBounds(t->s->sprite).left == pos.x)
            not_button = 1;
        t = t->next;
    }
    tmp = sfSprite_getGlobalBounds(m->save_button->s->sprite);
    if (sfFloatRect_contains(&tmp, e.x, e.y)) {
        save_map(m);
        not_button = 1;
    }
    if (not_button == 0)
        m->clone = create_tile(m->clone, m->type, pos);
}

void handle_click_remove(sfMouseButtonEvent e, map_t *m)
{
    tile_t *t = m->clone;
    int tile_pos = 0;
    sfVector2f pos = get_pos(e, m);

    while (t != NULL) {
        sfFloatRect bound = sfSprite_getGlobalBounds(t->s->sprite);
        if (bound.left == pos.x && bound.top == pos.y) {
            destroy_tile(&m, tile_pos);
        }
        t = t->next;
        tile_pos++;
    }
}