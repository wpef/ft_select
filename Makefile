all :
	gcc -lcurses -Wall -Werror -Wextra src/*.c -Iinc/ -Llibft -lft 

valgrind :
	gcc -g -lcurses -Wall -Werror -Wextra src/*.c -Iinc/ -Llibft -lft 

test : all
	./a.out
