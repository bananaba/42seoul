#!/bin/bash

TEST_00='/bin/ls'
TEST_01='/bin/cat asd'
TEST_02='echo "asd" zxc'
TEST_03='echo -n qwe "cvb"'
TEST_04='echo $?'
TEST_05='echo $?+$?'
TEST_06='echo "cat lol.c | cat > lol.c"'
TEST_07='echo "$HOME | cat > lol.c"'
TEST_08='ls -l | wc -l'
TEST_09='echo "$USER"'
TEST_10='env'
TEST_11='export'
TEST_12='pwd'
TEST_13='echo asd >'
TEST_14='echo qwe >>'
TEST_15='< asd cat >>'
TEST_16='cat asd | grep qwe | wc -l | cat'


echo -e "\033[0;31m"TEST CASE_00 : $TEST_00"\033[0m"
echo $TEST_00 | minishell > a
echo $TEST_00 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_01 : $TEST_01"\033[0m"
echo $TEST_01 | minishell > a
echo $TEST_01 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_02 : $TEST_02"\033[0m"
echo $TEST_02 | minishell > a
echo $TEST_02 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_03 : $TEST_03"\033[0m"
echo $TEST_03 | minishell > a
echo $TEST_03 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_04 : $TEST_04"\033[0m"
echo $TEST_04 | minishell > a
echo $TEST_04 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_05 : $TEST_05"\033[0m"
echo $TEST_05 | minishell > a
echo $TEST_05 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_06 : $TEST_06"\033[0m"
echo $TEST_06 | minishell > a
echo $TEST_06 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_07 : $TEST_07"\033[0m"
echo $TEST_07 | minishell > a
echo $TEST_07 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_08 : $TEST_08"\033[0m"
echo $TEST_08 | minishell > a
echo $TEST_08 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_09 : $TEST_09"\033[0m"
echo $TEST_09 | minishell > a
echo $TEST_09 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_10 : $TEST_10"\033[0m"
echo $TEST_10 | minishell > a
echo $TEST_10 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_11 : $TEST_11"\033[0m"
echo $TEST_11 | minishell > a
echo $TEST_11 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_12 : $TEST_12"\033[0m"
echo $TEST_12 | minishell > a
echo $TEST_12 | bash > b
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_13 : $TEST_13"\033[0m"
echo $TEST_13 a | minishell
echo $TEST_13 b | bash
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_14 : $TEST_14"\033[0m"
echo $TEST_14 a | minishell
echo $TEST_14 b | bash
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_15 : $TEST_15"\033[0m"
echo $TEST_15 a | minishell
echo $TEST_15 b | bash
diff -s a b
echo

echo -e "\033[0;31m"TEST CASE_16 : $TEST_16"\033[0m"
echo $TEST_16 | minishell > a
echo $TEST_16 | bash > b
diff -s a b
