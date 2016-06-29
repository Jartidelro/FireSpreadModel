#include "parameters.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Parameters::Parameters()
{
    timeCount = 1;

}


int Parameters::inputGridSize()
{
    std::ifstream gridFile ("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/GridSize.txt"); // Uni laptop
    //ifstream gridFile ("/home/jarro/ownCloud/Master/Programming/Parameter_input/GridSize.txt", ios::in); // home laptop
    if (gridFile.is_open())
    {
        gridFile >> gridSize;
        return gridSize;
    }
    else (std::cout << "File GridSize.txt did not open!");

    std::cout << "The grid size is " << gridSize << std::endl;
}

float Parameters::inputCellSize()
{
    std::ifstream gridFile ("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/CellSize.txt"); // Uni laptop
    //ifstream gridFile ("/home/jarro/ownCloud/Master/Programming/Parameter_input/GridSize.txt", ios::in); // home laptop
    if (gridFile.is_open())
    {
        gridFile >> cellSize;
        return cellSize;
    }
    else (std::cout << "File CellSize.txt did not open!");

    std::cout << "The cell size is " << cellSize << std::endl;
}

void Parameters::inputSeason()
{
    std::ifstream gridFile ("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/Season.txt"); // Uni laptop
    //ifstream gridFile ("/home/jarro/ownCloud/Master/Programming/Parameter_input/Season.txt", ios::in); // home laptop

    if (gridFile.is_open())
    {
        gridFile >> season;
    }
    else (std::cout << "File GridSize.txt did not open!");

    std::cout << "The grid season is " << season << std::endl;
}

void Parameters::GrassFuel::inputVegParamfileGrasses(const float gridSize, const float cellSize)
{
    double value;
    std::string foundIt;
    int fsize = 1000;

    /***wo***/

    std::ifstream streamwoGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/woParameterFileGrass.txt");
    streamwoGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamwoGrass){
        std::cerr << streamwoGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }


    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamwoGrass.ignore(fsize,':');
            streamwoGrass >> value;
        }
        woParameterGridGrass.push_back(value * cellSize);
        }
    }

    streamwoGrass.close();



//    std::cout << "woParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = woParameterGrid.begin(); i != woParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***delta***/

    std::ifstream streamdeltaGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/deltaParameterFileGrass.txt");
    streamdeltaGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamdeltaGrass){
        std::cerr << streamdeltaGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }


    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamdeltaGrass.ignore(fsize,':');
            streamdeltaGrass >> value;
        }
        deltaParameterGridGrass.push_back(value);
        }
    }

    streamdeltaGrass.close();



//    std::cout << "deltaParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = deltaParameterGrid.begin(); i != deltaParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***sigma***/

    std::ifstream streamsigmaGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/sigmaParameterFileGrass.txt");
    streamsigmaGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamsigmaGrass){
        std::cerr << streamsigmaGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamsigmaGrass.ignore(fsize,':');
            streamsigmaGrass >> value;
        }
        sigmaParameterGridGrass.push_back(value);
        }
    }

    streamsigmaGrass.close();

    /***h***/

    std::ifstream streamhGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/hParameterFileGrass.txt");
    streamhGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamhGrass){
        std::cerr << streamhGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {
            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamhGrass.ignore(fsize,':');
            streamhGrass >> value;
        }
        hParameterGridGrass.push_back(value);
        }
    }

    streamhGrass.close();

//    std::cout << "hParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = hParameterGrid.begin(); i != hParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***rhoP***/

    std::ifstream streamrhoPGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/rhoPParameterFileGrass.txt");
    streamrhoPGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamrhoPGrass){
        std::cerr << streamrhoPGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamrhoPGrass.ignore(fsize,':');
            streamrhoPGrass >> value;
        }
        rhoPParameterGridGrass.push_back(value);
        }
    }

    streamrhoPGrass.close();


//    std::cout << "rhoPParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = rhoPParameterGrid.begin(); i != rhoPParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***Mf***/

    std::ifstream streamMfGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/MfParameterFileGrass.txt");
    streamMfGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamMfGrass){
        std::cerr << streamMfGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamMfGrass.ignore(fsize,':');
            streamMfGrass >> value;
        }
        MfParameterGridGrass.push_back(value);
        }
    }

    streamMfGrass.close();

//    std::cout << "MfParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = MfParameterGrid.begin(); i != MfParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***sT***/

    std::ifstream streamsTGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/sTParameterFileGrass.txt");
    streamsTGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamsTGrass){
        std::cerr << streamsTGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamsTGrass.ignore(fsize,':');
            streamsTGrass >> value;
        }
        sTParameterGridGrass.push_back(value);
        }
    }

    streamsTGrass.close();

//    std::cout << "sTParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = sTParameterGrid.begin(); i != sTParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***se***/

    std::ifstream streamseGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/seParameterFileGrass.txt");
    streamseGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamseGrass){
        std::cerr << streamseGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamseGrass.ignore(fsize,':');
            streamseGrass >> value;
        }
        seParameterGridGrass.push_back(value);
        }
    }

    streamseGrass.close();


//    std::cout << "seParameterGrid:" << std::endl;
//    for (std::vector<float>::const_iterator i = seParameterGrid.begin(); i != seParameterGrid.end(); ++i)
//        std::cout << *i << ' ';
//    std::cout << std::endl << std::endl;

    /***Mx***/

    std::ifstream streamMxGrass("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/MxParameterFileGrass.txt");
    streamMxGrass.seekg(0); //position 0

    //if something goes wrong...
    if(!streamMxGrass){
        std::cerr << streamMxGrass
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamMxGrass.ignore(fsize,':');
            streamMxGrass >> value;
        }
        MxParameterGridGrass.push_back(value);
        }
    }

    streamMxGrass.close();


//    /***grassCover***/

//    std::ifstream streamGrassCover("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/grassCoverFile.txt");
//    streamGrassCover.seekg(0); //position 0

//    //if something goes wrong...
//    if(!streamGrassCover){
//        std::cerr << streamGrassCover
//                  << " File containing configuration parameters could not be opened!\n";
//        std::exit(-1);
//    }

//    value = 0;

//    for (int i=0; i<(gridSize*gridSize); i++)
//    {
//        streamGrassCover.ignore(fsize, ':'); //parses until end of file is reached (INT_MAX) OR until next ":" is found (mp, 09.06.2012)
//        streamGrassCover >> value;
//        grassCoverGrid.push_back(value);
//    }

//    streamGrassCover.close();


}


void Parameters::ShrubFuel::inputVegParamfileShrubs(const float gridSize, const float cellSize)
{
    double value;
    std::string foundIt;
    int fsize = 1000;

    /***wo***/

    std::ifstream streamwoShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/woParameterFileShrubs.txt");
    streamwoShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamwoShrubs){
        std::cerr << streamwoShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamwoShrubs.ignore(fsize,':');
            streamwoShrubs >> value;
        }
        woParameterGridShrubs.push_back(value * cellSize);
        }
    }


    streamwoShrubs.close();


    /***delta***/

    std::ifstream streamdeltaShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/deltaParameterFileShrubs.txt");
    streamdeltaShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamdeltaShrubs){
        std::cerr << streamdeltaShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamdeltaShrubs.ignore(fsize,':');
            streamdeltaShrubs >> value;
        }
        deltaParameterGridShrubs.push_back(value);
        }
    }
    streamdeltaShrubs.close();

    /***sigma***/

    std::ifstream streamsigmaShrubs_stem("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/sigmaParameterFileShrubs_stem.txt");
    streamsigmaShrubs_stem.seekg(0); //position 0

    //if something goes wrong...
    if(!streamsigmaShrubs_stem){
        std::cerr << streamsigmaShrubs_stem
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamsigmaShrubs_stem.ignore(fsize,':');
            streamsigmaShrubs_stem >> value;
        }
        sigmaParameterGridShrubs_stem.push_back(value);
        }
    }

    streamsigmaShrubs_stem.close();

    std::ifstream streamsigmaShrubs_branch("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/sigmaParameterFileShrubs_branch.txt");
    streamsigmaShrubs_branch.seekg(0); //position 0

    //if something goes wrong...
    if(!streamsigmaShrubs_branch){
        std::cerr << streamsigmaShrubs_branch
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamsigmaShrubs_branch.ignore(fsize,':');
            streamsigmaShrubs_branch >> value;
        }
        sigmaParameterGridShrubs_branch.push_back(value);
        }
    }

    streamsigmaShrubs_branch.close();

    /***h***/

    std::ifstream streamhShrubs_stem("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/hParameterFileShrubs_stem.txt");
    streamhShrubs_stem.seekg(0); //position 0

    //if something goes wrong...
    if(!streamhShrubs_stem){
        std::cerr << streamhShrubs_stem
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamhShrubs_stem.ignore(fsize,':');
            streamhShrubs_stem >> value;
        }
        hParameterGridShrubs_stem.push_back(value);
        }
    }

    streamhShrubs_stem.close();

    std::ifstream streamhShrubs_branch("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/hParameterFileShrubs_branch.txt");
    streamhShrubs_branch.seekg(0); //position 0

    //if something goes wrong...
    if(!streamhShrubs_branch){
        std::cerr << streamhShrubs_branch
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamhShrubs_branch.ignore(fsize,':');
            streamhShrubs_branch >> value;
        }
        hParameterGridShrubs_branch.push_back(value);
        }
    }

    streamhShrubs_branch.close();

    /***rhoP***/

    std::ifstream streamrhoPShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/rhoPParameterFileShrubs.txt");
    streamrhoPShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamrhoPShrubs){
        std::cerr << streamrhoPShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamrhoPShrubs.ignore(fsize,':');
            streamrhoPShrubs >> value;
        }
        rhoPParameterGridShrubs.push_back(value);
        }
    }

    streamrhoPShrubs.close();


    /***Mf***/

    std::ifstream streamMfShrubs_stem("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/MfParameterFileShrubs_stem.txt");
    streamMfShrubs_stem.seekg(0); //position 0

    //if something goes wrong...
    if(!streamMfShrubs_stem){
        std::cerr << streamMfShrubs_stem
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamMfShrubs_stem.ignore(fsize,':');
            streamMfShrubs_stem >> value;
        }
        MfParameterGridShrubs_stem.push_back(value);
        }
    }

    streamMfShrubs_stem.close();

    std::ifstream streamMfShrubs_branch("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/MfParameterFileShrubs_branch.txt");
    streamMfShrubs_branch.seekg(0); //position 0

    //if something goes wrong...
    if(!streamMfShrubs_branch){
        std::cerr << streamMfShrubs_branch
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamMfShrubs_branch.ignore(fsize,':');
            streamMfShrubs_branch >> value;
        }
        MfParameterGridShrubs_branch.push_back(value);
        }
    }

    streamMfShrubs_branch.close();

    /***sT***/

    std::ifstream streamsTShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/sTParameterFileShrubs.txt");
    streamsTShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamsTShrubs){
        std::cerr << streamsTShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamsTShrubs.ignore(fsize,':');
            streamsTShrubs >> value;
        }
        sTParameterGridShrubs.push_back(value);
        }
    }

    streamsTShrubs.close();

    /***se***/

    std::ifstream streamseShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/seParameterFileShrubs.txt");
    streamseShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamseShrubs){
        std::cerr << streamseShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamseShrubs.ignore(fsize,':');
            streamseShrubs >> value;
        }
        seParameterGridShrubs.push_back(value);
        }
    }

    streamseShrubs.close();

    /***Mx***/

    std::ifstream streamMxShrubs("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/MxParameterFileShrubs.txt");
    streamMxShrubs.seekg(0); //position 0

    //if something goes wrong...
    if(!streamMxShrubs){
        std::cerr << streamMxShrubs
                  << " File containing configuration parameters could not be opened!\n";
        std::exit(-1);
    }

    value = 0;

    for (int i=0; i<(gridSize); i++)
    {
        std::string i_s = std::to_string(i);
        for (int j=0; j<(gridSize); j++)
        {

            std::string j_s = std::to_string(j);
            std::string counter = "[" + i_s + "]" + "[" + j_s + "]:";
        if (foundIt.find(counter) == std::string::npos)
        {
            streamMxShrubs.ignore(fsize,':');
            streamMxShrubs >> value;
        }
        MxParameterGridShrubs.push_back(value);
        }
    }

    streamMxShrubs.close();

//    /***shrubCover***/

//    std::ifstream streamShrubCover("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/grassCoverFile.txt");
//    streamShrubCover.seekg(0); //position 0

//    //if something goes wrong...
//    if(!streamShrubCover){
//        std::cerr << streamShrubCover
//                  << " File containing configuration parameters could not be opened!\n";
//        std::exit(-1);
//    }

//    value = 0;

//    for (int i=0; i<(gridSize*gridSize); i++)
//    {
//        streamShrubCover.ignore(fsize, ':'); //parses until end of file is reached (INT_MAX) OR until next ":" is found (mp, 09.06.2012)
//        streamShrubCover >> value;
//        shrubCoverGrid.push_back(value);
//    }

//    streamShrubCover.close();


    /***shrubCrownVolume***/

    std::string load;

    std::string paramFile1 = "C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/ShrubAlloTraits.txt"; // Uni laptop
    std::ifstream stream(paramFile1);

    if (stream.is_open())
    {
        std::string dummyLine;
        std::getline( stream, dummyLine ); // Use getLine() for reading first line and then start to read second line

        while (getline(stream, load))
        {
            std::istringstream is(load);

            is >> shrubCrownVolumeMIN >> shrubCrownVolumeMAX;

            //std::cout << "ShrubCrownVolumeMIN = " << shrubCrownVolumeMIN << std::endl << "shrubCrownVolumeMAX = " << shrubCrownVolumeMAX << std::endl;
        }

        stream.close();

    }
}

void Parameters::inputLandArray()
{
    std::ifstream landFile ("C:/Users/Student/Desktop/Jarro/Master/Programming/Parameter_input/landArray.txt"); // Uni laptop
    //ifstream gridFile ("/home/jarro/ownCloud/Master/Programming/Parameter_input/GridSize.txt", ios::in); // home laptop
    landFile.seekg(0); //position 0
    if (landFile.is_open())
    {
        int value = 0;
        while (!landFile.eof())
        {
            landFile >> value;
            landArray.push_back(value);

        }
    }
    else (std::cout << "File landArray.txt did not open!");

//    std::cout << "landArray:" << std::endl;
//    int count = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            std::cout << landArray[count] << ' ';
//            count++;
//        }
//        std::cout << "\n";
//    };
//    std::cout << "\n";
}

void Parameters::parameterPointerDelete()
{
    delete shrubFuel;
    delete grassFuel;
}






