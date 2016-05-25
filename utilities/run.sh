#!/usr/bin/env sh

echo
echo "Using libXY..."

echo "Testing class X..."
./test_X
cat test_X.xml
./test_X_2
diff test_X.xml test_X_2.xml
./test_X_2b
diff test_X.xml test_X_2.xml

echo
echo "Testing class Y..."
./test_Y
cat test_Y.xml
./test_Y_2
diff test_Y.xml test_Y_2.xml
./test_Y_2b
diff test_Y.xml test_Y_2.xml

echo
echo "Testing polymorphic classes A and B..."
./test_AB
cat test_AB.xml
./test_AB_2
diff test_AB.xml test_AB_2.xml
./test_AB_2b
diff test_AB.xml test_AB_2.xml

echo
echo "Using libZ (and libXY)..."

echo
echo "Testing class Z..."
./test_Z
cat test_Z.xml
./test_Z_2
diff test_Z.xml test_Z_2.xml
./test_Z_2b
diff test_Z.xml test_Z_2.xml

echo
echo "Testing polymorphic class C..."
./test_C
cat test_C.xml
./test_C_2
diff test_C.xml test_C_2.xml
./test_C_2b
diff test_C.xml test_C_2.xml

echo
echo "Done."

exit 0
