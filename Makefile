P := main
OBJECTS := segmentDisplay.o
CFLAGS := -std=c99 
VPATH := src:test
BINDIR := bin

MYSYSTEM := $(shell uname -s)
ifeq ($(MYSYSTEM),Darwin)
  LDLIBS := -framework OpenGL -framework GLUT
else
  LDLIBS := -lglut -lGL
endif

CC=gcc

$(P):  $(OBJECTS) 

.PHONY: clean
clean:
	rm -rf $(P) $(OBJECTS)
	echo "Clean done"
