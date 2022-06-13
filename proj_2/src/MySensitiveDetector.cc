#include "MySensitiveDetector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}


G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0Hist)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    

    
    G4double edep = aStep->GetTotalEnergyDeposit();
    G4int evt1 = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    G4double step_length = aStep->GetStepLength(); 

    G4cout << step_length << "  " << evt1  << " edep = " << edep << G4endl; 
    // G4cout << "." << G4endl;
    
    
    man->FillNtupleIColumn(0, 0, evt1);
    man->FillNtupleDColumn(0, 1, edep);
    man->FillNtupleDColumn(0, 2, step_length);
    man->AddNtupleRow(0);
    


    

    return true;
}

/*
Ідея - порахувати всі можливі частинки по типам у першій симуляції, далі порахувати скільки з них зазвичай взаємодіє
Побудувати енергетичні спектри як утворених частинок так і залишеної енергії у детекторі.


Із сігмою все гаразд - просто порахувати ту кількість яка вилетить за межі дектектора - треба тільки мати на увазі що статус цікавить
не тільки взаємодія на границі, а просто виліт за межі. Або навпаки порахувати скільки "смертей" було в межах детектора. Для цього
треба ще брати до уваги що часто повтори івентів бувають, тому смерть врахувати найращий варіант - не буде ніяких додаткових варіантів
типу на межі.

З приводу спектру для експерименту первинного, то тут треба якось бачити первинний івент з утворення частинки і просто його зарахувати
разом із початковою кінетичною енергією. А не як я робив з початку - брав взаємодії на границі детектора, для означення частинок і їх
кінетичних енергій.
В цьому випадку треба використати мабудь щось інше - мабуть RunAction EventAction, або просто кінетичну енергію з треку.

*/