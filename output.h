#ifndef OUTPUT_H
#define OUTPUT_H

#include "fire.h"
#include "landscape.h"


class Output
{
public:
    Output();

    void countVeggies(const int gridSize, Parameters *parameters, Fire *fire);
//    void calculateVeggies(Landscape* landscape);
//    void outputVeggies(Landscape* landscape);




private:
    int burnt_annuals;
    int burnt_perennials;
    int burnt_shrubs;
    float fraction_annuals;
    float fraction_perennials;
    float fraction_shrubs;
};

#endif // OUTPUT_H
