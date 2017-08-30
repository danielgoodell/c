P=$(target)
OBJECTS=
SRCS = $(wildcard *.c)
LDLIBS= -lm -lncurses
CFLAGS= -g -Wall -std=c11 -O1 -pedantic $(LDLIBS)
#CC=c11

$(P): $(OBJECTS)

all: $(SRCS:.c=)

.c:
	-gcc $< -o $@ $(CFLAGS)

clean:
	find . -type f -executable -delete
