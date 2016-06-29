#ifndef WEATHER_H
#define WEATHER_H
#include <fstream>
#include <vector>
#include <sstream>


class Weather
{
public:
    // Constructor
    Weather();
    // Destructor
    ~Weather();

    void wfile_input();

    std::vector<int>yearV;
    std::vector<std::string>monthV;
    std::vector<float>tempV;
    std::vector<float>rainV;
    std::vector<float>windV;
    std::vector<int>wdirV;

private:
    double wind;
    double rain;
    double lightning;
    double temperature;
};

#endif // WEATHER_H
