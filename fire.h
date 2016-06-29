  #ifndef FIRE_H
#define FIRE_H
#include "landscape.h"
#include "climate.h"

#include <vector>


class Fire
{
public: // make functions public
    // Default constructor:
    Fire();

    // Destructor
    ~Fire();

    //int** fireArray;
    //int tempGrid[ijmax][ijmax];



    // Accessor Functions
    int rand_int(int to, int from);
    float rand_float(float from, float to);
    void burn(const int gridSize, const float cellSize, Parameters *parameters);

    int numberRuns; // for fireArray output
    int burningPatches;
    double elapsed_secs;
    int burntPatches;
    int burntPatches_temp;
    int numberOfBurntPatches;

    // ROS spread minimum threshold and random float generator ranges:
    float rMIN;
    float rMAX;

    float setParamThreshold;



private:

//    // Formula variables from Rothermel (1972), reformulated for SI-system by Wilson (1980):
//    double R; //spread rate
//    float IR; // reaction intensity
//    float T; // reaction velocity
//    float Tmax; // maximum reaction velocity
//    float betaOP; // optimum packing ratio
//    float A; // dimensionless variable
//    float etaM; // moisture damping coefficient
//    float xi; // propagating flux ratio
//    float phiW; // wind coefficient
//    float C; //dimensionless variable
//    float B; // dimensionless variable
//    float E; // dimensionless variable
//    float phiS; // slope factor
//    float epsilon; //effective heating number
//    float Qig; // heat of preignition
//    float beta; // packing ratio
//    float IB; // Byram's fireline intensity
//    float Lf; // estimate of flame lenght
//    float wn; // net fuel loading
//    float etaS; // mineral damping coefficient
////    float rhoP; // fuel particle density
////    float h; // fuel heat content
////    float sigma; // sav ratio
////    float Mf; // Fuel moisture content
////    float Mx; // fuel moisture of extinction
////    float se; // fuel effective mineral content
//    float U; // windspeed at midflame height
////    float wo; // ovendry fuel loading
////    float sT; // fuel total mineral content
//    float tanPhi; // slope (vertical rise/horizontal run)
//    float rhoB; // ovendry bulk density
////    float delta; // fuel depth
//    float R_cell;




};

#endif // FIRE_H
