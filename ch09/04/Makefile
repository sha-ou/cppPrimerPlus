CC = g++
CFLAGS = -Wall -g3

main: main.o sales.o
	$(CC) $(CFLAGS) $^ -o $@

%o:%cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm main
	@echo "clean done"
