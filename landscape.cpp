//#include "landscape.h"
//#include "climate.h"
//#include "parameters.h"

//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <random>
//#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
//#include <vector>
//#include <sstream>
//#include <conio.h>


///** Create a constructor:****************************/
///* - a constructor is a function that gets called automatically as soon as you create an object
//     * - main reason for constructor: give variables an initial value
//     * - constructors never return values (return type), they simply initialise the object
//     * - the constructor always has the same name as the class it's in */
//Landscape::Landscape(const int ijmax){
//    num_vegfree = ijmax*ijmax*5/100;
//    num_annuals = ijmax*ijmax*35/100;
//    num_perennials = ijmax*ijmax*35/100;
//    num_shrubs = ijmax*ijmax*25/100;

//    aggregation_annuals = 98;
//    aggregation_perennials = 98;
//    aggregation_shrubs = 98;
//    patchNum_annuals = ijmax;
//    patchNum_perennials = ijmax;
//    patchNum_shrubs = ijmax;



//}

///** Destructor**************************************/
//Landscape::~Landscape() {}

//// random number generator:
//int Landscape::rand_int(int from, int to)
//{
//    /*std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distr(from, to);
//    std::cout << "Random number!! " << distr(gen) << std::endl;
//    //return distr(gen);*/

//    int help = to-from;
//    int i2 = rand() % help;
//    i2 += from;
//    return i2;
//}


//// Landscape functions:
//void Landscape::initialise(const int ijmax)
//{
//    /**std::cout << "Starting in initialise. Press to continue to landArray." << "\n";
//    getch();**/

//    // A dynamic 2D array is basically an array of pointers to arrays. You should initialize it using a loop, like this:
//    // (from: http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new)
//    landArray = new int*[ijmax];
//    for(int i=0; i<ijmax; i++)
//    {
//        landArray[i] = new int[ijmax];
//    }

//    /**std::cout << "dynamic landArray initialised. press to continue to landarray(i)(j) = 0." << "\n";
//    getch();**/

//    int ipos, jpos;

//    /** initialise the plant-type landscape: **/

//    for (int i = 0; i < ijmax; i++)
//    {
//        for (int j = 0; j < ijmax; j++)
//        {
//            landArray [i][j] = 0;
//        }
//    }

//    /**std::cout << "landArray initialised to 0. press to continue." << "\n";
//    getch();**/

//    // Set a few random positions on grid to 4 (no vegetation):

//    for (int i = 0; i < num_vegfree; i++)
//    {

//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);

//        if (landArray[ipos][jpos] == 0)
//        {
//            landArray[ipos][jpos] = 4;
//        }
//        else
//        {
//            while (landArray[ipos][jpos] != 0)
//            {
//                ipos = rand_int(0,ijmax);
//                jpos = rand_int(0,ijmax);
//            }
//            landArray[ipos][jpos] = 4;
//        }
//    }

//    /**std::cout << "landArray bare patches initialised. press to continue." << "\n";
//    getch();**/

//    // if the landArray-cell is burnable set the vegtypeArray randomly to "annual", "perennial" or "shrub"
//    //  annual = 5
//    //  perennial = 6
//    //  shrub = 7

//    /** First set cluster-patches for all vegtypes:*********************/

//    // annuals:
//    for (int i = 0; i < patchNum_annuals; i++)
//    {
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);

//        if (landArray[ipos][jpos] == 0)
//        {
//            landArray[ipos][jpos] = 5;
//        }
//        else
//        {
//            while (landArray[ipos][jpos] != 0)
//            {
//                ipos = rand_int(0,ijmax);
//                jpos = rand_int(0,ijmax);
//            }
//            landArray[ipos][jpos] = 5;
//        }
//    }

//    /**std::cout << "cluster-patches annuals initialised. press to continue." << "\n";
//    getch();**/

//    // perennials:


//    // shrubs:


//    /** Cluster randomly some% of the annuals around cluster-patches: ******************/

//    int i_annuals = 0;
//    while (i_annuals < (num_annuals - patchNum_annuals))
//    {
//        // std::cout << "i_annuals" << i_annuals << std::endl;
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);
//        int aggregate = rand_int(0,100);

//        if (landArray[ipos][jpos] == 0)
//        {
//            if ((jpos-1) >= 0 && landArray[ipos][jpos-1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue; // continue jumps back to the beginning of the loop
//            }
//            if ((ipos+1) < ijmax && (jpos-1) >= 0 && landArray[ipos+1][jpos-1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && landArray[ipos+1][jpos] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && (jpos+1) < ijmax && landArray[ipos+1][jpos+1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((jpos+1) < ijmax && landArray[ipos][jpos+1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos+1) < ijmax && landArray[ipos-1][jpos+1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && landArray[ipos-1][jpos] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos-1) >= 0 && landArray[ipos-1][jpos-1] == 5)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//        }

//        if (landArray[ipos][jpos] == 0)
//        {
//            if (aggregate > aggregation_annuals)
//            {
//                landArray[ipos][jpos] = 5;
//                i_annuals++;
//                continue;
//            }
//        }
//    }

//    /**std::cout << "annuals distributed. press to continue." << "\n";
//    getch();**/

//    /** Set and cluster randomly some% of the cells to 6 (perennials): **************************/

//    for (int i = 0; i < patchNum_perennials; i++)
//    {
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);

//        if (landArray[ipos][jpos] == 0)
//        {
//            landArray[ipos][jpos] = 6;
//        }
//        else
//        {
//            while (landArray[ipos][jpos] != 0)
//            {
//                ipos = rand_int(0,ijmax);
//                jpos = rand_int(0,ijmax);
//            }
//            landArray[ipos][jpos] = 6;
//        }
//    }

//    /**std::cout << "cluster-patches perennials initialised. press to continue." << "\n";
//    getch();**/

//    int i_perennials = 0;
//    while (i_perennials < (num_perennials - patchNum_perennials))
//    {
//        // std::cout << "i_perennials" << i_perennials << std::endl;
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);
//        int aggregate = rand_int(0,100);

//        if (landArray[ipos][jpos] == 0)
//        {
//            if ((jpos-1) >= 0 && landArray[ipos][jpos-1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue; // continue jumps back to the beginning of the loop
//            }
//            if ((ipos+1) < ijmax && (jpos-1) >= 0 && landArray[ipos+1][jpos-1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && landArray[ipos+1][jpos] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && (jpos+1) < ijmax && landArray[ipos+1][jpos+1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((jpos+1) < ijmax && landArray[ipos][jpos+1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos+1) < ijmax && landArray[ipos-1][jpos+1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && landArray[ipos-1][jpos] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos-1) >= 0 && landArray[ipos-1][jpos-1] == 6)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//        }

//        if (landArray[ipos][jpos] == 0)
//        {
//            if (aggregate > aggregation_perennials)
//            {
//                landArray[ipos][jpos] = 6;
//                i_perennials++;
//                continue;
//            }
//        }
//    }

//    /**std::cout << "perennials distributed. press to continue." << "\n";
//    getch();**/

//    /** Set and cluster randomly some% of the cells to 7 (shrubs): ***********************************/

//    for (int i = 0; i < patchNum_shrubs; i++)
//    {
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);

//        if (landArray[ipos][jpos] == 0)
//        {
//            landArray[ipos][jpos] = 7;
//        }
//        else
//        {
//            while (landArray[ipos][jpos] != 0)
//            {
//                ipos = rand_int(0,ijmax);
//                jpos = rand_int(0,ijmax);
//            }
//            landArray[ipos][jpos] = 7;
//        }
//    }

//    /**std::cout << "cluster-patches shrubs initialised. press to continue." << "\n";
//    getch();**/

//    int i_shrubs = 0;
//    while (i_shrubs < (num_shrubs-patchNum_shrubs))
//    {
//        // std::cout << "i_shrubs" << i_shrubs << std::endl;
//        ipos = rand_int(0,ijmax);
//        jpos = rand_int(0,ijmax);
//        int aggregate = rand_int(0,100);

//        if (landArray[ipos][jpos] == 0)
//        {
//            if ((jpos-1) >= 0 && landArray[ipos][jpos-1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue; // continue jumps back to the beginning of the loop
//            }
//            if ((ipos+1) < ijmax && (jpos-1) >= 0 && landArray[ipos+1][jpos-1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && landArray[ipos+1][jpos] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((ipos+1) < ijmax && (jpos+1) < ijmax && landArray[ipos+1][jpos+1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((jpos+1) < ijmax && landArray[ipos][jpos+1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos+1) < ijmax && landArray[ipos-1][jpos+1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && landArray[ipos-1][jpos] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//            if ((ipos-1) >= 0 && (jpos-1) >= 0 && landArray[ipos-1][jpos-1] == 7)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//        }



//        if (landArray[ipos][jpos] == 0)
//        {

//            if (aggregate > aggregation_shrubs)
//            {
//                landArray[ipos][jpos] = 7;
//                i_shrubs++;
//                continue;
//            }
//        }
//    }

//    /**std::cout << "shrubs distributed. press to continue." << "\n";
//    getch();**/

///**    // Write the dynamic landArray to a static landscapeArray:
//    for (i=0; i<=ijmax; i++)
//    {
//        for (j=0; j<=ijmax; j++)
//        {
//            landscapeArray[i][j] = landArray[i][j];
//        }
//    }
//doesnt make any sense - we're at the same point as before...**/
//}


//void Landscape::landArrayDelete(const int ijmax)
//{
//    for (int i=0; i<ijmax; i++)
//    {
//        delete[] landArray[i];
//    }
//    delete[] landArray;
//}

















