#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmLivermorePolarizedPhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmDNAPhysics.hh"


class MyPhysicsList: public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    ~MyPhysicsList();


};


#endif