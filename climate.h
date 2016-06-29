#ifndef CLIMATE_H
#define CLIMATE_H

class Climate
{
public:
    // Constructor
    Climate();
    // Destructor
    ~Climate();

    void chooseSeason();
    //void output();
    int rand_int(int from, int to);
    int season;
    int getSeason();

private:

};

#endif // CLIMATE_H
