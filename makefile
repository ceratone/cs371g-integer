# http://stackoverflow.com/questions/31176997/what-does-clang-check-do-without-analyze-option

FILES :=                              \
    Integer.h                         \
    Integer.log                       \
    html                              \
    RunInteger.c++                    \
    RunInteger.out                    \
    TestInteger.c++                   \
    TestInteger.out

# uncomment these:
#    integer-tests/EID-RunInteger.out  \
#    integer-tests/EID-TestInteger.c++ \
#    integer-tests/EID-TestInteger.out \
CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

ifeq ($(CC), clang)
    CLANG-CHECK  := clang-check
    CXX          := clang++
else
    CXX          := g++-4.8
    GCOV         := gcov-4.8
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    GPROF        := gprof
    GPROFFLAGS   := -pg
endif

ifeq ($(CI), true)
    CLANG-FORMAT := clang-format
else
    CLANG-FORMAT := clang-format-3.4
endif

integer-tests:
	git clone https://github.com/cs371g-summer-2016/integer-tests.git

html: Doxyfile Integer.h RunInteger.c++ TestInteger.c++
	doxygen Doxyfile

Integer.log:
	git log > Integer.log

Doxyfile:
	doxygen -g
	# you must manually edit Doxyfile and
	# set EXTRACT_ALL     to YES
	# set EXTRACT_PRIVATE to YES
	# set EXTRACT_STATEIC to YES

RunInteger: Integer.h RunInteger.c++
ifeq ($(CC), clang)
	$(CXX) $(CXXFLAGS) RunInteger.c++ -o RunInteger
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunInteger.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunInteger.c++  --
else
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS) RunInteger.c++ -o RunInteger
endif

RunInteger.tmp: RunInteger
	./RunInteger > RunInteger.tmp
	diff RunInteger.tmp RunInteger.out
ifeq ($(CC), gcc)
	$(GPROF) ./RunInteger >> RunInteger.tmp
endif
	cat RunInteger.tmp

TestInteger: Integer.h TestInteger.c++
ifeq ($(CC), clang)
	$(CXX) $(CXXFLAGS) TestInteger.c++ -o TestInteger $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestInteger.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestInteger.c++ --
else
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TestInteger.c++ -o TestInteger $(LDFLAGS)
endif

TestInteger.tmp: TestInteger
	$(VALGRIND) ./TestInteger                                       >  TestInteger.tmp 2>&1
ifeq ($(CC), gcc)
	$(GCOV) -b TestInteger.c++ | grep -A 5 "File 'TestInteger.c++'" >> TestInteger.tmp
endif
	cat TestInteger.tmp

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  Integer.log
	rm -f  Doxyfile
	rm -f  gmon.out
	rm -f  RunInteger
	rm -f  RunInteger.tmp
	rm -f  TestInteger
	rm -f  TestInteger.tmp
	rm -rf integer-tests
	rm -rf html
	rm -rf latex

config:
	git config -l

format:
	$(CLANG-FORMAT) -i Integer.h
	$(CLANG-FORMAT) -i RunInteger.c++
	$(CLANG-FORMAT) -i TestInteger.c++

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: html Integer.log RunInteger.tmp TestInteger.tmp integer-tests check
