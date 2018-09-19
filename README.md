# Pistar-SSH-Helper
Display Pistar hotspot station info via an SSH session

This is a little C++ program that reads the latest MMDVM log
file from the default /var/log/pistar directory. It then
does a callsign lookup on the dmr id database file to
display additional info on the station. A command line
argument is used to specify the MMDVM log file as the
name changes daily.

Most dmr id database files can be used to retrieve station
information. It just needs to be named usr.bin and reside
in the current directory. Information retieved from the
dmr database will be displayed as below.
---------------------------------------------------------------------------
▄▄      ▄▄    ▄▄       ▄▄▄        ▄▄▄▄     ▄▄▄▄    ▄▄    ▄▄
██      ██   ████     █▀██      ██▀▀▀▀█   ██▀▀██   ▀██  ██▀
▀█▄ ██ ▄█▀   ████       ██     ██        ██    ██   ██  ██
 ██ ██ ██   ██  ██      ██     ██  ▄▄▄▄  ██    ██   ██  ██
 ███▀▀███   ██████      ██     ██  ▀▀██  ██    ██    ████
 ███  ███  ▄██  ██▄  ▄▄▄██▄▄▄   ██▄▄▄██   ██▄▄██     ████
 ▀▀▀  ▀▀▀  ▀▀    ▀▀  ▀▀▀▀▀▀▀▀     ▀▀▀▀     ▀▀▀▀      ▀▀▀▀



   ▄▄            ▄    █
   ██    ▄ ▄▄  ▄▄█▄▄  █ ▄▄   ▄   ▄   ▄ ▄▄
  █  █   █▀  ▀   █    █▀  █  █   █   █▀  ▀
  █▄▄█   █       █    █   █  █   █   █
 █    █  █       ▀▄▄  █   █  ▀▄▄▀█   █

13:59:00 WA1GOV,Arthur,"East Taunton",Massachusetts,"United States" TG91
         Duration  19.6 seconds, 0% packet loss, BER: 0.0%
---------------------------------------------------------------------------
The following requirements/prerequisites need to be done before
starting up the program.

Install figlet and toilet on the RPI hosting the hotspot.
sudo pistar-update
sudo apt-get install figlet
sudo apt-get install toilet

Download the database file in the pi-star home directory
cd ~
wget -O usr.bin http://www.amateurradio.digital/pi-star_data.php

Operation.

Use SSH from the pistar dashboard or another ssh client to login
to the Pistar hotspot. 

Execute: ./slh

Disclaimer.
This has only been tested with a Jumbospot MMDVM on RPI Zero.
