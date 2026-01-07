CC = cc
CFLAGS = -std=c99 -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs

SRC = main
FILE = add digits2str mod str2digits comp div isdigits mul sub intcal

SUBSRC  = $(FILE:=.c)
SUBOBJS = $(FILE:=.o)

OBJS = $(SRC).o libintcal.a

all: $(SRC)

$(SRC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

libintcal.a: $(SUBOBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c intcal.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.a $(SRC)
