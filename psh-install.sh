#!/bin/bash

cd ~
echo "Installing Pistar-SSH-Helper"
echo "Updating Pistar, please wait..."

sudo pistar-update > /dev/null
sleep 5
echo "Done updating Pistar!"

echo "Running rpi-rw"
sudo mount -o remount,rw / ; sudo mount -o remount,rw /boot

if [ -d Pistar-SSH-Helper ]
then
   echo "Pistar-SSH-Helper directory exists, updating..."
   cd ~/Pistar-SSH-Helper
   git pull
else
   echo "Downloading Pistar-SSH-Helper"
   git clone https://github.com/wa1gov/Pistar-SSH-Helper.git
fi

cd ~/Pistar-SSH-Helper

if [ -f psh-install.sh ]
then
    chmod +x psh-install.sh
fi
chmod +x showlh
chmod +x slh

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
