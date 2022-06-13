/// \file MyPrimaryGeneratorAction.hh
/// \brief Definition of the MyPrimaryGeneratorAction class

#ifndef MyPrimaryGeneratorAction_h
#define MyPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"


//use standart classes instead of including. Declare and than use in primari class
class G4Event;
class G4ParticleGun;
class G4GenericMessenger;

/// The first primary generator action class.

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    MyPrimaryGeneratorAction();    
    virtual ~MyPrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         

  private:
    G4GenericMessenger*  fMessenger;
    G4ParticleGun*  fParticleGun;  
    G4bool          fRandom;         
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


