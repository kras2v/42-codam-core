#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
RESET='\033[0m' 

# Function to run a test and check the exit code
run_test() {
	local ARG="$1"
	local expected_exit_code="$2"
	local description="$3"

	make > /dev/null 2>&1 # Suppress make output for cleaner test runs
	./philo $ARG > log.txt
	actual_exit_code=$?
	make fclean > /dev/null 2>&1

	echo
	echo "# VALIDATION - $description #"
	echo "Arguments: $ARG"
	echo "Expected exit code: $expected_exit_code, Actual exit code: $actual_exit_code"
	echo "Program Output:"
	cat log.txt

	if [ "$actual_exit_code" -ne "$expected_exit_code" ]; then
		echo -e "${RED}" "FAIL: $description" "${RESET}"
		return 1 # Return 1 to indicate failure
	else
		echo -e "${GREEN}" "PASS: $description" "${RESET}"
		return 0 # Return 0 to indicate success
	fi
}

# Array to store test results (0 for pass, 1 for fail)
declare -a test_results

# VALIDATION - Valid positive integers (4 arguments)
run_test "1 100 10 10" 0 "Valid 4 args 1"
test_results+=("$?")
run_test "5 800 200 200" 0 "Valid 4 args 2"
test_results+=("$?")

# VALIDATION - Valid positive integers (5 arguments)
run_test "1 100 10 10 5" 0 "Valid 5 args 1"
test_results+=("$?")
run_test "5 800 200 200 10" 0 "Valid 5 args 2"
test_results+=("$?")

# VALIDATION - Valid positive integers (edge cases)
run_test "1 1 1 1" 0 "Valid positive integers edge 1 (4 args)"
test_results+=("$?")
run_test "1 2147483647 2147483647 2147483647" 0 "Valid positive integers edge 2 (4 args)"
test_results+=("$?")
run_test "1 1 1 1 1" 0 "Valid positive integers edge 3 (5 args)"
test_results+=("$?")
run_test "1 2147483647 2147483647 2147483647 10" 0 "Valid positive integers edge 4 (5 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Non-numeric characters (4 args)
run_test "1 abc 10 10" 1 "Invalid input - Non-numeric 1 (4 args)"
test_results+=("$?")
run_test "1 10 x10 10" 1 "Invalid input - Non-numeric 2 (4 args)"
test_results+=("$?")
run_test "1 10 10 x" 1 "Invalid input - Non-numeric 3 (4 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Non-numeric characters (5 args)
run_test "1 abc 10 10 10" 1 "Invalid input - Non-numeric 4 (5 args)"
test_results+=("$?")
run_test "1 10 x10 10 10" 1 "Invalid input - Non-numeric 5 (5 args)"
test_results+=("$?")
run_test "1 10 10 x 10" 1 "Invalid input - Non-numeric 6 (5 args)"
test_results+=("$?")
run_test "1 10 10 10 x" 1 "Invalid input - Non-numeric 7 (5 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Multiple signs
run_test "1 --10 10 10" 1 "Invalid input - Multiple signs 1 (4 args)"
test_results+=("$?")
run_test "1 -+10 10 10" 1 "Invalid input - Multiple signs 2 (4 args)"
test_results+=("$?")
run_test "1 +-10 10 10" 1 "Invalid input - Multiple signs 3 (4 args)"
test_results+=("$?")
run_test "1 --10 10 10 10" 1 "Invalid input - Multiple signs 4 (5 args)"
test_results+=("$?")
run_test "1 -+10 10 10 10" 1 "Invalid input - Multiple signs 5 (5 args)"
test_results+=("$?")
run_test "1 +-10 10 10 10" 1 "Invalid input - Multiple signs 6 (5 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Non-integer characters
run_test "1 10.5 10 10" 1 "Invalid input - Non-integer 1 (4 args)"
test_results+=("$?")
run_test "1 10,5 10 10" 1 "Invalid input - Non-integer 2 (4 args)"
test_results+=("$?")
run_test "1 10.5 10 10 10" 1 "Invalid input - Non-integer 3 (5 args)"
test_results+=("$?")
run_test "1 10,5 10 10 10" 1 "Invalid input - Non-integer 4 (5 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Empty string
run_test "1  10 10" 1 "Invalid input - Empty string (4 args)"
test_results+=("$?")

# VALIDATION - Invalid input - Just a sign
run_test "1 - 10 10" 1 "Invalid input - Just a sign - (4 args)"
test_results+=("$?")
run_test "1 + 10 10" 1 "Invalid input - Just a sign + (4 args)"
test_results+=("$?")
run_test "1 - 10 10 10" 1 "Invalid input - Just a sign - (5 args)"
test_results+=("$?")
run_test "1 + 10 10 10" 1 "Invalid input - Just a sign + (5 args)"
test_results+=("$?")

# VALIDATION - Invalid input - missing arguments
run_test "1 10 10" 1 "Invalid input - Missing arg 1 (3 args)"
test_results+=("$?")
run_test "1 10" 1 "Invalid input - Missing arg 2 (2 args)"
run_test "1" 1 "Invalid input - Missing arg 3 (1 args)"
run_test "" 1 "Invalid input - Missing arg 4 (0 args)"
test_results+=("$?")
run_test "1 10 10 10" 0 "Valid input - 4 args"
test_results+=("$?")
run_test "1 10 10 10 10" 0 "Valid input - 5 args"
test_results+=("$?")
run_test "1 10 10 10 10 10" 1 "Invalid input - 6 args"
test_results+=("$?")

# Summarize test results
echo "# Summary"
all_passed=0
for result in "${test_results[@]}"; do
	if [ "$result" -ne 0 ]; then
		all_passed=1
		break
	fi
done

if [ "$all_passed" -eq 0 ]; then
	echo "All tests PASSED"
	exit 0
else
	echo "Some tests FAILED"
	exit 1
fi

rm -rf log.txt