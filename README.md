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
