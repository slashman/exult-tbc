AM_CPPFLAGS = -I$(srcdir)/../../headers -I$(srcdir)/.. -I$(srcdir)/../../files -I$(srcdir)/../.. \
	$(INCDIRS) $(DEBUG_FLAGS) $(CPPFLAGS)

AM_YFLAGS = -d -v				# Want ucparse.h.

ucc_SOURCES = ucparse.yy uclex.ll ucmain.cc \
	opcodes.h	\
	ucclass.cc	\
	ucclass.h	\
	ucexpr.cc	\
	ucexpr.h	\
	ucfun.cc	\
	ucfun.h		\
	uclabel.h	\
	ucloc.cc	\
	ucloc.h		\
	ucparse.h	\
	ucstmt.cc	\
	ucstmt.h	\
	ucsym.cc	\
	ucsym.h

if BUILD_COMPILER
bin_PROGRAMS = ucc
endif

ucc_LDADD = 			\
	../libusecode.la	\
	$(SYSLIBS)

ucparse.h: ucparse.cc
	test -e ucparse.hh && cp ucparse.hh ucparse.h

uclex.o: uclex.cc ucparse.h


CLEANFILES = *~
MAINTAINERCLEANFILES = uclex.cc ucparse.cc ucparse.h
