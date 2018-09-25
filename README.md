# Pistar-SSH-Helper

DESCRIPTION

Display Pistar hotspot station info via an SSH session

This is a little C++ program that reads the latest MMDVM log
file from the default /var/log/pistar directory. It then
does a callsign lookup on the dmr id database file to
display additional info on the station. A command line
argument is used to specify the MMDVM log file as the
name changes daily.

Most dmr id database files can be used to retrieve station
information. Typical format includes six comma delimited
fields similar to the following:

3125916,WA1GOV,Arthur,East Taunton,Massachusetts,US

The ID database needs to be named usr.bin and reside in
the home/current directory. Information retieved from the
dmr database will be displayed as in the example.jpg file.

----------------------------------------------------------------
REQUIREMENTS/PREREQUISITES

The following requirements/prerequisites need to be done before
starting up the program.

Use SSH from the pistar dashboard or another ssh client and login
to the Pistar hotspot.

Download the tar archive from GitHub:
    
    wget -O psh-install.tgz https://github.com/wa1gov/Pistar-SSH-Helper/raw/master/psh-install.tgz

Extract the contents of the tar archive:

    tar xvf psh-install.tgz

Run this script as follows:

    ./psh-install.sh

----------------------------------------------------------------
OPERATION and OPTIONS

The showlh.cfg offers the option to choose a color for the callsign
(DEFCOLOR), divider line (DIVCOLOR) and the text (TXTCOLOR) display:

BLACK
BBLACK
RED=DEFCOLOR
BRED
GREEN
BGREEN
WHITE=DIVCOLOR
WHITE=TXTCOLOR
BWHITE

Choose the color by editing the file and appending "=DEFCOLOR", 
"=DIVCOLOR", or "=TXTCOLOR", to the color of choice as in the example above.

Run slh to start the program

    ./slh

Use CTRL+C to exit the program

Run showlh -v to get the program version.

    ./showlh -v
    ./showlh version 1.1.0

You can run showlh <logfile name>
to specify a different logfile from the default.

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
