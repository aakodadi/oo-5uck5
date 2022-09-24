.PHONY: all clean run run-c run-cpp benchmark benchmark-c benchmark-cpp

all: cpp c

cpp: main.cpp
	$(CXX) main.cpp -o cpp

c: main.c
	$(CC) main.c -o c

clean:
	$(RM) cpp c

run: run-c run-cpp

run-c: c
	./c

run-cpp: cpp
	./cpp

benchmark: benchmark-c benchmark-cpp

benchmark-c: c
	time -p ./benchmark ./c

benchmark-cpp: cpp
	time -p ./benchmark ./cpp

