#!/bin/sh

for var in ~/Projects42/TEST_CHAMPS_ALL/*.cor ; do
	./CoreWar "$var"
	echo "\n"
done
