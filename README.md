# Boost Serialization with Two Compilation Units

A demo with C++ classes  from two compilation units (shared libraries)
with Boost/Serialization support:

* Author:      F.Mauger
* Affiliation: Université de Caen Normandie, LPC Caen (CNRS/IN2P3)
* Copyright :  Creative Commons BY-NC-SA (this README file and C++ code)
* Date:        2016-05-25
* Update:      2017-04-29
* Keywords:    Boost,Serialization,Compilation units

## Introduction

This  set   of  sample   C++  files   illustrates  how   to  implement
serialization   functionalities,   through   the   Boost/Serialization
library,  in   several  (simple)  classes  defined   from  three  shared
libraries with dependency relationship.   The libraries  instantiate
dedicated templatized  code for  serialization of classes  for several
types  of Boost  archives  as well  as  class registration  (*export*)
mechanism                                                         (see
the [Boost/Serialization documentation](http://www.boost.org/doc/libs/1_61_0/libs/serialization/doc/index.html)
for details).

Two use cases are considered:

1)  Simple class  ``xy::Y``  with an  attribute  (composition) of  the
   simpler class  ``xy::X`` in the  first library (``libXY``).  Class  ``z::Z`` in
   the second  library (``libZ``) with a class  ``xy::Y`` attribute (composition)
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
                        First shared lib (libXY)
    --------------------------------------------
                        Second shared lib (libZ)
    +-----------------+
    |      z::Z       |
    +-----------------+
    | y : xy::Y       |
    | x : xy::X       |
    +-----------------+
```

2) Class ``xy::B``  inherited from  polymorphic class  ``xy::A`` in  the first
   library (``libXY``); class  ``z::C`` in  the second  library (``libZ``) inherited  from class
   ``xy::B`` from the first library, class  ``plugin::P`` in  the third  library (``libPlugin``) inherited  from class
   ``xy::A`` from the first library.

```
    +-----------------+
    |    /xy::A/      |
    +-----------------+
    | val : uint32_t  |
    +-----------------+
    | /to_string/     |
    +-----------------+
		    ^     ^
inheritance |     |
			|     +--------------------------------+
            |                                      |
    +-----------------+                            |
    |    /xy::B/      |                            |
    +-----------------+                            |
    | val2 : uint32_t |                            |
    +-----------------+                            |
    | /to_string/     |                            |
    +-----------------+                            |
            ^                                      |
            |           First shared lib (libXY)   |
    --------|-----------------------------------   |
            |           Second shared lib (libZ)   |
inheritance |                                      |
    +-----------------+                            |
    |    /z::C/       |                            |
    +-----------------+                            |
    | val3 : uint32_t |                            |
    +-----------------+                            |
    | /to_string/     |                            |
    +-----------------+                            |
                                                   |
            +--------------------------------------+
	--------|-----------------------------------
            |       Third shared lib (libPlugin)
inheritance |
    +-----------------+
    |    plugin::P    |
    +-----------------+
    | val2 : uint32_t |
	+-----------------+

```

Various  test programs are provided to test (de)serialization.
The generated Boost archive files use the XML format.

This demo has been tested under Linux  but should work on any other OS
with a descent  C++ compiler and Boost/Serialization  installed on the
system.

A CMake script is provided to build the full chain of software (DLLs and test executable).

## Requirements

These examples  have been  successfully tested  on:

  * Linux  Ubuntu 16.04 with gcc 5.4.0 and system Boost/Serialization library versions 1.58 and 1.60.

## Shared library libXY(.so)

The  ``libXY.so``  (namespace  ``xy``)  shared  library  contains  the
definitions  of serializable  classes ``xy::X``,  ``xy::Y``, ``xy::A``
and  ``xy::B``   as  well  as  instantiated   serialization  code  and
registration code (for class ``xy::B``)  with regards of Boost XML and
text archives.

### Classes

  * Class   ``xy::X``   :   ``X.hpp``,   ``X.cpp``,   ``X-serial.hpp``
    (implementation of the templatized serialization method).
  * Class ``xy::Y``  with an  attribute of type  ``xy::X``: ``Y.hpp``,
    ``Y.cpp``,  ``Y-serial.hpp``  (implementation of  the  templatized
    serialization method).
  * Class  ``xy::A``  (polymorphic   class)  :  ``A.hpp``,  ``A.cpp``,
    ``A-serial.hpp`` (implementation of  the templatized serialization
    method).
  * Class  ``xy::B``  (inherited  from ``xy::A``)  :  ``B.hpp``  (with
    export  key), ``B.cpp``,  ``B-serial.hpp`` (implementation  of the
    templatized serialization method).
  * Instantiation  of   serialization  code  for   classes  ``xy::X``,
    ``xy::Y``, ``xy::A``,  ``xy::B`` and class  ``xy::B`` registration
    (export): ``serial_xy_ab.cpp``.

### Test programs

  * ``XY/testing/test_X.cxx``   :   serialization   of  class   ``xy::X``   (embedded
    serialization code).
  * ``XY/testing/test_X_2.cxx`` :  serialization of  class ``xy::X`` with  linkage to
    pre-instantiated  serialization   (serialization  code   from  the
    binary modules or shared library).
  * ``XY/testing/test_Y.cxx``   :   serialization   of  class   ``xy::Y``   (embedded
    serialization code).
  * ``XY/testing/test_Y_2.cxx``:  serialization of  class ``xy::Y``  with linkage  to
    pre-instantiated     serialization    and     registration    code
    (serialization code from the binary modules or the shared library).
  * ``XY/testing/test_AB.cxx`` :  serialization of pointers to  objects (``xy::A`` or
    ``xy::B``)   inherited   from   polymorphic  class   ``xy::A``   (embedded
    serialization/registration code).
  * ``XY/testing/test_AB_2.cxx`` : serialization of pointers to objects (``xy::A`` or
    ``xy::B``)     inherited     from      polymorphic     class     ``xy::A``
    (serialization/registration code  from the  binary modules  or the
    shared library).y


## Shared library libZ(.so)

The  ``libZ.so``   (namespace  ``z``)  shared  library   contains  the
definitions  of  serializable  classes  ``z::Z`` and  ``z::C``  as  well  as
instantiated  serialization  code  and registration  code  (for  class
``z::C``) with regards of Boost XML and text archives.

### Classes

  * Class ``z::Z``  with an attribute of  type ``xy::Y`` and an  attribute of
	type ``xy::X`` : ``Z.hpp``, ``Z.cpp``, ``Z-serial.hpp``.
  * Class ``z::C`` (inherited from ``xy::B``)  : ``C.hpp`` (with export key),
    ``C.cpp``, ``C-serial.ipp``.
  * Instantiation of serialization code  for classes ``z::Z``, ``z::C``, and
    class ``z::C`` registration (export): ``serial_z_c.cpp``.

### Test programs

  * ``Z/testing/test_Z.cxx``   :   serialization   of  class   ``z::Z``   (embedded
    serialization code).
  * ``Z/testing/test_Z_2.cxx`` :  serialization of  class ``z::Z`` with  linkage to
    pre-instantiated serialization (serialization code from the binary
    modules or the shared library).
  * ``Z/testing/test_C.cxx``  : serialization  of  pointers  to objects  (``xy::A``,
    ``xy::B`` or  ``z::C``) inherited from polymorphic  class ``xy::A`` (embedded
    serialization/registration code).
  * ``Z/testing/test_C_2.cxx`` :  serialization of  pointers to  objects (``xy::A``,
    ``xy::B``   or  ``z::C``)   inherited   from   polymorphic  class   ``xy::A``
    (serialization/registration code  from the  binary modules  or the
    shared library).


## Shared library libPlugin(.so)

The  ``libPlugin.so``   (namespace  ``plugin``)  shared  library   contains  the
definitions  of  serializable  classe  ``plugin::P``  as  well  as
instantiated  serialization  code  and registration  code  (for  class
``plugin::P``) with regards of Boost XML and text archives.


### Classes

  * Class ``plugin::P`` (inherited from ``xy::A``)  : ``P.hpp`` (with export key),
	``P.cpp``, ``P-serial.hpp``.
  * Instantiation of serialization code  for classes ``plugin::P`` and
	class registration (export): ``serial_plugin_p.cpp``.

### Test programs

  * ``Plugin/testing/test_Plugin.cxx`` :  use a factory for random instantiation of
	``xy::A``, ``xy::B``, ``z::C`` and ``plugin::P`` objects and serialization through
	shared pointers. The program is explicitely linked to the ``libPlugin.so`` DLL.
  * ``Plugin/testing/test_Plugin_2.cxx`` :  use a factory for random instantiation of
	``xy::A``, ``xy::B``, ``z::C`` and ``plugin::P`` objects and serialization through
	shared pointers. The ``libPlugin.so`` DLL is loaded dynamically by the executable.


## Building the demo

From the source directory:

```sh
$ mkdir _build.d
$ cd _build.d
$ cmake [-DBOOST_ROOT=/path/to/boost/installation] ..
$ make
$ make test
$ ls XY/ Z/ Plugin/
```

## Utilities

Shell scripts provided to build and test the code:

* ``utilities/build.sh``  : Build  binary  modules, shared  libraries and  test
  programs.

From the base source directory, run:

```sh
$ ./utilities/build.sh
```

 * ``utilities/run.sh`` : Run test  programs. Each executable produces
   an  XML  archive  file  which contains  serialized  object  of  the
   different classes implemented from both libraries.

   From the base source directory, run:

```sh
$ ./utilities/run.sh
```

 * ``utilities/clean.sh`` : Clean the working files (binaries, archive
   files).

   From the base source directory, run:

```sh
$ ./utilities/clean.sh
```
