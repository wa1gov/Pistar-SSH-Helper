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

The easiest way to install this is to run the following command:
    
    git clone https://github.com/wa1gov/Pistar-SSH-Helper.git

This will create a directory called Pistar-SSH-Helper.
In this directory look for the script:

    psh-install.sh

Make this script executable, then run it:

    cd ~/Pistar-SSH-Helper
    chmod +x psh-install.sh
    ./psh-install.sh

The command should perform all the other commands listed
in the next section below. If you ran psh-install.sh successfully,
you can now skip to OPERATION and OPTIONS.

----------------------------------------------------------------

Make slh and showlh executable.

    cd ~/Pistar-SSH-Helper
    chmod +x slh showlh

Download the database file in the pi-star home directory

    wget -O usr.bin http://www.amateurradio.digital/pi-star_data.php

Install figlet and toilet on the RPI hosting the hotspot.

    sudo pistar-update
    sudo apt-get install figlet
    sudo apt-get install toilet

----------------------------------------------------------------
OPERATION and OPTIONS

The showlh.cfg offers the option to choose a color for the callsign display:

BLACK
BBLACK
RED=DEFCOLOR
BRED
GREEN
BGREEN

Choose the color by editing the file and appending "=DEFCOLOR" to the 
color of choice as in the example above.

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

The logfile name changes automatically via Pistar at 2400 UTC.
The program may appear to hang at 2400 UTC as a new logfile is created.
If this condition occurs, stop and restart the program.
