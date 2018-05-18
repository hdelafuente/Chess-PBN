final_compile: io chess player main
	g++ -o main main.o io.o chess.o player.o -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
main: main.cpp io.h
	g++ -c -o main.o main.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

io: io.cpp io.h
	g++ -c -o io.o io.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

chess: chess.cpp chess.h
	g++ -c -o chess.o chess.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
	
player: player.cpp player.h
	g++ -c -o player.o player.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

clean:
	rm *.o
	rm main
	clear
