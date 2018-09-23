#!/bin/bash

echo "Installing Pistar-SSH-Helper"
echo "Updating Pistar, please wait..."

sudo pistar-update > /dev/null
sleep 5
echo "Done updating Pistar!"

echo "Running rpi-rw"
sudo mount -o remount,rw / ; sudo mount -o remount,rw /boot

echo "Downloading DMR ID database..."
wget -q -O usr.bin http://www.amateurradio.digital/pi-star_data.php
echo "Done downloading DMR ID database!"

echo "Installing/upgrading figlet..."
sudo apt-get -y install figlet > /dev/null
echo "Done installing figlet!"

echo "Installing/upgrading toilet..."
sudo apt-get -y install toilet > /dev/null
echo "Done installing toilet!"
echo
echo "To start Pistar-SSH-Helper,type:" 
echo "cd ~/Pistar-SSH-Helper"
echo "./slh"
echo
echo "Done installing Pistar-SSH-Helper!!"
