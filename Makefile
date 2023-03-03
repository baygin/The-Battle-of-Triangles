output = TheBattleOfTriangles

c_sources = $(wildcard src/*.c) $(wildcard src/*/*.c)
cp_sources = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
objects = $(c_sources:.c=.o) $(cp_sources:.cpp=.o) 
objects := $(addsuffix .o,$(basename $(objects)))

flags = -g -Wl,--copy-dt-needed-entries -I include -L lib -Wall -lSDL2main -lSDL2 -lSDL2_image -lGL -lSDL2_mixer -loyamo -ljson-c -luuid

$(output): $(objects)
	g++ $(objects) $(flags) -o ./bin/$(output)
%.o: %.c src/include/*/%.h
	g++ -c $(Flags) $< -o $@
clean:
	-rm -rf ./bin/*
	-rm -rf ./build/*
	-rm -rf src/*.o
	-rm -rf src/*/*.o
run:
	./bin/$(output)