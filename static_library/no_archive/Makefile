STATIC_LIB1 = $(shell pwd)/static1
STATIC_LIB2 = $(shell pwd)/static2

all: clean run

run: compile_static_lib compile_main
	./main

compile_static_lib:
	$(MAKE) -C $(STATIC_LIB1) STATIC_LIB2=$(STATIC_LIB2) $@
	$(MAKE) -C $(STATIC_LIB2) $@

compile_main:
	g++ -I$(STATIC_LIB1) -I$(STATIC_LIB2) -c main.cpp -o main.o
	g++ $(STATIC_LIB1)/static_lib1.o $(STATIC_LIB2)/static_lib2.o main.o -o main

clean:
	$(MAKE) -C $(STATIC_LIB1) clean
	$(MAKE) -C $(STATIC_LIB2) clean
	rm -rf *.o main

.PHONY: run compile_shared_lib compile_main clean all

