#include <set>

void an()
{

std::set<int> originalTrackIDp;
std::set<int> originalEventIDp;

std::set<int> originalTrackIDa;
std::set<int> originalEventIDa;





TH1F *histP = new TH1F("histP", "HistogramP",70,0,20);
TH1F *histA = new TH1F("histA", "HistogramA",27,0,18);

TFile *input = new TFile("1B_40_MeV.root", "read");

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
treeP->SetBranchAddress("treckLength", &trackLength);
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
    histP->Fill(energyP);
    originalEventIDp.insert(evIDp);
}


int numberOfProtons = 0;
for (std::set<int>::iterator it=originalEventIDp.begin(); it!=originalEventIDp.end(); it++)
{
    // cout << *it << endl;
    for(int i =0; i< entriesP; i++)
    {   
        treeP->GetEntry(i);
        if (evIDp==*it) originalTrackIDp.insert(trIDp);
    }
    numberOfProtons += originalTrackIDp.size();
    originalTrackIDp.clear();
}
cout <<endl << numberOfProtons << endl;

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
cout <<endl << numberOfA << endl;


TCanvas *cP = new TCanvas();
histP->Draw();
histP->GetXaxis()->SetTitle("E_{p}, MeV");
histP->GetYaxis()->SetTitle("Number of occurance");
TCanvas *cA = new TCanvas();
histA->Draw();
histA->GetXaxis()->SetTitle("E_{#alpha}, MeV");
histA->GetYaxis()->SetTitle("Number of occurance");

input->Close();

}