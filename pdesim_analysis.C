
#include <iostream>
#include "TClassTable.h"

#include <vector>
#include <map>
#include <set>
#include <cmath>

//#include <stdio>
//#include <stdint.h>
//#include <string>
//#include <stdlib>

#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"
#include "TClonesArray.h"
#include "TObject.h"
#include "TMath.h"
#include "TROOT.h"


void pdesim_analysis() {
   //Get old file, old tree and set top branch address
   TFile *file = new TFile("./events.root");
   TTree *tr = (TTree*)file->Get("t1");
   Int_t neve = tr->GetEntries();
   
   Int_t eventid;
   Double_t prim_Xpos;
   Double_t prim_Ypos;
   Double_t prim_Zpos;
   Int_t totsteps;
   std::vector<Long64_t> * trackid=0;
   std::vector<Long64_t> * parentid=0;
   std::vector<Long64_t> * firstparentid=0;
   std::vector<Int_t> evhits (neve,0);
     
  tr->SetBranchAddress("EvId",&eventid); //ev number
  tr->SetBranchAddress("prim_Xpos",&prim_Xpos);
  tr->SetBranchAddress("prim_Ypos",&prim_Ypos);
  tr->SetBranchAddress("prim_Zpos",&prim_Zpos);
  tr->SetBranchAddress("totsteps",&totsteps);
  tr->SetBranchAddress("trackid",&trackid);
  tr->SetBranchAddress("parentid",&parentid);
  tr->SetBranchAddress("firstparentid",&firstparentid);
  tr->GetEntry(0);
   for (Long64_t i=0;i<neve; i++) {
      tr->GetEntry(i);
      Long64_t evlen = trackid->size();
	  for (Long64_t j=0;j<evlen; j++) {
		  std::cout << "trackid" << (*trackid)[j] << "parentid" << (*parentid)[j] << "firstparentid" << (*firstparentid)[j] << std::endl;
	  }
   }
   
}
