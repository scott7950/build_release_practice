STATIC_LIB_PATH1_PATH = $(shell pwd)/static1
STATIC_LIB_PATH2_PATH = $(shell pwd)/static2

LIB_PATH = $(shell pwd)/lib

all: clean run

run: compile_static_lib compile_main
	./main

compile_static_lib:
	$(MAKE) -C $(STATIC_LIB_PATH1_PATH) STATIC_LIB_PATH2_PATH=$(STATIC_LIB_PATH2_PATH) $@
	$(MAKE) -C $(STATIC_LIB_PATH2_PATH) $@
	-mkdir $(LIB_PATH)
	ar -crvf $(LIB_PATH)/libstatic.a $(STATIC_LIB_PATH1_PATH)/static_lib1.o $(STATIC_LIB_PATH2_PATH)/static_lib2.o

compile_main:
	g++ -I$(STATIC_LIB_PATH1_PATH) -c main.cpp -o main.o
	g++  main.o -o main -L$(LIB_PATH) -lstatic
	#g++ main.o -o main $(LIB_PATH)/libstatic.a

clean:
	$(MAKE) -C $(STATIC_LIB_PATH1_PATH) clean
	$(MAKE) -C $(STATIC_LIB_PATH2_PATH) clean
	rm -rf *.o main lib

.PHONY: run compile_shared_lib compile_main clean all

