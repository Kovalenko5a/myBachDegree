#include <set>

void an1()
{

std::set<int> originalTrackIDpLong;
std::set<int> originalTrackIDpShort;
std::set<int> originalEventIDp;

std::set<int> originalTrackIDa;
std::set<int> originalEventIDa;





TH1F *histPLong = new TH1F("histPLong", "Energy distr. from target",70,0,20);
TH1F *histPShort = new TH1F("histPShort", "Energy distr. from detector",70,0,20);

TH1F *histA = new TH1F("histA", "HistogramA",27,0,18);

TFile *input = new TFile("/home/yantuzemec/Documents/knu/4kurs/geant4_besh/geant_code_bachelor/myBachDegree/proj_1/build2/output.root", "read");

TTree *treeP = (TTree*) input->Get("HitsP");
TTree *treeA = (TTree*) input->Get("HitsA");

double energyN, energyP, energyA;
double trackLength;
int evIDn, evIDp, evIDa;
int trIDn, trIDp, trIDa;
treeA->SetBranchAddress("KinEnergy",&energyA);
treeA->SetBranchAddress("EvID",&evIDa);
treeA->SetBranchAddress("TrID",&trIDa);

treeP->SetBranchAddress("KinEnergy",&energyP);
treeP->SetBranchAddress("EvID",&evIDp);
treeP->SetBranchAddress("TrID",&trIDp);
treeP->SetBranchAddress("trackLength", &trackLength);
int entriesA = treeA->GetEntries();
int entriesP = treeP->GetEntries();



for(int i =0; i< entriesA; i++)
{
    treeA->GetEntry(i);
    histA->Fill(energyA);
    originalEventIDa.insert(evIDa);
}

for(int i =0; i< entriesP; i++)
{
    treeP->GetEntry(i);
    originalEventIDp.insert(evIDp);
    // cout << trackLength << endl;
}


int numberOfProtonsFromTarget = 0;
int numberOfProtonsFromSD = 0;
for (std::set<int>::iterator it=originalEventIDp.begin(); it!=originalEventIDp.end(); it++)
{
    // cout << *it << endl;
    //rough
    for(int i =0; i< entriesP; i++)
    {   
        treeP->GetEntry(i);
        if (evIDp==*it && trackLength>300. && energyP>0.6) {originalTrackIDpLong.insert(trIDp); histPLong->Fill(energyP);}
        if (evIDp==*it && trackLength<1. && energyP>0.6) {originalTrackIDpShort.insert(trIDp);  histPShort->Fill(energyP);}
    }
    numberOfProtonsFromTarget += originalTrackIDpLong.size();
    originalTrackIDpLong.clear();
    numberOfProtonsFromSD += originalTrackIDpShort.size();
    originalTrackIDpShort.clear();
}
cout << endl << numberOfProtonsFromTarget << endl;
cout << endl << numberOfProtonsFromSD << endl;

int numberOfA = 0;
for (std::set<int>::iterator it=originalEventIDa.begin(); it!=originalEventIDa.end(); it++)
{
    // cout << *it << endl;
    for(int i =0; i< entriesA; i++)
    {   
        treeA->GetEntry(i);
        if (evIDa==*it) originalTrackIDa.insert(trIDa);
    }
    numberOfA += originalTrackIDa.size();
    originalTrackIDa.clear();
}
// cout <<endl << numberOfA << endl;


TCanvas *cP1 = new TCanvas();
auto* legend1 = new TLegend(0.2, 0.2, .8, .8);
histPLong->Draw();
histPLong->GetXaxis()->SetTitle("E_{p}, MeV");
histPLong->GetYaxis()->SetTitle("Number of occurance");
legend1->AddEntry((TObject*)0, "Number of protons from target = 57", "");
legend1->Draw();

TCanvas *cP2 = new TCanvas();
auto* legend2 = new TLegend(0.2, 0.2, .8, .8);
histPShort->Draw();
histPShort->GetXaxis()->SetTitle("E_{p}, MeV");
histPShort->GetYaxis()->SetTitle("Number of occurance");
legend2->AddEntry((TObject*)0, "Number of protons in detector = 2394", "");
legend2->Draw();

TCanvas *cA = new TCanvas();
histA->Draw();
histA->GetXaxis()->SetTitle("E_{#alpha}, MeV");
histA->GetYaxis()->SetTitle("Number of occurance");

input->Close();

}