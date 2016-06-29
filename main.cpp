#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <direct.h>

#include "fire.h"
#include "landscape.h"
#include "weather.h"
#include "climate.h"
#include "output.h"
#include "parameters.h"




int main()
{
    /** Set a main random seed in the main function (outside of all loops!): **/
    srand(time(0));

    Parameters* parameters = new Parameters(); //1.create a new variable "parameters" with the type "Parameters*", that is, a pointer to an object of type "Parameters"
                                               //2.allocate a new "Parameters" object on the heap
                                               //3.set the "parameters" variable to point to the new "Parameters" object

    Weather* weather = new Weather();

 //   Output* output = new Output();

    const int gridSize = parameters -> inputGridSize();
    std::cout << "gridSize = " << gridSize << std::endl;

    const float cellSize = parameters -> inputCellSize();
    std::cout << "cellSize = " << cellSize << " meter" << std::endl;

    std::cout << "Press ENTER to continue to input parameters." << std::endl;
    std::cin.get();
    std::cout << "Please wait." << std::endl;

    parameters -> inputLandArray();

    std::cout << "Debug 1" << std::endl;

    parameters->grassFuel->inputVegParamfileGrasses(gridSize,cellSize);

    std::cout << "Debug 2" << std::endl;

    parameters->shrubFuel->inputVegParamfileShrubs(gridSize,cellSize);

    std::cout << "Debug 3" << std::endl;

    weather -> wfile_input();


    // The Fire pointers have to be declared after gridSize was initialised:

    mkdir("C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2");

    Fire* fire = new Fire();

    std::cout << "Debug 4" << std::endl;

    fire -> burn(gridSize,cellSize,parameters);


//    /**std::cout << "Continue to output -> outputFireArray." << std::endl;
//    getch();**/

//    output -> outputFireArray(ijmax,fire);
//    output -> fireArrayTXT(ijmax,fire);

    Output* output = new Output();
    output->countVeggies(gridSize,parameters,fire);



    delete weather;
    delete fire;
    delete parameters;
    delete output;


    return 0;
}

