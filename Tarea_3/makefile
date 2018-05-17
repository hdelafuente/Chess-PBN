final_compile: io chess main
	g++ -o main main.o io.o chess.o -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
main: main.cpp io.h
	g++ -c -o main.o main.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

io: io.cpp io.h
	g++ -c -o io.o io.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

chess: chess.cpp chess.h
	g++ -c -o chess.o chess.cpp -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

clean:
	rm *.o
	rm main
	clear
