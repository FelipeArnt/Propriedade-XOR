#!/bin/sh

set -xe
cc -Wall -Wextra -ggdb main.c xor_list.c -o run && ./run
