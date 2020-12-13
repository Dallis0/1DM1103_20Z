all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-backwards:
	./mydb baza.csv list_students_backwards

test-iles: all
	./mydb baza.csv count_students 

test-malejacos: all
	./mydb baza.csv stud_descending

test-rosnacos: all
	./mydb baza.csv stud_ascending 

test-kodprzed: all
	./mydb baza.csv list_ccode

test-kodprzed-backwards: all
	./mydb baza.csv list_ccode_backwards

test-kodprzed-malejaco: all
	./mydb baza.csv ccode_descending

test-kodprzed-rosnaco: all
	./mydb baza.csv ccode_ascending

test-nazprzed-malejaco: all
	./mydb baza.csv cname_descending

test-nazprzed-rosnaco: all
	./mydb baza.csv cname_ascending

test-oceny-studenta: all
	./mydb baza.csv find_stud 305426

test-oceny-przedmiot: all
	./mydb baza.csv find_course 1DC7111

test-dodajs: all
	./mydb baza.csv add_student Stanisław Tyburski 311751 tybusta@gmail.com

test-dodajp: all
	./mydb baza.csv add_course 1DC7111 "Podstawy Programowania" 2020Z

test-memory: all
	valgrind ./mydb baza.csv add_student_to_course 1DE1203 l305426 4 Super

test-ilep: all
	./mydb baza.csv count_courses 

test-ileo: all
	./mydb baza.csv count_grades

test-dodajo: all
	./mydb baza.csv add_student_to_course 1DM1102 305426 4 "Ładnie"

clean:
	rm -f mydb