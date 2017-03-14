P=$(target)
OBJECTS=
SRCS = $(wildcard *.c)
CFLAGS= -g -Wall -O2 -std=c11 -pedantic
LDLIBS=
#CC=c11

$(P): $(OBJECTS)

all: $(SRCS:.c=)

.c:
	-gcc $(CFLAGS) $< -o $@

clean:
	find . -type f -executable -delete
