tcpcli-pthread:tcpcli-pthread.o my_unp.o
	gcc -o tcpcli-pthread my_unp.o tcpcli-pthread.o -lpthread
tcpcli-pthread.o:tcpcli-pthread.c my_unp.h
	gcc -c tcpcli-pthread.c
clean:
	rm *.o
