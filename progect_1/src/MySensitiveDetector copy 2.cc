// #include "MySensitiveDetector.hh"
// #include "MyRunManager.hh"

// // G4RunManager::GetRunManager()->SetNumberOfEventsToBeStored(1);

// MySensitiveDetector::MySensitiveDetector(G4String name)
//     : G4VSensitiveDetector(name) {}

// MySensitiveDetector::~MySensitiveDetector() {}

// G4bool MySensitiveDetector::ProcessHits(G4Step *aStep,
//                                         G4TouchableHistory *R0Hist) {
//   G4String procName;
//   G4AnalysisManager *man = G4AnalysisManager::Instance();
//   G4Track *track = aStep->GetTrack();

//   G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
//   G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

//   G4ThreeVector posPhoton = preStepPoint->GetPosition();
//   G4double edep = aStep->GetTotalEnergyDeposit();

//   G4RunManager *runM = G4RunManager::GetRunManager();
//   evt = runM->GetCurrentEvent()->GetEventID();

//   // G4int old_trackID
//   // G4int trackID = track->GetTrackID();

//   // if (runM->GetPreviousEvent(1)) {
//   //   G4int evt_old = runM->GetPreviousEvent(1)->GetEventID();
//   // }
//   // G4cout << evt << "  " << evt_old << G4endl;

//   G4StepStatus status = preStepPoint->GetStepStatus();

//   // how to identify the type of particle (for bachelor code)
//   const G4ParticleDefinition *d = track->GetParticleDefinition();
//   G4String particleName = d->GetParticleName();
//   if (track->GetCreatorProcess() && particleName != "e+" &&
//       particleName != "e-" && particleName != "gamma") {
//     const G4VProcess *proc = track->GetCreatorProcess();
//     procName = proc->GetProcessName();
//     // if (procName == "photonNuclear") {
//     //   G4cout << "NAME   " << procName << "  " << particleName << " status "
//     //          << status << "  evt  " << evt << "  " << posPhoton << "  "
//     //          << trackID << G4endl;
//     // }
//   }

//   // ідея в тому, щоб знайти одну і ту саму частинку що влетіла і вилетіла, але
//   // залищила енергію, або частинку що влетиіла але не вилетіла

//   if (status == fGeomBoundary &&
//       procName == "photonNuclear") {
//     // G4cout << particleName << ":Particle and event ID: " << evt << G4endl;
//     // G4cout << particleName << G4endl;
//     // G4double kineEnergy1 = track->GetKineticEnergy();
//     G4double kineEnergy = preStepPoint->GetKineticEnergy();
//     const G4Material *material = track->GetMaterial();

//     // G4cout << "Particle " << particleName << "   " << status1 << "  STATUS  " << status2 << "NAME  " << procName
//           //  << " KineticEnergy = " << kineEnergy << " eventID " << evt << G4endl;
//           G4cout << " !  " << G4endl;
//     if(particleName == "proton")
//     man->FillNtupleDColumn(0, kineEnergy);
//     else if(particleName == "neutron")
//     man->FillNtupleDColumn(1, kineEnergy);
//     else if(particleName == "alpha")
//     man->FillNtupleDColumn(2, kineEnergy);

//     man->AddNtupleRow(0);
//   }
//   G4cout << "." << G4endl;

//   // 0 event everywhere if /run/beamOn 1
//   //  man->FillNtupleIColumn(0, evt);

//   // edep
//   //  man->FillNtupleIColumn(0, edep);

//   // histograms of disctribution of particles on the surface of detector

//   // here we more interested in what? Edep distribution of different particles?
//   return true;
// }

// /*
// Ідея - порахувати всі можливі частинки по типам у першій симуляції, далі
// порахувати скільки з них зазвичай взаємодіє Побудувати енергетичні спектри як
// утворених частинок так і залишеної енергії у детекторі.
// */