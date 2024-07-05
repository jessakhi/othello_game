#Alias des instructions et répertoires
SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR=$(SRCDIR)/tests
TESTBINDIR=tests
INCLUDEDIR=include
DOCDIR = doc
CC = gcc
AR = ar -rcs
DOXY = doxygen Doxyfile
CFLAGS=-Wall -pedantic -g -std=gnu99 -I$(INCLUDEDIR)
LDFLAGS=-Llib -ljeu -lia -lunite -ljeu  -ltad -g
# l'éxécutable pour l'instant est le test
EXEC = othello

#Ensembles de fichiers
# les TAD
TADS = $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/TAD_*.c))
# les JEU
JEU = $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/JEU_*.c))
# les IA
IA = $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/IA_*.c))
#les UNIT
UNITES = $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/UNIT_*.c))


all :  prg tests doc

prg : $(SRCDIR)/OTHELLO.o $(LIBDIR)/libtad.a $(LIBDIR)/libjeu.a $(LIBDIR)/libia.a $(LIBDIR)/libunite.a
	$(CC)  -o $(BINDIR)/$(EXEC) $< $(LDFLAGS)

doc: $(DOCDIR)/html/index.html $(DOCDIR)/rapport/rapport.pdf

rpt : $(DOCDIR)/rapport/rapport.pdf


tests: $(TESTBINDIR)/test_TAD $(TESTBINDIR)/test_JEU 
	
	
$(DOCDIR)/html/index.html :
	$(DOXY)
	
$(DOCDIR)/rapport/rapport.pdf : 
	cd $(DOCDIR)/rapport/;pdflatex main.tex; cd ../..	

$(TESTBINDIR)/% : $(TESTDIR)/%.o $(LIBDIR)/libtad.a $(LIBDIR)/libjeu.a $(LIBDIR)/libunite.a $(LIBDIR)/libia.a
	$(CC) -o $@ $< $(LDFLAGS) -lcunit


$(LIBDIR)/libtad.a : $(TADS)
	$(AR) $(LIBDIR)/libtad.a $^
	
$(LIBDIR)/libunite.a : $(UNITES)
	$(AR) $(LIBDIR)/libunite.a $^
	
$(LIBDIR)/libjeu.a : $(JEU)
	$(AR) $(LIBDIR)/libjeu.a $^
	
$(LIBDIR)/libia.a : $(IA)
	$(AR) $(LIBDIR)/libia.a $^


$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/*.o
	rm -rf $(SRCTESTDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -rf $(DOCDIR)/html
	rm -rf $(DOCDIR)/rapport/*.pdf
	rm -rf $(DOCDIR)/latex/*.pdf
	
	
	

