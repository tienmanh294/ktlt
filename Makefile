objects = main.o Project.o Task.o Issue.o User.o Utils.o

all: $(objects)
	g++ -o main $(objects)
main.o: src/main.cpp include/main.h include/Utils.h
	g++ -c src/main.cpp
Project.o: src/Project.cpp include/Project.h 
	g++ -c src/Project.cpp
Task.o: src/Task.cpp include/Task.h 
	g++ -c src/Task.cpp
Issue.o: src/Issue.cpp include/Issue.h 
	g++ -c src/Issue.cpp
User.o: src/User.cpp include/User.h
	g++ -c src/User.cpp
Utils.o: src/Utils.cpp include/Utils.h
	g++ -c src/Utils.cpp
.PHONY : clean
clean:
	rm -f *.o
