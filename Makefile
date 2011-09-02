DESTDIR = /usr/local

all: lib/libCWGI.so

ATL:
	git clone git://gitorious.org/atl/atl.git ATL

lib/libCWGI.so: ATL
	cd src && make

clean:
	-rm -f *~
	-find . -name *~ -exec rm -f {} \;
	-rm -Rf ATL
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
