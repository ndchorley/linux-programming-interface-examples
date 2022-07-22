#!/bin/bash

if [ ! -e "bin" ]
then
    mkdir bin
fi

gcc create_child_process_with_fork.c -o bin/create_child_process_with_fork
