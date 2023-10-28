all:
	g++ -ISDL2/include -LSDL2/lib -O3 -o main src/main.cpp src/card.cpp -lmingw32 -lSDL2main -lSDL2