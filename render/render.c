#include "render.h" // Cabeçalho para funções de renderização
#include "utils.h"  // Para funções como touch e fixed_dist
#include "player.h" // Para funções como move_player
#include "map.h"    // Para a função draw_map

void put_pixel(int x, int y, int color, t_game *game)
{
    // Verifica se as coordenadas (x, y) estão dentro dos limites da janela
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;

    // Calcula o índice no buffer de imagem onde o pixel será desenhado
    int index = y * game->size_line + x * game->bpp / 8;

    // Define os valores de cor no formato (B, G, R) no buffer
    game->data[index] = color & 0xFF;             // Azul
    game->data[index + 1] = (color >> 8) & 0xFF;  // Verde
    game->data[index + 2] = (color >> 16) & 0xFF; // Vermelho
}

void draw_square(int x, int y, int size, int color, t_game *game)
{
    // Desenha um quadrado preenchendo cada pixel dentro de um tamanho especificado
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            put_pixel(x + i, y + j, color, game);
}

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle = cos(start_x); // Direção do raio (cosseno do ângulo)
    float sin_angle = sin(start_x); // Direção do raio (seno do ângulo)
    float ray_x = player->x;        // Posição inicial do raio (jogador)
    float ray_y = player->y;

    // Lança o raio até encontrar uma parede
    while (!touch(ray_x, ray_y, game))
    {
        ray_x += cos_angle;
        ray_y += sin_angle;
    }

    // Determina a direção da parede atingida
    int direction = touch(ray_x, ray_y, game);
    void *texture = NULL;

    // Seleciona a textura com base na direção da parede
    if (direction == NORTH)
        texture = game->textures.north;
    else if (direction == SOUTH)
        texture = game->textures.south;
    else if (direction == WEST)
        texture = game->textures.west;
    else if (direction == EAST)
        texture = game->textures.east;

    if (!texture)
        return;

    // Calcula a distância corrigida entre o jogador e a parede
    float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
    if (dist < 0.1)
        dist = 0.1; // Evita divisões por valores pequenos

    // Calcula a altura da parede baseada na distância
    float height = (BLOCK / dist) * (HEIGHT / 2);
    int wall_start = (int)((HEIGHT - height) / 2);
    int wall_end = (int)(wall_start + height);

    // Garante que as paredes estejam dentro dos limites da janela
    if (wall_start < 0)
        wall_start = 0;
    if (wall_end >= HEIGHT)
        wall_end = HEIGHT;

    // Mapeia a coordenada da textura para o raio atual
    int texture_width = 64, texture_height = 64;
    int texture_x;

    if (direction == NORTH || direction == SOUTH)
        texture_x = (int)(fmod(ray_x, BLOCK) * texture_width / BLOCK);
    else
        texture_x = (int)((ray_y - floor(ray_y / BLOCK) * BLOCK) * texture_width / BLOCK);

    if (texture_x < 0)
        texture_x = 0;
    if (texture_x >= texture_width)
        texture_x = texture_width - 1;

    // Preenche a linha com a textura correspondente
    for (int y = wall_start; y < wall_end; y++)
    {
        int texture_y = (y - wall_start) * texture_height / (wall_end - wall_start);

        if (wall_end - wall_start == 0)
            wall_end = wall_start + 1;
        if (texture_y < 0)
            texture_y = 0;
        if (texture_y >= texture_height)
            texture_y = texture_height - 1;

        int color = get_texture_color(texture, texture_x, texture_y);
        put_pixel(i, y, color, game);
    }

    // Preenche o teto com a cor do teto
    if (wall_start > 0)
    {
        for (int y = 0; y < wall_start; y++)
            put_pixel(i, y, game->ceiling_color, game);
    }

    // Preenche o chão com a cor do chão
    if (wall_end < HEIGHT)
    {
        for (int y = wall_end; y < HEIGHT; y++)
            put_pixel(i, y, game->floor_color, game);
    }
}

int draw_loop(t_game *game)
{
    t_player *player = &game->player;

    if (player->key_esc)
        exit_program(game); // Fecha o jogo ao pressionar ESC

    // Atualiza a posição do jogador
    move_player(player, game);

    // Limpa a tela
    clear_image(game);

    // Raycasting: calcula e desenha os raios
    float fraction = (PI / 3) / WIDTH;      // Divisão do campo de visão
    float start_x = player->angle - PI / 6; // Ângulo inicial
    int i = 0;
    while (i < WIDTH)
    {
        draw_line(player, game, start_x, i); // Renderiza o raio
        start_x += fraction;                 // Incrementa o ângulo para o próximo raio
        i++;
    }

    // Atualiza a imagem na janela
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

    return 0;
}

int get_texture_color(void *img, int x, int y)
{
    int bpp, size_line, endian;
    char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    if (!data)
    {
        fprintf(stderr, "Error: Invalid texture data\n");
        exit(EXIT_FAILURE);
    }

    int index = (y * size_line) + (x * (bpp / 8));
    return *(int *)(data + index);
}

void clear_image(t_game *game)
{
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0, game); // Define a cor preta
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