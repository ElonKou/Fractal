CC = g++
program = main
deps = $(shell find ./ -name "*.h")
obj = Matrix.o Point.o Fractal.o window.o main.o lib.o

${program} : ${obj} 
	${CC} -o ${program} ${obj} -l GL -l GLU -l glut
	rm -rf ${obj}
	@echo "Compilation completed."
	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"

main.o :
	${CC} -c main.cpp -std=c++11 

Matrix.o :
	${CC} -c Matrix.cpp -std=c++11

Point.o :
	${CC} -c Point.cpp -std=c++11

Fractal.o :
	${CC} -c Fractal.cpp -std=c++11

window.o :
	${CC} -c window.cpp -std=c++11

lib.o :
	${CC} -c lib.cpp -std=c++11

.PHONY:clean
clean :
	rm -rf ${obj} ${program}