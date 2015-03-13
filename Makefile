.SUFFIXES:.c.o

CC = gcc

INC =
LIBS =
CFLAGS = -g -D_DEBUG $(INC) -fPIC
#CFLAGS = -g -D_DEBUG $(INC) -O0 -g3 -Wall -c -fmessage-length=0
#CFLAGS = $(INC) -O3 -Wall -c -fmessage-length=0

OBJS = bkdebug.o
SRCS = bkdebug.c
HEADERS = bkdebug.h

TARGET = libbk.so.1
#TARGET = libbk.a

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -shared -Wl,-soname,$@ -o $@ $(OBJS)
	cp $@ ~/lib
	cp $(HEADERS) ~/include
#	$(AR) rcv $@ $(OBJS)
#	ranlib $@

dep :
	gccmakedep $(INC) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET) core

new :
	$(MAKE) clean
	$(Make)
