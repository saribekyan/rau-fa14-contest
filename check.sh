#!/bin/bash

# Tests of test_sol.cpp against the tests.

FILES=`ls tests/[0-9][0-9][0-9]`
for f in $FILES
do
    echo $f
    diff <( ./test_sol.cpp.out < $f ) $f.a
done

