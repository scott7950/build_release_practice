SHARED_LIB_PATH = $(shell pwd)/share
LD_LIBRARY_PATH = $(SHARED_LIB_PATH)

all: clean run

run: compile_shared_lib compile_main
	./main

compile_shared_lib:
	$(MAKE) -C $(SHARED_LIB_PATH) $@

compile_main:
	g++ -I$(SHARED_LIB_PATH) -c main.cpp -o main.o
	g++ -L$(SHARED_LIB_PATH) -lshared_lib main.o -o main

clean:
	rm -rf $(SHARED_LIB_PATH)/*.o $(SHARED_LIB_PATH)/*.so *.o main

.PHONY: run compile_shared_lib compile_main clean all

