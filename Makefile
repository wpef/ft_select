all :
	gcc -lcurses -Wall -Werror -Wextra src/*.c -Iinc/ -Llibft -lft 

valgrind :
	gcc -g -lcurses -Wall -Werror -Wextra src/*.c -Iinc/ -Llibft -lft 

test : all
	mkdir pute
	touch pute/aa
	touch pute/ba
	touch pute/ca
	touch pute/ea
	touch pute/fa
	touch pute/ga
	touch pute/ha
	touch pute/ia
	touch pute/ka
	touch pute/aa
	touch pute/baa
	touch pute/caa
	touch pute/eaa
	touch pute/faa
	rm `./a.out pute/*`
