#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "G4UImanager.hh"
#include "G4PhysListFactory.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "FTFP_BERT.hh"
// #include "QGSP_BIC_HP_EMZ.hh"
#include "G4VUserPhysicsList.hh"
#include "physics.hh"

namespace {
  void PrintUsage() {
    G4cerr << " Usage: " << G4endl;
    G4cerr << " exampleED [-m macro ] [-p physList ] [-u UIsession]  [-t nThreads]" << G4endl;
    G4cerr << "   note: -t option is available only for multi-threaded mode." << G4endl;
    G4cerr << G4endl;
  }
}


int main(int argc, char** argv){

  // Evaluate arguments
  //
  if ( argc > 7 ) {
    PrintUsage();
    return 1;
  }
  
  G4String macro;
  G4String session;
  G4String physicsListName;
  G4int nofThreads = 0;
  for ( G4int i=1; i<argc; i=i+2 ) {
    if      ( G4String(argv[i]) == "-m" ) macro = argv[i+1];
    else if ( G4String(argv[i]) == "-u" ) session = argv[i+1];
    else if ( G4String(argv[i]) == "-p" ) physicsListName = argv[i+1];
    #ifdef G4MULTITHREADED
    else if ( G4String(argv[i]) == "-t" ) {
      nofThreads = G4UIcommand::ConvertToInt(argv[i+1]);
    }
    #endif
    else {
      PrintUsage();
      return 1;
    }
  } 


// Construct the run manager
  //
  #ifdef G4MULTITHREADED
  G4MTRunManager * runManager = new G4MTRunManager;
  if ( nofThreads > 0 ) { 
    runManager->SetNumberOfThreads(nofThreads);
  }  
#else
  G4RunManager * runManager = new G4RunManager;
#endif

// runManager->SetNumberOfEventsToBeStored(3);
runManager->SetUserInitialization(new MyDetectorConstruction());

// G4VUserPhysicsList* physicsList = new FTFP_BERT;
// physicsList->SetVerboseLevel(1);
// runManager->SetUserInitialization(physicsList);

runManager->SetUserInitialization(new MyPhysicsList());


runManager->SetUserInitialization(new MyActionInitialization());
runManager->Initialize();

// Initialize visualization

  G4UIExecutive *ui = new G4UIExecutive(argc, argv);
  //
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();


    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");
    // UImanager->ApplyCommand("/vis/viewer/rebuild");

    ui->SessionStart();
  

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !
  
  delete visManager;
  delete runManager;
}