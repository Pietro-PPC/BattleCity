#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Tanque.hpp"
#include "Parede.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "allegro/Sprite.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Player : public Tanque {
    public:
        Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
                EnumDirecao direcao, Allegro::Sprite4D* const &sprites, Allegro::Sprite4D* const &tiroSprites);

        ~Player();

        void mover(const std::vector<Parede *> &paredes, const std::vector<Parede *> &paredesInvenciveis);

        /**
         * @todo: a colisão funciona, porém ela não é aqui e é com objeto genérico 
         */

        bool algumaColisao(const std::vector<Parede *> &paredes);
        
    private:
};


#endif