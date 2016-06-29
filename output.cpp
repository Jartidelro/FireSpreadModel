#include <iostream>
#include <sstream>
#include <fstream>


#include "output.h"
#include "landscape.h"
#include "fire.h"

Output::Output()
{
}


void Output::countVeggies(const int gridSize, Parameters* parameters, Fire* fire)
{
    // Output summary file:

    std::ofstream summaryFile ("C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/summaryFile.txt");
    summaryFile << "Parameter threshold = " << fire->setParamThreshold << '\n'
                     << "ROS minimum = " << fire->rMIN << '\n'
                     << "Number of patches burnt = " << fire->numberOfBurntPatches << '\n'
                     << "Amount of grid burnt = " << fire->numberOfBurntPatches / gridSize << '\n'
                     << "Number of runs used = " << fire->numberRuns << '\n'
                     << "Number of seconds consumed = " << fire->elapsed_secs;

    summaryFile.close();



//    burnt_annuals = 0;
//    burnt_perennials = 0;
//    burnt_shrubs = 0;

//    // count the burnt annuals after fire-runthrough
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            if (landscape -> landArray[i][j] == 5 && fire -> fireArray[i][j] == 2)
//                burnt_annuals++;
//        }
//    }

//    // count the burnt perennials after fire-runthrough
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            if (landscape -> landArray[i][j] == 6 && fire -> fireArray[i][j] == 2)
//                burnt_perennials++;
//        }
//    }

//    // count the burnt shrubs after fire-runthrough
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            if (landscape -> landArray[i][j] == 7 && fire -> fireArray[i][j] == 2)
//                burnt_shrubs++;
//        }
//    }
}

//void Output::calculateVeggies(Landscape *landscape)
//{
//    fraction_annuals = (float)burnt_annuals / (float)landscape -> num_annuals;
//    fraction_perennials =(float) burnt_perennials / (float)landscape -> num_perennials;
//    fraction_shrubs = (float)burnt_shrubs / (float)landscape -> num_shrubs;
//}

//void Output::outputVeggies(Landscape *landscape)
//{
//    std::cout << "burnt_annuals = " << burnt_annuals << std::endl;
//    std::cout << "burnt_perennials = " << burnt_perennials << std::endl;
//    std::cout << "burnt_shrubs = " << burnt_shrubs << std::endl;

//    std::cout << "num_annuals = " << landscape -> num_annuals << std::endl;
//    std::cout << "num_perennials = " << landscape -> num_perennials << std::endl;
//    std::cout << "num_shrubs = " << landscape -> num_shrubs << std::endl;

//    std::cout << "fraction_annuals = " << fraction_annuals << std::endl;
//    std::cout << "fraction_perennials = " << fraction_perennials << std::endl;
//    std::cout << "fraction_shrubs = " << fraction_shrubs << std::endl;
//}





