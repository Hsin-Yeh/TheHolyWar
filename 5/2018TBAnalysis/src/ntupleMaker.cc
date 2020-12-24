#include "ntupleMaker.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TGaxis.h"
#include <utility>
#include <vector>

//Constructor
ntupleMaker::ntupleMaker(){}
ntupleMaker::ntupleMaker( TChain *c1,TChain *c2,TChain *c3,string filename ):T_Rechit(c1),T_DWC(c2),T_Meta(c3)
{
    cout << "Data: Constructor of makePlot ... \n\n" << endl;
    fname = filename;
    // Set object pointer(Data)
    rechit_detid = 0;
    rechit_module = 0;
    rechit_layer = 0;
    rechit_chip = 0;
    rechit_channel = 0;
    rechit_type = 0;
    rechit_x = 0;
    rechit_y = 0;
    rechit_z = 0;
    rechit_iu = 0;
    rechit_iv = 0;
    rechit_energy = 0;
    rechit_energy_noHG = 0;
    rechit_amplitudeHigh = 0;
    rechit_amplitudeLow = 0;
    rechit_hg_goodFit = 0;
    rechit_lg_goodFit = 0;
    rechit_hg_saturated = 0;
    rechit_lg_saturated = 0;
    rechit_fully_calibrated = 0;
    rechit_TS2High = 0;
    rechit_TS2Low = 0;
    rechit_TS3High = 0;
    rechit_TS3Low = 0;
    rechit_Tot = 0;
    rechit_timeMaxHG = 0;
    rechit_timeMaxLG = 0;
    rechit_toaRise = 0;
    rechit_toaFall = 0;
nihao
}
ntupleMaker::ntupleMaker( TChain *c1,TChain *c2,string filename ):T_Rechit(c1),T_DWC(c2){
    cout << "MC: Constructor of makePlot ... \n\n" << endl;
    fname = filename;
    // Set object pointer(Data)
    rechit_detid = 0;
    rechit_module = 0;
    rechit_layer = 0;
    rechit_chip = 0;
    rechit_channel = 0;
    rechit_type = 0;
    rechit_x = 0;
    rechit_y = 0;
    rechit_z = 0;
    rechit_iu = 0;
    rechit_iv = 0;
    rechit_energy = 0;
    rechit_energy_noHG = 0;
    rechit_amplitudeHigh = 0;
    rechit_amplitudeLow = 0;
    rechit_hg_goodFit = 0;
    rechit_lg_goodFit = 0;
    rechit_hg_saturated = 0;
    rechit_lg_saturated = 0;
    rechit_fully_calibrated = 0;
    rechit_TS2High = 0;
    rechit_TS2Low = 0;
    rechit_TS3High = 0;
    rechit_TS3Low = 0;
    rechit_Tot = 0;
    rechit_timeMaxHG = 0;
    rechit_timeMaxLG = 0;
    rechit_toaRise = 0;
    rechit_toaFall = 0;

}
ntupleMaker::ntupleMaker( TChain *c1,string filename ):T_Rechit(c1){
    cout << "Test Data: Constructor of makePlot ... \n\n" << endl;
    fname = filename;
    // Set object pointer(Data)
    rechit_detid = 0;
    rechit_module = 0;
    rechit_layer = 0;
    rechit_chip = 0;
    rechit_channel = 0;
    rechit_type = 0;
    rechit_x = 0;
    rechit_y = 0;
    rechit_z = 0;
    rechit_iu = 0;
    rechit_iv = 0;
    rechit_energy = 0;
    rechit_energy_noHG = 0;
    rechit_amplitudeHigh = 0;
    rechit_amplitudeLow = 0;
    rechit_hg_goodFit = 0;
    rechit_lg_goodFit = 0;
    rechit_hg_saturated = 0;
    rechit_lg_saturated = 0;
    rechit_fully_calibrated = 0;
    rechit_TS2High = 0;
    rechit_TS2Low = 0;
    rechit_TS3High = 0;
    rechit_TS3Low = 0;
    rechit_Tot = 0;
    rechit_timeMaxHG = 0;
    rechit_timeMaxLG = 0;
    rechit_toaRise = 0;
    rechit_toaFall = 0;
    TestRun = true;
}

//Destructor
ntupleMaker::~ntupleMaker()
{
    cout << "\n\n";
    cout << "Destructor of makePlot ... " << endl;
}

void ntupleMaker::Init(){

    nevents = T_Rechit->GetEntries();
    if(Is_Data)
        cout << "(Data)Nevents: "<< nevents << endl;
    else
        cout << "(MC)Nevents: "<< nevents << endl;

    T_Rechit->SetBranchAddress("event", &event);
    T_Rechit->SetBranchAddress("run", &run);
    T_Rechit->SetBranchAddress("pdgID", &pdgID);
    T_Rechit->SetBranchAddress("beamEnergy", &beamEnergy);
    T_Rechit->SetBranchAddress("trueBeamEnergy", &trueBeamEnergy);
    T_Rechit->SetBranchAddress("NRechits", &NRechits);
    T_Rechit->SetBranchAddress("rechit_detid", &rechit_detid);
    T_Rechit->SetBranchAddress("rechit_module", &rechit_module);
    T_Rechit->SetBranchAddress("rechit_layer", &rechit_layer);
    T_Rechit->SetBranchAddress("rechit_chip", &rechit_chip);
    T_Rechit->SetBranchAddress("rechit_channel", &rechit_channel);

    T_Rechit->SetBranchAddress("rechit_x", &rechit_x);
    T_Rechit->SetBranchAddress("rechit_y", &rechit_y);
    T_Rechit->SetBranchAddress("rechit_z", &rechit_z);
    T_Rechit->SetBranchAddress("rechit_iu", &rechit_iu);
    T_Rechit->SetBranchAddress("rechit_iv", &rechit_iv);
    T_Rechit->SetBranchAddress("rechit_energy", &rechit_energy);

    T_Rechit->SetBranchAddress("rechit_amplitudeHigh", &rechit_amplitudeHigh);
    T_Rechit->SetBranchAddress("rechit_amplitudeLow", &rechit_amplitudeLow);
    
    T_Rechit->SetBranchAddress("rechit_Tot", &rechit_Tot);
    T_Rechit->SetBranchAddress("rechit_timeMaxHG", &rechit_timeMaxHG);
    T_Rechit->SetBranchAddress("rechit_timeMaxLG", &rechit_timeMaxLG);
    T_Rechit->SetBranchAddress("rechit_toaRise", &rechit_toaRise);
    T_Rechit->SetBranchAddress("rechit_toaFall", &rechit_toaFall);

    if(Is_Data){
        T_Rechit->SetBranchAddress("rechit_type", &rechit_type);
        T_Rechit->SetBranchAddress("rechit_energy_noHG", &rechit_energy_noHG);
        T_Rechit->SetBranchAddress("rechit_hg_goodFit", &rechit_hg_goodFit);
        T_Rechit->SetBranchAddress("rechit_lg_goodFit", &rechit_lg_goodFit);
        T_Rechit->SetBranchAddress("rechit_hg_saturated", &rechit_hg_saturated);
        T_Rechit->SetBranchAddress("rechit_lg_saturated", &rechit_lg_saturated);
        T_Rechit->SetBranchAddress("rechit_fully_calibrated", &rechit_fully_calibrated);
        T_Rechit->SetBranchAddress("rechit_TS2High", &rechit_TS2High);
        T_Rechit->SetBranchAddress("rechit_TS2Low", &rechit_TS2Low);
        T_Rechit->SetBranchAddress("rechit_TS3High", &rechit_TS3High);
        T_Rechit->SetBranchAddress("rechit_TS3Low", &rechit_TS3Low);
    }
    else {
        cout << "hi" << endl;
        T_Rechit->SetBranchAddress("ahc_energySum", &ahc_energySum);
    }


    T_DWC->SetBranchAddress("ntracks", &ntracks, &b_ntracks);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_1", &impactX_HGCal_layer_1, &b_impactX_HGCal_layer_1);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_1", &impactY_HGCal_layer_1, &b_impactY_HGCal_layer_1);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_2", &impactX_HGCal_layer_2, &b_impactX_HGCal_layer_2);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_2", &impactY_HGCal_layer_2, &b_impactY_HGCal_layer_2);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_3", &impactX_HGCal_layer_3, &b_impactX_HGCal_layer_3);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_3", &impactY_HGCal_layer_3, &b_impactY_HGCal_layer_3);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_4", &impactX_HGCal_layer_4, &b_impactX_HGCal_layer_4);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_4", &impactY_HGCal_layer_4, &b_impactY_HGCal_layer_4);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_5", &impactX_HGCal_layer_5, &b_impactX_HGCal_layer_5);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_5", &impactY_HGCal_layer_5, &b_impactY_HGCal_layer_5);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_6", &impactX_HGCal_layer_6, &b_impactX_HGCal_layer_6);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_6", &impactY_HGCal_layer_6, &b_impactY_HGCal_layer_6);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_7", &impactX_HGCal_layer_7, &b_impactX_HGCal_layer_7);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_7", &impactY_HGCal_layer_7, &b_impactY_HGCal_layer_7);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_8", &impactX_HGCal_layer_8, &b_impactX_HGCal_layer_8);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_8", &impactY_HGCal_layer_8, &b_impactY_HGCal_layer_8);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_9", &impactX_HGCal_layer_9, &b_impactX_HGCal_layer_9);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_9", &impactY_HGCal_layer_9, &b_impactY_HGCal_layer_9);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_10", &impactX_HGCal_layer_10, &b_impactX_HGCal_layer_10);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_10", &impactY_HGCal_layer_10, &b_impactY_HGCal_layer_10);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_11", &impactX_HGCal_layer_11, &b_impactX_HGCal_layer_11);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_11", &impactY_HGCal_layer_11, &b_impactY_HGCal_layer_11);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_12", &impactX_HGCal_layer_12, &b_impactX_HGCal_layer_12);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_12", &impactY_HGCal_layer_12, &b_impactY_HGCal_layer_12);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_13", &impactX_HGCal_layer_13, &b_impactX_HGCal_layer_13);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_13", &impactY_HGCal_layer_13, &b_impactY_HGCal_layer_13);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_14", &impactX_HGCal_layer_14, &b_impactX_HGCal_layer_14);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_14", &impactY_HGCal_layer_14, &b_impactY_HGCal_layer_14);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_15", &impactX_HGCal_layer_15, &b_impactX_HGCal_layer_15);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_15", &impactY_HGCal_layer_15, &b_impactY_HGCal_layer_15);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_16", &impactX_HGCal_layer_16, &b_impactX_HGCal_layer_16);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_16", &impactY_HGCal_layer_16, &b_impactY_HGCal_layer_16);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_17", &impactX_HGCal_layer_17, &b_impactX_HGCal_layer_17);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_17", &impactY_HGCal_layer_17, &b_impactY_HGCal_layer_17);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_18", &impactX_HGCal_layer_18, &b_impactX_HGCal_layer_18);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_18", &impactY_HGCal_layer_18, &b_impactY_HGCal_layer_18);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_19", &impactX_HGCal_layer_19, &b_impactX_HGCal_layer_19);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_19", &impactY_HGCal_layer_19, &b_impactY_HGCal_layer_19);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_20", &impactX_HGCal_layer_20, &b_impactX_HGCal_layer_20);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_20", &impactY_HGCal_layer_20, &b_impactY_HGCal_layer_20);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_21", &impactX_HGCal_layer_21, &b_impactX_HGCal_layer_21);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_21", &impactY_HGCal_layer_21, &b_impactY_HGCal_layer_21);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_22", &impactX_HGCal_layer_22, &b_impactX_HGCal_layer_22);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_22", &impactY_HGCal_layer_22, &b_impactY_HGCal_layer_22);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_23", &impactX_HGCal_layer_23, &b_impactX_HGCal_layer_23);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_23", &impactY_HGCal_layer_23, &b_impactY_HGCal_layer_23);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_24", &impactX_HGCal_layer_24, &b_impactX_HGCal_layer_24);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_24", &impactY_HGCal_layer_24, &b_impactY_HGCal_layer_24);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_25", &impactX_HGCal_layer_25, &b_impactX_HGCal_layer_25);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_25", &impactY_HGCal_layer_25, &b_impactY_HGCal_layer_25);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_26", &impactX_HGCal_layer_26, &b_impactX_HGCal_layer_26);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_26", &impactY_HGCal_layer_26, &b_impactY_HGCal_layer_26);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_27", &impactX_HGCal_layer_27, &b_impactX_HGCal_layer_27);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_27", &impactY_HGCal_layer_27, &b_impactY_HGCal_layer_27);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_28", &impactX_HGCal_layer_28, &b_impactX_HGCal_layer_28);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_28", &impactY_HGCal_layer_28, &b_impactY_HGCal_layer_28);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_29", &impactX_HGCal_layer_29, &b_impactX_HGCal_layer_29);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_29", &impactY_HGCal_layer_29, &b_impactY_HGCal_layer_29);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_30", &impactX_HGCal_layer_30, &b_impactX_HGCal_layer_30);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_30", &impactY_HGCal_layer_30, &b_impactY_HGCal_layer_30);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_31", &impactX_HGCal_layer_31, &b_impactX_HGCal_layer_31);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_31", &impactY_HGCal_layer_31, &b_impactY_HGCal_layer_31);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_32", &impactX_HGCal_layer_32, &b_impactX_HGCal_layer_32);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_32", &impactY_HGCal_layer_32, &b_impactY_HGCal_layer_32);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_33", &impactX_HGCal_layer_33, &b_impactX_HGCal_layer_33);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_33", &impactY_HGCal_layer_33, &b_impactY_HGCal_layer_33);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_34", &impactX_HGCal_layer_34, &b_impactX_HGCal_layer_34);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_34", &impactY_HGCal_layer_34, &b_impactY_HGCal_layer_34);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_35", &impactX_HGCal_layer_35, &b_impactX_HGCal_layer_35);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_35", &impactY_HGCal_layer_35, &b_impactY_HGCal_layer_35);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_36", &impactX_HGCal_layer_36, &b_impactX_HGCal_layer_36);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_36", &impactY_HGCal_layer_36, &b_impactY_HGCal_layer_36);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_37", &impactX_HGCal_layer_37, &b_impactX_HGCal_layer_37);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_37", &impactY_HGCal_layer_37, &b_impactY_HGCal_layer_37);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_38", &impactX_HGCal_layer_38, &b_impactX_HGCal_layer_38);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_38", &impactY_HGCal_layer_38, &b_impactY_HGCal_layer_38);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_39", &impactX_HGCal_layer_39, &b_impactX_HGCal_layer_39);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_39", &impactY_HGCal_layer_39, &b_impactY_HGCal_layer_39);
    T_DWC->SetBranchAddress("impactX_HGCal_layer_40", &impactX_HGCal_layer_40, &b_impactX_HGCal_layer_40);
    T_DWC->SetBranchAddress("impactY_HGCal_layer_40", &impactY_HGCal_layer_40, &b_impactY_HGCal_layer_40);
    T_DWC->SetBranchAddress("trackChi2_X", &trackChi2_X, &b_trackChi2_X);
    T_DWC->SetBranchAddress("trackChi2_Y", &trackChi2_Y, &b_trackChi2_Y);
    T_DWC->SetBranchAddress("dwcReferenceType", &dwcReferenceType, &b_dwcReferenceType);
    T_DWC->SetBranchAddress("m_x", &m_x, &b_m_x);
    T_DWC->SetBranchAddress("m_y", &m_y, &b_m_y);
    T_DWC->SetBranchAddress("b_x", &b_x, &b_b_x);
    T_DWC->SetBranchAddress("b_y", &b_y, &b_b_y);

    /*
      if(Is_Data){
      T_Meta->SetBranchAddress("configuration", &configuration);
      T_Meta->SetBranchAddress("biasCurrentCh0", &biasCurrentCh0);
      T_Meta->SetBranchAddress("biasCurrentCh1", &biasCurrentCh1);
      T_Meta->SetBranchAddress("biasCurrentCh2", &biasCurrentCh2);
      T_Meta->SetBranchAddress("biasCurrentCh3", &biasCurrentCh3);
      T_Meta->SetBranchAddress("humidity_RHDP4", &humidity_RHDP4);
      T_Meta->SetBranchAddress("TCassette07", &TCassette07);
      T_Meta->SetBranchAddress("tablePositionY", &tablePositionY);
      T_Meta->SetBranchAddress("humidity_air", &humidity_air);
      T_Meta->SetBranchAddress("temperature_air", &temperature_air);
      }*/
    Init_Runinfo();
}
void ntupleMaker::Init_Runinfo(){
    T_Rechit->GetEntry(0);
    beamE = beamEnergy;
    if( pdgID == 11 ){
        beam_str = "Ele";
        PID = 0;}
    else if( pdgID == 13){
        beam_str = "Mu";
        PID = 2;}
    else if( pdgID == 211){
        beam_str = "Pi";
        PID = 1;}
    else{
        cout << "unknown PDGID QQ" << endl;
        beam_str = "??";
        PID = -1;}
    if(Is_Data)
        runN = run;
    else
        runN = 0;
    cout << beam_str.c_str()  << " , "<< beamE << "GeV\n" << endl;
}

void ntupleMaker::NtupleMaker(){
  
    Init();
    char title[200];
    int start = fname.find_last_of("/");
    int end = fname.find(".root");
    string f_substr = fname.substr(start+1,end-start-1);

    if(Is_Data)
        sprintf(title,"output_root/data_%iGeV_%s.root",beamE,beam_str.c_str());
    else
        sprintf(title,"output_root/%s.root",f_substr.c_str());

    cout << "output file: " << title << endl;
    TFile outf(title,"recreate");
    TTree *outT1,*outT2;
    outT1 = T_Rechit->CopyTree("");
    outT2 = T_DWC->CopyTree("");
    TTree *outT3 = new TTree("rechit_var","rechit_var");
 
    vector<vector<double> > hit_tmp(NLAYER);
    vector<vector<double> > hit_x(NLAYER);
    vector<vector<double> > hit_y(NLAYER);
    vector<vector<double> > hit_z(NLAYER);
    int Nhits;
    int layerNhit[NLAYER];
    double totalE,totalNhit_CEE,totalNhit_CEH,totalE_CEE,totalE_CEH;
    double layerE[NLAYER];
    double E_1[NLAYER];
    double E_7[NLAYER];
    double E_19[NLAYER];
    double E_37[NLAYER];
    double E_61[NLAYER];
    double E_1_showerAxis[NLAYER];
    double E_7_showerAxis[NLAYER];
    double E_19_showerAxis[NLAYER];
    double E_37_showerAxis[NLAYER];
    double E_61_showerAxis[NLAYER];
    double E_ch[NLAYER][NCHANNEL];
    double x_ch[NLAYER][NCHANNEL];
    double y_ch[NLAYER][NCHANNEL];
    double z_ch[NLAYER][NCHANNEL];
    double impactX[NLAYER];
    double impactY[NLAYER];
    double COGx[NLAYER];
    double COGy[NLAYER];
    int maxID[NLAYER];
    double ahc_Esum;
    

    outT3->Branch("hit_mip","std::vector< std::vector<double> >",&hit_tmp);
    outT3->Branch("hit_x","std::vector< std::vector<double> >",&hit_x);
    outT3->Branch("hit_y","std::vector< std::vector<double> >",&hit_y);
    outT3->Branch("hit_z","std::vector< std::vector<double> >",&hit_z);
    outT3->Branch("COGx",COGx,"COGx[40]/D");
    outT3->Branch("COGy",COGy,"COGy[40]/D");
    outT3->Branch("layerNhit",layerNhit,"layerNhit[40]/I");
    outT3->Branch("totalE",&totalE,"totalE/D");
    outT3->Branch("totalE_CEE",&totalE_CEE,"totalE_CEE/D");
    outT3->Branch("totalE_CEH",&totalE_CEH,"totalE_CEH/D");
    outT3->Branch("totalNhit_CEE",&totalNhit_CEE,"totalNhit_CEE/D");
    outT3->Branch("totalNhit_CEH",&totalNhit_CEH,"totalNhit_CEH/D");
  

    outT3->Branch("layerE",layerE,"layerE[40]/D");
    outT3->Branch("layerE1",E_1,"layerE1[40]/D");
    outT3->Branch("layerE7",E_7,"layerE7[40]/D");
    outT3->Branch("layerE19",E_19,"layerE19[40]/D");
    outT3->Branch("layerE37",E_37,"layerE37[40]/D");
    outT3->Branch("layerE61",E_61,"layerE61[40]/D");
    outT3->Branch("layerE1_showerAxis",E_1_showerAxis,"layerE1_showerAxis[40]/D");
    outT3->Branch("layerE7_showerAxis",E_7_showerAxis,"layerE7_showerAxis[40]/D");
    outT3->Branch("layerE19_showerAxis",E_19_showerAxis,"layerE19_showerAxis[40]/D");
    outT3->Branch("layerE37_showerAxis",E_37_showerAxis,"layerE37_showerAxis[40]/D");
    outT3->Branch("layerE61_showerAxis",E_61_showerAxis,"layerE61_showerAxis[40]/D");
    outT3->Branch("impactX",impactX,"impactX[40]/D");
    outT3->Branch("impactY",impactY,"impactY[40]/D");
    outT3->Branch("maxID",maxID,"maxID[40]/I");
    outT3->Branch("ahc_Esum",&ahc_Esum,"ahc_Esum/D");

  

    // ------------------------------ Loop Over Events ------------------------------ //
  
    for(int ev = 0; ev < nevents; ++ev){
        if(ev %10000 == 0) cout << "Processing event: "<< ev << endl;
        GetData(ev);
        Nhits = NRechits;

        // Initialize
        for(int iL = 0; iL < NLAYER ; ++iL){
            hit_tmp[iL].clear();
            hit_x[iL].clear();
            hit_y[iL].clear();
            hit_z[iL].clear();
            layerE[iL] = 0;
            layerNhit[iL] = 0;
            E_1[iL] = 0;
            E_7[iL] = 0;
            E_19[iL] = 0;
            E_37[iL] = 0;
            E_61[iL] = 0;
            E_1_showerAxis[iL] = 0;
            E_7_showerAxis[iL] = 0;
            E_19_showerAxis[iL] = 0;
            E_37_showerAxis[iL] = 0;
            E_61_showerAxis[iL] = 0;
            maxID[iL] = -1;
            for(int ich = 0; ich < NCHANNEL; ++ich){
                E_ch[iL][ich] = 0;
            }
        }

        impactX[0] = impactX_HGCal_layer_1;
        impactX[1] = impactX_HGCal_layer_2;
        impactX[2] = impactX_HGCal_layer_3;
        impactX[3] = impactX_HGCal_layer_4;
        impactX[4] = impactX_HGCal_layer_5;
        impactX[5] = impactX_HGCal_layer_6;
        impactX[6] = impactX_HGCal_layer_7;
        impactX[7] = impactX_HGCal_layer_8;
        impactX[8] = impactX_HGCal_layer_9;
        impactX[9] = impactX_HGCal_layer_10;
        impactX[10] = impactX_HGCal_layer_11;
        impactX[11] = impactX_HGCal_layer_12;
        impactX[12] = impactX_HGCal_layer_13;
        impactX[13] = impactX_HGCal_layer_14;
        impactX[14] = impactX_HGCal_layer_15;
        impactX[15] = impactX_HGCal_layer_16;
        impactX[16] = impactX_HGCal_layer_17;
        impactX[17] = impactX_HGCal_layer_18;
        impactX[18] = impactX_HGCal_layer_19;
        impactX[19] = impactX_HGCal_layer_20;
        impactX[20] = impactX_HGCal_layer_21;
        impactX[21] = impactX_HGCal_layer_22;
        impactX[22] = impactX_HGCal_layer_23;
        impactX[23] = impactX_HGCal_layer_24;
        impactX[24] = impactX_HGCal_layer_25;
        impactX[25] = impactX_HGCal_layer_26;
        impactX[26] = impactX_HGCal_layer_27;
        impactX[27] = impactX_HGCal_layer_28;
        impactY[0] = impactY_HGCal_layer_1;
        impactY[1] = impactY_HGCal_layer_2;
        impactY[2] = impactY_HGCal_layer_3;
        impactY[3] = impactY_HGCal_layer_4;
        impactY[4] = impactY_HGCal_layer_5;
        impactY[5] = impactY_HGCal_layer_6;
        impactY[6] = impactY_HGCal_layer_7;
        impactY[7] = impactY_HGCal_layer_8;
        impactY[8] = impactY_HGCal_layer_9;
        impactY[9] = impactY_HGCal_layer_10;
        impactY[10] = impactY_HGCal_layer_11;
        impactY[11] = impactY_HGCal_layer_12;
        impactY[12] = impactY_HGCal_layer_13;
        impactY[13] = impactY_HGCal_layer_14;
        impactY[14] = impactY_HGCal_layer_15;
        impactY[15] = impactY_HGCal_layer_16;
        impactY[16] = impactY_HGCal_layer_17;
        impactY[17] = impactY_HGCal_layer_18;
        impactY[18] = impactY_HGCal_layer_19;
        impactY[19] = impactY_HGCal_layer_20;
        impactY[20] = impactY_HGCal_layer_21;
        impactY[21] = impactY_HGCal_layer_22;
        impactY[22] = impactY_HGCal_layer_23;
        impactY[23] = impactY_HGCal_layer_24;
        impactY[24] = impactY_HGCal_layer_25;
        impactY[25] = impactY_HGCal_layer_26;
        impactY[26] = impactY_HGCal_layer_27;
        impactY[27] = impactY_HGCal_layer_28;


        double dR = sqrt( impactX[0]*impactX[0] + impactY[0]*impactY[0]);

        int layer, chip, channel;
        double posx, posy, posz, energy, TOT;
        totalE = 0;
        totalE_CEE = 0;
        totalE_CEH = 0;
        totalNhit_CEE = 0;
        totalNhit_CEH = 0;
    
        if ( Is_Data )
            {
                ahc_Esum = 0;
            }
        else
            {
                ahc_Esum = ahc_energySum;
            }

        for(int h = 0; h < Nhits ; ++h){

            Getinfo(h, layer, chip, channel, posx, posy, posz, energy, TOT);
            // cout << " event: " << event << " dwcReferenceType: " << dwcReferenceType <<  " layer: " << layer << " chip: " << chip << " channel: " << channel << " energy: " << energy << endl;
            if ( layer == 36 ) continue;
            if ( layer == 37 ) continue;
            if ( energy < 0.5 ) continue;
            if ( layer == 1  )
                if ( chip == 0 ) continue;
            if ( chip == 3 )
                if ( channel == 22 ) continue;
            if ( energy < 0.5 ) continue;
            //Be careful here layerID start from 1
            //cout << " event: " << event << " dwcReferenceType: " << dwcReferenceType <<  " layer: " << layer << " chip: " << chip << " channel: " << channel << " energy: " << energy << endl;
            totalE += energy;
            if(layer <= 28) {
                totalE_CEE += energy;
                totalNhit_CEE++;
            }
            else {
                totalE_CEH += energy;
                totalNhit_CEH++;
            }
            layerNhit[layer-1]++;
            layerE[layer-1] += energy;
            hit_tmp[layer-1].push_back(energy);
            hit_x[layer-1].push_back(posx);
            hit_y[layer-1].push_back(posy);
            hit_z[layer-1].push_back(posz);
            E_ch[layer-1][ (chip*32) + (channel/2) ] += energy;
            x_ch[layer-1][ (chip*32) + (channel/2) ] = posx;
            y_ch[layer-1][ (chip*32) + (channel/2) ] = posy;
            z_ch[layer-1][ (chip*32) + (channel/2) ] = posz;

            // if ( chip == 0 ) {
            //     cout << "channel =" << channel << endl;
            // }
            // if ( chip == 0 && channel == 26 ) {
            //     cout << "chip0 channel26 x=" << posx << "y" << posy << endl;
            // }
            // else if ( chip == 1 && channel == 0 ) {
            //     cout << "chip1 channel0 x=" << posx << "y" << posy << endl;
            // }
        }

        for(int iL = 0; iL < NLAYER ; ++iL){
            //Find seed
            double Emax = -1;
            // for(int ich = 0; ich < NCHANNEL; ich++){
                // if( E_ch[iL][ich] > Emax){
                    // Emax = E_ch[iL][ich];
                    // maxID[iL] = ich;
                    // E_1[iL] = E_ch[iL][ich];
                // }
            // }
            for (int idx = 0; idx < (int)hit_tmp[iL].size(); idx++){
                if ( hit_tmp[iL][idx] > Emax ) {
                    Emax = hit_tmp[iL][idx];
                    maxID[iL] = idx;
                    E_1[iL] = hit_tmp[iL][idx];
                }
            }
            //Computing impact position of the shower on a given layer using Thorben's logE method
            double w, totalWeight;
            double numerator_x, numerator_y;
            numerator_x = 0;
            numerator_y = 0;
            totalWeight = 0;
            w = 0;

            float log_a = 3.5;
            float log_b = 1.0;

            for ( int ihit = 0 ; ihit < layerNhit[iL] ; ihit++ ) {
                double E = hit_tmp[iL].at(ihit);
                if ( E == 0 ) continue;
                w = std::max( log_a + log_b * log(E/layerE[iL]) , 0.0 );
                totalWeight += w;
                numerator_x += w * hit_x[iL].at(ihit);
                numerator_y += w * hit_y[iL].at(ihit);
            }

            COGx[iL] = numerator_x / totalWeight;
            COGy[iL] = numerator_y / totalWeight;
        }

        for(int iL = 0; iL < NLAYER; ++iL){
            double dx,dy,dR;
            for(int ich = 0; ich < NCHANNEL; ich++){
                if( E_ch[iL][ich] == 0 ) continue;
                // dx = x_ch[iL][ich] - x_ch [iL] [ maxID[iL] ];
                // dy = y_ch[iL][ich] - y_ch [iL] [ maxID[iL] ];
                // dR = sqrt(dx*dx + dy*dy);
                // if( dR < 1.12455*1.2) E_7[iL] += E_ch[iL][ich];
                // if( dR < 1.12455*2*1.2) E_19[iL] += E_ch[iL][ich];
                // if( dR < 1.12455*3*1.2) E_37[iL] += E_ch[iL][ich];
                // if( dR < 1.12455*4*1.2) E_61[iL] += E_ch[iL][ich];
                // // radial distribution w.r.t the shower axis
                dx = x_ch[iL][ich] - x_ch[iL] [ maxID[ iL%2 + 2 ] ]; // using the layer 3 & 4 energy max channel as shower axis
                dy = y_ch[iL][ich] - y_ch[iL] [ maxID[ iL%2 + 2 ] ];
                dR = sqrt(dx*dx + dy*dy);
                E_1_showerAxis[iL] = E_ch[iL] [ maxID[ iL%2 + 2 ] ];
                if( dR < 1.12455*1.2) E_7_showerAxis[iL] += E_ch[iL][ich];
                if( dR < 1.12455*2*1.2) E_19_showerAxis[iL] += E_ch[iL][ich];
                if( dR < 1.12455*3*1.2) E_37_showerAxis[iL] += E_ch[iL][ich];
                if( dR < 1.12455*4*1.2) E_61_showerAxis[iL] += E_ch[iL][ich];
            }
            for( int idx = 0; idx < (int)hit_tmp[iL].size(); idx++ ){
                dx = hit_x[iL][idx] - hit_x[iL][maxID[iL]];
                dy = hit_y[iL][idx] - hit_y[iL][maxID[iL]];
                dR = sqrt(dx*dx + dy*dy);
                if( dR < 1.12455*1.2) E_7[iL] += hit_tmp[iL][idx];
                if( dR < 1.12455*2*1.2) E_19[iL] += hit_tmp[iL][idx];
                if( dR < 1.12455*3*1.2) E_37[iL] += hit_tmp[iL][idx];
                if( dR < 1.12455*4*1.2) E_61[iL] += hit_tmp[iL][idx];

            }

            double E1devE7_showerAxis =  E_1_showerAxis[iL] / E_7_showerAxis[iL];
            double E1devE7 =  E1[iL] / E7[iL];
            //cout << iL << " " << E1devE7 << " " << E1devE7_showerAxis << " " << endl;
        }


        outT3->Fill();
    }
    outT1->Write();
    outT2->Write(); 
    outT3->Write();
    outf.Close();
}


void ntupleMaker::GetData(int evt){
    T_Rechit-> GetEntry(evt);
    T_DWC   -> GetEntry(evt);
}

void ntupleMaker::Getinfo(int ihit,int &layer,int &chip,int &channel,double &x, double &y, double &z, double &ene, double &TOT){
    layer = rechit_layer->at(ihit);
    chip = rechit_chip->at(ihit);
    channel = rechit_channel->at(ihit);
    x     = rechit_x    ->at(ihit);
    y     = rechit_y    ->at(ihit);
    z     = rechit_z    ->at(ihit);
    ene   = rechit_energy->at(ihit)
    TOT   = rechit_Tot->at(ihit);
}

bool ntupleMaker::Mask_NoisyChannel(int layer, int chip, int channel, double posx, double posy){
    if(chip==0&&channel==44){return true;}
    else if(chip==3&&channel==28){return true;}
    else if(chip==3&&channel==22){return true;}
    else if(layer==38 && posx<=2.0 && posx>=1.9 && posy<=4.6 && posy>= 3.3){return true;}
    else if(layer==37 && posx<=0 && posx>=-2 && posy<=-5.5 && posy>=-6.2){return true;}
    else if(layer==37 && posx<=-15 && posx>=-16 && posy<=-1.5 && posy>=-3){return true;}
    else{return false;}
}



double* ntupleMaker::Set_X0(double X0_arr[]){

    // len["Cu"] = 1.436; //cm                                  
    // Len["W"] = 0.35; //cm                                  
    // len["Lead"] = 0.56; //cm                               
    // len["Pb"] = 0.56; //cm                                 
    // len["CuW"] = 0.43; //cm                                
    // len["Al"] = 8.897; //cm

    // 4-July-2018
    // In all the checks done, Pb is 4.9 mm (~0.875 X0) and 
    // Cu is 6 mm (~0.42 X0)  

    // 10-July-2018
    // Odd layers have this config: 
    // Fe(0.3)-Pb(4.9)-Fe(0.3)-Air (4.6) - PCB - Si
    // Even layers have this config: 
    // Kapton(0.01)-CuW(1.2)-Cu(6)-CuW-Kapton-Si

    // 17-July-2018
    // Fe-Pb-Fe-Air-PCB-Si 
    // Kap-CuW-Cu-CuW-Si

    /*
    // 17-July-2018
    1 0.933   2 0.976   3 0.909   4 0.976   5 0.909
    6 0.976   7 0.909   8 0.976   9 0.909   10 0.976
    11 0.909  12 0.976  13 0.909  14 0.976  15 0.909
    16 1.143  17 0.909  18 0.976  19 0.909  20 1.43
    21 0.909  22 0.976  23 0.909  24 0.976  25 0.909
    26 0.976  27 0.909  28 0.976
    */
    double single_layer_X0[NLAYER];
    for( int i = 0 ; i < NLAYER ; ++i){
        if ( i % 2 == 0) single_layer_X0[i] = 0.909;
        else single_layer_X0[i] = 0.976;
    }
    single_layer_X0[0]  = 0.933;
    single_layer_X0[15] = 1.143;
    single_layer_X0[19] = 1.43;

    //Temporarily assign 4.5X0 to the layer in FH
    for(int i = 28 ; i < NLAYER ; ++i){
        single_layer_X0[i]  = 4.5;
    }
  
    double X0_sum = 0.;
    for(int iL = 0 ; iL < NLAYER ; ++iL){
        X0_sum += single_layer_X0[iL];
        X0_arr[iL] = X0_sum;
    }
  
    return X0_arr;
}


