#include "MySensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include <set>

// G4RunManager::GetRunManager()->SetNumberOfEventsToBeStored(1);

MySensitiveDetector::MySensitiveDetector(G4String name)
    : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep,
                                        G4TouchableHistory* R0Hist) {
  

  G4String procName;
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  G4Track *track = aStep->GetTrack();

  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4StepStatus status = preStepPoint->GetStepStatus();


  // how to identify the type of particle (for bachelor code)
  const G4ParticleDefinition *d = track->GetParticleDefinition();
  G4String particleName = d->GetParticleName();

  // ідея в тому, щоб знайти одну і ту саму частинку що влетіла і вилетіла, але
  // залищила енергію, або частинку що влетиіла але не вилетіла
  // G4cout << "."; 
  G4double kineEnergy = track->GetKineticEnergy();
  G4int trackID = track->GetTrackID();
  G4int parentID = track->GetParentID();
  G4double trackLength = track->GetTrackLength();
  if(G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID() && track->GetCreatorProcess())
    {
    G4RunManager *runM = G4RunManager::GetRunManager();
    G4int evt = runM->GetCurrentEvent()->GetEventID();


    const G4VProcess *proc = track->GetCreatorProcess();
    procName = proc->GetProcessName();
    if (//status == fGeomBoundary &&
      procName == "photonNuclear") 
      {
    
    
    G4double kineEnergy = preStepPoint->GetKineticEnergy();
    if(particleName == "neutron")
    {
    
    
    man->FillNtupleDColumn(0, 0, kineEnergy);
    man->FillNtupleIColumn(0, 1, trackID);
    man->FillNtupleIColumn(0, 2, evt);
    man->FillNtupleIColumn(0, 3, parentID);
    // G4cout << " n  " << evt << "  " << kineEnergy << G4endl;
    man->AddNtupleRow(0);
    }
    if(particleName == "proton")
    {
    man->FillNtupleDColumn(1, 0, kineEnergy);
    man->FillNtupleIColumn(1, 1, trackID);
    man->FillNtupleIColumn(1, 2, evt);
    man->FillNtupleIColumn(1, 3, parentID);
    man->FillNtupleDColumn(1,4,trackLength);
    G4cout << parentID << " p  " << evt << "  " << kineEnergy << "  " << trackLength/cm << G4endl;
    man->AddNtupleRow(1);
    }

    if(particleName == "alpha")
    {
    man->FillNtupleDColumn(2, 0, kineEnergy);
    man->FillNtupleIColumn(2, 1, trackID);
    man->FillNtupleIColumn(2, 2, evt);
    man->FillNtupleIColumn(2, 3, parentID);
    man->FillNtupleDColumn(2, 4, trackLength);
    // G4cout << parentID << " a  " << evt << "  " <<  kineEnergy<< G4endl;
    man->AddNtupleRow(2);
    }

    
  }
        }

 
  return true;
}

/*
Ідея - порахувати всі можливі частинки по типам у першій симуляції, далі
порахувати скільки з них зазвичай взаємодіє Побудувати енергетичні спектри як
утворених частинок так і залишеної енергії у детекторі.
*/