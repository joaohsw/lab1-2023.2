#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#define TAMANHO_TELA_X 800
#define TAMANHO_TELA_Y 600

void menu() {
    // L�gica do menu aqui
}

void jogo() {
    // L�gica do jogo aqui
}

void pvp() {

    int matriz_tabuleiro[6][6] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};


}

void tabuleiro_inicial(ALLEGRO_DISPLAY *janela){

        int i, j = 0;

        ALLEGRO_BITMAP *tabuleiro = al_load_bitmap("surakarta.png");
        ALLEGRO_BITMAP *peca1 = al_load_bitmap("peca1.png");
        ALLEGRO_BITMAP *peca2 = al_load_bitmap("peca2.png");

        al_draw_bitmap(tabuleiro, 0, 0, 0); // Desenha o fundo na tela

        int x = 222;

        for(i = 0; i < 6; i++, j++){

            if (i == 0){
                al_draw_bitmap(peca1, 222, 125, 0);

            }
            else {
                al_draw_bitmap(peca1, (x + 60), 125, 0);
                x += 60;
            }
        }

        x = 222;

        for(i = 0; i < 6; i++, j++){

            if (i == 0){
                al_draw_bitmap(peca1, 222, 185, 0);

            }
            else {
                al_draw_bitmap(peca1, (x + 60), 185, 0);
                x += 60;
            }
        }

        x = 222;

        for(i = 0; i < 6; i++, j++){

            if (i == 0){
                al_draw_bitmap(peca2, 222, 415, 0);

            }
            else {
                al_draw_bitmap(peca2, (x + 60), 415, 0);
                x += 60;
            }
        }

        x = 222;

        for(i = 0; i < 6; i++, j++){

            if (i == 0){
                al_draw_bitmap(peca2, 222, 355, 0);

            }

            else {
                al_draw_bitmap(peca2, (x + 60), 355, 0);
                x += 60;
            }
        }

        al_flip_display();

}

int main(void) {

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMER *timer = NULL;

    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();

    font = al_create_builtin_font();
    fila_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / 30.0);

    janela = al_create_display(TAMANHO_TELA_X, TAMANHO_TELA_Y);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    al_start_timer(timer);

    bool rodando = true;

     while (rodando) {

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            rodando = false;
        }

        tabuleiro_inicial(janela);

    }

    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
