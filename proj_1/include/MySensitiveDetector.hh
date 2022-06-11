#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include "G4HadronicProcessStore.hh"
#include "G4SystemOfUnits.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4HadronicProcessType.hh"
#include "G4AdjointProton.hh"
#include "G4HadronElasticProcess.hh"


#include "MyRunAction.hh"



    
    
// G4RunManager::GetRunManager()->SetNumberOfEventsToBeStored(3);


class G4HadronicProcessStore;
class G4ParticleDefinition;
class G4VProcess;
class G4Material;
class G4AdjointProton;
enum G4HadronicProcessType;

class MySensitiveDetector : public G4VSensitiveDetector
{
    public:
        MySensitiveDetector(G4String);
        ~MySensitiveDetector();
    private:
    
        virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
        // G4int evt = 0;
        // G4int evt_old = 0;
        // G4int trackID = 0;
        // G4HadronicProcessStore* newProcessStore;
        // G4AdjointProton* Proton;
        // G4VProcess* MyProc;
        // G4HadronElasticProcess* HaElPro;
        
};

#endif