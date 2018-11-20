CCX = gcc
CFLAGS = -O0 -g -w -Wall
FLTK_FLAGS = #`fltk-config --ldflags --use-images`
SOURCE = main
DEPENDENCES = #../../GUI/Graph.cpp ../../GUI/Window.cpp  ../../GUI/GUI.cpp ../../GUI/Func_window.cpp

$(SOURCE):
	$(CCX)	$(CFLAGS)	-o $(SOURCE)	$(DEPENDENCES)	$(SOURCE).c	$(FLTK_FLAGS)	

clean:
	rm -r $(SOURCE) $(SOURCE).dSYM
