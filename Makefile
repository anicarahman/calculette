

CC=gcc
CFLAGS=-I. -Wall -O2 -Werror
LDFLAGS=
SRC=pile_r.c infix2postfix.c ratio.c
OBJ=$(SRC:.c=.o)
EXE=miniCalculatrice

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c pile_r.h ratio.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXE) *~
