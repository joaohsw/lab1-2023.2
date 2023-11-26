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

void limpar_matriz_tabuleiro(int matriz_tabuleiro[6][6]){

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if (matriz_tabuleiro[i][j] == 3){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 4){
                matriz_tabuleiro[i][j] = 0;
            }
        }
    }
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

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(matriz_tabuleiro[i][j] == 4){

            }
        }
    }

}


void opcoes_de_movimento(int matriz_tabuleiro[6][6], int i, int j, int *pode_jogar){

    if(j + 1 < 6 && matriz_tabuleiro[i][j + 1] == 0){
        matriz_tabuleiro[i][j + 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i + 1 < 6 && j + 1 < 6 && matriz_tabuleiro[i + 1][j + 1] == 0){
        matriz_tabuleiro[i + 1][j + 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i + 1 < 6 && matriz_tabuleiro[i + 1][j] == 0){
        matriz_tabuleiro[i + 1][j] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i - 1 >= 0 && matriz_tabuleiro[i - 1][j] == 0){
        matriz_tabuleiro[i - 1][j] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(j - 1 >= 0 && matriz_tabuleiro[i][j - 1] == 0){
        matriz_tabuleiro[i][j - 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i - 1 >= 0 && j - 1 >= 0 && matriz_tabuleiro[i - 1][j - 1] == 0){
        matriz_tabuleiro[i - 1][j - 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i - 1 >= 0 && j + 1 < 6 && matriz_tabuleiro[i - 1][j + 1] == 0){
        matriz_tabuleiro[i - 1][j + 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }
    if(i + 1 < 6 && j - 1 >= 0 && matriz_tabuleiro[i + 1][j - 1] == 0){
        matriz_tabuleiro[i + 1][j - 1] = 3;
        matriz_tabuleiro[i][j] = 4;
        *pode_jogar = 1;
    }

}

void hitbox(int matriz_tabuleiro[6][6], posicao matriz_coord[6][6], int coordx, int coordy, int *pode_jogar, ALLEGRO_BITMAP *tabuleiro, int *andar, int *vez){

    int i, j;
    int y = 0;



    for(i = 0; i < 6; i++){
        al_draw_bitmap(tabuleiro, 0, 0, 0);
        imprimir_matriz(matriz_coord, matriz_tabuleiro);



        int x = 0;

        if (i > 0) {
            y += 60;
        }

        for(j = 0; j < 6; j++){
            if(j > 0) {
                x += 60;
            }

            if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && *pode_jogar == 0 && (matriz_tabuleiro[i][j] == 1 && *vez == 1)){
                opcoes_de_movimento(matriz_tabuleiro, i, j, pode_jogar);
                if(*pode_jogar == 1){
                    for(i = 0; i < 6; i++){
                        for(j = 0; j < 6; j++){
                            if(matriz_tabuleiro[i][j] == 3){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 20, al_map_rgb(0, 255, 0));
                            }
                        }
                    }
                    *andar = 1;
                }

                printf("\n");

                for(i = 0; i < 6; i++){
                    for(j = 0; j < 6; j++){
                            printf("%4d", matriz_tabuleiro[i][j]);
                    }
                    printf("\n");
                }

            }

            if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && *pode_jogar == 0 && (matriz_tabuleiro[i][j] == 2 && *vez == 2)){
                opcoes_de_movimento(matriz_tabuleiro, i, j, pode_jogar);
                if(*pode_jogar == 1){
                    for(i = 0; i < 6; i++){
                        for(j = 0; j < 6; j++){
                            if(matriz_tabuleiro[i][j] == 3){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 20, al_map_rgb(0, 255, 0));
                            }
                        }
                    }
                    *andar = 1;
                }

                printf("\n");

                for(i = 0; i < 6; i++){
                    for(j = 0; j < 6; j++){
                            printf("%4d", matriz_tabuleiro[i][j]);
                    }
                    printf("\n");
                }

            }
        }
    }

    al_flip_display();
}

void bug_fix(int matriz_tabuleiro[6][6], int *vez){

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(matriz_tabuleiro[i][j] == 3){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 4 && *vez == 1){
                matriz_tabuleiro[i][j] = 1;
            }
            else if(matriz_tabuleiro[i][j] == 4 && *vez == 2){
                matriz_tabuleiro[i][j] = 2;
            }
        }
    }
}

void peca_andar(int matriz_tabuleiro[6][6],  posicao matriz_coord[6][6], int coordx, int coordy, int *andar, ALLEGRO_BITMAP *tabuleiro, int *pode_jogar, int *vez, bool *se_moveu) {

    int i, j, ja_mexeu = 0;

    if (*vez == 1 && ja_mexeu == 0){
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && matriz_tabuleiro[i][j] == 3) {
                    matriz_tabuleiro[i][j] = 1;
                    imprimir_matriz(matriz_coord, matriz_tabuleiro);
                    limpar_matriz_tabuleiro(matriz_tabuleiro);
                    *se_moveu = true;
                }
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && matriz_tabuleiro[i][j] != 3) {
                    bug_fix(matriz_tabuleiro, vez);
                    imprimir_matriz(matriz_coord, matriz_tabuleiro);
                }
            }
        }
        *pode_jogar = 0;
        *andar = 0;
        ja_mexeu = 1;
    }

    if (*vez == 2 && ja_mexeu == 0){
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && matriz_tabuleiro[i][j] == 3) {
                    matriz_tabuleiro[i][j] = 2;
                    imprimir_matriz(matriz_coord, matriz_tabuleiro);
                    limpar_matriz_tabuleiro(matriz_tabuleiro);
                    *se_moveu = true;
                }
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && matriz_tabuleiro[i][j] != 3) {
                    bug_fix(matriz_tabuleiro, vez);
                    imprimir_matriz(matriz_coord, matriz_tabuleiro);
                }
            }
        }
        *pode_jogar = 0;
        *andar = 0;
        ja_mexeu = 1;
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
    ALLEGRO_TIMER *fps = NULL, *timer = NULL;
    ALLEGRO_BITMAP *tabuleiro = al_load_bitmap("surakarta.png");
    ALLEGRO_MOUSE_STATE state;

    font = al_create_builtin_font();
    fila_eventos = al_create_event_queue();
    fps = al_create_timer(1.0 / 30.0);
    timer = al_create_timer(1.0);
    al_start_timer(fps);

    janela = al_create_display(TAMANHO_TELA_X, TAMANHO_TELA_Y);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(fps));

    bool rodando = true;

    int situacao = 1, vez = 1, rodadas = 0, andar = 0, pode_jogar = 0, clicks = 0;
    int matriz_tabuleiro[6][6] = {
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1
    };

    posicao matriz_coord[6][6];

    al_draw_bitmap(tabuleiro, 0, 0, 0);
    imprimir_matriz(matriz_coord, matriz_tabuleiro);

    al_start_timer(timer);

    while (rodando) {


        while(!al_is_event_queue_empty(fila_eventos)){

            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = false;
            }


            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                clicks++;
                int mouseX = evento.mouse.x;
                int mouseY = evento.mouse.y;
                printf("\n x = %d y = %d", mouseX, mouseY);
                printf("clicks: %d\n", clicks);

                if (andar == 1){
                    bool se_moveu;
                    peca_andar(matriz_tabuleiro, matriz_coord, mouseX, mouseY, &andar, tabuleiro, &pode_jogar, &vez, &se_moveu);
                    if (se_moveu == true){
                        if(vez == 1){
                            vez = 2;
                        }
                        else if(vez == 2){
                            vez = 1;
                        }
                    }
                }

                hitbox(matriz_tabuleiro, matriz_coord, mouseX, mouseY, &pode_jogar, tabuleiro, &andar, &vez);
            }


        }

        //printf("vez = %d\n", vez);

        al_flip_display();

    }

    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(tabuleiro);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font);

    return 0;
}
