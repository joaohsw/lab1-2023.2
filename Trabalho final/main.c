#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#define TAMANHO_TELA_X 800
#define TAMANHO_TELA_Y 600

struct pecas {

    int nP1;
    int nP2;

};


void menu() {
    // Lógica do menu aqui
}

void jogo() {
    // Lógica do jogo aqui
}

void tabuleiro_inicial(ALLEGRO_BITMAP *tabuleiro, ALLEGRO_BITMAP *peca1, ALLEGRO_BITMAP *peca2){

    int i, j = 0;

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

}

void pvp(int coordx, int coordy, ALLEGRO_BITMAP *opcao, int vez) {

    int matriz_tabuleiro[6][6] = {
            2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1
        };

    struct pecas pecaspvp;

    pecaspvp.nP1 = 12;
    pecaspvp.nP2 = 12;

    int p1x[12] = {250, 310, 370, 430, 490, 550, 250, 310, 370, 430, 490, 550};
    int p1y[12] = {435, 435, 435, 435, 435, 435, 390, 390, 390, 390, 390, 390};

    int p2x[12] = {250, 310, 370, 430, 490, 550, 250, 310, 370, 430, 490, 550};
    int p2y[12] = {150, 150, 150, 150, 150, 150, 210, 210, 210, 210, 210, 210};

    if (vez == 1){




    }
    if(coordx >= 285 && coordx <= 335 && coordy >= 425 && coordy <= 470){
        al_draw_bitmap(opcao, 200, 200, 0);
    }
    

}


int main(void) {

    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *tabuleiro = al_load_bitmap("surakarta.png");
    ALLEGRO_BITMAP *peca1 = al_load_bitmap("peca1.png");
    ALLEGRO_BITMAP *peca2 = al_load_bitmap("peca2.png");
    ALLEGRO_BITMAP *opcao = al_load_bitmap("opcao.png");
    ALLEGRO_MOUSE_STATE state;



    font = al_create_builtin_font();
    fila_eventos = al_create_event_queue();
    timer = al_create_timer(0.1);
    al_start_timer(timer);

    janela = al_create_display(TAMANHO_TELA_X, TAMANHO_TELA_Y);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    bool rodando = true;
    int situacao = 1;
    int vez = 1;

     while (rodando) {

        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            rodando = false;
        }

         if (evento.type == ALLEGRO_EVENT_TIMER) {
            if (al_get_timer_count(timer)%240 == 0) {
                situacao = !situacao;
            }
        }

        if (situacao == 1) {
            tabuleiro_inicial(tabuleiro, peca1, peca2);
        }

        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && vez == 1){
            al_get_mouse_state(&state);
            pvp(state.x, state.y, opcao, vez);
        }

        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && vez == 2){
            al_get_mouse_state(&state);
            pvp(state.x, state.y, opcao, vez);
        }

        al_flip_display();

    }

    al_destroy_bitmap(tabuleiro);
    al_destroy_bitmap(peca1);
    al_destroy_bitmap(peca2);

    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
