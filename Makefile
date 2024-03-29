# Makefile
PROJ=IMS_CA
SOURCES=src/ims_ca.cpp src/model.cpp
HEADERS=src/ims_ca.h src/model.h
FLAGS=-lsimlib
CC=g++
AUTHORS=xwilla00_xlanic04

RUN_PARAMS=-f 20 -m 10 # TBD

default:
	${CC} ${SOURCES} ${FLAGS} -o ${PROJ}

run:default
	./${PROJ} ${RUN_PARAMS}

test: default
	./sim.sh -n 5 -f 500 -m 50

clean:
	rm IMS_CA

pack:
	tar -cvf ${AUTHORS}.tar.gz doc/ Makefile README.md src/ CMakeLists.txt
