surreal: mruby_build
	cd src && make

clean:
	cd src && make clean

mruby_build:
	cd mruby && make

mruby_test:
	cd mruby && make test

run: surreal
	build/surreal