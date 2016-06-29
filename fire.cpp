#include "fire.h"
#include "landscape.h"
#include "climate.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <math.h>
#include <conio.h>
#include <vector>
#include <cfloat>
#include <string>



// Constructor
Fire::Fire() {

    // Set Variables to their null-state:

    //    rMIN = 0.0001;
    //    rMAX = 0.01;

}

// Destructor
Fire::~Fire(){}

int Fire::rand_int(int from, int to)
{
    int help = to-from;
    int i2 = rand() % help;
    i2 += from;
    return i2;
}

//float Fire::rand_float(float from, float to)
//{
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<> dis(from, std::nextafter(to, DBL_MAX));
//    return dis(gen);
//}


/** -------------------------------------------------------------- **/
/** generate arrays of pointer objects                             **/
/** -------------------------------------------------------------- **/

// from: http://stackoverflow.com/questions/10159780/declaring-a-2d-array-of-pointer-objects

void Fire::burn(const int gridSize, const float cellSize, Parameters* parameters)
{
    // fireArray[][] should act as an index for the movement of fire in space.
    Parameters* fireArray[gridSize][gridSize];
    Parameters::GrassFuel* grassParams[gridSize][gridSize];
    Parameters::ShrubFuel* shrubParams[gridSize][gridSize];
    Parameters::ShrubFuel::Branches* branchParams[gridSize][gridSize];
    Parameters::ShrubFuel::Stem* stemParams[gridSize][gridSize];

    std::cout << "Debug 5" << std::endl;

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            fireArray[i][j] = new Parameters();
            grassParams[i][j] = new Parameters::GrassFuel();
            shrubParams[i][j] = new Parameters::ShrubFuel();
            stemParams[i][j] = new Parameters::ShrubFuel::Stem();
            branchParams[i][j] = new Parameters::ShrubFuel::Branches();
        }
    }

    std::cout << "Debug 6" << std::endl;

    int counter = 0;

    parameters->shrubFuel->shrubCrownVolumeMIN = 145.0;
    parameters->shrubFuel->shrubCrownVolumeMAX = 146.0;

    /** -------------------------------------------------------------- **/
    /** input all cell parameters into the new objects                 **/
    /** -------------------------------------------------------------- **/

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            fireArray[i][j]-> pft = parameters -> landArray[counter];
            fireArray[i][j]->burnStatus = 0;
            fireArray[i][j]->timeCount = 1;

            std::cout << "Debug 7" << std::endl;

            // Calculate parameters for grass fuel:
            grassParams[i][j]->woGrass = parameters->grassFuel->woParameterGridGrass[counter];
            std::cout << "grassParams[i][j]->woGrass" << grassParams[i][j]->woGrass << std::endl;

            std::cout << "Debug 8" << std::endl;

            //            std::cout << "TEST ========" << grassParams[i][j]->woGrass << std::endl;
            grassParams[i][j]->deltaGrass = parameters->grassFuel->deltaParameterGridGrass[counter];
            grassParams[i][j]->sigmaGrass = parameters->grassFuel->sigmaParameterGridGrass[counter];
            grassParams[i][j]->hGrass = parameters->grassFuel->hParameterGridGrass[counter];
            grassParams[i][j]->rhoPGrass = parameters->grassFuel->rhoPParameterGridGrass[counter];
            grassParams[i][j]->MfGrass = parameters->grassFuel->MfParameterGridGrass[counter];
            grassParams[i][j]->sTGrass = parameters->grassFuel->sTParameterGridGrass[counter];
            grassParams[i][j]->seGrass = parameters->grassFuel->seParameterGridGrass[counter];
            grassParams[i][j]->MxGrass = parameters->grassFuel->MxParameterGridGrass[counter];
            //            grassParams[i][j]->grassCover = parameters->grassCoverGrid[counter];

            std::cout << "Debug 9" << std::endl;


            std::cout << "[" << i << "]" << "[" << j << "]" << std::endl;
            std::cout << "shrubParams[i][j]->woParameterGridShrubs[counter] = " << parameters->shrubFuel->woParameterGridShrubs[counter] << '\n';
            std::cout << "shrubCrownVolumeMIN = " << parameters->shrubFuel->shrubCrownVolumeMIN << '\n';
            std::cout << "shrubCrownVolumeMAX = " << parameters->shrubFuel->shrubCrownVolumeMAX << '\n';
            std::cout << "shrubCrownVolume = " << shrubParams[i][j]->shrubCrownVolume << '\n';
            std::cout << "shrubCircumference = " << shrubParams[i][j]->shrubCircumference<< '\n';
            std::cout << "shrubBranchyBiomass = " << shrubParams[i][j]->shrubBranchyBiomass << '\n';
            std::cout << "shrubStemBiomass= " << shrubParams[i][j]->shrubStemBiomass<< '\n';

            // calculate parameters for stems:
            //            shrubParams[i][j]->shrubCover = parameters->shrubCoverGrid[counter];
            stemParams[i][j]->woStem = (parameters->shrubFuel->woParameterGridShrubs[counter] - parameters->shrubFuel->shrubBranchyBiomass);
            stemParams[i][j]->deltaStem = parameters->shrubFuel->deltaParameterGridShrubs[counter];
            stemParams[i][j]->sigmaStem = parameters->shrubFuel->sigmaParameterGridShrubs_stem[counter];
            stemParams[i][j]->hStem = parameters->shrubFuel->hParameterGridShrubs_stem[counter];
            stemParams[i][j]->rhoPStem = parameters->shrubFuel->rhoPParameterGridShrubs[counter];
            stemParams[i][j]->MfStem = parameters->shrubFuel->MfParameterGridShrubs_stem[counter];
            stemParams[i][j]->sTStem = parameters->shrubFuel->sTParameterGridShrubs[counter];
            stemParams[i][j]->seStem = parameters->shrubFuel->seParameterGridShrubs[counter];
            stemParams[i][j]->MxStem = parameters->shrubFuel->MxParameterGridShrubs[counter];

            // calculate parameters for branches:
            //            shrubParams[i][j]->shrubCover = parameters->shrubCoverGrid[counter];
            branchParams[i][j]->woBranches = (parameters->shrubFuel->woParameterGridShrubs[counter] - parameters->shrubFuel->shrubStemBiomass);
            branchParams[i][j]->deltaBranches = parameters->shrubFuel->deltaParameterGridShrubs[counter];
            branchParams[i][j]->sigmaBranches = parameters->shrubFuel->sigmaParameterGridShrubs_branch[counter];
            branchParams[i][j]->hBranches = parameters->shrubFuel->hParameterGridShrubs_branch[counter];
            branchParams[i][j]->rhoPBranches = parameters->shrubFuel->rhoPParameterGridShrubs[counter];
            branchParams[i][j]->MfBranches = parameters->shrubFuel->MfParameterGridShrubs_branch[counter];
            branchParams[i][j]->sTBranches = parameters->shrubFuel->sTParameterGridShrubs[counter];
            branchParams[i][j]->seBranches = parameters->shrubFuel->seParameterGridShrubs[counter];
            branchParams[i][j]->MxBranches = parameters->shrubFuel->MxParameterGridShrubs[counter];

            // Calculate weighted average sigma for one heterogeneous cell (using the formulas from Rothermel (1972)):
            // BEWARE of the unit transformations!!!
            fireArray[i][j]->Ai_grass = (grassParams[i][j]->sigmaGrass * (grassParams[i][j]->woGrass * 0.0001)) / (grassParams[i][j]->rhoPGrass * 0.000001);
            fireArray[i][j]->Ai_branch = (branchParams[i][j]->sigmaBranches * (branchParams[i][j]->woBranches * 0.0001)) / (branchParams[i][j]->rhoPBranches * 0.000001);
            fireArray[i][j]->Ai_stem = (stemParams[i][j]->sigmaStem * (stemParams[i][j]->woStem * 0.0001)) / (stemParams[i][j]->rhoPStem * 0.000001);
            fireArray[i][j]->Adead = fireArray[i][j]->Ai_grass + fireArray[i][j]->Ai_branch + fireArray[i][j]->Ai_stem;
            fireArray[i][j]->fi_grass = fireArray[i][j]->Ai_grass / fireArray[i][j]->Adead;
            fireArray[i][j]->fi_branch = fireArray[i][j]->Ai_branch / fireArray[i][j]->Adead;
            fireArray[i][j]->fi_stem = fireArray[i][j]->Ai_stem / fireArray[i][j]->Adead;
            fireArray[i][j]->sigmaDead = (fireArray[i][j]->fi_grass * grassParams[i][j]->sigmaGrass) + (fireArray[i][j]->fi_branch * branchParams[i][j]->sigmaBranches) + (fireArray[i][j]->fi_stem * stemParams[i][j]->sigmaStem);
            fireArray[i][j]->sigmaCell = fireArray[i][j]->Adead * fireArray[i][j]->sigmaDead;

            //            std::cout << "sigmaCell = " << fireArray[i][j]->sigmaCell << std::endl;
            //            std::cout << "Adead = " << fireArray[i][j]->Adead << std::endl;
            //            std::cout << "sigmaDead = " << fireArray[i][j]->sigmaDead << std::endl;
            //            std::cout << "AiGrass = " << fireArray[i][j]->Ai_grass << std::endl;
            //            std::cout << "AiStem = " << fireArray[i][j]->Ai_stem << std::endl;
            //            std::cout << "AiBranch = " << fireArray[i][j]->Ai_branch << std::endl;
            //            std::cout << "fiGrass = " << fireArray[i][j]->fi_grass << std::endl;
            //            std::cout << "fistem = " << fireArray[i][j]->fi_stem << std::endl;
            //            std::cout << "fiBranch = " << fireArray[i][j]->fi_branch << std::endl;
            //            std::cout << "rhoPGrass = " << grassParams[i][j]->rhoPGrass << std::endl;
            //            std::cout << "rhoPStem = " << stemParams[i][j]->rhoPStem << std::endl;
            //            std::cout << "rhoPBranch = " << branchParams[i][j]->rhoPBranches << std::endl;
            //            std::cout << "sigmaGrass = " << grassParams[i][j]->sigmaGrass << std::endl;
            //            std::cout << "sigmaStem = " << stemParams[i][j]->sigmaStem << std::endl;
            //            std::cout << "sigmaBranch = " << branchParams[i][j]->sigmaBranches << std::endl;
            //            std::cout << "woGrass = " << grassParams[i][j]->woGrass << std::endl;
            //            std::cout << "woStem = " << stemParams[i][j]->woStem << std::endl;
            //            std::cout << "woBranch = " << branchParams[i][j]->woBranches << std::endl;



            // Calculate a weighted average Mf and rhoP for one heterogeneous cell (using a standard weighted average relationship):
            fireArray[i][j]->woCell = grassParams[i][j]->woGrass + branchParams[i][j]->woBranches + stemParams[i][j]->woStem;
            fireArray[i][j]->MfCell = ((grassParams[i][j]->MfGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->MfBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->MfStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->rhoPCell = ((grassParams[i][j]->rhoPGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->rhoPBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->rhoPStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->deltaCell = ((grassParams[i][j]->deltaGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->deltaBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->deltaStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->hCell = ((grassParams[i][j]->hGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->hBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->hStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->sTCell = ((grassParams[i][j]->sTGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->sTBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->sTStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->seCell = ((grassParams[i][j]->seGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->seBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->seStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;
            fireArray[i][j]->MxCell = ((grassParams[i][j]->MxGrass * grassParams[i][j]->woGrass / fireArray[i][j]->woCell) + (branchParams[i][j]->MxBranches * branchParams[i][j]->woBranches / fireArray[i][j]->woCell) + (stemParams[i][j]->MxStem * stemParams[i][j]->woStem / fireArray[i][j]->woCell)) / 3;



            counter++;
        }
    }


    std::cout << "Press ENTER to calculate ROS for each cell." << std::endl;
    std::cin.get();
    std::cout << "Please wait." << std::endl;


    /** -------------------------------------------------------------- **/
    /** calculate the ROS for each cell                                **/
    /** -------------------------------------------------------------- **/


    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (fireArray[i][j]->pft != 4)
            {
                // 1. calculate ovendry bulk density:
                fireArray[i][j]->rhoB = fireArray[i][j]->woCell / fireArray[i][j]->deltaCell;
                //                std::cout << "TEST rhoB ========" << fireArray[i][j]->rhoB << std::endl;

                // 2. calculate effective heating number:
                fireArray[i][j]->epsilon = exp (-4.528 / fireArray[i][j]->sigmaCell);
                //                std::cout << "TEST epsilon ========" << fireArray[i][j]->epsilon << std::endl;

                // 3. calculate heat of preignition:
                fireArray[i][j]->Qig = 581 + 2594 * fireArray[i][j]->MfCell;
                //                std::cout << "TEST Qig ========" << fireArray[i][j]->Qig << std::endl;

                // 4. calculate net fuel loading:
                fireArray[i][j]->wn = fireArray[i][j]->woCell * (1 - fireArray[i][j]->sTCell);
                //                std::cout << "TEST wn ========" << fireArray[i][j]->wn << std::endl;

                // 5. calculate packing ratio:
                fireArray[i][j]->beta = fireArray[i][j]->rhoB / fireArray[i][j]->rhoPCell;
                //                std::cout << "TEST beta ========" << fireArray[i][j]->beta << std::endl;

                // 6. optimum packing ratio:
                fireArray[i][j]->betaOP = 0.20395 * pow (fireArray[i][j]->sigmaCell, -0.8189);
                //                std::cout << "TEST betaOP ========" << fireArray[i][j]->betaOP << std::endl;

                // 7. calc B:
                fireArray[i][j]->B = 0.15988 * pow (fireArray[i][j]->sigmaCell, 0.54);
                //                std::cout << "TEST B ========" << fireArray[i][j]->B << std::endl;

                // 8. calculate C:
                fireArray[i][j]->C = 7.47 * exp(-0.8711 * pow (fireArray[i][j]->sigmaCell, 0.54));
                //               std::cout << "TEST C ========" << fireArray[i][j]->C << std::endl;

                // 9. calculate mineral damping coefficient:
                fireArray[i][j]->etaS = 0.174 * pow (fireArray[i][j]->seCell, -0.19);
                if (fireArray[i][j]->etaS > 1)
                    fireArray[i][j]->etaS = 1;
                //               std::cout << "TEST etaS ========" << fireArray[i][j]->etaS << std::endl;

                // 10. calculate moisture damping coefficient:
                fireArray[i][j]->etaM = 1 - 2.59 * (fireArray[i][j]->MfCell / fireArray[i][j]->MxCell) + 5.11 * pow ((fireArray[i][j]->MfCell / fireArray[i][j]->MxCell), 2) - 3.52 * pow ((fireArray[i][j]->MfCell / fireArray[i][j]->MxCell), 3);
                //                std::cout << "TEST etaM ========" << fireArray[i][j]->etaM << std::endl;

                // 11. calculate A:
                fireArray[i][j]->A = 8.9033 * pow (fireArray[i][j]->sigmaCell, -0.7913);
                //                std::cout << "TEST A ========" << fireArray[i][j]->A << std::endl;

                // 12. calculate E:
                fireArray[i][j]->E = 0.715 * exp (-0.01094 * fireArray[i][j]->sigmaCell);
                //                std::cout << "TEST E ========" << fireArray[i][j]->E << std::endl;

                // 13. calculate maximum reaction velocity:
                fireArray[i][j]->Tmax = pow ((0.0591 + 2.926 * pow (fireArray[i][j]->sigmaCell, -1.5)), -1);
                //                std::cout << "TEST Tmax ========" << fireArray[i][j]->Tmax << std::endl;

                // 14. calculate optimum reaction velocity:
                fireArray[i][j]->T = fireArray[i][j]->Tmax * pow (((fireArray[i][j]->beta / fireArray[i][j]->betaOP) * exp (1 - fireArray[i][j]->beta / fireArray[i][j]->betaOP)), fireArray[i][j]->A); // pow is the C++ exponent
                //                std::cout << "TEST T ========" << fireArray[i][j]->T << std::endl;

                // 15. calculate reaction intensity:
                fireArray[i][j]->IR = fireArray[i][j]->T * fireArray[i][j]->wn * fireArray[i][j]->hCell * fireArray[i][j]->etaM * fireArray[i][j]->etaS;
                //                std::cout << "TEST IR ========" << fireArray[i][j]->IR << std::endl;

                // 16. calculate propagation flux ratio:
                fireArray[i][j]->xi = pow ((192 + 7.9095 * fireArray[i][j]->sigmaCell), -1) * exp ((0.792 + 3.7597 * pow (fireArray[i][j]->sigmaCell, 0.5)) * (fireArray[i][j]->beta + 0.1));
                //                std::cout << "TEST xi ========" << fireArray[i][j]->xi << std::endl;

                // 17. calculate wind coefficient:
                /** Check this rule again for metric conversion!!!!!!!!!!!!! **/
                if (fireArray[i][j]->U > (pow (fireArray[i][j]->IR,(1/3)) * 96.81))
                    fireArray[i][j]->U = 96.81 * pow (fireArray[i][j]->IR,float(1/3));
                fireArray[i][j]->phiW = fireArray[i][j]->C * pow (3.281 * fireArray[i][j]->U, fireArray[i][j]->B) * pow ((fireArray[i][j]->beta / fireArray[i][j]->betaOP), -(fireArray[i][j]->E));
                //                std::cout << "TEST U ========" << fireArray[i][j]->U << std::endl;
                //                std::cout << "TEST phiW========" << fireArray[i][j]->phiW << std::endl;

                // 18. calculate slope coefficient:
                fireArray[i][j]->phiS = 5.275 * pow (fireArray[i][j]->beta, -0.3) * pow (fireArray[i][j]->tanPhi, 2);
                //                std::cout << "TEST phiS ========" << fireArray[i][j]->phiS << std::endl;

                // 19. calculate spread rate:
                if ((fireArray[i][j]->rhoB * fireArray[i][j]->epsilon * fireArray[i][j]->Qig) != 0)
                    fireArray[i][j]->R = (fireArray[i][j]->IR * fireArray[i][j]->xi * (1 + fireArray[i][j]->phiW + fireArray[i][j]->phiS)) / (fireArray[i][j]->rhoB * fireArray[i][j]->epsilon * fireArray[i][j]->Qig);
                else (fireArray[i][j]->R = 0);

                // 20. calculate fire intensity:
                fireArray[i][j]->IB = float(1.f/60.f) * fireArray[i][j]->IR * fireArray[i][j]->R * 12.6 / fireArray[i][j]->sigmaCell;

                // 21. calculate flame length:
                fireArray[i][j]->Lf = 0.0775 * pow (fireArray[i][j]->IB, 0.46);
            }
            else
            {
                fireArray[i][j]->R = 0;
                fireArray[i][j]->IB = 0;
                fireArray[i][j]->Lf = 0;

                fireArray[i][j]->rhoB = 0;
                fireArray[i][j]->epsilon = 0;
                fireArray[i][j]->Qig = 0;
                fireArray[i][j]->wn = 0;
                fireArray[i][j]->beta = 0;
                fireArray[i][j]->betaOP = 0;
                fireArray[i][j]->B = 0;
                fireArray[i][j]->C = 0;
                fireArray[i][j]->A = 0;
                fireArray[i][j]->etaS = 0;
                fireArray[i][j]->etaM = 0;
                fireArray[i][j]->E = 0;
                fireArray[i][j]->Tmax = 0;
                fireArray[i][j]->T = 0;
                fireArray[i][j]->IR = 0;
                fireArray[i][j]->xi = 0;

                if (fireArray[i][j]->U > (pow (fireArray[i][j]->IR,(1/3)) * 96.81))
                    fireArray[i][j]->U = 96.81 * pow (fireArray[i][j]->IR,(1.f/3.f));
                fireArray[i][j]->phiW = fireArray[i][j]->C * pow (3.281 * fireArray[i][j]->U, fireArray[i][j]->B) * pow ((fireArray[i][j]->beta / fireArray[i][j]->betaOP), -(fireArray[i][j]->E));

                fireArray[i][j]->phiS = 5.275 * pow (fireArray[i][j]->beta, -0.3) * pow (fireArray[i][j]->tanPhi, 2);
            }

        }
    }




    std::cout << "Press ENTER to calculate the maximum timestep." << std::endl << std::endl;
    std::cin.get();
    std::cout << "Please wait." << std::endl;


    /** -------------------------------------------------------------- **/
    /** calculate maximum timestep                                     **/
    /** -------------------------------------------------------------- **/


    // Calculate maximum ROS:
    // Die höchste R gibt an wie klein die Zeitschritte gewählt werden müssen.
    float maxROS = fireArray[0][0]->R;
    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (fireArray[i][j]->R > maxROS)
                maxROS = fireArray[i][j]->R;
            //            std::cout << "maxROS = " << maxROS << std::endl;

        }

    }

    // Recalculate ROS for all cells according to maximum timestep:
    // ROS are multiplied by 1/maxROS
    // Also divide by 6 so that the ROS is now calculated in 10sec batches, so as to have less "ROS-overshoot" for each cell:

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            fireArray[i][j]->Radj = (fireArray[i][j]->R / maxROS) / 6;
        }
    }

    std::cout << "Maximum ROS = " << maxROS << std::endl;

    // Write output file for new adjusted ROS:
    std::ofstream RadjOutput("C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/RadjOutput.txt");
    RadjOutput << "Grid Cell" << "\t" << "Radj" << "\n";

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            RadjOutput << "[" << i << "]" << "[" << j << "]:" << "\t" << fireArray[i][j]->Radj << "\n";
        }
    }
    RadjOutput.close();


    std::cout << "Press Enter to start ignition process." << std::endl;
    std::cin.get();


    /** -------------------------------------------------------------- **/
    /** start ignition process                                         **/
    /** -------------------------------------------------------------- **/

    //if fire is slower than 1mm/min it's underneath the logical threshold
    /////////////////////
                     ////
    rMIN = 0.001;    ////
    rMAX = 0.1;      ////
                     ////
    /////////////////////

    // determine if ignition is possible through the ROS threshold:
    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if(fireArray[i][j]->R <= rMIN)
            {
                fireArray[i][j]->ignitionPossible = false;
            }

            // also set all bare cells to false:
            if(fireArray[i][j]->Radj == 0)
            {
                fireArray[i][j]->ignitionPossible = false;
            }
        }
    }


    // ignition:
    /** WARNING:with these adjustments ignition will always happen!**/
    int ipos = rand_int(0,gridSize);
    int jpos = rand_int(0,gridSize);

    while (fireArray[ipos][jpos]->ignitionPossible == false)
    {
        ipos = rand_int(0,gridSize);
        jpos = rand_int(0,gridSize);
    }
    if (fireArray[ipos][jpos]->ignitionPossible == true)
    {
        fireArray[ipos][jpos]->burnStatus = 1;
    }



    /** -------------------------------------------------------------- **/
    /** burn algorithm                                                 **/
    /** -------------------------------------------------------------- **/

    // Create a temporary fireArray to ensure simultanious update of burnStatus:
    Parameters* tempFireArray[gridSize][gridSize];

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            tempFireArray[i][j] = new Parameters();
            tempFireArray[i][j]->burnStatus	= fireArray[i][j]->burnStatus;
            tempFireArray[i][j]->timeCount = fireArray[i][j]->timeCount;
        }
    }




    burntPatches = 0;
    burntPatches_temp = 0;
    elapsed_secs = 0;
    numberOfBurntPatches = 0;


    std::cout << "Press ENTER to go to burn-cycle." << std::endl << std::endl;
    std::cin.get();
    std::cout << "Please wait." << std::endl;


    // record used time (from: http://stackoverflow.com/questions/2808398/easily-measure-elapsed-time):
    std::clock_t begin = std::clock();

    /** set the variable parameter threshold: **/
    /////////////////////////////////////////////////////////////////
    setParamThreshold = 0.0;                                     ////
    for (int i = 0; i< gridSize; i++)                            ////
    {                                                            ////
        for (int j = 0; j < gridSize; j++)                       ////
        {                                                        ////
            if(fireArray[i][j]->woCell <= setParamThreshold)     ////
            {                                                    ////
                fireArray[i][j]->parameterFireThreshold = true;  ////
            }                                                    ////
        }                                                        ////
    }                                                            ////
    /////////////////////////////////////////////////////////////////


    numberRuns = 0;


    //        while(std::cin.get()=='\n')
    //        {
    do
    {
        burningPatches = 0;
        burntPatches = 0;

        for (int i = 0; i< gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                // if a cell is burning continue:
                if (fireArray[i][j]->burnStatus == 1)
                {

                    /** -------------------------------------------------------------- **/
                    /** start to check the neighbours                                  **/
                    /** -------------------------------------------------------------- **/


                    // neighbour topleft:
                    if (((cellSize * sqrt(2)) / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i-1)>=0 && (j-1)>=0)
                    {
                        if (fireArray[i-1][j-1]->parameterFireThreshold == false
                                && fireArray[i-1][j-1]->burnStatus == 0
                                && fireArray[i-1][j-1]->ignitionPossible == true)
                        {
                            tempFireArray[i-1][j-1]->burnStatus = 1;
                        }
                        else if (fireArray[i-1][j-1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i-1][j-1]->R)
                            {
                                tempFireArray[i-1][j-1]->burnStatus = 1;
                                tempFireArray[i-1][j-1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour top:
                    if ((cellSize / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i-1)>=0)
                    {
                        if (fireArray[i-1][j]->parameterFireThreshold == false
                                && fireArray[i-1][j]->burnStatus == 0
                                && fireArray[i-1][j]->ignitionPossible == true)
                        {
                            tempFireArray[i-1][j]->burnStatus = 1;
                        }
                        else if (fireArray[i-1][j]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i-1][j]->R)
                            {
                                tempFireArray[i-1][j]->burnStatus = 1;
                                tempFireArray[i-1][j]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour topright:
                    if (((cellSize * sqrt(2)) / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i-1)>=0 && (j+1)<gridSize)
                    {
                        if (fireArray[i-1][j+1]->parameterFireThreshold == false
                                && fireArray[i-1][j+1]->burnStatus == 0
                                && fireArray[i-1][j+1]->ignitionPossible == true)
                        {
                            tempFireArray[i-1][j+1]->burnStatus = 1;
                        }
                        else if (fireArray[i-1][j+1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i-1][j+1]->R)
                            {
                                tempFireArray[i-1][j+1]->burnStatus = 1;
                                tempFireArray[i-1][j+1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour right:
                    if ((cellSize / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (j+1)<gridSize)
                    {
                        if (fireArray[i][j+1]->parameterFireThreshold == false
                                && fireArray[i][j+1]->burnStatus == 0
                                && fireArray[i][j+1]->ignitionPossible == true)
                        {
                            tempFireArray[i][j+1]->burnStatus = 1;
                        }
                        else if (fireArray[i][j+1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i][j+1]->R)
                            {
                                tempFireArray[i][j+1]->burnStatus = 1;
                                tempFireArray[i][j+1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour bottomright:
                    if (((cellSize * sqrt(2)) / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i+1)<gridSize && (j+1)<gridSize)
                    {
                        if (fireArray[i+1][j+1]->parameterFireThreshold == false
                                && fireArray[i+1][j+1]->burnStatus == 0
                                && fireArray[i+1][j+1]->ignitionPossible == true)
                        {
                            tempFireArray[i+1][j+1]->burnStatus = 1;
                        }
                        else if (fireArray[i+1][j+1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i+1][j+1]->R)
                            {
                                tempFireArray[i+1][j+1]->burnStatus = 1;
                                tempFireArray[i+1][j+1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour bottom:
                    if ((cellSize / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i+1)<gridSize)
                    {
                        if (fireArray[i+1][j]->parameterFireThreshold == false
                                && fireArray[i+1][j]->burnStatus == 0
                                && fireArray[i+1][j]->ignitionPossible  == true)
                        {
                            tempFireArray[i+1][j]->burnStatus = 1;
                        }
                        else if (fireArray[i+1][j]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i+1][j]->R)
                            {
                                tempFireArray[i+1][j]->burnStatus = 1;
                                tempFireArray[i+1][j]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour bottomleft:
                    if (((cellSize * sqrt(2)) / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (i+1)<gridSize && (j-1)>=0)
                    {
                        if (fireArray[i+1][j-1]->parameterFireThreshold == false
                                && fireArray[i+1][j-1]->burnStatus == 0
                                && fireArray[i+1][j-1]->ignitionPossible == true)
                        {
                            tempFireArray[i+1][j-1]->burnStatus = 1;
                        }
                        else if (fireArray[i+1][j-1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i+1][j-1]->R)
                            {
                                tempFireArray[i+1][j-1]->burnStatus = 1;
                                tempFireArray[i+1][j-1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    // neighbour left:
                    if ((cellSize / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) >= 1 && (j-1)>=0)
                    {
                        if (fireArray[i][j-1]->parameterFireThreshold == false
                                && fireArray[i][j-1]->burnStatus == 0
                                && fireArray[i][j-1]->ignitionPossible == true)
                        {
                            tempFireArray[i][j-1]->burnStatus = 1;
                        }
                        else if (fireArray[i][j-1]->parameterFireThreshold == true)
                        {
                            if (rMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(rMAX-rMIN))) < fireArray[i][j-1]->R)
                            {
                                tempFireArray[i][j-1]->burnStatus = 1;
                                tempFireArray[i][j-1]->parameterFireThreshold = false;
                            }
                        }
                    }

                    /** -------------------------------------------------------------- **/
                    /** update all counters and tempArrays                             **/
                    /** -------------------------------------------------------------- **/

                    // Add one timestep to the cell-counter if the cell has been in burning this round:
                    if(fireArray[i][j]->burnStatus == 1)
                    {
                        tempFireArray[i][j]->timeCount = tempFireArray[i][j]->timeCount + 1;
                    }

                    // A cell is burned out after the fire reaches its border:
                    if ((cellSize / (fireArray[i][j]->Radj * fireArray[i][j]->timeCount)) <= 1 && fireArray[i][j]->Radj != 0)
                        tempFireArray[i][j]->burnStatus = 2;

                    // Set the burningPatches-counter for this round:
                    if (tempFireArray[i][j]->burnStatus == 1)
                        burningPatches++;

                    // Set the burntPatches-counter for this round:
                    if (fireArray[i][j]->burnStatus == 2)
                        burntPatches++;

                }
            }
        }

        // Overwrite fireArray with tempFireArray for this round:
        for (int i = 0; i< gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                fireArray[i][j]->burnStatus = tempFireArray[i][j]->burnStatus;
                fireArray[i][j]->timeCount = tempFireArray[i][j]->timeCount;
            }
        }


        //  }

        // count the number of seconds used for the model:
        std::clock_t end = std::clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        // Add +1 to the number of runs the burn-algorithm is already running through:
        numberRuns++;

        /** -------------------------------------------------------------- **/
        /** write fireArray files                                          **/
        /** -------------------------------------------------------------- **/

        // output only every 10th run:
        if (numberRuns <=1000000 && numberRuns%100 == 0)
        {
            std::string outfile_name = "C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/fireArray" + std::to_string(numberRuns) + ".txt";

            std::ofstream outfile (outfile_name);
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    outfile << fireArray[i][j]->burnStatus << ' ';
                }
                outfile << "\n";
            };
            outfile << "\n";
            outfile.close();
        }

        burntPatches_temp = burntPatches;

    } while (burningPatches > 0); // only continue in the loop if any currently burning patches are left
    //        }

    // Count the overall number of burnt patches:
    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (fireArray[i][j]->burnStatus == 2)
                numberOfBurntPatches++;
        }
    }

    /** -------------------------------------------------------------- **/
    /** write parameter files for analysis                             **/
    /** -------------------------------------------------------------- **/

    std::ofstream parameterOutput("C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/parameterOutput.txt");
    parameterOutput << "Grid Cell" << "\t"
                    << "ROS" << "\t"
                    << "IB" << "\t"
                    << "Lf" << "\t"
                    << "Burnt" << "\t"
                    << "wo" << "\t"
                    << "delta" << "\t"
                    << "sigma" << "\t"
                    << "h" << "\t"
                    << "rhoP" << "\t"
                    << "Mf" << "\t"
                    << "Mx" << "\t"
                    << "sT" << "\t"
                    << "se" << "\t"
                    << "IR" << "\t"
                    << "T" << "\t"
                    << "Tmax" << "\t"
                    << "betaOP" << "\t"
                    << "A" << "\t"
                    << "etaM" << "\t"
                    << "etaS" << "\t"
                    << "xi" << "\t"
                    << "C" << "\t"
                    << "B" << "\t"
                    << "E" << "\t"
                    << "wn" << "\t"
                    << "rhoB" << "\t"
                    << "epsilon" << "\t"
                    << "Qig" << "\t"
                    << "beta" << "\t"
                    << "phiW" << "\t"
                    << "phiS" << "\n";

    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            parameterOutput << "[" << i << "]" << "[" << j << "]:" << "\t"
                            << fireArray[i][j]->R << "\t"
                            << fireArray[i][j]->IB << "\t"
                            << fireArray[i][j]->Lf << "\t"
                            << fireArray[i][j]->burnStatus << "\t"
                            << fireArray[i][j]->woCell << "\t"
                            << fireArray[i][j]->deltaCell << "\t"
                            << fireArray[i][j]->sigmaCell << "\t"
                            << fireArray[i][j]->hCell << "\t"
                            << fireArray[i][j]->rhoPCell << "\t"
                            << fireArray[i][j]->MfCell << "\t"
                            << fireArray[i][j]->MxCell << "\t"
                            <<fireArray[i][j]->sTCell << "\t"
                           << fireArray[i][j]->seCell << "\t"
                           << fireArray[i][j]->IR << "\t"
                           << fireArray[i][j]->T << "\t"
                           << fireArray[i][j]->Tmax << "\t"
                           << fireArray[i][j]->betaOP << "\t"
                           << fireArray[i][j]->A << "\t"
                           << fireArray[i][j]->etaM << "\t"
                           << fireArray[i][j]->etaS << "\t"
                           << fireArray[i][j]->xi << "\t"
                           << fireArray[i][j]->C << "\t"
                           << fireArray[i][j]->B << "\t"
                           << fireArray[i][j]->E << "\t"
                           << fireArray[i][j]->wn << "\t"
                           << fireArray[i][j]->rhoB << "\t"
                           << fireArray[i][j]->epsilon << "\t"
                           << fireArray[i][j]->Qig << "\t"
                           << fireArray[i][j]->beta << "\t"
                           << fireArray[i][j]->phiW << "\t"
                           << fireArray[i][j]->phiS << "\n";
        }
    }
    parameterOutput.close();

    // output the last fireArray->burnStatus, after the while-loop (burn algorithm) has been terminated
    std::string outfileLAST_name = "C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/fireArrayLAST.txt";
    std::ofstream outfileLAST (outfileLAST_name);
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            outfileLAST << fireArray[i][j]->burnStatus << ' ';
        }
        outfileLAST << "\n";
    };
    outfileLAST << "\n";
    outfileLAST.close();


    // output of percentage shrub/grass array:
    std::string outfileGrassArray = "C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/grassArray.txt";
    std::ofstream outfileGrass (outfileGrassArray);
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (grassParams[i][j]->woGrass > 0)
            {
                outfileGrass << (grassParams[i][j]->woGrass / fireArray[i][j]->woCell) << ' ';
            }
            else
            {
                outfileGrass << 0 << ' ';
            }
        }
        outfileGrass << "\n";
    };
    outfileGrass << "\n";
    outfileGrass.close();

    std::string outfileShrubsArray = "C:/Users/Student/Desktop/Jarro/Master/Programming/Model_results/TEST2/shrubsArray.txt";
    std::ofstream outfileShrubs (outfileShrubsArray);
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if ((stemParams[i][j]->woStem + branchParams[i][j]->woBranches) > 0)
            {
                outfileShrubs << ((stemParams[i][j]->woStem + branchParams[i][j]->woBranches) / fireArray[i][j]->woCell) << ' ';
            }

            else
            {
                outfileShrubs << 0 << ' ';
            }
        }
        outfileShrubs << "\n";
    };
    outfileShrubs << "\n";
    outfileShrubs.close();


    /** -------------------------------------------------------------- **/
    /** deleete all objects                                            **/
    /** -------------------------------------------------------------- **/


    // Delete all objects:
    for (int i = 0; i< gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            delete fireArray[i][j];
            delete tempFireArray[i][j];
            delete grassParams[i][j];
            delete shrubParams[i][j];
            delete stemParams[i][j];
            delete branchParams[i][j];
        }
    }

}




