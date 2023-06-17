exec = ./KeyboardHandler.testout
flags = -o $(exec) -g -Wl,--copy-dt-needed-entries -I include -L lib -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lGL
objects = ../../../src/Game/Event/KeyboardHandler.o ../../../src/Game/Event/Keyboard.o

test: 
	g++ KeyboardHandler.cpp $(objects) $(flags)
run:
	$(exec)
clean:
	-rm -rf $(exec)
