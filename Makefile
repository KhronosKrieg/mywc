CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2
TARGET = mywc
SRC = mywc.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

