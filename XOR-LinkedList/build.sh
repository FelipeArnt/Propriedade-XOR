#!/bin/sh

set -xe
cc -Wall -Wextra -ggdb -o ll ll.c && ./ll
