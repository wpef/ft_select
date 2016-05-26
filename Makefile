all :
	gcc -lcurses -Wall -Werror -Wextra src/*.c -Iinc/ -Llibft -lft 

test : all
	./a.out
