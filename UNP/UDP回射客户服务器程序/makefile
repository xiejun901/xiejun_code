all:udpcli udpserv
udpcli:udpcli.o my_unp.o
	gcc -o udpcli my_unp.o udpcli.o
udpserv:udpserv.o my_unp.o
	gcc -o udpserv my_unp.o udpserv.o
udpcli.o:udpcli.c my_unp.h
	gcc -c udpcli.c
my_unp.o:my_unp.c my_unp.h
	gcc -c my_unp.c
udpserv.o:udpserv.c my_unp.h
	gcc -c udpserv.c
clean:
	rm *.o udpserv udpcli
