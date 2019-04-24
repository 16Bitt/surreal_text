CFLAGS 		 =  -Werror -Wall -I../mruby/include $(shell pkg-config gtk+-3.0 --cflags --static)
STATIC_LIB = ../mruby/build/host/lib/libmruby.a
TARGETS 	 = $(patsubst %.c,%.o,$(wildcard *.c))

all: $(TARGETS)
	mkdir -p ../build
	$(CC) $(CFLAGS) $(TARGETS) $(STATIC_LIB) -o ../build/surreal $(shell pkg-config gtk+-3.0 --libs --static)

clean:
	- rm $(TARGETS)