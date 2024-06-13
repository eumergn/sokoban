CFLAGS += -Wall -Wextra -std=c99
LDFLAGS += -lm -lSDL2 

main: main.o grid.o player.o sdl2.o
	gcc main.o grid.o player.o sdl2.o $(LDFLAGS) -o $@

main.o: main.c grid.h player.h
	gcc main.c $(CFLAGS) -c -g -o $@

grid.o: grid.c grid.h player.h
	gcc grid.c $(CFLAGS) -c -g -o $@

player.o: player.c grid.h player.h
	gcc player.c $(CFLAGS) -c -g -o $@

sdl2.o: sdl2.c sdl2.h grid.h
	gcc sdl2.c $(CFLAGS) -c -g -o $@

clean:
	rm -r *.o main html *.gz

doc:
	doxygen

SDL:
	cd SDL2 && ./configure --prefix=$PWD/../install_dir && make install -j16

archive:
	tar -cf sokoban.tar.gz Doxyfile grid.c grid.h level1.txt main.c makefile player.c player.h sdl2.c sdl2.h README.md 