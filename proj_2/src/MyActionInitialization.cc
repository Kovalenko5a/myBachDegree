/// \file MyActionInitialization.cc
/// \brief Implementation of the MyActionInitialization class

#include "MyActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyRunAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyActionInitialization::MyActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyActionInitialization::~MyActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyActionInitialization::BuildForMaster() const
{
  SetUserAction(new MyRunAction);
  // SetUserAction(new EDPrimaryGeneratorAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyActionInitialization::Build() const
{
  SetUserAction(new MyPrimaryGeneratorAction);
  SetUserAction(new MyRunAction);
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
