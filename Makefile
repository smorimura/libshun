CC = cc
CFLAGS = -Wextra -Wall -O2
AR = ar
ARFLAGS = rcs
INSTALL = cp -i
RM = rm -f

LIB_DIR = $(HOME)/lib
INC_DIR = $(HOME)/include

HEADER_NAME = libshun.h
LIB_NAME    = libshun.a



#
# add object filenames when adding new functions to this library
#
OBJS = getparam.o isfile.o isprefix.o errexit.o cutnline.o getlabel.o exp_tab.o getcpath.o strcpy.o

.PHONY : all install clean

.c.o:
	$(CC) $(CFLAGS) -c $<

all : $(LIB_NAME)

$(LIB_NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_NAME) $(OBJS)

install :
	$(INSTALL) $(LIB_NAME)    $(LIB_DIR)
	$(INSTALL) $(HEADER_NAME) $(INC_DIR)

clean :
	$(RM) $(LIB_NAME) *.o *~ *.bak

#
# add dependency relations of object files when adding new functions to this library
#
isprefix.o :	libshun.h
isfile.o :		libshun.h
getparam.o :	libshun.h
errexit.o :
cutnline.o :
getlabel.o :	libshun.h
exp_tab.o :
getcpath.o :
strcpy.o :

