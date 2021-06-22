run: all
	./quapa.out

all:
	gcc */*.c -o quapa.out

clean:
	rm -rf $(EXECUTABLE)