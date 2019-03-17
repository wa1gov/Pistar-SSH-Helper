#!/bin/bash

echo "Installing Pistar-SSH-Helper"
echo "Updating Pistar, please wait..."

sudo pistar-update > /dev/null
sleep 5
echo "Done updating Pistar!"

echo "Running rpi-rw"
sudo mount -o remount,rw / ; sudo mount -o remount,rw /boot

echo "Downloading DMR ID database..."
#wget -q -O usr.bin http://www.amateurradio.digital/pi-star_data.php
#wget -q -O usr.bin https://www.radioid.net/static/users.csv
#wget --timeout=120 --no-check-certificate --wait=3 'https://ham-digital.org/status/users.csv' -O usr.bin
wget --timeout=120 --no-check-certificate --wait=3 'https://www.radioid.net/api/dmr/user/?id=%&format=csv' -O usr_raw.bin
awk -F\" '{print $10","$2","$8","$4","$14","$6}' usr_raw.bin > usr.bin
echo "Done downloading DMR ID database!"

echo "Installing/upgrading figlet..."
sudo apt-get -y install figlet > /dev/null
echo "Done installing figlet!"

echo "Installing/upgrading toilet..."
sudo apt-get -y install toilet > /dev/null
echo "Done installing toilet!"
echo
echo "To start Pistar-SSH-Helper,type:" 
echo
echo "./slh"
echo
echo "Done installing Pistar-SSH-Helper!!"
