#include "MyDetectorConstruction.hh"
#include "MySensitiveDetector.hh"

MyDetectorConstruction::MyDetectorConstruction()
: G4VUserDetectorConstruction()
{}
MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{

    G4double a,z,density,fractionmass;
    G4String name,symbol;
    G4int nel,natoms;
    double pi = 3.14159265358979323846;
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    density = 2.7*g/cm3;
    a = 26.98*g/mole;
    G4Material *Aluminium = new G4Material(name="Aluminium",z=13.,a,density);

    G4Material *C12H18O7 = new G4Material(name="C12H18O7", 1.31*g/cm3 ,3);
    C12H18O7->AddElement(nist->FindOrBuildElement("C"),12);
    C12H18O7->AddElement(nist->FindOrBuildElement("H"),18);
    C12H18O7->AddElement(nist->FindOrBuildElement("O"),7);

    // G4Isotope *sourceMat = nist-> Find
    //NaI - detector
    //Pb with point source in center

    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, vacuum, "logicWorld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"physWorld",0, false, 0, true);

    // G4Tubs *solidDetector = new G4Tubs("solidDetector", 0.005*m, 0.2*m, 0.2*m, 2*pi, 2*pi);
    // G4LogicalVolume *logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
    // G4VPhysicalVolume *physDetector = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.01),logicDetector,"physDetector",logicWorld, false, 0, true);

    G4Box *solidTarget = new G4Box("solidTarget", 0.2*m, 0.1*m, 0.3*cm);
    G4LogicalVolume *logicTarget = new G4LogicalVolume(solidTarget, Aluminium, "logicTarget");
    G4VPhysicalVolume *physTarget = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.01),logicTarget,"physTarget",logicWorld, false, 0, true);

G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m);
    logicDetector = new G4LogicalVolume(solidDetector, C12H18O7, "logicDetector");

    for(G4int i=0;  i<100; i++)
    {
        for(G4int j=0; j<100; j++)
        {
            G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, 0.05*m), logicDetector, "physDetector", logicWorld, false, j+i*100);
        }
    }



    return physWorld;
}


void MyDetectorConstruction::ConstructSDandField()
{       
    //tot class cotory s name inheritetd in detector.cc
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
    logicDetector->SetSensitiveDetector(sensDet);
}
