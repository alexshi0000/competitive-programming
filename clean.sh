#!/bin/bash
for OBJECT in *.cpp
do
	mv $OBJECT src
done

for OBJECT in *.c
do
	mv $OBJECT src
done

for OBJECT in *.class
do
	rm -f $OBJECT
done
