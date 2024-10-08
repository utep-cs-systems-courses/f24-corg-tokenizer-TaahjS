CFLAGS=-g

all: tokenizemain

tokenizemain.o: tokenizer.h
tokenizer.o: tokenizer.h
history.o: tokenizer.h

tokenizemain: tokenizemain.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizemain

run:tokenizemain
	./tokenizemain
