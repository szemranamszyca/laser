[![Build Status](https://travis-ci.org/szemranamszyca/laser.svg?branch=master)](https://github.com/szemranamszyca/laser)
[![codecov](https://codecov.io/gh/szemranamszyca/laser/branch/master/graph/badge.svg)](https://codecov.io/gh/szemranamszyca/laser)
# Simple Laser Emulator
Command to compile project:

* mkdir build
* cd build
* cmake ..
* make all
* ctest


Compiled on g++ (GCC) 8.2.1 20180831

Main class, Laser owns 3. main components:
* HMI - Human Machine Interface. Input for the application. Typed parameters are passed to:
* CmdProcessor - analyzing command and trigger proper function
* ControlPanel - configure above elements and control them.

Things to improve:
* refactor CmdProcessor::process - now it's little messy.
* simplify arguments passing to/from ControlPanel
