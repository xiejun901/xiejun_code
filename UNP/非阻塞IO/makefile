tcpcli_nonblock:tcpcli_nonblock.o my_unp.o
	gcc -o tcpcli_nonblock my_unp.o tcpcli_nonblock.o
tcpcli_nonblock.o:tcpcli_nonblock.c my_unp.h
	gcc -c tcpcli_nonblock.c
my_unp.o:my_unp.c my_unp.h
	gcc -c my_unp.c
clean:
	rm *.o tcpcli_nonblock
