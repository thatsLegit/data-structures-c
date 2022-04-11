CC=gcc

# general set of flags
FLAGS=-g -Wall
# flags attached only with the compilation of objects files
OBJ_FLAGS=${FLAGS}
# Flags for tests only
TEST_FLAGS = --fail-fast --full-stats --verbose

SRCDIR=src
SRCS=$(wildcard ${SRCDIR}/*.c)

OBJDIR=obj
OBJS=$(patsubst ${SRCDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})
# literally take everything that is in the 3rd param, and replace every
# element that looks like the 1st with the 2nd param's pattern
# This way, every source file produces an object file

TESTDIR=tests
TESTS=$(wildcard ${TESTDIR}/*.test.c)
TESTBINS=$(patsubst ${TESTDIR}/%.test.c, ${TESTDIR}/bin/%, ${TESTS})

BINDIR=bin
SO_LIB=${BINDIR}/libdynarray.dylib
STATIC_LIB=${BINDIR}/libdynarray.a

#####################################################################################
DYNAMIC_libdynarray: clean
DYNAMIC_libdynarray: FLAGS=-g -Wall -shared -lc -O2 -DNDEBUG
DYNAMIC_libdynarray: OBJ_FLAGS=-g -Wall -fPIC -O2 -DNDEBUG
DYNAMIC_libdynarray: ${SO_LIB}

STATIC_libdynarray: clean
STATIC_libdynarray: ${STATIC_LIB}

####################################

# including bin and obj directories as dependencies so they can be created
${SO_LIB}: ${BINDIR} ${OBJDIR} ${OBJS}
	$(CC) $(FLAGS) ${OBJS} -o $@

# r: replace / c: create / s: index
${STATIC_LIB}: ${BINDIR} ${OBJDIR} ${OBJS}
	ar rcs $@ ${OBJS}

####################################

${OBJDIR}/%.o: ${SRCDIR}/%.c ${SRCDIR}/%.h
	$(CC) $(OBJ_FLAGS) -c $< -o $@

${TESTDIR}/bin/%: ${TESTDIR}/%.test.c
	$(CC) $(FLAGS) $< ${OBJS} -o $@ -lcriterion

####################################

${OBJDIR}:
	mkdir $@

${BINDIR}:
	mkdir $@

${TESTDIR}/bin:
	mkdir $@

###################################
test: ${TESTDIR}/bin ${TESTBINS}
	for test in ${TESTBINS} ; do ./$$test ${TEST_FLAGS} ; done
	
clean: 
	${RM} -r ${BINDIR}/* ${OBJDIR}/*;
	${RM} -r **/**/*.dSYM;
	${RM} ${TESTBINS}