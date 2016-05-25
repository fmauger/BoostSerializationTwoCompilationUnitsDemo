#!/usr/bin/env sh

find . -name "*~" -exec rm -f \{\} \;
rm -f *.o
rm -f *.so
rm -f *.xml
rm -f test_X
rm -f test_X_2
rm -f test_X_2b
rm -f test_Y
rm -f test_Y_2
rm -f test_Y_2b
rm -f test_AB
rm -f test_AB_2
rm -f test_AB_2b
rm -f test_Z
rm -f test_Z_2
rm -f test_Z_2b
rm -f test_C
rm -f test_C_2
rm -f test_C_2b

exit 0
