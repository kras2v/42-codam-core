#!/bin/bash
ARG=$1 && make && ./philo $ARG && make fclean 