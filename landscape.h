#ifndef LANDSCAPE_H
#define LANDSCAPE_H
#include "climate.h"
#include "parameters.h"
#include <vector>


class Landscape
{
public:
    // Constructor
    Landscape(const int ijmax);
    // Destructor
    ~Landscape();

    int rand_int(int from, int to);
    void initialise(const int ijmax);
    void landArrayDelete(const int ijmax);

    Parameters* parameters;

    // Dynamic arrays:
    // I want to be able to let the user decide what the grid size of the model is going to be, meaning that I cant use static arrays
    // as in that case the array size has to be defined beforhand

    // These have to be public so output.cpp can access them...
    int num_vegfree; // set the values up in the constructor!
    int num_annuals;
    int num_perennials;
    int num_shrubs;




 private:

    float aggregation_annuals;
    float aggregation_perennials;
    float aggregation_shrubs;
    int patchNum_annuals;
    int patchNum_perennials;
    int patchNum_shrubs;

    double fuel_moisture;
    double biomass;

};

#endif // LANDSCAPE_H
