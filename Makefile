# all:
# 	# g++ -ISDL2/include -LSDL2/lib -o main /main.cpp /card.cpp /graphics.cpp /textGraphics.cpp /vector.cpp -lmingw32 -lSDL2main -lSDL2

CC = g++
INCLUDES = -I../SDL2/include
SDL = -L../SDL2/lib -lmingw32 -lSDL2main -lSDL2

main.exe: main.o card.o graphics.o textGraphics.o vector.o
	${CC} -o main main.o card.o graphics.o textGraphics.o vector.o ${SDL}

main.o: src/main.cpp
	${CC} -c $< ${INCLUDES}

%.o: src/%.cpp src/%.h
	${CC} -c $< ${INCLUDES}

clean:
	del *.o