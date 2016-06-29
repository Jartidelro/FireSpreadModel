#include "weather.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


// Constructor
Weather::Weather(){ }


// Destructor
    Weather::~Weather(){}


void Weather::wfile_input()
{
    // From: http://stackoverflow.com/questions/18616432/read-specific-entry-from-text-file
    int i;
    std::string load;

    int year[50];
    std::string month[50];
    float temp[50];
    float rain[50];
    float wind[50];
    int wdir[50];

    std::ifstream stream("C:/Users/Student/Desktop/weather_sandveld_monthAVG.txt"); // Uni laptop
    //std::ifstream stream("home/jarro/ownCloud/Master/Programming/Parameter_inputweather_sandveld_monthAVG.txt"); // home laptop

    std::cout << "year" << "\t" << "month" << "\t" << "temp" << "\t" << "rain" << "\t" << "wind" << std::endl;

//    std::cout << "ifstream done!" << std::endl;

    std::string dummyLine;
    std::getline( stream, dummyLine ); // Use getLine() for reading first line and then start to read second line

//    std::cout << "getline() done!" << std::endl;
    i=0;

    //while(!stream.eof())//End-of-file
    while (getline(stream, load))
        {
//        std::cout << "inside while()1" << std::endl;
        std::istringstream is(load);


//            std::cout << "ginside while()2" << std::endl;

            is >> year[i] >> month[i] >> temp[i] >> rain[i] >> wind[i] >> wdir[i];
            yearV.push_back(year[i]);
            monthV.push_back(month[i]);
            tempV.push_back(temp[i]);
            rainV.push_back(rain[i]);
            windV.push_back(wind[i]);
            wdirV.push_back(wdir[i]);


            std::cout << year[i] << "\t" << month[i] << "\t" << temp[i] << "\t" << rain[i] << "\t" << wind[i] << std::endl;



//                        std::cout << "ginside while()3" << std::endl;
        }
//    std::cout << "while() done!" << std::endl;
    //std::cout << "size of yearV" << yearV.size() << std::endl;

        stream.close();

}

