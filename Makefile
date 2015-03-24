TARGET = DigitalSignatureSystem
LIBS = -lm -lstdc++ -lgcrypt -lgpg-error 
CC = gcc
CFLAGS = -g -Wall -std=c11 -I /usr/local/ssl/include/ 


.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
clean:
		-rm -f *.o
		-rm -f $(TARGET)
