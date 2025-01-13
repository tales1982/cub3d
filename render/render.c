#include "render.h"  // Cabeçalho para funções de renderização
#include "utils.h"   // Para funções como touch e fixed_dist
#include "player.h"  // Para funções como move_player
#include "map.h"     // Para a função draw_map


void put_pixel(int x, int y, int color, t_game *game)
{
    // Verifica se as coordenadas (x, y) estão dentro dos limites da janela
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;

    // Calcula o índice no buffer de imagem
    int index = y * game->size_line + x * game->bpp / 8;

    // Define os valores de cor (B, G, R) no buffer
    game->data[index] = color & 0xFF;           // Azul
    game->data[index + 1] = (color >> 8) & 0xFF; // Verde
    game->data[index + 2] = (color >> 16) & 0xFF; // Vermelho
}


void clear_image(t_game *game)
{
    // Itera sobre todas as linhas da janela
    for(int y = 0; y < HEIGHT; y++)
        // Itera sobre todas as colunas da janela
        for(int x = 0; x < WIDTH; x++)
            // Define cada pixel como preto
            put_pixel(x, y, 0, game);
}


void draw_square(int x, int y, int size, int color, t_game *game)
{
    // Desenha a borda superior
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);

    // Desenha a borda esquerda
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);

    // Desenha a borda inferior
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);

    // Desenha a borda direita
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);
}

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while (!touch(ray_x, ray_y, game))
    {
        ray_x += cos_angle;
        ray_y += sin_angle;
    }

    float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
    float height = (BLOCK / dist) * (WIDTH / 2);
    int wall_start = (HEIGHT - height) / 2;
    int wall_end = wall_start + height;

    // Pintar o teto
    for (int y = 0; y < wall_start; y++)
        put_pixel(i, y, 0x87CEEB, game); // Cor azul clara (código hexadecimal)

    // Pintar a parede
    for (int y = wall_start; y < wall_end; y++)
        put_pixel(i, y, 0xFF0000, game); // Cor branca (pode alterar para outra cor)

    // Pintar o solo
    for (int y = wall_end; y < HEIGHT; y++)
        put_pixel(i, y, 0x228B22, game); // Cor verde (código hexadecimal)
}



int draw_loop(t_game *game)
{
    t_player *player = &game->player;

    // Atualiza a posição do jogador
    move_player(player);

    // Limpa a tela
    clear_image(game);

    // Renderiza elementos no modo DEBUG
    if (DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, game); // Posição do jogador
        draw_map(game); // Desenha o mapa
    }

    // Raycasting: calcula e desenha os raios
    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while (i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }

    // Atualiza a imagem na janela
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

    return 0;
}


/*
 * 
 * Resumo
Função	Objetivo
put_pixel	Desenha um pixel em (x, y) no buffer de imagem.
clear_image	Preenche a tela com preto (limpa a imagem).
draw_square	Desenha um quadrado de tamanho size na posição (x, y).
draw_line	Desenha um raio (linha) e calcula paredes no raycasting.
draw_loop	Loop principal de renderização que desenha todos os elementos.
*/