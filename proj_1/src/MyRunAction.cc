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
    
    man->CreateNtuple("HitsN","HitsN");
    man->CreateNtupleDColumn("KinEnergy");
    man->CreateNtupleIColumn("TrID");
    man->CreateNtupleIColumn("EvID");
    man->CreateNtupleIColumn("PrID");
    man->CreateNtupleDColumn("trackLength");
    man->FinishNtuple(); 
    
    

    man->CreateNtuple("HitsP","HitsP");
    man->CreateNtupleDColumn("KinEnergy");
    man->CreateNtupleIColumn("TrID");
    man->CreateNtupleIColumn("EvID");
    man->CreateNtupleIColumn("PrID");
    man->CreateNtupleDColumn("trackLength");
    man->FinishNtuple();  

    man->CreateNtuple("HitsA","HitsA");
    man->CreateNtupleDColumn("KinEnergy");
    man->CreateNtupleIColumn("TrID");
    man->CreateNtupleIColumn("EvID");
    man->CreateNtupleIColumn("PrID");
    man->CreateNtupleDColumn("trackLength");
    man->FinishNtuple();


    // man->CreateNtuple("Scoring", "Scoring");
    // man->CreateNtupleDColumn("fEdep");
    // man->FinishNtuple(1);
}
void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    man->Write();
    man->CloseFile("output.root");
}
