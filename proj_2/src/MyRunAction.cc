#include "MyRunAction.hh"

MyRunAction::MyRunAction():G4UserRunAction()
{}
MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->SetNtupleMerging(true);
    man->OpenFile("output.root");
    
    // man->CreateNtuple("Hits","Hits");
    // man->CreateNtupleDColumn("kinEnergy");
    // man->CreateNtupleIColumn("eventID");
    // man->FinishNtuple(0);


    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleIColumn("event");
    man->CreateNtupleDColumn("fEdep");
    man->CreateNtupleDColumn("stepLength");
    man->FinishNtuple(0);
}
void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    man->Write();
    man->CloseFile("output.root");
}
