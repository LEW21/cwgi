LIBRARY_NAME  = CWGI
VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_PATCH = 0

TARGET        = ../lib/lib$(LIBRARY_NAME).so.$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)
TARGET0       = ../lib/lib$(LIBRARY_NAME).so
TARGET1       = ../lib/lib$(LIBRARY_NAME).so.$(VERSION_MAJOR)
TARGET2       = ../lib/lib$(LIBRARY_NAME).so.$(VERSION_MAJOR).$(VERSION_MINOR)

####### Compiler, tools and options

CXX           = g++
DEFINES       =
CFLAGS        = -pipe -O2 -fno-strict-aliasing -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -fno-strict-aliasing -Wall -W -D_REENTRANT -fPIC $(DEFINES) -std=gnu++0x
INCPATH       = -I/usr/include -I../include -I../ATL/include
LINK          = g++
LFLAGS        = -m64 -Wl,--hash-style=gnu -Wl,--as-needed -Wl,-O1 -shared -Wl,-soname,lib$(LIBRARY_NAME).so.$(VERSION_MAJOR)
STRIP         = strip

####### Build rules

all: $(TARGET)

cwgi.o: ../include/CWGI/cwgi.h cwgi.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cwgi.o cwgi.cpp

$(TARGET): cwgi.o
	-mkdir -p ../lib
	-rm -f $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) cwgi.o
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	$(STRIP) $(TARGET)

clean:
	-rm -f *.o *~

distclean: clean
	-rm -f $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
