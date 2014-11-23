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


#$(BINDIR)/$(P): test/%.c 
#		$(CC) $(CFLAGS) -c -o $@ $< 

#$(BINDIR)/%.o : src/%.c
#	        $(CC) $(CFLAGS) -c -o $@ $<

#$(OBJECTS): $(BINDIR)/%.o : src/%.c
#   	 $(CC) $(CFLAGS) -c $< $(LIB_PATH) $(LIBS)

$(P):  $(OBJECTS) 



.PHONY: clean
clean:
	rm -rf $(P) $(OBJECTS)
	echo "Clean done"
