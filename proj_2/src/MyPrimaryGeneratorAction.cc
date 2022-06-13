/// \file MyPrimaryGeneratorAction.cc
/// \brief Implementation of the MyPrimaryGeneratorAction class

#include "MyPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4GenericMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fMessenger(0),
  fParticleGun(0),
  fRandom(true)
{   
  G4int nofParticles = 1;
  fParticleGun  = new G4ParticleGun(nofParticles);

  // Define particle properties
  G4String particleName = "proton";
  //G4String particleName = "geantino";
  G4ThreeVector position(0, 0, -400.*mm);   
  G4ThreeVector momentum(0, 0, 20.0*MeV);
  
  // Default particle kinematics
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentum(momentum);
  fParticleGun->SetParticlePosition(position);
  
  // Generic messenger
  // Define /B4/event commands using generic messenger class
  fMessenger 
    = new G4GenericMessenger(this, "/ED/primary/", "Primary generator control");

  // Define /B4/event/setPrintModulo command
  fMessenger
    ->DeclareProperty("setRandom", 
                      fRandom, 
                      "Activate/Inactivate random option");
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  //this function is called at the begining of ecah event
  //

  if ( fRandom ) {
     G4double x = 2*(G4UniformRand()-0.5)*0.05*m;
    G4double y = 2*(G4UniformRand()-0.5)*0.05*m;

    fParticleGun->SetParticlePosition(G4ThreeVector(x, y, -400.*mm));
  } 

  fParticleGun->GeneratePrimaryVertex(event);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

