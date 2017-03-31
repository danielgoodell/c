P=$(target)
OBJECTS=
SRCS = $(wildcard *.c)
CFLAGS= -g -Wall -std=c11 -O1 -pedantic
LDLIBS=
#CC=c11

$(P): $(OBJECTS)

all: $(SRCS:.c=)

.c:
	-gcc $(CFLAGS) $< -o $@

clean:
	find . -type f -executable -delete
