demo:	obj/demo.o obj/lib.o obj/udp.o obj/ip.o  obj/tcp.o  obj/eth.o obj/eth_header.o obj/udp_header.o obj/ip_header.o obj/tcp_header.o obj/validity.o obj/convert.o
	gcc -o demo obj/*.o
	
obj/validity.o	: src/validity.c include/validity.h
	gcc -Iinclude  -c src/validity.c -o obj/validity.o

obj/convert.o	: src/convert.c include/convert.h
	gcc -Iinclude  -c src/convert.c -o obj/convert.o

obj/lib.o	: src/lib.c include/lib.h
	gcc -Iinclude  -c src/lib.c -o obj/lib.o
	
obj/udp.o	: src/udp.c include/udp.h 
	gcc -Iinclude	-c src/udp.c  -o obj/udp.o

obj/udp_header.o	: src/udp_header.c  include/udp_header.h
	gcc -Iinclude	-c  src/udp_header.c -o obj/udp_header.o

obj/tcp.o	: src/tcp.c include/tcp.h 
	gcc -Iinclude	-c src/tcp.c -o obj/tcp.o

obj/tcp_header.o	: src/tcp.c include/tcp.h 
	gcc -Iinclude	-c src/tcp_header.c  -o obj/tcp_header.o

obj/eth.o	: src/eth.c include/eth_header.h include/eth.h
	gcc -Iinclude	-c  src/eth.c -o obj/eth.o

obj/eth_header.o	: src/eth.c include/eth_header.h
	gcc -Iinclude	-c src/eth_header.c  -o obj/eth_header.o

obj/ip.o	: src/ip.c include/ip.h
	gcc -Iinclude	-c src/ip.c -o obj/ip.o

obj/ip_header.o	: src/ip.c include/ip_header.h 
	gcc -Iinclude	-c src/ip_header.c -o obj/ip_header.o

obj/demo.o	: src/demo.c
	gcc -Iinclude -c src/demo.c -o obj/demo.o

clean:
	rm obj/*.o
	
	