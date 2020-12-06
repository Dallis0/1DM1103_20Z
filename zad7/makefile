all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-iles: all
	./mydb baza.csv count_students 

test-valgrind: all
	valgrind ./mydb baza.csv add_student_to_course 1DE1203 211818 4 Wooooooow

test-dodajp: all
	./mydb baza.csv add_course 1DM1103 Matematyka 2020Z
	
test-przypisz: all
	./mydb baza.csv add_student_to_course 1DE1203 211818 4 Wooooooow

clean:
	rm -f mydb