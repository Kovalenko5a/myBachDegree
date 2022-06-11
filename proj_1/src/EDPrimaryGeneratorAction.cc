//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
/// \file EDPrimaryGeneratorAction.cc
/// \brief Implementation of the EDPrimaryGeneratorAction class

#include "EDPrimaryGeneratorAction.hh"

#include "G4GenericMessenger.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EDPrimaryGeneratorAction::EDPrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction()
   {
  G4int nofParticles = 1;
  fParticleGun  = new G4ParticleGun(nofParticles);
    G4ParticleDefinition *particle = G4Gamma::Definition();
  G4ThreeVector pos(0., 0., -100.);
  G4ThreeVector mom(0., 0., 1.);
  // fParticleGun->SetNumberOfParticles(100);
  fParticleGun->SetParticlePosition(pos);
  fParticleGun->SetParticleMomentumDirection(mom);
  fParticleGun->SetParticleMomentum(38 * MeV);
  fParticleGun->SetParticleDefinition(particle);
  // fParticleGun->SetNumberOfParticles(nofParticles);
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EDPrimaryGeneratorAction::~EDPrimaryGeneratorAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EDPrimaryGeneratorAction::GeneratePrimaries(G4Event *event) {
  // this function is called at the begining of ecah event
  //


  fParticleGun->GeneratePrimaryVertex(event);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
