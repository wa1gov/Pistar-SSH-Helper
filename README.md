# Pistar-SSH-Helper

DESCRIPTION

Program to display Pistar hotspot station info via an SSH 
session.

This is a little C++ program that does a callsign lookup
on a DMR id database file to display an extra large callsign
and first name with additional info on the station (See the 
example*.* files).

----------------------------------------------------------------
REQUIREMENTS/PREREQUISITES TO DOWNLOAD AND INSTALL THE EXECUTABLE

Most users can just install the executable as follows in this
section. If problems arise, go to the next section to compile and
create the executable for your particular hardware. 

Use SSH from the pistar dashboard or another ssh client and login
to the Pistar hotspot.

Download the tar archive from GitHub:
    
    wget -O psh-install.tgz https://github.com/wa1gov/Pistar-SSH-Helper/raw/master/psh-install.tgz

Extract the contents of the tar archive:

    tar xvf psh-install.tgz

psh-install.sh
README.md
showlh
showlh.cfg
slh

Run this script as follows:

    ./psh-install.sh

----------------------------------------------------------------
REQUIREMENTS/PREREQUISITES TO DOWNLOAD and COMPILE THE SOURCE CODE

The following requirements/prerequisites need to be done to compile
and install the program. Perform these steps if there was a problem
with using the executable in the above section. Otherwise, skip to the 
OPERATION and OPTIONS section.

Use SSH from the pistar dashboard or another ssh client and login
to the Pistar hotspot.

Download the tar archive from GitHub:

    wget -O psh-install.tgz https://github.com/wa1gov/Pistar-SSH-Helper/raw/master/Pistar-SSH-Helper.tgz

Extract the contents of the tar archive:

    tar xvf psh-install.tgz

example.jpg
example2.jpg
example3.jpg
psh-install.sh
README.md
makefile
showlh.cfg
showlh.h
showlh.cpp

Run make clean:

    make clean

Run make:

    make

Run this script to install the program:

    ./psh-install.sh

----------------------------------------------------------------
OPERATION and OPTIONS

The showlh.cfg offers the option to choose a color for the callsign
(DEFCOLOR) and the text (TXTCOLOR) display:

 BLACK
 BBLACK
 RED=DEFCOLOR
 BRED
 GREEN
 BGREEN
 WHITE=TXTCOLOR
 BWHITE

Choose the color by editing the file and appending "=DEFCOLOR" 
or "=TXTCOLOR" to the color of choice as in the example above.

The the program will display the CPU temperature on the divider
line (see example3.jpg). The divider line color will change based
on the CPU temperature as follows:

GREEN < 50 degrees C.
YELLOW >= 50 degrees C.
RED >= 69 degrees C.

Run slh to start the program

    ./slh

Use CTRL+C to exit the program

Run showlh -v to get the program version.

    ./showlh -v
    ./showlh version 1.1.0

You can run showlh <logfile name>
to specify a different logfile from the default.

Run the install script at any time to update the DMR ID database files.

    ./psh-install.sh

----------------------------------------------------------------
DISCLAIMER and CAVEATS

This program has only been tested with a Jumbospot MMDVM on RPI Zero.
Other hotspots may exhibit different results or errors.

For MMDVM hotspots, the default logfile is located in 
/var/log/pi-star and is named by convention:

    MMDVM-year-month-day.log

A new logfile is created for the next day automatically via Pistar
at 2400 UTC. The program may appear to hang at 2400 UTC when the new
logfile is created. If this occurs, stop and restart the program.
