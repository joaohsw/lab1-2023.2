#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif


#define TAMANHO_TELA_X 800
#define TAMANHO_TELA_Y 600

typedef struct {

    int nP1;
    int nP2;

} pecas;

typedef struct {

    int cx;
    int cy;

} posicao;

void limpaTela() {

 system(CLEAR);

}


void menu() {
    // Lógica do menu aqui
}

void jogo() {
    // Lógica do jogo aqui
}


void imprimir_matriz (posicao matriz_coord[6][6], int matriz_tabuleiro[6][6]){

    int i, j, x, y;

    x = 250;
    y = 150;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){

            matriz_coord[i][j].cx = x + (j * 60); 
            matriz_coord[i][j].cy = y + (i * 60);
        }
    }

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(matriz_tabuleiro[i][j] == 1){
                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 25, al_map_rgb(0, 0, 255));
            }
            if(matriz_tabuleiro[i][j] == 2){
                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 25, al_map_rgb(255, 0, 0));
            }
        }
    }

    al_flip_display();

}

void hitbox(int matriz_tabuleiro[6][6], posicao matriz_coord[6][6], int coordx, int coordy, int *podeJogar){

    int i, j;

    //while(1) {

        int y = 0;
        for(i = 0; i < 6; i++){
            int x = 0;
            if (i > 0) {
                y += 60;
            }


            for(j = 0; j < 6; j++){
                if(j > 0) {
                    x += 60;
                }
                
                if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && matriz_tabuleiro[i][j] == 1){
                    if(matriz_tabuleiro[i][j + 1] == 0){
                        al_draw_filled_circle(matriz_coord[i][j + 1].cx, matriz_coord[i][j + 1].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i + 1][j + 1] == 0){
                        al_draw_filled_circle(matriz_coord[i + 1][j + 1].cx, matriz_coord[i + 1][j + 1].cy, 20, al_map_rgb(0, 255, 0));
                    }
                    printf("time: %d\n", matriz_tabuleiro[i + 1][j]); 
                    if(matriz_tabuleiro[i + 1][j] == 1){
                        printf("AQUI");
                        al_draw_filled_circle(matriz_coord[i + 1][j].cx, matriz_coord[i + 1][j].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i - 1][j] == 0){
                        al_draw_filled_circle(matriz_coord[i - 1][j].cx, matriz_coord[i - 1][j].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i][j - 1] == 0){
                        al_draw_filled_circle(matriz_coord[i][j - 1].cx, matriz_coord[i][j - 1].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i - 1][j + - 1] == 0){
                        al_draw_filled_circle(matriz_coord[i - 1][j - 1].cx, matriz_coord[i - 1][j - 1].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i - 1][j + 1] == 0){
                        al_draw_filled_circle(matriz_coord[i - 1][j + 1].cx, matriz_coord[i - 1][j + 1].cy, 20, al_map_rgb(0, 255, 0));
                    } if(matriz_tabuleiro[i + 1][j - 1] == 0){
                        al_draw_filled_circle(matriz_coord[i + 1][j - 1].cx, matriz_coord[i + 1][j - 1].cy, 20, al_map_rgb(0, 255, 0));
                    }

                    *podeJogar = 1;
                }
            }
        }
        
    //}
    al_flip_display();
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
    /* timer = al_create_timer(1.0 / 30.0);
    al_start_timer(timer); */

    janela = al_create_display(TAMANHO_TELA_X, TAMANHO_TELA_Y);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
   /* al_register_event_source(fila_eventos, al_get_timer_event_source(timer)); */

    bool rodando = true;

    int situacao = 1, vez = 1, rodadas = 0;

    int podeJogar = 0;
    int matriz_tabuleiro[6][6] = {
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1
    };

    posicao matriz_coord[6][6];

    

    while (rodando) {

        while(!al_is_event_queue_empty(fila_eventos)){

            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = false;
            }
                
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
                //al_get_mouse_state(&state);
                int mouseX = evento.mouse.x;
                int mouseY = evento.mouse.y;
                printf("\n x = %d  y = %d", mouseX, mouseY);
                //printf("\n%d %d", state.x, state.y);
                hitbox(matriz_tabuleiro, matriz_coord, mouseX, mouseY, &podeJogar);

            }
            
            
        }

        //a
        if (situacao == 1){
            al_draw_bitmap(tabuleiro, 0, 0, 0);
            imprimir_matriz(matriz_coord, matriz_tabuleiro);
        }

        //a
        if (!podeJogar) {
        al_flip_display();
        }

    }

    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(tabuleiro);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font);

    return 0;
}
