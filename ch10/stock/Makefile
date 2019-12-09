CC = g++
CFLAGS = -Wall -g3

main: usestock.o stock.o
	$(CC) $(CFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm main
	@echo "clean done"

