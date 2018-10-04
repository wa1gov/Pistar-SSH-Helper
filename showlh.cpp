/* 
 *  file    slh.cpp
 *  author  WA1GOV
 *  date    9/15/2018  
 *  version 1.1.3 
 *  
 *  Pi-star ssh helper callsign lookup and display
 *
 *  DESCRIPTION
 *  
 *  This is a little program that reads the latest MMDVM log
 *  file from the default /var/log/pistar directory. It then
 *  does a callsign lookup on the dmr id database file to 
 *  display additional info on the station. A command line
 *  argument is used to specify the MMDVM log file as the
 *  name changes daily. 
 *
 */

// Use "c++ -std=c++0x slh.cpp" or
//     "g++ -std=c++0x slh.cpp" to compile

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include "showlh.h"

using namespace std;

int firstrun=0;
static int last_position=0;
string DEFCOLOR;
string TXTCOLOR;
string DIVCOLOR;

std::string(get_callsign(const std::string& callsign))
{
    string id, scall;
    string call_line;

    ifstream ip("usr.bin");
    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    // find the callsign in the database, return the full line

    while(ip.good())
    {
        getline(ip,call_line);
        if( call_line.find(callsign) != string::npos) {
            std::stringstream stream(call_line);
            getline(stream, id, ',');
            getline(stream, scall, ',');
            if ( callsign==scall ) {
                return(call_line);
            }
        }
    }
    ip.close();
    return("Reached EOF,Callsign,Not_found,Update,database");
}

// read file until new line
// save position

int find_new_text(ifstream &infile) {

    infile.seekg(0,ios::end);
    int filesize = infile.tellg();
    float cputemp, BER;
    int loss;
    string line, cline, pktl, ber, netpl, netber;
    string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6;
    string strWords[17]; // [2] = ID, [11] = callsign, [14] = TG
    string trimtime, trimname;
    string dmrid, call, name, city, state, country;
    short counter = 0;

    // check if the new file started

    if(filesize < last_position) {
        last_position=0;
    }

    // only do this the first time through

    if( firstrun == 0 ) {
        last_position=filesize;
        firstrun=1;
    }

    // read file from last position until new line is found

    for(int n=last_position; n<filesize; n++) {

        // get the packet loss and BER for the last station

        infile.seekg( last_position-48,ios::beg);
        getline(infile, line);
        if( line.find("BER") != string::npos) {
            for(unsigned int i=0; i<line.length(); i++) {
                if(line[i] == ' ') {
                    counter++;
                } else {
                    strWords[counter] += line[i];
                }
            }

            if( strWords[5] == "RSSI:" ) {
                netber=strWords[4];
                netpl="0%"; 
            } else {
                netber=strWords[7];
                netpl=strWords[3];
            }
            
            // Set color for packet loss
            std::string pktl = netpl.substr(0, netpl.find("%"));
            stringstream pl(pktl);
            pl >> loss;
            if (loss < 2) DIVCOLOR=TXTCOLOR;
            if (loss >= 2) DIVCOLOR="YELLOW";
            if (loss > 3) DIVCOLOR="RED";
            cout << "\t Duration " << strWords[1] << " seconds, ";
            cout << colors[DIVCOLOR] << netpl << " packet loss, ";

            // Set color for BER
            std::string ber = netber.substr(0, netber.find("%"));
            stringstream lb(ber);
            lb >> BER;
            if (BER < 2) DIVCOLOR=TXTCOLOR;
            if (BER >= 2) DIVCOLOR="YELLOW";
            if (BER > 4.9) DIVCOLOR="RED";
            cout << colors[DIVCOLOR] << "BER: " << netber << "\n";
        }
   
        // clear array and counter
        for(int i = 0; i <= counter; i++) {
            strWords[i].clear();
        }
        counter=0;

        // get only lines that contain the word "header"

        infile.seekg( last_position,ios::beg);
        getline(infile, line);
        last_position = infile.tellg();
        if( line.find("header") != string::npos) {
            for(unsigned int i=0; i<line.length(); i++) {
                if(line[i] == ' ') {
                    counter++;
                } else {
                    strWords[counter] += line[i];
                }
            }

            // Trim the 10th of seconds off of the time string

            std::string trimtime = strWords[2].substr(0, strWords[2].find("."));

            // Get the line in the database for this callsign

            std::string cline = get_callsign(strWords[11]);
      
            // Display the divider line with CPU Temp

            std::ifstream tempin("/sys/class/thermal/thermal_zone0/temp");
            tempin >> cputemp;
            if (cputemp/1000 < 50) DIVCOLOR="GREEN";
            if (cputemp/1000 >= 50) DIVCOLOR="YELLOW";
            if (cputemp/1000 >= 69) DIVCOLOR="RED";

            cout << colors[DIVCOLOR] << "═══════════════════════ CPU Temp: ";
            cout << std::fixed << std::setprecision(1) << cputemp/1000 << "C/" << cputemp/1000*1.8+32;
            cout << "F ════════════════════════" << RESET;

            // Use figlet to banner the callsign
            
            // Set callsign color

            cout << colors[DEFCOLOR] << "\n";

            std::string cmd1 = "figlet -f mono12 ";
            std::string cmd2 = strWords[11];
            std::string cmd3 = cmd1+cmd2;

            system( cmd3.c_str() );

            cout << colors[TXTCOLOR] << "\n"; // text color 

            // Parse the database line

            std::stringstream stream(cline);
            getline(stream, dmrid, ',');
            getline(stream, call, ',');
            getline(stream, name, ',');
            if ( name != "" ) {

                // Get the first name only

                std::string tname = name.substr(0, name.find(" "));

                // Strip out quotes in first name

                tname.erase(std::remove(tname.begin(), tname.end(), '"')\
                     , tname.end());
                trimname = tname;
                if ( tname.length() > 11 ) {
                    tname.erase(11, tname.length());
                }
                getline(stream, city, ',');
                getline(stream, state, ',');
                getline(stream, country, ',');

                // Use figlet to banner the first name

                std::string cmd4 = "figlet -f mono9 ";
                std::string cmd5 = tname;
                std::string cmd6 = cmd4+cmd5;
                system( cmd6.c_str() );
            }

            // print out the database info after callsign and name banner

            cout << trimtime << " " << call << "," << trimname << ",";
            cout << city << "," << state << "," << country << " TG";
            cout << strWords[14] << endl;

            // clear array and counter
            for(int i = 0; i <= counter; i++) {
                strWords[i].clear();
            }
            counter=0;
        }

        // end of file

        if(filesize == last_position) {
            return filesize;
        }
    }

    return 0;
}


int main(int argc, char *argv[]) {
    if (argc < 2) { // infile name
        std::cerr << "Usage: " << argv[0] << " <Log file name>" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "-v") {
        std::cout << argv[0] << " version 1.1.3\n";
        return 0;
    }
    std::ifstream cfgin("showlh.cfg");
    if(!cfgin.is_open()) {
        std::cout << "##### showlh.cfg ERROR: File Open #####" << '\n';
    }
    std::string cfgline;
    DEFCOLOR="WHITE";
    TXTCOLOR="WHITE";
    while( std::getline(cfgin, cfgline)) {
        std::stringstream stream(cfgline);
        if( cfgline.find("DEFCOLOR") != string::npos) {
            std::stringstream stream(cfgline);
            getline(stream, DEFCOLOR, '=');
        }
        if( cfgline.find("TXTCOLOR") != string::npos) {
            std::stringstream stream(cfgline);
            getline(stream, TXTCOLOR, '=');
        }
    }
    cfgin.close();
    std::cout << "***** Gateway Activity from " << argv[1] << " *****\n";
    for(;;) {
        std::ifstream infile(argv[1]);
        int current_position = find_new_text(infile);
        usleep(1000000);
    }

}
