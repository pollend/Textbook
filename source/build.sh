#!/bin/bash
CORES=`nproc` 
CORES=$(($CORES +1))
echo "running with : "$CORES
#cmake .
make #-j $CORES 
../release/generate.wt COMMAND
#./generate.cgi COMMAND
service apache2 restart
