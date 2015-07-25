SHARED_LIB2 = ../share2

compile_shared_lib:
	g++ -fpic -I$(SHARED_LIB2) -c shared_lib1.cpp -o shared_lib1.o
	g++ -shared shared_lib1.o -o libshared_lib1.so

clean:
	rm -rf *.o *.so

