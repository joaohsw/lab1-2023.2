#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#define TAMANHO_TELA_X 800
#define TAMANHO_TELA_Y 600

typedef struct {

    int nP1;
    int nP2;

} pecas;

typedef struct {

    int cx;
    int cy

} posicao;


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
            al_draw_filled_circle(222, 355, 30, al_map_rgb(0, 0, 255));

        }

        else {
            al_draw_filled_circle((x + 60), 355, 30, al_map_rgb(0, 0, 255));
            x += 60;
        }
    }

}

void teste (posicao matriz_coord[6][6], int rodadas, int vez){

    int i, j, x, y;

    x = 250;
    y = 150;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(i == 0){
                matriz_coord[i][j].cx = x;
            }
            else if (i > 0){
                matriz_coord[i][j].cx = x + 60;
                if (x = 550){
                    x = 250;
                }
            }
            if(j = 0){
                matriz_coord[i][j].cy = y;
            } else if(j = 1){
                matriz_coord[i][j].cy = y + 60;
            } else if(j = 2){
                matriz_coord[i][j].cy = y + 120;
            } else if(j = 3){
                matriz_coord[i][j].cy = y + 180;
            } else if(j = 4){
                matriz_coord[i][j].cy = y + 240;
            } else if(j = 5){
                matriz_coord[i][j].cy = y + 300;
            }
        }
    }




}


void pvp(int coordx, int coordy, int *vez, int *rodadas) {

    posicao matriz_coord[6][6];
    pecas pecaspvp; 

    teste(matriz_coord, rodadas, vez);


    pecaspvp.nP1 = 12;
    pecaspvp.nP2 = 12;

    int p1x[12] = {250, 310, 370, 430, 490, 550, 250, 310, 370, 430, 490, 550};
    int p1y[12] = {435, 435, 435, 435, 435, 435, 390, 390, 390, 390, 390, 390};

    int p2x[12] = {250, 310, 370, 430, 490, 550, 250, 310, 370, 430, 490, 550};
    int p2y[12] = {150, 150, 150, 150, 150, 150, 210, 210, 210, 210, 210, 210};

    if (vez == 1){
        if(coordx >= 285 && coordx <= 335 && coordy >= 380 && coordy <= 425){
            al_draw_filled_circle(310, 330, 25, al_map_rgb(0, 0, 255));
        }



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
    int situacao = 1, vez = 1, rodadas = 0;

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

        al_draw_bitmap(tabuleiro, 0, 0, 0);
        rodadas++;

        if (situacao == 1) {
            
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && vez == 1){
                al_get_mouse_state(&state);
                pvp(state.x, state.y, vez, rodadas);
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                
                }
            }

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && vez == 2){
                al_get_mouse_state(&state);
                pvp(state.x, state.y, vez, rodadas);
            }

        }

        al_flip_display();

    }

    al_destroy_bitmap(tabuleiro);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
