// #include "MySensitiveDetector.hh"

// MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
// {}

// MySensitiveDetector::~MySensitiveDetector()
// {}

// MySensitiveDetector::MyProc(const G4String& aName = "hadElastic",G4ProcessType   aType = fHadronic)
// {}

// G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0Hist)
// {
//     G4AnalysisManager *man = G4AnalysisManager::Instance();
//     G4Track *track = aStep->GetTrack();
//     // G4double edep = aStep->GetTotalEnergyDeposit();
//     // G4cout << edep << endl;
//     //cut the photons from the side:
//     track->SetTrackStatus(fStopAndKill);

//     G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
//     G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

//     G4ThreeVector posPhoton = preStepPoint->GetPosition();
//     // G4cout << "Photon position: " << posPhoton << G4endl;

//     const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
//     G4int copyNo = touchable->GetCopyNumber();
//     // G4cout << "Photon position cell: " << copyNo << G4endl;

//     G4VPhysicalVolume *physVol = touchable->GetVolume();
//     G4ThreeVector posDetector = physVol->GetTranslation();
//     // G4cout << "Detector cell position: " << posDetector << G4endl;
    
//     //how to identify the type of particle (for bachelor code)
//     const G4ParticleDefinition *d = track->GetParticleDefinition();
//     G4String particleName = d->GetParticleName();
//     G4int number_of_protons =0;

//     G4double edep = aStep->GetTotalEnergyDeposit();

//     G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
//     G4cout << evt << G4endl;
//     G4cout << d->GetParticleName() << G4endl;



//     if (particleName!="e-" && particleName!="e+" && particleName!="gamma")
//     {
//     G4cout << d->GetParticleName() << G4endl;
//     G4double kineEnergy = track->GetKineticEnergy();
//     const G4VProcess * proc = track->GetCreatorProcess();
//     const G4Material * material = track->GetMaterial();
//     G4int subType = proc->GetProcessSubType();

//     number_of_protons++;
//     G4cout << "^^^^^  "  << edep << " KineticEnergy = " << kineEnergy << G4endl; 
//     // G4String proc_name = track->GetCreatorProcess()->GetProcessName();
//     G4cout << "   " << proc << G4endl;


//     // const G4ParticleDefinition *particleDefinititon1 = Proton->Definition();
//     // // G4cout << "sfsgsdfgsfdg" << particleDefinititon1 << G4endl;
//     // G4double kineEnergy1 = 40*MeV;
//     // // G4ProcessType *procType = new  G4ProcessType fHadronic;
//     // const G4String& aName = "hadElastic";
//     // G4ProcessType   aType = fHadronic;
//     // G4VProcess * process1 = MyProc(aName, aType); 
//     // G4cout << "asfdd " << process1 << G4endl;
//     // const G4Material * material1 = ;
//     // G4double crossSection = newProcessStore->GetCrossSectionPerVolume(particleDefinititon1, kineEnergy1, process1, material1);
//     // G4cout <<  "Step number in track " << track->GetCurrentStepNumber() << G4endl;
//     // G4cout << "crossSection -== " << crossSection << G4endl;
//     man->FillNtupleIColumn(0, edep);
//     }


//     G4cout << number_of_protons << " ///////////  " << d->GetParticleName() << G4endl;

    
//     //0 event everywhere if /run/beamOn 1
//     // man->FillNtupleIColumn(0, evt);

//     //edep
//     // man->FillNtupleIColumn(0, edep);

//     //histograms of disctribution of particles on the surface of detector
//     man->FillNtupleDColumn(1, posDetector[0]);
//     man->FillNtupleDColumn(2, posDetector[1]);
//     man->FillNtupleDColumn(3, posDetector[2]);
//     man->AddNtupleRow(0);

//     //here we more interested in what? Edep distribution of different particles?
//     return true;
// }
