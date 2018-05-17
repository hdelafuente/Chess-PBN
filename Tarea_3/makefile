final_compile: io chess main
	g++ -o main main.o io.o chess.o
main: main.cpp io.h
	g++ -c -o main.o main.cpp

io: io.cpp io.h
	g++ -c -o io.o io.cpp

chess: chess.cpp chess.h
	g++ -c -o chess.o chess.cpp

clean:
	rm *.o
	rm main
	clear
