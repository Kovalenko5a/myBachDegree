/// \file MyActionInitialization.hh
/// \brief Definition of the MyActionInitialization class

#ifndef MyActionInitialization_h
#define MyActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class MyActionInitialization : public G4VUserActionInitialization
{
  public:
    MyActionInitialization();
    virtual ~MyActionInitialization();

    virtual void Build() const;
    virtual void BuildForMaster() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
