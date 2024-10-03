CFLAGS=-g

all: tokenizemain

tokenizemain.o: tokenizer.h
tokenizer.o: tokenizer.h

tokenizemain: tokenizemain.o tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizemain

run:tokenizemain
	./tokenizemain
