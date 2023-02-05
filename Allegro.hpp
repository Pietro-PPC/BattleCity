#ifndef ALLEGRO_HPP
#define ALLEGRO_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include <string>

// Utiliza padrão singleton 
class Allegro{
    public:
        ~Allegro();
        Allegro(Allegro &outro) = delete;
        void operator=(const Allegro &outro) = delete;

        static Allegro *getInstancia();

        static constexpr double FRAMERATE = 1.0/60.0;
        static const unsigned int KEY_SEEN = 1;
        static const unsigned int KEY_RELEASED = 2;

        /* ===== AÇÕES DE CONTROLE DO JOGO ===== */
        void inicializar();

        /*
            Testa se foi feita uma ação para sair imediatamente do jogo
        */
        bool sairJogo();
        void finalizar();

        /* ===== MÉTODOS DE FILA DE EVENTOS ===== */
        unsigned short int getEvento();
        void esperarEvento();
        void esvaziarFila();

        /* ===== MÉTODOS DE TECLADO ===== */
        void visualizarTeclas();
        void pressionarTecla();
        void soltarTecla();

        /* ===== MÉTODOS DE TELA ===== */
        void limparTelaCor();
        void desenharTexto();
        void trocarDisplay();


        ALLEGRO_BITMAP* carregarSpritesheet(const std::string &nomeArquivo);
        ALLEGRO_BITMAP *pegarSprite(ALLEGRO_BITMAP *sheet, int x, int y, int w, int h);
        
        enum evento{
            TEMPO_QUADRO,
            TECLA_PRESSIONADA,
            TECLA_SOLTA,
            INDEFINIDO
        };


    private:
        Allegro();
        static Allegro *instancia;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_FONT* font;
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* queue;

        std::vector<unsigned char> key;

        void testInit(bool test, const std::string message);
};

#endif