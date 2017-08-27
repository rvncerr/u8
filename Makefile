all:
	gcc -c -o u8.o u8.c
	ar rcs libu8.a u8.o

clean:
	rm *.a
	rm *.o
