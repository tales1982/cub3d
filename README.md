# cub3d
Repositorio destinado ao curso 42 luxembourg


## Make File
Melhorias no Makefile:
Suporte ao Valgrind:

Adicionei uma regra chamada valgrind para rodar o executável com Valgrind, verificando vazamentos de memória.
Separação de Objetos em Diretórios:

Arquivos objeto são compilados no diretório obj/, organizado por subdiretórios.
Mensagens Coloridas:

Adicionei mensagens coloridas para tornar a saída mais legível.
Melhor Modularidade:

Uso do wildcard para capturar todos os arquivos .c recursivamente no diretório src.
Flags de Debugging:

Adicionei a flag -g ao CFLAGS para facilitar a depuração com ferramentas como o GDB.
Memcheck:

Adicionei a regra memcheck para recompilar o projeto e rodar o Valgrind.
Criar Diretórios Automaticamente:

O diretório obj/ é criado dinamicamente para armazenar os objetos.
Inclusão de Cabeçalhos:

Usei a flag -I para garantir que o compilador encontre os arquivos no diretório include.


## Como Usar
Compilar o projeto:

bash
Copiar código
make
Limpar arquivos objeto:

bash
Copiar código
make clean
Limpar tudo (objetos e binários):

bash
Copiar código
make fclean
Recompilar tudo:

bash
Copiar código
make re
Testar com Valgrind:

bash
Copiar código
make valgrind
Recompilar e testar memória:

bash
Copiar código
make memcheck

## 1. Entenda o Projeto

Os parâmetros do mapa (ex.: paredes 1, espaços vazios 0, pontos de spawn do jogador N, S, E, W).
O funcionamento do raycasting para renderizar paredes em 3D.
As bibliotecas permitidas, especialmente a MiniLibX.
2. Planejamento
Divida o projeto em partes:
Leitura e validação do mapa
Carregar o arquivo .cub.
Verificar erros no formato do mapa (ex.: paredes fechadas, caracteres inválidos).
Renderização do mapa 2D
Renderizar um minimapa simples.
Movimentação do jogador
Implementar os controles básicos (andar para frente/trás, virar a câmera).
Raycasting para renderização 3D
Implementar o cálculo de interseções de raios com paredes.
Renderizar as "paredes" baseadas na distância.
Adições e ajustes
Implementar texturas nas paredes, portas, sprites (se necessário).
Melhorar performance e corrigir bugs.
3. Por Onde Começar
(1) Leitura e validação do mapa
Função: parse_map()

Leia o arquivo .cub.
Valide o formato do mapa (ex.: bordas fechadas, símbolos válidos, ponto de spawn único).
Estude:

Como manipular arquivos em C (open, read, close).
Estruturas de dados para armazenar o mapa (ex.: matrizes de caracteres).
Algoritmos de validação de mapas (ex.: flood-fill para verificar paredes fechadas).
(2) Renderização do minimapa
Função: render_minimap()

Renderize um grid 2D simples para representar o mapa.
Use funções básicas da MiniLibX (mlx_pixel_put ou mlx_image).
Estude:

Como desenhar na tela com a MiniLibX.
Representação de mapas em 2D.
(3) Movimentação do jogador
Função: move_player()

Atualize a posição do jogador com base na entrada do teclado.
Verifique colisões com paredes no minimapa.
Estude:

Detecção de teclas na MiniLibX.
Estruturas de controle (ex.: structs para posição do jogador).
(4) Raycasting básico
Função: raycast()

Calcule as interseções de raios lançados do ponto de vista do jogador.
Renderize linhas verticais para simular "paredes".
Estude:

Matemática de vetores (senos, cossenos, tangentes).
Como projetar uma cena 3D a partir de um mapa 2D.
4. Cronograma Sugerido
Semana 1: Base do Projeto
Leia o mapa e implemente validações básicas.
Renderize o mapa em 2D como minimapa.
Garanta que o jogador possa se movimentar no minimapa.
Semana 2: Renderização 3D
Implemente o raycasting básico.
Renderize paredes sem texturas.
Semana 3: Adições e Melhorias
Adicione texturas.
Ajuste a movimentação do jogador.
Teste e corrija bugs.
5. Ferramentas e Recursos
Debugging: Use gdb ou printf para identificar problemas.
Referências Matemáticas: Relembre funções trigonométricas para cálculos de ângulos.
MiniLibX: Estude bem a documentação e os exemplos básicos.
