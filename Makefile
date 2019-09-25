:############################################################
####	Makefile template for opencv use
############################################################
RM 			= @rm -rfv
CC = g++
CFLAGS = -g -Wall -std=c++11
#VPATH = .:./ED
#SRCS = $(wildcard **/*.cpp)
SRCS = $(wildcard src/*.cpp) $(wildcard src/ED/*.cpp)
#PROG = HelloWorld
PROG      = $(notdir $(shell pwd))	## current foldername is target name

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

#	clean
clean:
#	$(RM) $(BUILD_PATH)
	$(RM) $(PROG)
	@echo "Done."


