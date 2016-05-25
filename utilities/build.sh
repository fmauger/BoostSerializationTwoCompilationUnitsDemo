#!/usr/bin/env sh

objects_xy="B.o A.o Y.o X.o"
cflags="-I."
ldflags="-lboost_serialization"

echo "cflags  = ${cflags}"
echo "ldflags = ${ldflags}"

echo
echo "Building the libXY shared lib..."

# X module:
g++ -c -fPIC ${cflags} XY/X.cpp
ls -l X.o

# Y module:
g++ -c -fPIC ${cflags} XY/Y.cpp
ls -l Y.o

# A module:
g++ -c -fPIC ${cflags} XY/A.cpp
ls -l A.o

# B module:
g++ -c -fPIC ${cflags} XY/B.cpp
ls -l B.o

# Build the module with embedded serialization code (instantiation of template
# methods for supported archives):
g++ -c -fPIC ${cflags} XY/serial_xy_ab.cpp
ls -l serial_xy_ab.o

# Build the shared lib with embedded serialization code:
g++ --shared serial_xy_ab.o B.o A.o Y.o X.o -o libXY.so ${ldflags}
ls -l libXY.so

echo
echo "Building the test programs associated to the libXY shared lib..."

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/XY/test_X.cxx -o test_X ${objects_xy} ${ldflags}
ls -l test_X

# Link the executable with the dedicated module with instantiated serialization methods:
g++ ${cflags} testing/XY/test_X_2.cxx -o test_X_2 serial_xy_ab.o ${objects_xy} ${ldflags}
ls -l test_X_2

# Link the executable with the shared lib that contains the instantiated serialization methods:
g++ ${cflags} testing/XY/test_X_2.cxx -o test_X_2b libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_X_2b

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/XY/test_Y.cxx -o test_Y ${objects_xy} ${ldflags}
ls -l test_Y

# Link the executable with the dedicated module with instantiated serialization methods:
g++ ${cflags} testing/XY/test_Y_2.cxx -o test_Y_2 serial_xy_ab.o ${objects_xy} ${ldflags}
ls -l test_Y_2

# Link the executable with the shared lib that contains the instantiated serialization methods:
g++ ${cflags} testing/XY/test_Y_2.cxx -o test_Y_2b libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_Y_2b

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/XY/test_AB.cxx -o test_AB ${objects_xy} ${ldflags}
ls -l test_AB

# Link the executable with the shared lib that contains the instantiated serialization methods:
g++ ${cflags} testing/XY/test_AB_2.cxx -o test_AB_2 serial_xy_ab.o ${objects_xy} ${ldflags}
ls -l test_AB_2

# Link the executable with the shared lib that contains the instantiated serialization methods:
g++ ${cflags} testing/XY/test_AB_2.cxx -o test_AB_2b libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_AB_2b

echo
echo "Building the libZ shared lib..."

objects_z="C.o Z.o"

# Z module:
g++ -c -fPIC ${cflags} Z/Z.cpp
ls -l Z.o

# C module:
g++ -c -fPIC ${cflags} Z/C.cpp
ls -l C.o

# Build the module with embedded serialization code (instantiation of template
# methods for supported archives):
g++ -c -fPIC ${cflags} Z/serial_z_c.cpp
ls -l serial_z_c.o

# Build the shared lib with embedded serialization code:
g++ --shared serial_z_c.o ${objects_z} -o libZ.so libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l libZ.so

echo
echo "Building the test programs associated to the libZ shared lib..."

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/Z/test_Z.cxx -o test_Z ${objects_z} libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_Z

# Link the executable with the dedicated module with instantiated serialization methods:
g++ ${cflags} testing/Z/test_Z_2.cxx -o test_Z_2 serial_z_c.o ${objects_z} libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_Z_2

# Link the executable with the shared lib that contains the instantiated serialization methods:
g++ ${cflags} testing/Z/test_Z_2.cxx -o test_Z_2b libZ.so libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_Z_2b

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/Z/test_C.cxx -o test_C ${objects_z} libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_C

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/Z/test_C_2.cxx -o test_C_2 serial_z_c.o ${objects_z} libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_C_2

# Link the executable with local definition of template serialization method:
g++ ${cflags} testing/Z/test_C_2.cxx -o test_C_2b libZ.so libXY.so ${ldflags} -Wl,-rpath=$(pwd)
ls -l test_C_2b

echo
echo "Done."

exit 0

# end
