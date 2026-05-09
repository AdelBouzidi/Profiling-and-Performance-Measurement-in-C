CC=gcc
CXX=g++
DEBUG_CFLAGS=-g
CXXFLAGS=-Wall -I./include -std=c++17 $(DEBUG_CFLAGS)
LDFLAGS=

BINDIR=bin
BLDDIR=build
INCDIR=include
LIBDIR=lib
SRCDIR=src
TSTDIR=tests

LIBNAME=prflib
# MAIN TARGET
## all: $(LIBDIR)/$(LIBNAME).a $(BINDIR)/test-001.out $(BINDIR)/test-002.out $(BINDIR)/test-003.out
all: $(LIBDIR)/$(LIBNAME).a $(BINDIR)/test001.exe


####################################################################
####################################################################
# COMPILATION WORK
####################################################################
####################################################################


####################################################################
# LIBRARY BUILD
####################################################################
$(LIBDIR)/$(LIBNAME).a: $(BLDDIR)/cblasl0.o $(BLDDIR)/cblasl1.o $(BLDDIR)/cblasl3.o
	ar -rc $@ $^

$(BLDDIR)/cblasl0.o: $(SRCDIR)/cblasl0.cc $(INCDIR)/cblasl0.hh
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(BLDDIR)/cblasl1.o: $(SRCDIR)/cblasl1.cc $(INCDIR)/cblasl1.hh
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(BLDDIR)/cblasl3.o: $(SRCDIR)/cblasl3.cc $(INCDIR)/cblasl3.hh
	$(CXX) $(CXXFLAGS) $< -c -o $@

####################################################################
# TEST BUILD
####################################################################
# TEST 001
$(BINDIR)/test001.exe: $(BLDDIR)/test001.o $(LIBDIR)/$(LIBNAME).a
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BLDDIR)/test001.o: $(TSTDIR)/test001.cc $(INCDIR)/cblas.hh $(INCDIR)/cblasl0.hh $(INCDIR)/cblasl1.hh
	$(CXX) $(CXXFLAGS) $< -c -o $@


####################################################################
# CLEAN
####################################################################
clean:
	rm -f ./$(BLDDIR)/*.o ./$(LIBDIR)/*.a ./$(BINDIR)/*.exe $(SRCDIR)/*~ $(INCDIR)/*~


####################################################################
####################################################################
# RUNNING WORK
####################################################################
####################################################################

####################################################################
# TEST RUNS
####################################################################
runtests: test001
	@echo "[END of TESTS]..."

test001:
	@echo "[test001-START]"
	./$(BINDIR)/test001.exe 4
	@echo "[test001-END]"
