CC = g++
CFLAGS = -Wall -g3

main: useperson.o person.o
	$(CC) $(CFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm main
	@echo "clean done"
