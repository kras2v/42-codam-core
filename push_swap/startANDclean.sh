#!/bin/bash
make
cc -Wall -Werror -Wextra push_swap.a -o push_swap
./push_swap "$@"
rm -rf push_swap
make fclean