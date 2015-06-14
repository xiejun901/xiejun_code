serv03:serv03.o my_unp.o
	gcc -o serv03 my_unp.o serv03.o
my_unp.o:my_unp.c my_unp.h
	gcc -c my_unp.c
serv03.o:serv03.c my_unp.h
	gcc -c serv03.c
clean:
	rm *.o serv03
