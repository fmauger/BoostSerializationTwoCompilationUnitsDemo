# Boost Serialization with (More Than) Two Compilation Units

A Boost/Serialization demo with C++ classes  from several compilation units (shared libraries):

* Author:      F.Mauger
* Affiliation: Université de Caen Normandie, LPC Caen (CNRS/IN2P3)
* Copyright :  Creative Commons BY-NC-SA (this README file and C++ code)
* Date:        2016-05-25
* Update:      2017-05-02
* Keywords:    Boost,Serialization,Compilation units

## Introduction

This demo has been  created as a test bench of  some advanced usage of
the Boost  Serialization Library on  some systems of  interest (mostly
computers running  Linux for  computing, simulation and  data analysis
for  experimental  physics).  It  is  provided  as  is, first  for  my
personal usage  and also  in the  hope it could  help someone  else to
understand and setup Boost based serialization features in his/her own code.

This  set   of  sample   C++  files   illustrates  how   to  implement
serialization   functionalities,   through   the   Boost/Serialization
library,  in   several  (simple)  classes  defined   from  three  shared
libraries with dependency relationship.   The libraries  instantiate
dedicated templatized  code for  serialization of classes  for several
types  of Boost  archives  as well  as  class registration  (*export*)
mechanism                                                         (see
the [Boost/Serialization documentation](http://www.boost.org/doc/libs/1_60_0/libs/serialization/doc/index.html)
for details).

Several use cases are considered:

1)  Plain serialization of simple classes:

   Simple class  ``xy::Y``  with an  attribute of  the
   class  ``xy::X`` in the  first library (``libXY``).  Class  ``z::Z`` in
   the second  library (``libZ``) with a class  ``xy::X`` attribute
   and  a  class  ``xy::Y``  attribute  from  the  first
   library (``libXY``).

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

2) Serialization of polymorphic classes through pointer to a base class:

   Class ``xy::B``  inherited from  polymorphic class  ``xy::A`` in  the first
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

3) Serialization of objects only known from a plugin library, dynamically loaded at runtime
from a compilation unit (executable) that does not know about the class of the serialized objects.

Various  test programs are provided to test (de)serialization of
the classes. We use the official *XML Boost archive* format. Optionally the use of
*EOS portable binary archives* (version 5.1) can be activated.

## Requirements

This demo has been tested under Linux  but should work on any other OS
with a descent  C++ compiler and Boost/Serialization  installed on the
system.

A CMake script is provided to build the full chain of software on Linux (DLLs and test executable).

These examples  have been  successfully tested  on Linux  Ubuntu 16.04 with :

	* gcc 5.4.0
	* Boost/Serialization library versions 1.58 (system installation on ``/usr``) and 1.60.
	* CMake 3.5.1

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
  * Abstract class  ``xy::BasePlugin``  :  base class for object factory classes.
    Object instantiated from such factories must inherit the ``xy::A`` class.
  * Class  ``xy::plugin_deck``  :  provide a singleton which points to an object factory instance.
    Object instantiated from such factories inherit the ``xy::A`` class.

### Test programs

  * ``XY/testing/test_X.cxx``   :   serialization   of  class   ``xy::X``.
  * ``XY/testing/test_Y.cxx``   :   serialization   of  class   ``xy::Y``.
  * ``XY/testing/test_AB.cxx`` :  serialization of pointers to  objects (``xy::A`` or
    ``xy::B``)   inherited   from   polymorphic  class   ``xy::A``.

## Shared library libZ(.so)

The  ``libZ.so``   (namespace  ``z``)  shared  library   contains  the
definitions  of  serializable  classes  ``z::Z`` and  ``z::C``  as  well  as
instantiated  serialization  code  and registration  code  (for  class
``z::C``) with regards of Boost XML and text archives.
The ``libZ.so``  DLL is explicitely linked to the ``libXY.so`` DLL.

### Classes

  * Class ``z::Z``  with an attribute of  type ``xy::Y`` and an  attribute of
	type ``xy::X`` : ``Z.hpp``, ``Z.cpp``, ``Z-serial.hpp``.
  * Class ``z::C`` (inherited from ``xy::B``)  : ``C.hpp`` (with export key),
    ``C.cpp``, ``C-serial.hpp``.
  * Instantiation of serialization code  for classes ``z::Z``, ``z::C``, and
    class ``z::C`` registration (export): ``serial_z_c.cpp``.

### Test programs

  * ``Z/testing/test_Z.cxx``   :   serialization   of  class   ``z::Z``.
  * ``Z/testing/test_C.cxx``  : serialization  of  pointers  to objects  (``xy::A``,
    ``xy::B`` or  ``z::C``) inherited from polymorphic  class ``xy::A``.

## Shared library libPlugin(.so)

The  ``libPlugin.so``   (namespace  ``plugin``)  shared  library   contains  the
definitions  of  serializable  classe  ``plugin::P``  as  well  as
instantiated  serialization  code  and registration  code  (for  class
``plugin::P``) with regards of Boost XML and text archives.
The ``libPlugin.so``  DLL is explicitely linked to the ``libZ.so`` DLL.
At loading, the ``libPlugin.so`` DLL instantiates a specific object factory and register it
from the ``libXY.so`` DLL. From this factory, it is then possible to instantiate objects
of various types (``xy::A``, ``xy::B``,``z::C`` or ``plugin::P``) from a
compilation unit which is only linked to the ``libXY.so`` DLL and from which the ``libPlugin.so``
DLL has been dynamically loaded.

### Classes

  * Class ``plugin::P`` (inherited from ``xy::A``)  : ``P.hpp`` (with export key),
	``P.cpp``, ``P-serial.hpp``.
  * Instantiation of serialization code  for classes ``plugin::P`` and
	class registration (export): ``serial_plugin_p.cpp``.
  * Class  ``plugin::Plugin``  :  object factory class.
	Object of types ``xy::A``, ``xy::B``,``z::C`` or ``plugin::P`` are randomly
	instantiated from this factory.
  * Class  ``plugin::init_lib``  : provide a singleton for initialization of the library at loading.
	A 	``plugin::Plugin`` instance is automatically registered in the ``xy:plugin_deck`` singleton
	from the ``libXY.so`` DLL.

### Test programs

  * ``Plugin/testing/test_Plugin.cxx`` :  use a factory for random instantiation of
	several ``xy::A``, ``xy::B``, ``z::C`` or ``plugin::P`` objects and serialization through
	a vector of shared pointers. The executable is explicitely linked to the ``libPlugin.so`` DLL
	and thus the  ``libZ.so`` and ``libXY.so`` DLLs..
  * ``Plugin/testing/test_Plugin_2.cxx`` :  use a factory for random instantiation of
	``xy::A``, ``xy::B``, ``z::C`` and ``plugin::P`` objects and serialization through
	a vector of shared pointers.  The executable is only explicitely linked to the ``libXY.so`` DLL.
	The ``libPlugin.so`` DLL is loaded dynamically by the executable at runtime which makes
	possible the serialization of random objects of type ``z::C`` and ``plugin::P`` thanks
	to export code implemented in both ``libZ.so`` and ``libPlugin.so`` DLLs.


## Building the demo

### Options

The demo supports two optional parameters:

- ``BOOST_ROOT`` : The path where the Boost libraries are installed. For a system installation on Linux, this should be ``/usr`` and automatically found by CMake.

  Example: to target a specific Boost installation:

```sh
$ cmake ... -DBOOST_ROOT=/opt/sw/Boost/install-1.60 ...
```

- ``BSTCUD_WITH_EOS`` : This flag enables support and test of the EOS Portable Binary Archives (version 5.1,
  by Christian Pfligersdorffer). By default it is inhibited.

  Example:

```sh
$ cmake ... -DBSTCUD_WITH_EOS=ON ...
```


### Configure and build

From the source directory:

```sh
$ mkdir _build.d
$ cd _build.d
$ cmake [-DBOOST_ROOT=/path/to/boost/installation] [-DBSTCUD_WITH_EOS=ON] ..
$ make
$ ls XY/ Z/ Plugin/
$ make test
```

By default, the CMake ``find_package(Boost ...)`` function will search for
a system installation of the Boost library
from the ``/usr`` directory. This can be changed with the ``-DBOOST_ROOT=...``
variable.
