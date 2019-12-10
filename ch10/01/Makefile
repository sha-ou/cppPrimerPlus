CC = g++
CFLAGS = -Wall -g3

main: useaccount.o account.o
	$(CC) $(CFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm main
	@echo "clean done"
