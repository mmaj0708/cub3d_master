clang -g3 -fsanitize=address -I /usr/local/include -g -L /usr/local/lib *.c -lX11 -lXext -lm -lmlx ; ./a.out map.cub
