TARGET    := dsmath

DIR_BIN   := bin
DIR_SRC   := src
DIR_LIBS  := libs
DIR_TESTS := tests

TESTS 	:= $(basename $(notdir $(wildcard $(DIR_TESTS)/*.c)))
SOURCES := $(wildcard $(DIR_SRC)/*.c)
SOURCES += $(wildcard $(DIR_LIBS)/*.c)
OBJECTS := $(patsubst src,bin,$(patsubst %.c,%.o,$(SOURCES)))

VERSION := $(shell git describe --long --dirty --tags --always 2>/dev/null)

CFLAGS += -I./src
CFLAGS += -g -Wall
CFLAGS += -Werror
LDLIBS += 
CFLAGS += -DVERSION=\"$(VERSION)\"

all: ${TARGET}
	@echo "All done."
${TARGET}: ${SOURCES}
	$(CC) -o bin/$@ main.c $^
tests: ${TESTS}
${TESTS}: ${SOURCES}
	$(CC) $(CFLAGS) $(LDLIBS) -o $(DIR_BIN)/$@ $(DIR_TESTS)/$@.c $^
summary:
	@echo "TARGET  : $(TARGET)"
	@echo "VERSION : $(VERSION)"
	@echo "SOURCES : $(SOURCES)"
	@echo "OBJECTS : $(OBJECTS)"
	@echo "CFLAGS  : $(CFLAGS)"
	@echo "LDLIBS  : $(LDLIBS)"
clean:
	$(shell rm bin/*)