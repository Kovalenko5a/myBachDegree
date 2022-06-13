void an()
{

TH1F *histN = new TH1F("histN", "HistogramN",150,0,14);
TH1F *histP = new TH1F("histP", "HistogramP",70,0,20);
TH1F *histA = new TH1F("histA", "HistogramA",27,0,18);

TFile *input = new TFile("1B_40_MeV.root", "read");
TTree *treeN = (TTree*) input->Get("HitsN");
TTree *treeP = (TTree*) input->Get("HitsP");
TTree *treeA = (TTree*) input->Get("HitsA");

double energyN, energyP, energyA;
int evIDn, evIDp, evIDa;
treeA->SetBranchAddress("KinEnergy",&energyA);
treeA->SetBranchAddress("EvID",&evIDa);

treeN->SetBranchAddress("KinEnergy",&energyN);
treeN->SetBranchAddress("EvID",&evIDn);

treeP->SetBranchAddress("KinEnergy",&energyP);
treeP->SetBranchAddress("EvID",&evIDp);
int entriesA = treeA->GetEntries();
int entriesP = treeP->GetEntries();
int entriesN = treeN->GetEntries();


for(int i =0; i< entriesA; i++)
{
    treeA->GetEntry(i);
    cout << energyA << " "<< evIDa<< endl;
    histA->Fill(energyA);
}

for(int i =0; i< entriesP; i++)
{
    treeP->GetEntry(i);
    cout << energyP << " "<< evIDp << endl;
    histP->Fill(energyP);
}
for(int i =0; i< entriesN; i++)
{
    treeN->GetEntry(i);
    // cout << energyN << " "<< evIDn << endl;s
    histN->Fill(energyN);
}
cout << entriesA << " =A " << entriesN <<  " =N " << entriesP <<  " =P "<< endl;
TCanvas *cN = new TCanvas();
histN->Draw();
histN->GetXaxis()->SetTitle("E_{n}, MeV");
histN->GetYaxis()->SetTitle("Number of occurance");
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