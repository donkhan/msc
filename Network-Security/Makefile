caesar:	obj/caesar.o 
	gcc -o caesar obj/caesar.o
	
obj/caesar.o	: Caesar.c
	gcc -Iinclude -c Caesar.c -o obj/caesar.o
	
clean:
	rm obj/*.o
	
	