LD_LIBRARY_PATH = ./share

all: clean run

run: compile_shared_lib compile_main
	./main

compile_shared_lib:
	$(MAKE) -C share $@

compile_main:
	g++ -Ishare -c main.cpp -o main.o
	g++ -Lshare -lshared_lib main.o -o main

clean:
	rm -rf share/*.o share/*.so *.o main

.PHONY: run compile_shared_lib compile_main clean all

