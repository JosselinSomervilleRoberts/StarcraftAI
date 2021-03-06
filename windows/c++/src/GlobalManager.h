#pragma once

#include <BWAPI.h>
#include <vector>

#include "BaseManager.h"
#include "Tools.h"



class GlobalManager {

public:
    GlobalManager();

    void initiate();
    void update();

    bool reserveGas(int gas_, bool& enoughGas);
    bool reserveMinerals(int minerals_, bool& enoughMinerals);
    bool reserveRessources(int minerals_, int gas_, bool& enoughMinerals, bool& enoughGas);
    void releaseGas(int gas_);
    void releaseMinerals(int minerals_);
    void releaseRessources(int minerals_, int gas_);
    int getAvailableGas();
    int getAvailableMinerals();

    BWAPI::Unit acquireWorker();
    void releaseWorker(BWAPI::Unit worker);
    void setRessourceAim(int cristalAim, int gasAim);
    void setRefineryState(BuildingState state);


    void onUnitCreate(BWAPI::Unit unit);
    void onUnitDestroy(BWAPI::Unit unit);
    void onUnitComplete(BWAPI::Unit unit);


private:
    std::vector<BaseManager*> bases;
    int reservedGas = 0;
    int reservedMinerals = 0;
};
