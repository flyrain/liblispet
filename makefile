CC= gcc
LIBS=-ledit -lm
CFLAG=-c -std=c99
SRCS = lispet.c mpc.c functions.c 
OBJS = $(SRCS:.c=.o)

liblispet.a: $(OBJS) 
	ar cr $@ $(OBJS) 

%.o: %.c 
	$(CC) $(CFLAG) -o $@ $< $(LIBS) 

.PHONY: clean

clean:
	rm -f core *.o *.a 
