void an()
{


TFile *input = new TFile("../build1/output.root", "read");
TTree *tree = (TTree*) input->Get("Scoring");

double edep, stepLength, x;
int event;
x=0;
tree->SetBranchAddress("fEdep",&edep);
tree->SetBranchAddress("stepLength",&stepLength);
tree->SetBranchAddress("event",&event);

int entries = tree->GetEntries();
   auto g = new TGraph(entries);
   auto g1 = new TGraph(entries);
   


for(int i =0; i< entries; i++)
{
    tree->GetEntry(i);
    x+=stepLength;
    g->AddPoint (x, edep/stepLength);
    g1->AddPoint (x, edep);
    cout << edep << " " << x << endl;
    // histA->Fill(energyA);
}


TCanvas *cA = new TCanvas();
g->Draw("A*");
TCanvas *cb = new TCanvas();
g1->Draw("A*");

input->Close();

}