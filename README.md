# Pistar-SSH-Helper
Display Pistar hotspot station info via an SSH session
Initial version: 1.1.0

This is a little C++ program that reads the latest MMDVM log
file from the default /var/log/pistar directory. It then
does a callsign lookup on the dmr id database file to
display additional info on the station. A command line
argument is used to specify the MMDVM log file as the
name changes daily.

Most dmr id database files can be used to retrieve station
information. It just needs to be named usr.bin and reside
in the current directory. Information retieved from the
dmr database will be displayed on the ssh terminal.

The callsign and name will be displayed in large characters
followed by a timestamp, callsign, first name, city, state,
country and talkgroup in normal text (see example.jpg).

The following requirements/prerequisites need to be done before
starting up the program.

Use SSH from the pistar dashboard or another ssh client and login
to the Pistar hotspot.

Install figlet and toilet on the RPI hosting the hotspot.

sudo pistar-update
sudo apt-get install figlet
sudo apt-get install toilet

Download the database file in the pi-star home directory

cd ~
wget -O usr.bin http://www.amateurradio.digital/pi-star_data.php

Download showlh and slh into the pi-star home directory from GitHub.
Make both files executable.

chmod +x slh showlh

Operation and options.

Run: ./slh to start the program
Use CTRL+C to exit the program

Run: ./showlh -v to get the version
./showlh version 1.1.0

Run: ./showlh <logfile name>
to specify a different logfile from the default.

Disclaimer and Caveats

This program has only been tested with a Jumbospot MMDVM on RPI Zero.
Other hotspots may exhibit different results or errors.

For MMDVM hotspots, the default logfile is located in /var/log/pi-star and is named
MMDVM-year-month-day.log

The logfile name changes automatically via Pistar at 2400 UTC.
The program may appear to hang at 2400 UTC as a new logfile is created.
If this condition occurs, stop and restart the program.

