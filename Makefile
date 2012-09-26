DESTDIR = /usr/local

all: lib/libCWGI.so

lib/libCWGI.so:
	cd src && make

clean:
	-rm -f *~
	-find . -name *~ -exec rm -f {} \;
	cd src && make clean

distclean: clean
	cd src && make distclean
	rm -rf lib/

install: lib/libCWGI.so
	mkdir -p $(DESTDIR)/lib
	cp lib/libCWGI.so* $(DESTDIR)/lib
	mkdir -p $(DESTDIR)/include
	cp -R include/CWGI $(DESTDIR)/include

uninstall:
	rm -Rf $(DESTDIR)/include/CWGI
	rm $(DESTDIR)/lib/libCWGI.so*
