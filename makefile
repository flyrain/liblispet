LIBS=-ledit -lm
all:
	ar cr liblispet.a lispet.o mpc.o
lispet.o:
	cc -c -std=c99 lispet.c $(LIBS) 
mpc.o:
	cc -c -std=c99 mpc.c $(LIBS) 
clean:
	rm -f lispet core *.o *.a 
