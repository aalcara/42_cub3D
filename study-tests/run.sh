#primeiro contato com minilibx, iniciando testes para abrir uma nova janela

#clang -Wall -Werror -Wextra new_window.c -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm
clang -Wall -Werror -Wextra -fsanitize=address -O3 new_window.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm && ./a.out
