#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4EmLivermorePhysics());
    RegisterPhysics (new G4EmLivermorePolarizedPhysics());
    RegisterPhysics (new G4EmPenelopePhysics());
    RegisterPhysics (new G4EmDNAPhysics());
}

MyPhysicsList::~MyPhysicsList()
{
     
}