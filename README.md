Title:       C++ classes from two compilation units (shared libraries) with Boost/Serialization support
Author:      F.Mauger
Email:       mauger@lpccaen.in2p3.fr
Affiliation: Université de Caen Normandie, LPC Caen (CNRS/IN2P3)
Copyright :  Creative Commons BY-NC-SA (README file and C++ code)
Date:        2016-05-25
Keywords:    Boost,Serialization,Compilation units

# BoostSerializationTwoCompilationUnitsDemo

## Introduction

This set  of sample  C++ files illustrates  how to  give serialization
functionalities, through  the Boost/Serialization library,  to several
(simple)  classes defined  from two  shared libraries.   The libraries
contain the instantiated templatized code for serialization of classes
for  several types  of Boost  archives as  well as  class registration
(*export*) code.  Two use cases are considered:

1)  Simple class  ``xy::Y``  with an  attribute  (composition) of  the
   simpler class  ``xy::X`` in the  first library.  Class  ``z::Z`` in
   the second  library with a class  ``xy::Y`` attribute (composition)
   and  a  class  ``xy::X``  attribute (composition)  from  the  first
   library.

```
    +-----------------+
    |      xy::X      |
    +-----------------+
    | val : uint32_t  |
    +-----------------+

    +-----------------+
    |      xy::Y      |
    +-----------------+
    | x : xy::X       |
    +-----------------+
                                First shared lib
    --------------------------------------------
                               Second shared lib
    +-----------------+
    |      z::Z       |
    +-----------------+
    | y : xy::Y       |
    | x : xy::X       |
    +-----------------+
```

2) Class ``xy::B``  inherited from  polymorphic class  ``xy::A`` in  the first
   library; class  ``z::C`` in  the second  library inherited  from class
   ``xy::B`` from the first library.

```
    +-----------------+
    |    /xy::A/      |
    +-----------------+
    | val : uint32_t  |
    +-----------------+
    | /to_string/     |
    +-----------------+
            ^
            | inheritance
            |
    +-----------------+
    |    /xy::B/      |
    +-----------------+
    | val2 : uint32_t |
    +-----------------+
    | /to_string/     |
    +-----------------+
            ^
            | inheritance       First shared lib
    --------|-----------------------------------
            |                  Second shared lib
    +-----------------+
    |    /z::C/       |
    +-----------------+
    | val3 : uint32_t |
    +-----------------+
    | /to_string/     |
    +-----------------+

```

Several linkage schemes are considered through various test programs.
The generated Boost archive files use the XML format.

This demo has been tested under Linux  but should work on any other OS
with a descent C++ compiler and a Boost/Serialization installation.

Simple shell  scripts (for Linux)  are provided  to build and  run the
test programs.

## Requirements

These examples  have been  successfully tested  on Linux  Ubuntu 14.04
with gcc 4.8.4 and system Boost/Serialization library version 1.54.


## Shared library libXY(.so)

The  ``libXY.so``  (namespace  ``xy``)  shared  library  contains  the
definitions of serializable  classes ``xy::X``, ``xy::Y``, ``xy::A``  and ``xy::B`` as
well  as instantiated  serialization code  and registration  code (for
class ``xy::B``) with regards of Boost XML and text archives.

### Classes

  * Class    ``xy::X``    :   ``X.hpp``,    ``X.cpp``,    ``X-serial.ipp``
    (implementation of templatized serialization method).
  * Class ``xy::Y`` with an attribute of type ``xy::X``: ``Y.hpp``, ``Y.cpp``,
    ``Y-serial.ipp``  (implementation   of  templatized  serialization
    method).
  * Class   ``xy::A``   (polymorphic   class)  :   ``A.hpp``,   ``A.cpp``,
    ``A-serial.ipp``  (implementation   of  templatized  serialization
    method).
  * Class ``xy::B`` (inherited from ``xy::A``)  : ``B.hpp`` (with export key),
    ``B.cpp``,   ``B-serial.ipp``   (implementation   of   templatized
    serialization method).
  * Instantiation  of serialization  code  for  classes ``xy::X``,  ``xy::Y``,
    ``xy::A``,    ``xy::B``   and    class   ``xy::B``    registration   (export):
    ``serial_xy_ab.cpp``.

### Test programs

  * ``testing/XY/test_X.cxx``   :   serialization   of  class   ``xy::X``   (embedded
    serialization code).
  * ``testing/XY/test_X_2.cxx`` :  serialization of  class ``xy::X`` with  linkage to
    pre-instantiated  serialization   (serialization  code   from  the
    binary modules or shared library).
  * ``testing/XY/test_Y.cxx``   :   serialization   of  class   ``xy::Y``   (embedded
    serialization code).
  * ``testing/XY/test_Y_2.cxx``:  serialization of  class ``xy::Y``  with linkage  to
    pre-instantiated     serialization    and     registration    code
    (serialization code from the binary modules or the shared library).
  * ``testing/XY/test_AB.cxx`` :  serialization of pointers to  objects (``xy::A`` or
    ``xy::B``)   inherited   from   polymorphic  class   ``xy::A``   (embedded
    serialization/registration code).
  * ``testing/XY/test_AB_2.cxx`` : serialization of pointers to objects (``xy::A`` or
    ``xy::B``)     inherited     from      polymorphic     class     ``xy::A``
    (serialization/registration code  from the  binary modules  or the
    shared library).


## Shared library libZ(.so)

The  ``libZ.so``   (namespace  ``z``)  shared  library   contains  the
definitions  of  serializable  classes  ``z::Z`` and  ``z::C``  as  well  as
instantiated  serialization  code  and registration  code  (for  class
``z::C``) with regards of Boost XML and text archives.

### Classes

  * Class ``z::Z``  with an attribute of  type ``xy::Y`` and an  attribute of
    type ``xy::X`` : ``Z.hpp``, ``Z.cpp``, ``Z-serial.ipp``.
  * Class ``z::C`` (inherited from ``xy::B``)  : ``C.hpp`` (with export key),
    ``C.cpp``, ``C-serial.ipp``.
  * Instantiation of serialization code  for classes ``z::Z``, ``z::C``, and
    class ``z::C`` registration (export): ``serial_z_c.cpp``.

### Test programs

  * ``testing/Z/test_Z.cxx``   :   serialization   of  class   ``z::Z``   (embedded
    serialization code)..
  * ``testing/Z/test_Z_2.cxx`` :  serialization of  class ``z::Z`` with  linkage to
    pre-instantiated serialization (serialization code from the binary
    modules or the shared library).
  * ``testing/Z/test_C.cxx``  : serialization  of  pointers  to objects  (``xy::A``,
    ``xy::B`` or  ``z::C``) inherited from polymorphic  class ``xy::A`` (embedded
    serialization/registration code).
  * ``testing/Z/test_C_2.cxx`` :  serialization of  pointers to  objects (``xy::A``,
    ``xy::B``   or  ``z::C``)   inherited   from   polymorphic  class   ``xy::A``
    (serialization/registration code  from the  binary modules  or the
    shared library).


## Utilities

Shell scripts provided to build and test the code:

 * ``utilities/build.sh``  : Build  binary  modules, shared  libraries and  test
   programs.

   From the base source directory, run:

```sh
$ ./utilities/build.sh
```


 * ``utilities/run.sh`` :  Run test  programs. Each  executable produces  an XML
   archive  file which  contains  serialized object  of the  different
   classes implemented from both libraries.

   From the base source directory, run:

```sh
$ ./utilities/run.sh
```

 * ``utilities/clean.sh`` : Clean the working files (binaries, archive files).

   From the base source directory, run:

```sh
$ ./utilities/clean.sh
```
