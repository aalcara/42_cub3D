#primeiro contato com minilibx, iniciando testes para abrir uma nova janela

#clang -Wall -Werror -Wextra new_window.c -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm

#rodar new-window
# clang -Wall -Werror -Wextra -fsanitize=address -O3 new_window.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm && ./a.out


#rodar hooks
# clang -Wall -Werror -Wextra -fsanitize=leak -O3 hooks.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm && ./a.out

#rodar print_map
# clang -Wall -Werror -Wextra -fsanitize=address -O3 print_map.c get_next_line.c get_next_line_utils.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm && ./a.out test.cub
# gcc print_map.c get_next_line.c get_next_line_utils.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm && ./a.out test.cub
clang -g -Wall -Werror -Wextra -fsanitize=address print_map.c get_next_line.c get_next_line_utils.c -I. -L./../libraries/minilibx-linux -lmlx -lXext -lX11 -lm
