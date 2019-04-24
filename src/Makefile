CFLAGS 		 = -I../mruby/include -I.
EXTRA_LIBS = ../mruby/build/host/lib/libmruby.a
TARGETS 	 = $(patsubst %.c,%.o,$(wildcard *.c))

all: $(TARGETS)
	mkdir -p ../build
	$(CC) $(CFLAGS) $(TARGETS) $(EXTRA_LIBS) -o ../build/surreal