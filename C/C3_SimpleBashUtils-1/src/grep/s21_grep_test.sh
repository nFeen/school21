#!/bin/bash

echo "Not all that Mrs. Bennet, however, with the assistance of her
five daughters, could ask on the subject, was sufficient to
draw from her husband any satisfactory description of Mr.
Bingley. They attacked him in various ways--with barefaced
questions, ingenious suppositions, and distant surmises; but he
eluded the skill of them all, and they were at last obliged to
accept the second-hand intelligence of their neighbour, Lady
Lucas. Her report was highly favourable. Sir William had
been delighted with him. He was quite young, wonderfully
handsome, extremely agreeable, and, to crown the whole, he
meant to be at the next assembly with a large party. Nothing
could be more delightful! To be fond of dancing was a certain
step towards falling in love; and very lively hopes of Mr.
Bingley's heart were entertained." >1.txt

echo "An invitation to dinner was soon afterwards dispatched;
and already had Mrs. Bennet planned the courses that were to
do credit to her housekeeping, when an answer arrived which
deferred it all. Mr. Bingley was obliged to be in town the
following day, and, consequently, unable to accept the honour
of their invitation, etc. Mrs. Bennet was quite disconcerted.
She could not imagine what business he could have in town so
soon after his arrival in Hertfordshire; and she began to fear
that he might be always flying about from one place to
another, and never settled at Netherfield as he ought to be.
Lady Lucas quieted her fears a little by starting the idea of his
being gone to London only to get a large party for the ball;
and a report soon followed that Mr. Bingley was to bring
twelve ladies and seven gentlemen with him to the assembly.
The girls grieved over such a number of ladies, but were
comforted the day before the ball by hearing, that instead of
twelve he brought only six with him from London--his five 1.txt
sisters and a cousin. And when the party entered the assembly
room it consisted of only five altogether--Mr. Bingley, his two
sisters, the husband of the eldest, and another young man." >2.txt

echo "" >3.txt

echo "the
Mr
r$" >pat.txt

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE1="1.txt"
TEST_FILE2="2.txt 3.txt"
echo >log.txt

for pattern1 in 123 girl. The "o$" could "d[a-z][a-z]" "\w," terr; do

  TEST1="$pattern1 $TEST_FILE1 $TEST_FILE2"
  ./s21_grep $TEST1 >s21_grep.txt
  echo "$TEST1"
  grep $TEST1 >grep.txt
  DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
  if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    ((COUNTER_SUCCESS++))
  else
    echo "$TEST1" >>log.txt
    ((COUNTER_FAIL++))
  fi

  rm s21_grep.txt
  rm grep.txt

done

for var1 in -i -v -c -l -n; do
  for pattern1 in girl. The could "d[a-z][a-z]" "\w,"; do
    for pattern2 in suppositions "o$" assembly gentle "six."; do
      TEST1="-e $pattern1 $TEST_FILE1 -e $pattern2 $TEST_FILE2 $var1 "
      echo "$TEST1"
      ./s21_grep $TEST1 >s21_grep.txt
      grep $TEST1 >grep.txt
      DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
      if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
        ((COUNTER_SUCCESS++))
      else
        echo "$TEST1" >>log.txt
        ((COUNTER_FAIL++))
      fi
      rm s21_grep.txt grep.txt
    done
  done
done

for var1 in -i -v -c -l -n; do
  for pattern in "the" "Mr" "r$"; do
    TEST1="-e $pattern $TEST_FILE1 $TEST_FILE2 $var1"
    echo "$TEST1"
    ./s21_grep $TEST1 >s21_grep.txt
    grep $TEST1 >grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
      ((COUNTER_SUCCESS++))
    else
      echo "$TEST1" >>log.txt
      ((COUNTER_FAIL++))
    fi
    rm s21_grep.txt grep.txt

    TEST1="$TEST_FILE1 -e $pattern $TEST_FILE2"
    echo "$TEST1"
    ./s21_grep $TEST1 >s21_grep.txt
    grep $TEST1 >grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
      ((COUNTER_SUCCESS++))
    else
      echo "$TEST1" >>log.txt
      ((COUNTER_FAIL++))
    fi
    rm s21_grep.txt grep.txt

    TEST1="$TEST_FILE1 $TEST_FILE2 -e $pattern"
    echo "$TEST1"
    ./s21_grep $TEST1 >s21_grep.txt
    grep $TEST1 >grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
      ((COUNTER_SUCCESS++))
    else
      echo "$TEST1" >>log.txt
      ((COUNTER_FAIL++))
    fi
    rm s21_grep.txt grep.txt
  done
done
for var1 in v c l n e i; do
  for var2 in v c l n e i; do
    for pattern1 in 123 girl. The "o$" could "d[a-z][a-z]" "\w," terr; do
      if [ $var1 == "s" ] || [ $var2 == "s" ]; then
        TEST_FILE2="2.txt 3.txt unexisting.txt"
      else
        TEST_FILE2="2.txt 3.txt"
      fi
      if [ $var1 != $var2 ]; then

        if [ "$var1" == "e" ]; then
          if [ "$var2" == "f" ]; then
            TEST1="-$var1 $pattern1 -$var2 pat.txt $TEST_FILE1 $TEST_FILE2 "
          else
            TEST1="-$var1 $pattern1 -$var2 $TEST_FILE1 $TEST_FILE2 "
          fi
        else
          if [ $var1 == "f" ]; then
            if [ $var2 == "e" ]; then
              TEST1="-$var1 pat.txt -$var2 $pattern1 $TEST_FILE1 $TEST_FILE2"
            else
              TEST1="-$var1 pat.txt -$var2 $TEST_FILE1 $TEST_FILE2"
            fi
          else
            if [ $var2 == "f" ]; then
              TEST1="-$var1 -$var2 pat.txt $TEST_FILE1 $TEST_FILE2"
            else
              TEST1="-$var1 -$var2 $pattern1 $TEST_FILE1 $TEST_FILE2"
            fi

          fi
        fi

        ./s21_grep $TEST1 >s21_grep.txt
        echo "$TEST1"
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi

        rm s21_grep.txt
        rm grep.txt
      fi
    done
  done
done

TEST_FILE1="s21_grep.c"
TEST_FILE2="s21_grep.h"

for var1 in -i -v -c -l -n; do
  for var2 in -i -v -c -l -n; do
    if [ $var1 != $var2 ]; then
      for pattern in int void define opt; do
        TEST1="$var1 $var2 $pattern $TEST_FILE1 $TEST_FILE2"
        echo "$TEST1"
        ./s21_grep $TEST1 >s21_grep.txt
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST1="$pattern $var1 $TEST_FILE1 $TEST_FILE2 $var2"
        echo "$TEST1"
        ./s21_grep $TEST1 >s21_grep.txt
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"

        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST1="$pattern $TEST_FILE1 $var1 $TEST_FILE2 $var2"
        echo "$TEST1"
        ./s21_grep $TEST1 >s21_grep.txt
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST1="$pattern $TEST_FILE1 $TEST_FILE2 $var1 $var2"
        echo "$TEST1"
        ./s21_grep $TEST1 >s21_grep.txt
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

      done
    fi
  done
done
rm 1.txt
rm 2.txt
rm 3.txt
rm pat.txt

echo "SUCCESS: $COUNTER_SUCCESS"
echo "SUCCESS: $COUNTER_SUCCESS" >>log.txt
echo "FAIL: $COUNTER_FAIL"
echo "FAIL: $COUNTER_FAIL" >>log.txt
