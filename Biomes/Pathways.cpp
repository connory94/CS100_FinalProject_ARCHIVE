#include "Pathways.h"



using namespace std;

Pathways::Pathways(const string& name, const string& areaName, Shop* pathShop) {
    this->name = name;
    this->areaName = areaName;
    this->pathShop = pathShop;
    this->pathEnemy = nullptr;
    this->visited = false;
}

Pathways::Pathways(const string& name, const string& areaName, Enemy* pathEnemy) {
    this->name = name;
    this->areaName = areaName;
    this->pathEnemy = pathEnemy;
    this->pathShop = nullptr;
    this->visited = false;
}

Pathways::Pathways(const string& name, const string& areaName) {
    this->name = name;
    this->areaName = areaName;
    this->pathEnemy = nullptr;
    this->pathShop = nullptr;
    this->visited = false;
}

Pathways::Pathways() {
    this->name = "none";
    this->areaName = "none";
    this->pathEnemy = nullptr;
    this->pathShop = nullptr;
    this->visited = false;
}

// when using pathways only use new enemy, or new shop, becuase destructor assumes pathways owns the enemy, potential undefined behavior if not
Pathways::~Pathways() {
    for (int i = 0; i < differentPaths.size(); i++) {
        delete differentPaths[i];
    }
    delete pathEnemy;
    delete pathShop;
}

void Pathways::markVisited() {
    visited = true;
}

bool Pathways::getVisited() const {
    return visited;
}

void Pathways::addPath( Pathways* path){
    differentPaths.push_back(path);
}

Pathways* Pathways::userTraverse(const int& pathChoice) {
    if (pathChoice < 1 || pathChoice > differentPaths.size()-1) {
        cout << "Invalid path choice." << endl;
        return nullptr;
    }

    if (differentPaths[pathChoice - 1]->getVisited()) {
        cout << "You have already visited this path. Please choose another one." << endl;
        return nullptr;
    }

    
    return differentPaths[pathChoice - 1];
}

// checks visited status including boss pathway
bool Pathways::mainPathsVisitedWithBoss() {
    for (int i = 0; i < differentPaths.size() - 1; i++) {
        if (!differentPaths[i]->getVisited()) {
            return false;
        }
    }
    return true;
}

// checks if the player visited all normal paths other than boss and exit paths
bool Pathways::travelPathsVisited() {
    for (int i = 0; i < differentPaths.size() - 2; i++) {
        if (!differentPaths[i]->getVisited()) {
            return false;
        }
    }
    return true;
}

string Pathways::getName() const {
    return name;
}

bool Pathways::hasEnemy() const {
    if (pathEnemy != nullptr) {
        return true;
    }
    return false;
}

Enemy* Pathways::getEnemy() const {
    return pathEnemy;
}

bool Pathways::hasShop() const {
    if (pathShop != nullptr) {
        return true;
    }
    return false;
}

Shop* Pathways::getShop() const {
    return pathShop;
}

string Pathways::getAreaName() const {
    return areaName;
}

vector<Pathways*> Pathways::getDifferentPaths() const {
    return differentPaths;
}


// seperate display class and shows all pathways that player can taake
void PathwaysDisplay::showAvailablePaths(const Pathways& pathways) {
    vector<Pathways*> availablePaths = pathways.getDifferentPaths();
    if (availablePaths.empty()) {
        cout << "No available paths can be shown." << endl;
        return;
    }

    for (int i = 0; i < availablePaths.size() -2; i++) {
        if (!availablePaths[i]->getVisited()) {
            cout << i + 1 << ". " << availablePaths[i]->getName() << endl;
        }
    }
    cout << endl;
}