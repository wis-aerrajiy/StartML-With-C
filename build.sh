#!/bin/sh

set -xe
cc -Wall -Wextra -Werror -o main main.c -lm
cc -Wall -Wextra -Werror -o gates gates.c -lm