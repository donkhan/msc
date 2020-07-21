lab:	obj/caesar.o  obj/main.o
	gcc -o lab obj/*.o
	
	
obj/caesar.o	: src/caesar.c include/caesar.h
	gcc -Iinclude -c src/caesar.c -o obj/caesar.o

obj/main.o	: src/main.c 
	gcc -Iinclude -c src/main.c -o obj/main.o
	
clean:
	rm obj/*.o
	rm lab
	
	