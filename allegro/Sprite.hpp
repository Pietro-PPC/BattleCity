#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <allegro5/allegro5.h>
#include <string>

namespace Allegro{
class Sprite {
    public:
        Sprite();
        Sprite(const std::string &fileName);
        Sprite(const Sprite *sprite, int x, int y, int w, int h);
        ~Sprite();

        ALLEGRO_BITMAP *getBitmap() const;

    private:
        ALLEGRO_BITMAP *bitmap;
};
}
#endif