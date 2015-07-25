SHARED_LIB1_PATH = $(shell pwd)/share1
SHARED_LIB2_PATH = $(shell pwd)/share2

LD_LIBRARY_PATH = $(SHARED_LIB1_PATH):$(SHARED_LIB2_PATH)
export LD_LIBRARY_PATH

all: clean run

run: compile_shared_lib compile_main
	./main

compile_shared_lib:
	$(MAKE) -C $(SHARED_LIB1_PATH) $@
	$(MAKE) -C $(SHARED_LIB2_PATH) $@

compile_main:
	g++ -I$(SHARED_LIB1_PATH) -c main.cpp -o main.o
	g++ main.o -o main -L$(SHARED_LIB1_PATH) -lshared_lib1 -L$(SHARED_LIB2_PATH) -lshared_lib2

clean:
	$(MAKE) -C $(SHARED_LIB1_PATH) $@
	$(MAKE) -C $(SHARED_LIB2_PATH) $@
	rm -rf *.o main lib

.PHONY: run compile_shared_lib compile_main clean all

