DEPS= main.o wczytaj.o kalkulator.o

zad6: $(DEPS)
	valgrind gcc $(DEPS) -o $@ -Wall -pedantic -lm

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -f zad6
	rm -f *.o

test: zad6
	./zad6 sum A.txt B.txt
