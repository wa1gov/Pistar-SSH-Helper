#!/bin/bash

echo "Installing Pistar-SSH-Helper"
echo "Updating Pistar, please wait..."

sudo pistar-update > /dev/null
sleep 5
echo "Done updating Pistar!"

echo "Running rpi-rw"
sudo mount -o remount,rw / ; sudo mount -o remount,rw /boot

echo "Downloading DMR ID database..."
wget --timeout=120 --no-check-certificate --wait=3 'https://www.radioid.net/static/user.csv' -O usr_raw.bin
awk -F, '{print $1","$2","$3","$5","$6","$7}' usr_raw.bin > usr.bin
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
