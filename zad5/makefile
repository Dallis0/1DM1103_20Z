DEPS=main.o dziekanat.o studenci.o

zad5: $(DEPS)
	gcc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -f zad5
	rm -f *.o

test: zad5
	./zad5 1 2 3
