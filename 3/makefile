P=$(target)
OBJECTS=
SRCS = $(wildcard *.c)
CFLAGS= -g -lm -Wall -std=c11 -O1 -pedantic
LDLIBS= -lm
#CC=c11

$(P): $(OBJECTS)

all: $(SRCS:.c=)

.c:
	-gcc $< -o $@ $(CFLAGS)

clean:
	find . -type f -executable -delete
