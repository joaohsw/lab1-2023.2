#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
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
    AJUDA,
    FIM,
    HISTORICO,
    JOGAR2,
    MODO
    
} game_state;

typedef struct {

    int cx;
    int cy;

} posicao;

void limpaTela() {

 system(CLEAR);

}

void menu(ALLEGRO_FONT *font_titulo, ALLEGRO_FONT *font_corpo) {

    int button_width = 130;
    int button_height = 45;

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Surakarta");

    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - button_width / 2, TAMANHO_TELA_Y / 2 - button_height / 2, TAMANHO_TELA_X / 2 + button_width / 2, TAMANHO_TELA_Y / 2 + button_height / 2, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, TAMANHO_TELA_Y / 2 - button_height / 2, ALLEGRO_ALIGN_CENTRE, "Jogar");

    int ajuda_y = TAMANHO_TELA_Y / 2 + button_height / 2 + 10;
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - button_width / 2, ajuda_y, TAMANHO_TELA_X / 2 + button_width / 2, ajuda_y + button_height, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, ajuda_y + 10, ALLEGRO_ALIGN_CENTRE, "Ajuda");

    ajuda_y += button_height + 10;
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - button_width / 2, ajuda_y, TAMANHO_TELA_X / 2 + button_width / 2, ajuda_y + button_height, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, ajuda_y + 10, ALLEGRO_ALIGN_CENTRE, "Histórico");

    ajuda_y += button_height + 10;
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - button_width / 2, ajuda_y, TAMANHO_TELA_X / 2 + button_width / 2, ajuda_y + button_height, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, ajuda_y + 10, ALLEGRO_ALIGN_CENTRE, "Sair");

    al_flip_display();

}

void tela_historico(ALLEGRO_FONT *font_titulo, ALLEGRO_FONT *font_corpo){

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(255, 0, 255), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Histórico");
    al_draw_rectangle(50, 50, TAMANHO_TELA_X - 50, TAMANHO_TELA_Y - 50, al_map_rgb(0, 0, 0), 2);

    FILE *file = fopen("historico.txt", "r");
    if(file != NULL){
        char line[256];
        int y = 70; // Start y-coordinate for text
        while(fgets(line, sizeof(line), file)){
            al_draw_text(font_corpo, al_map_rgb(0, 0, 0), 60, y, ALLEGRO_ALIGN_LEFT, line);
            y += al_get_font_line_height(font_corpo); // Move y-coordinate down for the next line
        }
        fclose(file);
    }

    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - 50, TAMANHO_TELA_Y - 50, TAMANHO_TELA_X / 2 + 50, TAMANHO_TELA_Y, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, TAMANHO_TELA_Y - 40, ALLEGRO_ALIGN_CENTRE, "Voltar");



}


void tela_vitoria(int ganhador, ALLEGRO_FONT *font_corpo, ALLEGRO_FONT *font_titulo){

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Vitória!");
    if (ganhador == 1){
        al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 70, ALLEGRO_ALIGN_CENTRE, "O jogador 1 venceu!");

    }
    else if (ganhador == 2){
        al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 70, ALLEGRO_ALIGN_CENTRE, "O jogador 2 venceu!");
    }
    al_draw_filled_rectangle(TAMANHO_TELA_X / 2 - 50, TAMANHO_TELA_Y - 50, TAMANHO_TELA_X / 2 + 50, TAMANHO_TELA_Y, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, TAMANHO_TELA_Y - 40, ALLEGRO_ALIGN_CENTRE, "Voltar");

}

void tela_modo(ALLEGRO_FONT *font_titulo, ALLEGRO_FONT *font_corpo){

    int quadrado = 100;
    int gap = 150; 

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(font_titulo, al_map_rgb(0, 0, 0), TAMANHO_TELA_X / 2, 10, ALLEGRO_ALIGN_CENTRE, "Modo de Jogo");

    int x1 = TAMANHO_TELA_X / 2 - quadrado - gap / 2;
    al_draw_filled_rectangle(x1, TAMANHO_TELA_Y / 2 - quadrado / 2, x1 + quadrado, TAMANHO_TELA_Y / 2 + quadrado / 2, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), x1 + quadrado / 2, TAMANHO_TELA_Y / 2, ALLEGRO_ALIGN_CENTRE, "PvP");

    int x2 = TAMANHO_TELA_X / 2 + gap / 2;
    al_draw_filled_rectangle(x2, TAMANHO_TELA_Y / 2 - quadrado / 2, x2 + quadrado, TAMANHO_TELA_Y / 2 + quadrado / 2, al_map_rgb(0, 255, 255));
    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), x2 + quadrado / 2, TAMANHO_TELA_Y / 2, ALLEGRO_ALIGN_CENTRE, "PvC");
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


void limpar_matriz_tabuleiro(int matriz_tabuleiro[6][6], int *vez){

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if (matriz_tabuleiro[i][j] == 3){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 4){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 5 && *vez == 2){
                matriz_tabuleiro[i][j] = 1;
            }
            else if(matriz_tabuleiro[i][j] == 5 && *vez == 1){
                matriz_tabuleiro[i][j] = 2;
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

void ataque(int matriz_tabuleiro[6][6], int i, int j, int *vez){
    int inimigo = (*vez == 1) ? 2 : 1;
    int amigo = (*vez == 1) ? 1 : 2;
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for(int d = 0; d < 8; d++){
        int x = i, y = j;
        while(x >= 0 && x < 6 && y >= 0 && y < 6){
            if(matriz_tabuleiro[x][y] == inimigo){
                matriz_tabuleiro[x][y] = 5;
                break;
            } else if(matriz_tabuleiro[x][y] == amigo) {
                break;
            }
            x += direcoes[d][0];
            y += direcoes[d][1];
            if(x < 0 || x >= 6) x = 5 - x;
            if(y < 0 || y >= 6) y = 5 - y;
        }
    }
}

int adjacente(int matriz_tabuleiro[6][6], int i, int j){
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for(int d = 0; d < 8; d++){
        int x = i + direcoes[d][0];
        int y = j + direcoes[d][1];
        if(x >= 0 && x < 6 && y >= 0 && y < 6 && matriz_tabuleiro[x][y] == 2){
            return 1;
        }
    }
    return 0;
}

void limpar_tela_pc(int matriz_tabuleiro[6][6]){

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(matriz_tabuleiro[i][j] == 3){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 4){
                matriz_tabuleiro[i][j] = 0;
            }
            if(matriz_tabuleiro[i][j] == 5){
                matriz_tabuleiro[i][j] = 1;
            }
        }
    }
}

void pc(int matriz_tabuleiro[6][6], int *vez){
    printf("teste\n");
    srand(time(NULL));
    int i, j, x, y, atacar_andar = 0;
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    do {
        i = rand() % 6;
        j = rand() % 6;
    } while(matriz_tabuleiro[i][j] != 2);

    for(int k = 0; k < 8; k++) {
        x = i + direcoes[k][0];
        y = j + direcoes[k][1];
        if(x >= 0 && x < 6 && y >= 0 && y < 6 && matriz_tabuleiro[x][y] == 0) {
            matriz_tabuleiro[x][y] = 2;
            matriz_tabuleiro[i][j] = 0;
            break;
        }
    }

    do {
        i = rand() % 6;
        j = rand() % 6;
    } while(matriz_tabuleiro[i][j] != 0 || !adjacente(matriz_tabuleiro, i, j));

    ataque(matriz_tabuleiro, i, j, vez);
    *vez = 1;
    limpar_tela_pc(matriz_tabuleiro);

}

void hitbox(int matriz_tabuleiro[6][6], posicao matriz_coord[6][6], int coordx, int coordy, int *pode_jogar, ALLEGRO_BITMAP *tabuleiro, int *andar, int *vez, int *modo){

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

            if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && *pode_jogar == 0 && (matriz_tabuleiro[i][j] == 1 && *vez == 1 && *modo == 2)){
                opcoes_de_movimento(matriz_tabuleiro, i, j, pode_jogar);
                ataque(matriz_tabuleiro, i, j, vez);
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

            if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && *pode_jogar == 0 && (matriz_tabuleiro[i][j] == 2 && *vez == 2 && *modo == 2)){
                opcoes_de_movimento(matriz_tabuleiro, i, j, pode_jogar);
                ataque(matriz_tabuleiro, i, j, vez);
                if(*pode_jogar == 1){
                    for(i = 0; i < 6; i++){
                        for(j = 0; j < 6; j++){
                            if(matriz_tabuleiro[i][j] == 3){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 20, al_map_rgb(0, 255, 0));  
                            }
                            if(matriz_tabuleiro[i][j] == 5){
                                al_draw_filled_circle(matriz_coord[i][j].cx, matriz_coord[i][j].cy, 25, al_map_rgb(0, 0, 255));
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

            if(coordx >= 225 + x && coordx <= 275 + x && coordy <=175 + y && coordy >= 125 + y && *pode_jogar == 0 && (matriz_tabuleiro[i][j] == 1 && *vez == 1 && *modo == 1)){
                opcoes_de_movimento(matriz_tabuleiro, i, j, pode_jogar);
                ataque(matriz_tabuleiro, i, j, vez);
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

            if(*modo == 1 && *vez == 2){
                pc(matriz_tabuleiro, vez);
                if(*pode_jogar == 1){
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
                    limpar_matriz_tabuleiro(matriz_tabuleiro, vez);
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
                if (coordx >= matriz_coord[i][j].cx - 25 && coordx <= matriz_coord[i][j].cx + 25 && coordy >= matriz_coord[i][j].cy - 25 && coordy <= matriz_coord[i][j].cy + 25 && matriz_tabuleiro[i][j] == 3 || matriz_tabuleiro[i][j] == 5) {
                    matriz_tabuleiro[i][j] = 2;
                    imprimir_matriz(matriz_coord, matriz_tabuleiro);
                    limpar_matriz_tabuleiro(matriz_tabuleiro, vez);
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

int decidir_ganhador(int matriz_tabuleiro[6][6]){

    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(matriz_tabuleiro[i][j] == 1) {
                count1++;
            }
            if(matriz_tabuleiro[i][j] == 2){
                count2++;
            }
            if(matriz_tabuleiro[i][j] == 3){
                count3++;
            }
            if(matriz_tabuleiro[i][j] == 4){
                count4++;
            }
            if(matriz_tabuleiro[i][j] == 5){
                count5++;
            }
        }
    }

    if(count1 == 0 && count3 == 0 && count4 == 0 && count5 == 0){
        return 2;

    }
    else if (count2 == 0 && count3 == 0 && count4 == 0 && count5 == 0){
        return 1;
    } 
    else {
        return 0;  
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

    bool rodando = true, resultado_escrito = false;

    int ganhador, segundos, situacao = 1, vez = 1, rodadas = 0, andar = 0, pode_jogar = 0, clicks = 0, tempo = 0, minutos = 0, horas = 0, n_pecas1 = 12, n_pecas2 = 12, modo = 0;
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
                segundos = tempo;
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

                int botao_comprimento = 130;
                int botao_altura = 45; 
                int botao_x = TAMANHO_TELA_X / 2 - botao_comprimento / 2;
                int botao_y = TAMANHO_TELA_Y / 2 - botao_altura / 2 - 10; 

                if(estado == MENU){

                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= botao_y && evento.mouse.y <= botao_y + botao_altura){
                        estado = MODO;
                    }

                    int ajuda_y = botao_y + botao_altura + 10;
                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= ajuda_y && evento.mouse.y <= ajuda_y + botao_altura){
                        estado = AJUDA;
                    }

                    int historico_y = ajuda_y + botao_altura + 10;
                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= historico_y && evento.mouse.y <= historico_y + botao_altura){
                        estado = HISTORICO;
                    }

                    int sair_y = historico_y + botao_altura + 10;
                    if(evento.mouse.x >= botao_x && evento.mouse.x <= botao_x + botao_comprimento && evento.mouse.y >= sair_y && evento.mouse.y <= sair_y + botao_altura){
                        rodando = false;
                    }   
                }

                if(estado == MODO){
                    int quadrado = 100;
                    int gap = 150;
                    int x1 = TAMANHO_TELA_X / 2 - quadrado - gap / 2;
                    int x2 = TAMANHO_TELA_X / 2 + gap / 2;

                    tela_modo(font_titulo, font_corpo);
                    if(evento.mouse.x >= x1 && evento.mouse.x <= x1 + quadrado && evento.mouse.y >= TAMANHO_TELA_Y / 2 - quadrado / 2 && evento.mouse.y <= TAMANHO_TELA_Y / 2 + quadrado / 2){
                        estado = JOGAR;
                        modo = 2;
                    }
                    if(evento.mouse.x >= x2 && evento.mouse.x <= x2 + quadrado && evento.mouse.y >= TAMANHO_TELA_Y / 2 - quadrado / 2 && evento.mouse.y <= TAMANHO_TELA_Y / 2 + quadrado / 2){
                        estado = JOGAR;
                        modo = 1;
                    }
                }

                
                if(estado == JOGAR){

                    clicks++;
                    int mouseX = evento.mouse.x;
                    int mouseY = evento.mouse.y;
                    printf("\n x = %d y = %d", mouseX, mouseY);
                    printf("\nclicks: %d\n", clicks);

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

                    hitbox(matriz_tabuleiro, matriz_coord, mouseX, mouseY, &pode_jogar, tabuleiro, &andar, &vez, &modo);

                    int texto_comprimento = al_get_text_width(font_corpo, text);
                    int texto_altura = al_get_font_line_height(font_corpo);

                    int x = TAMANHO_TELA_X - texto_comprimento - 20;

                    al_draw_filled_rectangle(x, TAMANHO_TELA_Y / 2 - texto_altura / 2 - 10, x + texto_comprimento + 20, TAMANHO_TELA_Y / 2 + texto_altura / 2 + 10, al_map_rgb(0, 255, 255));
                    al_draw_text(font_corpo, al_map_rgb(0, 0, 0), x + 10, TAMANHO_TELA_Y / 2 - texto_altura / 2, ALLEGRO_ALIGN_LEFT, text);

                    if(mouseX >= pause_x && mouseX <= pause_x + pause_comprimento && mouseY >= pause_y && mouseY <= pause_y + pause_altura) {
                        estado = PAUSE;
                    }
                    
                    ganhador = decidir_ganhador(matriz_tabuleiro);
                    if(ganhador == 1){
                        estado = FIM;
                    }
                    else if(ganhador == 2){
                        estado = FIM;
                    }

                }

                if(estado == AJUDA){
                    pagina_ajuda(font_corpo, font_titulo);
                    if(evento.mouse.x >= TAMANHO_TELA_X / 2 - 50 && evento.mouse.x <= TAMANHO_TELA_X / 2 + 50 && evento.mouse.y >= TAMANHO_TELA_Y - 50 && evento.mouse.y <= TAMANHO_TELA_Y){
                        estado = MENU;
                    }
                }

                if(estado == HISTORICO){
                    tela_historico(font_titulo, font_corpo);
                    if(evento.mouse.x >= TAMANHO_TELA_X / 2 - 50 && evento.mouse.x <= TAMANHO_TELA_X / 2 + 50 && evento.mouse.y >= TAMANHO_TELA_Y - 50 && evento.mouse.y <= TAMANHO_TELA_Y){
                        estado = MENU;
                    }
                }
            
                if(estado == FIM){

                    tela_vitoria(ganhador, font_corpo, font_titulo);

                    if(!resultado_escrito){
                        FILE *arquivo = fopen("historico.txt", "a");
                        fprintf(arquivo, "Jogador %d venceu em %02d:%02d no modo %d\n", ganhador, minutos, segundos, modo);
                        fclose(arquivo);
                        resultado_escrito = true;
                    }
                    
                    if(evento.mouse.x >= TAMANHO_TELA_X / 2 - 50 && evento.mouse.x <= TAMANHO_TELA_X / 2 + 50 && evento.mouse.y >= TAMANHO_TELA_Y - 50 && evento.mouse.y <= TAMANHO_TELA_Y){
                        estado = MENU;
                        limpaTela();
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
