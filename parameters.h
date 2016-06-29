#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <vector>



class Parameters
{
public:
    Parameters();

    void inputLandArray();
    int inputGridSize();
    float inputCellSize();
    void inputSeason();

    class GrassFuel
    {
    public:

        void inputVegParamfileGrasses(const float gridSize, const float cellSize);

        std::vector<float>rhoPParameterGridGrass;
        std::vector<float>hParameterGridGrass;
        std::vector<float>sigmaParameterGridGrass;
        std::vector<float>MfParameterGridGrass;
        std::vector<float>MxParameterGridGrass;
        std::vector<float>seParameterGridGrass;
        std::vector<float>woParameterGridGrass;
        std::vector<float>sTParameterGridGrass;
        std::vector<float>deltaParameterGridGrass;

        float woGrass;
        float deltaGrass;
        float sigmaGrass;
        float hGrass;
        float rhoPGrass;
        float MfGrass;
        float sTGrass;
        float seGrass;
        float MxGrass;

        float grassCover;


    };

    class ShrubFuel
    {
    public:

        void inputVegParamfileShrubs(const float gridSize, const float cellSize);

        std::vector<float>rhoPParameterGridShrubs;
        std::vector<float>hParameterGridShrubs_stem;
        std::vector<float>hParameterGridShrubs_branch;
        std::vector<float>sigmaParameterGridShrubs_stem;
        std::vector<float>sigmaParameterGridShrubs_branch;
        std::vector<float>MfParameterGridShrubs_stem;
        std::vector<float>MfParameterGridShrubs_branch;
        std::vector<float>MxParameterGridShrubs;
        std::vector<float>seParameterGridShrubs;
        std::vector<float>woParameterGridShrubs;
        std::vector<float>sTParameterGridShrubs;
        std::vector<float>deltaParameterGridShrubs;

        float woShrubs;
        float deltaShrubs;
        float sigmaShrubs;
        float hShrubs;
        float rhoPShrubs;
        float MfShrubs;
        float sTShrubs;
        float seShrubs;
        float MxShrubs;

        float shrubCover;

        float shrubStemBiomass;
        float shrubBranchyBiomass;
        float shrubCrownVolumeMIN;
        float shrubCrownVolumeMAX;
        float shrubCrownVolume;
        float shrubCircumference;

        class Stem
        {
        public:
            float woStem;
            float deltaStem;
            float sigmaStem;
            float hStem;
            float rhoPStem;
            float MfStem;
            float sTStem;
            float seStem;
            float MxStem;

        };

        class Branches
        {
        public:
            float woBranches;
            float deltaBranches;
            float sigmaBranches;
            float hBranches;
            float rhoPBranches;
            float MfBranches;
            float sTBranches;
            float seBranches;
            float MxBranches;
        };

    };

    GrassFuel* grassFuel = new GrassFuel();
    ShrubFuel* shrubFuel = new ShrubFuel();

    void parameterPointerDelete();

    int gridSize;
    float cellSize;
    int season;

    std::vector<float>landArray;

//    std::vector<float>grassCoverGrid;
//    std::vector<float>shrubCoverGrid;

    // Plant parameters:
    int pft;
    int burnStatus;

    // Weather parameters:
    /** U and tanPhi have to be adaptive at some point. 0 is only for test purposes! **/
    float U = 3;
    float tanPhi = 0;

    // Fire parameters:
    float IR;
    float T;
    float Tmax;
    float betaOP;
    float A;
    float etaM;
    float etaS;
    float xi;
    float phiW;
    float C;
    float B;
    float E;
    float wn;
    float phiS;
    float rhoB;
    float epsilon;
    float Qig;
    float beta;
    float IB;
    float Lf;
    float R;
    float Radj;

    // Averaged variables to calculate ROS for a heterogeneous cell:
    // Using naming convention of Rothermel (1972).
    float Ai_grass;
    float Ai_stem;
    float Ai_branch;
    float Adead;
    float fi_grass;
    float fi_stem;
    float fi_branch;
    float sigmaDead;
    float sigmaAVG;
    float MfAVG;
    float rhoPAVG;

    float woCell;
    float deltaCell;
    float sigmaCell;
    float hCell;
    float rhoPCell;
    float MfCell;
    float sTCell;
    float seCell;
    float MxCell;

    bool parameterFireThreshold = false;
    bool ignitionPossible = true;



    int timeCount;


private:


};

#endif // PARAMETERS_H
