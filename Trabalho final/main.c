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

typedef enum {
    
    MENU,
    JOGAR,
    SAIR,
    PAUSE,
    AJUDA
    
} game_state;



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


void menu(ALLEGRO_FONT *font_titulo, ALLEGRO_FONT *font_corpo) {

    const char *texto = "Jogar";
    int texto_comprimento = al_get_text_width(font_corpo, texto);
    int texto_altura = al_get_font_line_height(font_corpo);

    const char *texto2 = "Ajuda";
    int texto_comprimento2 = al_get_text_width(font_corpo, texto2);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Surakarta");
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10, TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10, TAMANHO_TELA_X / 2 + texto_comprimento / 2 + 10, TAMANHO_TELA_Y / 2 + texto_altura / 2 + 10, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, TAMANHO_TELA_Y / 2 - texto_altura / 2, ALLEGRO_ALIGN_CENTRE, texto);

    int ajuda_y = TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10 + texto_altura + 20 + 10; 
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10, ajuda_y, TAMANHO_TELA_X / 2 + texto_comprimento / 2 + 10, ajuda_y + texto_altura + 20, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, ajuda_y + 10, ALLEGRO_ALIGN_CENTRE, texto2);

    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10, ajuda_y + texto_altura + 20 + 10, TAMANHO_TELA_X / 2 + texto_comprimento / 2 + 10, ajuda_y + texto_altura + 20 + 10 + texto_altura + 20, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, ajuda_y + texto_altura + 20 + 10 + 10, ALLEGRO_ALIGN_CENTRE, "Sair");

    al_flip_display();
}

void tela_pause(int mouseX, int mouseY, game_state *estado, ALLEGRO_FONT *font_corpo) {

    const char *texto = "Continuar";
    const char *texto2 = "Sair";
    int texto_comprimento = al_get_text_width(font_corpo, texto);
    int texto_altura = al_get_font_line_height(font_corpo);
    int continue_x = TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10;
    int continue_y = TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10;
    int continue_comprimento = texto_comprimento + 20;
    int continue_altura = texto_altura + 20;

    int sair_x = continue_x;
    int sair_y = continue_y + continue_altura + 10; 

    al_draw_filled_rectangle(continue_x, continue_y, continue_x + continue_comprimento, continue_y + continue_altura, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, continue_y + continue_altura / 2 - texto_altura / 2, ALLEGRO_ALIGN_CENTRE, texto);

    al_draw_filled_rectangle(sair_x, sair_y, sair_x + continue_comprimento, sair_y + continue_altura, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, sair_y + continue_altura / 2 - continue_altura / 2, ALLEGRO_ALIGN_CENTRE, texto2);
    al_flip_display();        

}

void pagina_ajuda (ALLEGRO_FONT *font_corpo, ALLEGRO_FONT *font_titulo) {

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Ajuda");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 70, ALLEGRO_ALIGN_CENTRE, "O Surakarta possui uma grade de 6x6 e apenas 12 peças;");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 100, ALLEGRO_ALIGN_CENTRE, "O objetivo do jogo é capturar as peças do adversário;");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 130, ALLEGRO_ALIGN_CENTRE, "O jogo possui dois circuitos  de 3/4 de circunferência");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 160, ALLEGRO_ALIGN_CENTRE, "(circuito interno e externo) em cada um dos quatro cantos");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 190, ALLEGRO_ALIGN_CENTRE, "do tabuleiro e cujo percurso é obrigatório no momento");
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 220, ALLEGRO_ALIGN_CENTRE, "da captura de uma peça adversária.");
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - 50, TAMANHO_TELA_Y - 50, TAMANHO_TELA_X / 2 + 50, TAMANHO_TELA_Y, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, TAMANHO_TELA_Y - 40, ALLEGRO_ALIGN_CENTRE, "Voltar");
    al_flip_display();


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

void pode_atacar(int matriz_tabuleiro[6][6], int *pode_jogar, int *vez, int i, int j){
    
    int circuito_dentro[24] = {matriz_tabuleiro[1][0], matriz_tabuleiro[1][1], matriz_tabuleiro[1][2], matriz_tabuleiro[1][3], matriz_tabuleiro[1][4], matriz_tabuleiro[1][5], matriz_tabuleiro[0][4], matriz_tabuleiro[1][4], matriz_tabuleiro[2][4], matriz_tabuleiro[3][4], matriz_tabuleiro[4][4], matriz_tabuleiro[5][4], matriz_tabuleiro[4][5], matriz_tabuleiro[4][4], matriz_tabuleiro[4][3], matriz_tabuleiro[4][2], matriz_tabuleiro[4][1], matriz_tabuleiro[4][0], matriz_tabuleiro[5][1], matriz_tabuleiro[4][1], matriz_tabuleiro[3][1], matriz_tabuleiro[2][1], matriz_tabuleiro[1][1], matriz_tabuleiro[0][1]};
    int circuito_fora[24] = {matriz_tabuleiro[3][0], matriz_tabuleiro[3][1], matriz_tabuleiro[3][2], matriz_tabuleiro[3][3], matriz_tabuleiro[3][4], matriz_tabuleiro[3][5], matriz_tabuleiro[0][3], matriz_tabuleiro[1][3], matriz_tabuleiro[2][3], matriz_tabuleiro[3][3], matriz_tabuleiro[4][3], matriz_tabuleiro[5][3], matriz_tabuleiro[3][5], matriz_tabuleiro[3][4], matriz_tabuleiro[3][3], matriz_tabuleiro[3][2], matriz_tabuleiro[3][1], matriz_tabuleiro[3][0], matriz_tabuleiro[5][2], matriz_tabuleiro[4][2], matriz_tabuleiro[3][2], matriz_tabuleiro[2][2], matriz_tabuleiro[1][2], matriz_tabuleiro[0][2]};

    int posicao_dentro, posicao_fora;

    bool no_circuito_dentro = false, no_circuito_fora = false, pode_comer = false, deu_volta = false, passou_checkpoint = false, parou = false;

    int k, l;
    int posicao_peca_a_ser_comida, posicao_peca_a_ser_comida2;
    int checkpoints_dentro[8] = {matriz_tabuleiro[1][0], matriz_tabuleiro[1][5], matriz_tabuleiro[0][4], matriz_tabuleiro[5][4], matriz_tabuleiro[4][5], matriz_tabuleiro[4][0], matriz_tabuleiro[5][1], matriz_tabuleiro[0][1]};
    int checkpoints_fora[8] = {matriz_tabuleiro[3][0], matriz_tabuleiro[3][5], matriz_tabuleiro[0][3], matriz_tabuleiro[5][3], matriz_tabuleiro[3][5], matriz_tabuleiro[3][0], matriz_tabuleiro[5][2], matriz_tabuleiro[0][2]};

    for(k = 0; k < 24; k++){;
        if(circuito_dentro[i] == 4){
            no_circuito_dentro = true;
            posicao_dentro = i;
        }
        if(circuito_fora[i] == 4){
            no_circuito_fora = true;
            posicao_fora = i;
        }
    }

    // implementar ataque

    if(no_circuito_dentro == true && *vez == 1){

        int posicao_dentro2 = posicao_dentro;

        for(k = 0; k < 6; k++){
            for(l = 0; l < 6; l++){
                if(matriz_tabuleiro[k][l] == 4){
                    for(int aux = k; aux < 6; aux++){
                        if(matriz_tabuleiro[aux][l] == 1 || matriz_tabuleiro[aux][l] == 2 && passou_checkpoint == false){
                            parou = true;
                            break;
                        }
                        else if((matriz_tabuleiro[aux][l] == checkpoints_dentro[0] || matriz_tabuleiro[aux][l] == checkpoints_dentro[1] || matriz_tabuleiro[aux][j] == checkpoints_dentro[2] || matriz_tabuleiro[aux][j] == checkpoints_dentro[3] || matriz_tabuleiro[aux][j] == checkpoints_dentro[4] || matriz_tabuleiro[aux][j] == checkpoints_dentro[5] || matriz_tabuleiro[aux][j] == checkpoints_dentro[6] || matriz_tabuleiro[aux][j] == checkpoints_dentro[7]) && parou == false){
                            passou_checkpoint = true;
                        }
                        else if(matriz_tabuleiro[aux][l] == 2 && passou_checkpoint == true){
                            pode_comer = true;
                            matriz_tabuleiro[aux][l] = 5;
                        }   
                    }

                    parou = false;
                    passou_checkpoint = false;
                    pode_comer = false;

                    for(int aux = k; aux >= 0; aux++){
                        if(matriz_tabuleiro[aux][l] == 1 || matriz_tabuleiro[aux][l] == 2 && passou_checkpoint == false){
                            parou = true;
                            break;
                        }
                        else if((matriz_tabuleiro[aux][l] == checkpoints_dentro[0] || matriz_tabuleiro[aux][l] == checkpoints_dentro[1] || matriz_tabuleiro[aux][j] == checkpoints_dentro[2] || matriz_tabuleiro[aux][j] == checkpoints_dentro[3] || matriz_tabuleiro[aux][j] == checkpoints_dentro[4] || matriz_tabuleiro[aux][j] == checkpoints_dentro[5] || matriz_tabuleiro[aux][j] == checkpoints_dentro[6] || matriz_tabuleiro[aux][j] == checkpoints_dentro[7]) && parou == false){
                            passou_checkpoint = true;
                        }
                        else if(matriz_tabuleiro[aux][l] == 2 && passou_checkpoint == true){
                            pode_comer = true;
                            matriz_tabuleiro[aux][l] = 5;
                        }
                    }

                    parou = false;
                    passou_checkpoint = false;
                    pode_comer = false;

                    for(int aux = l; aux < 6; aux++){
                        if(matriz_tabuleiro[k][aux] == 1 || matriz_tabuleiro[k][aux] == 2 && passou_checkpoint == false){
                            parou = true;
                            break;
                        }
                        else if((matriz_tabuleiro[aux][l] == checkpoints_dentro[0] || matriz_tabuleiro[aux][l] == checkpoints_dentro[1] || matriz_tabuleiro[aux][j] == checkpoints_dentro[2] || matriz_tabuleiro[aux][j] == checkpoints_dentro[3] || matriz_tabuleiro[aux][j] == checkpoints_dentro[4] || matriz_tabuleiro[aux][j] == checkpoints_dentro[5] || matriz_tabuleiro[aux][j] == checkpoints_dentro[6] || matriz_tabuleiro[aux][j] == checkpoints_dentro[7]) && parou == false){
                            passou_checkpoint = true;
                        }
                        else if(matriz_tabuleiro[aux][l] == 2 && passou_checkpoint == true){
                            pode_comer = true;
                            matriz_tabuleiro[aux][l] = 5;
                        }   
                    }
                    
                }
            }
        }


        deu_volta = false;
        pode_comer = false;
        passou_checkpoint = false;

    }

    if(no_circuito_fora){
        
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
                pode_atacar(matriz_tabuleiro, pode_jogar, vez, i, j);
                if(*pode_jogar == 1){
                    for(i = 0; i < 6; i++){
                        for(j = 0; j < 6; j++){
                            if(matriz_tabuleiro[i][j] == 3){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 20, al_map_rgb(0, 255, 0));
                            }
                            if(matriz_tabuleiro[i][j] == 5){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 25, al_map_rgb(255, 0, 0));
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
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && (matriz_tabuleiro[i][j] == 3 || matriz_tabuleiro[i][j] == 5)) {
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
    al_init_ttf_addon();
    al_init_font_addon();

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *tabuleiro = al_load_bitmap("surakarta.png");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT *font_titulo = NULL, *font_corpo = NULL;

    game_state estado = MENU;

    font_titulo = al_load_font("./open-sans/OpenSans-BoldItalic.ttf", 52, 0);
    font_corpo = al_load_font("./open-sans/OpenSans-Semibold.ttf", 28, 0);
    fila_eventos = al_create_event_queue();
    timer = al_create_timer(1.0);

    janela = al_create_display(TAMANHO_TELA_X, TAMANHO_TELA_Y);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    bool rodando = true;

    int situacao = 1, vez = 1, rodadas = 0, andar = 0, pode_jogar = 0, clicks = 0, tempo = 0, minutos = 0, horas = 0;
    int matriz_tabuleiro[6][6] = {
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1
    };

    int pause_x = TAMANHO_TELA_X - 100;
    int pause_y = 300;
    int pause_comprimento = 80;
    int pause_altura = 50;
    char text[] = "Pause";

    posicao matriz_coord[6][6];

    al_start_timer(timer);

    while (rodando) {



        while(!al_is_event_queue_empty(fila_eventos)){

            if(estado == MENU){
                menu(font_titulo, font_corpo);
            }

            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = false;
            }

            if (evento.type == ALLEGRO_EVENT_TIMER) {
                if(estado == JOGAR){
                    tempo++;
                }    
            }

            if (estado == PAUSE){
                int mouseX = evento.mouse.x, mouseY = evento.mouse.y;
                const char *texto = "Continuar";
                int texto_comprimento = al_get_text_width(font_corpo, texto);
                int texto_altura = al_get_font_line_height(font_corpo);
                tela_pause(mouseX, mouseY, &estado, font_corpo);

                if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if(mouseX >= TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10 && mouseX <= TAMANHO_TELA_X / 2 + texto_comprimento / 2 + 10 && mouseY >= TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10 && mouseY <= TAMANHO_TELA_Y / 2 + texto_altura / 2 + 10) {
                        estado = JOGAR;
                    }
                    else if (mouseX >= TAMANHO_TELA_X / 2 - texto_comprimento / 2 - 10 && mouseX <= TAMANHO_TELA_X / 2 + texto_comprimento / 2 + 10 && mouseY >= TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10 + texto_altura + 10 && mouseY <= TAMANHO_TELA_Y / 2 + texto_altura / 2 + 10 + texto_altura + 10) {
                        estado = MENU;
                    }
                }
            }

            if (estado == JOGAR){
                char tempo_texto[50];
                int segundos = tempo;
                if(segundos == 60){
                    minutos++;
                    segundos = 0;
                    tempo = 0;
                }
                if(minutos == 60){
                    horas++;
                    minutos = 0;
                }
                sprintf(tempo_texto, "%d:%02d:%02d", horas, minutos, segundos);
                al_draw_filled_rectangle(TAMANHO_TELA_X - 110, 0, TAMANHO_TELA_X, 50, al_map_rgb(0, 0, 0));
                al_draw_text(font_corpo, al_map_rgb(255, 255, 255), TAMANHO_TELA_X - 10, 10, ALLEGRO_ALIGN_RIGHT, tempo_texto);
            }
    

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

                const char *texto = "Teste";

                int texto_comprimento = al_get_text_width(font_corpo, texto);
                int texto_altura = al_get_font_line_height(font_corpo);
                int botao_comprimento = texto_comprimento + 20; // width of the rectangle
                int botao_altura = texto_altura + 20; // height of the rectangle
                int botao_x = TAMANHO_TELA_X / 2 - botao_comprimento / 2; // x position of the rectangle
                int botao_y = TAMANHO_TELA_Y / 2 - botao_altura / 2 - 10; // y position of the rectangle

                if(estado == MENU){

                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= botao_y && evento.mouse.y <= botao_y + botao_altura){
                        estado = JOGAR;
                    }

                    int ajuda_y = botao_y + botao_altura + 10;
                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= ajuda_y && evento.mouse.y <= ajuda_y + botao_altura){
                        estado = AJUDA;
                    }

                    int sair_y = ajuda_y + botao_altura + 10;
                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= sair_y && evento.mouse.y <= sair_y + botao_altura){
                        rodando = false;
                    }   
                }

                
                if(estado == JOGAR){

                    clicks++;
                    int mouseX = evento.mouse.x;
                    int mouseY = evento.mouse.y;
                    printf("\n x = %d y = %d", mouseX, mouseY);
                    printf("clicks: %d\n", clicks);

                    if (andar == 1){
                        bool se_moveu = false;
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

                    int texto_comprimento = al_get_text_width(font_corpo, text);
                    int texto_altura = al_get_font_line_height(font_corpo);

                    int x = TAMANHO_TELA_X - texto_comprimento - 20;

                    al_draw_filled_rectangle(x, TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10, x + texto_comprimento + 20, TAMANHO_TELA_Y / 2 + texto_altura / 2 + 10, al_map_rgb(0, 255, 255));
                    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), x + 10, TAMANHO_TELA_Y / 2 - texto_altura / 2, ALLEGRO_ALIGN_LEFT, text);

                    if(mouseX >= pause_x && mouseX <= pause_x + pause_comprimento && mouseY >= pause_y && mouseY <= pause_y + pause_altura) {
                        estado = PAUSE;
                    }
                    
                }

                if(estado == AJUDA){
                    pagina_ajuda(font_corpo, font_titulo);
                    if(evento.mouse.x >= TAMANHO_TELA_X / 2 - 50 && evento.mouse.x <= TAMANHO_TELA_X / 2 + 50 && evento.mouse.y >= TAMANHO_TELA_Y - 50 && evento.mouse.y <= TAMANHO_TELA_Y){
                        estado = MENU;
                    }
                }


            }

            al_flip_display();

    }
}

    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(tabuleiro);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_font(font_titulo);
    al_destroy_font(font_corpo);

    return 0;
}
