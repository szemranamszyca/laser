[![Build Status](https://travis-ci.org/szemranamszyca/laser.svg?branch=master)](https://github.com/szemranamszyca/laser)

# Simple Laser Emulator
Command to compile project:

* mkdir build
* cd build
* cmake ..
* make


Compiled on g++ (GCC) 8.2.1 20180831

Main class, Laser owns 3. main components:
* HMI - Human Machine Interface. Input for the application. Typed parameters are passed to:
* CmdProcessor - analyzing command and trigger proper function
* ControlPanel - configure above elements and control them.

Things to improve:
* add functinality to "KAL" command. E.g. trigger function every 5 seconds and set ControlPanel::emissionStatus_ to false;
* refactor CmdProcessor::process - now it's little messy.
* simplify CmdProcessor configuring - function-action. Maybe SignalSlot pattern?
* simplify arguments passing to/from ControlPanel
