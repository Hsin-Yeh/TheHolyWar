/////////////////////////////////////////////////////////
// Author : Hsin-Yeh Wu thankyouyou06@gmail.com
// Original FrameWork Author : Chia-hung Chien  chchien521@gmail.com 
// Just use the same class name as we used to.
// Branch Created Date : Nov 4, 2018
// For 2018October TestBeamAnalysis
/////////////////////////////////////////////////////////

#ifndef makePlots_h
#define makePlots_h

#include "PlotSetting.h"
#include "TTree.h"
#include "TROOT.h"
#include "TH2Poly.h"
#include "TApplication.h"
#include "TChain.h"
#include <string>
#include <vector>

using namespace std;

class makePlots{
public:
    makePlots();
    makePlots( TChain *c1, TChain *c2, TChain *c3, string filename );
 
    ~makePlots();
  
    void Loop();
    void PlotProducer(bool ignore_EE, bool hitmap);
    void Event_Display(); //Actually shows the average over some events

  
    //member
    int  beamE;
    int  PID; // 0 for electron, 1 for pion, 2 for muon
    string beam_str; // "Ele","Pi","Mu"
    bool Is_Data;
  
    PlotSetting *P = nullptr;

private:
    // Members
    string fname;
    //TApplication *app;
  
    //static int NLAYER = 40;
  
  
    TFile        *Inputfile;
    TTree        *T_Rechit;
    TTree        *T_DWC;
    TTree        *T_rechit_var;
    int          nevents;
  
    // Mainframe functions
    void Init();
    void Init_Runinfo();
    void GetData(int evt);
    void Getinfo(int nhit, int &layer, int &chip, int &channel, double &x, double &y, double &z, double &ene);    
    // Tool functions
    void InitTH2Poly(TH2Poly& poly); //Give frame to TH2Poly
    void InitTH2Poly_flower(TH2Poly& poly);
    void root_logon();
    double* Set_X0(double X0_arr[]); // Set accumulated X0 to 28 layers
    double findMedian(double a[], int n);
 
    ///////////////////////////////
    // Declaration of leaf types //
    ///////////////////////////////
    /*Data*/
    //For Rechit
    UInt_t          event;
    UInt_t          run;
    Int_t           pdgID;
    Float_t        beamEnergy;
    Float_t        trueBeamEnergy;
    UInt_t           NRechits
    vector<unsigned int> *rechit_detid;
    vector<unsigned int> *rechit_module;
    vector<unsigned int> *rechit_layer;
    vector<unsigned int> *rechit_chip;
    vector<unsigned int> *rechit_channel;
    vector<unsigned int> *rechit_type;
    vector<float>   *rechit_x;
    vector<float>   *rechit_y;
    vector<float>   *rechit_z;
    vector<int>     *rechit_iu;
    vector<int>     *rechit_iv;
    vector<float>   *rechit_energy;
    vector<float>   *rechit_energy_noHG;
    vector<float>   *rechit_amplitudeHigh;
    vector<float>   *rechit_amplitudeLow;
    vector<bool>     *rechit_hg_goodFit;
    vector<bool>     *rechit_lg_goodFit;
    vector<bool>     *rechit_hg_saturated;
    vector<bool>     *rechit_lg_saturated;
    vector<bool>     *rechit_fully_calibrated;
    vector<float>   *rechit_TS2High;
    vector<float>   *rechit_TS2Low;
    vector<float>   *rechit_TS3High;
    vector<float>   *rechit_TS3Low;
    vector<unsigned short>   *rechit_Tot;
    vector<float>   *rechit_timeMaxHG;
    vector<float>   *rechit_timeMaxLG;
    vector<unsigned short>   *rechit_toaRise;
    vector<unsigned short>   *rechit_toaFall;

    // For ImpactPoints (from Delayed wire chamber)
    // Declaration of leaf types
    Int_t           ntracks;
    Float_t         impactX_HGCal_layer_1;
    Float_t         impactY_HGCal_layer_1;
    Float_t         impactX_HGCal_layer_2;
    Float_t         impactY_HGCal_layer_2;
    Float_t         impactX_HGCal_layer_3;
    Float_t         impactY_HGCal_layer_3;
    Float_t         impactX_HGCal_layer_4;
    Float_t         impactY_HGCal_layer_4;
    Float_t         impactX_HGCal_layer_5;
    Float_t         impactY_HGCal_layer_5;
    Float_t         impactX_HGCal_layer_6;
    Float_t         impactY_HGCal_layer_6;
    Float_t         impactX_HGCal_layer_7;
    Float_t         impactY_HGCal_layer_7;
    Float_t         impactX_HGCal_layer_8;
    Float_t         impactY_HGCal_layer_8;
    Float_t         impactX_HGCal_layer_9;
    Float_t         impactY_HGCal_layer_9;
    Float_t         impactX_HGCal_layer_10;
    Float_t         impactY_HGCal_layer_10;
    Float_t         impactX_HGCal_layer_11;
    Float_t         impactY_HGCal_layer_11;
    Float_t         impactX_HGCal_layer_12;
    Float_t         impactY_HGCal_layer_12;
    Float_t         impactX_HGCal_layer_13;
    Float_t         impactY_HGCal_layer_13;
    Float_t         impactX_HGCal_layer_14;
    Float_t         impactY_HGCal_layer_14;
    Float_t         impactX_HGCal_layer_15;
    Float_t         impactY_HGCal_layer_15;
    Float_t         impactX_HGCal_layer_16;
    Float_t         impactY_HGCal_layer_16;
    Float_t         impactX_HGCal_layer_17;
    Float_t         impactY_HGCal_layer_17;
    Float_t         impactX_HGCal_layer_18;
    Float_t         impactY_HGCal_layer_18;
    Float_t         impactX_HGCal_layer_19;
    Float_t         impactY_HGCal_layer_19;
    Float_t         impactX_HGCal_layer_20;
    Float_t         impactY_HGCal_layer_20;
    Float_t         impactX_HGCal_layer_21;
    Float_t         impactY_HGCal_layer_21;
    Float_t         impactX_HGCal_layer_22;
    Float_t         impactY_HGCal_layer_22;
    Float_t         impactX_HGCal_layer_23;
    Float_t         impactY_HGCal_layer_23;
    Float_t         impactX_HGCal_layer_24;
    Float_t         impactY_HGCal_layer_24;
    Float_t         impactX_HGCal_layer_25;
    Float_t         impactY_HGCal_layer_25;
    Float_t         impactX_HGCal_layer_26;
    Float_t         impactY_HGCal_layer_26;
    Float_t         impactX_HGCal_layer_27;
    Float_t         impactY_HGCal_layer_27;
    Float_t         impactX_HGCal_layer_28;
    Float_t         impactY_HGCal_layer_28;
    Float_t         impactX_HGCal_layer_29;
    Float_t         impactY_HGCal_layer_29;
    Float_t         impactX_HGCal_layer_30;
    Float_t         impactY_HGCal_layer_30;
    Float_t         impactX_HGCal_layer_31;
    Float_t         impactY_HGCal_layer_31;
    Float_t         impactX_HGCal_layer_32;
    Float_t         impactY_HGCal_layer_32;
    Float_t         impactX_HGCal_layer_33;
    Float_t         impactY_HGCal_layer_33;
    Float_t         impactX_HGCal_layer_34;
    Float_t         impactY_HGCal_layer_34;
    Float_t         impactX_HGCal_layer_35;
    Float_t         impactY_HGCal_layer_35;
    Float_t         impactX_HGCal_layer_36;
    Float_t         impactY_HGCal_layer_36;
    Float_t         impactX_HGCal_layer_37;
    Float_t         impactY_HGCal_layer_37;
    Float_t         impactX_HGCal_layer_38;
    Float_t         impactY_HGCal_layer_38;
    Float_t         impactX_HGCal_layer_39;
    Float_t         impactY_HGCal_layer_39;
    Float_t         impactX_HGCal_layer_40;
    Float_t         impactY_HGCal_layer_40;
    Float_t         trackChi2_X;
    Float_t         trackChi2_Y;
    Int_t           dwcReferenceType;
    Double_t        m_x;
    Double_t        m_y;
    Double_t        b_x;
    Double_t        b_y;

    // List of branches
    TBranch        *b_event;   //!
    TBranch        *b_run;   //!
    TBranch        *b_ntracks;   //!
    TBranch        *b_impactX_HGCal_layer_1;   //!
    TBranch        *b_impactY_HGCal_layer_1;   //!
    TBranch        *b_impactX_HGCal_layer_2;   //!
    TBranch        *b_impactY_HGCal_layer_2;   //!
    TBranch        *b_impactX_HGCal_layer_3;   //!
    TBranch        *b_impactY_HGCal_layer_3;   //!
    TBranch        *b_impactX_HGCal_layer_4;   //!
    TBranch        *b_impactY_HGCal_layer_4;   //!
    TBranch        *b_impactX_HGCal_layer_5;   //!
    TBranch        *b_impactY_HGCal_layer_5;   //!
    TBranch        *b_impactX_HGCal_layer_6;   //!
    TBranch        *b_impactY_HGCal_layer_6;   //!
    TBranch        *b_impactX_HGCal_layer_7;   //!
    TBranch        *b_impactY_HGCal_layer_7;   //!
    TBranch        *b_impactX_HGCal_layer_8;   //!
    TBranch        *b_impactY_HGCal_layer_8;   //!
    TBranch        *b_impactX_HGCal_layer_9;   //!
    TBranch        *b_impactY_HGCal_layer_9;   //!
    TBranch        *b_impactX_HGCal_layer_10;   //!
    TBranch        *b_impactY_HGCal_layer_10;   //!
    TBranch        *b_impactX_HGCal_layer_11;   //!
    TBranch        *b_impactY_HGCal_layer_11;   //!
    TBranch        *b_impactX_HGCal_layer_12;   //!
    TBranch        *b_impactY_HGCal_layer_12;   //!
    TBranch        *b_impactX_HGCal_layer_13;   //!
    TBranch        *b_impactY_HGCal_layer_13;   //!
    TBranch        *b_impactX_HGCal_layer_14;   //!
    TBranch        *b_impactY_HGCal_layer_14;   //!
    TBranch        *b_impactX_HGCal_layer_15;   //!
    TBranch        *b_impactY_HGCal_layer_15;   //!
    TBranch        *b_impactX_HGCal_layer_16;   //!
    TBranch        *b_impactY_HGCal_layer_16;   //!
    TBranch        *b_impactX_HGCal_layer_17;   //!
    TBranch        *b_impactY_HGCal_layer_17;   //!
    TBranch        *b_impactX_HGCal_layer_18;   //!
    TBranch        *b_impactY_HGCal_layer_18;   //!
    TBranch        *b_impactX_HGCal_layer_19;   //!
    TBranch        *b_impactY_HGCal_layer_19;   //!
    TBranch        *b_impactX_HGCal_layer_20;   //!
    TBranch        *b_impactY_HGCal_layer_20;   //!
    TBranch        *b_impactX_HGCal_layer_21;   //!
    TBranch        *b_impactY_HGCal_layer_21;   //!
    TBranch        *b_impactX_HGCal_layer_22;   //!
    TBranch        *b_impactY_HGCal_layer_22;   //!
    TBranch        *b_impactX_HGCal_layer_23;   //!
    TBranch        *b_impactY_HGCal_layer_23;   //!
    TBranch        *b_impactX_HGCal_layer_24;   //!
    TBranch        *b_impactY_HGCal_layer_24;   //!
    TBranch        *b_impactX_HGCal_layer_25;   //!
    TBranch        *b_impactY_HGCal_layer_25;   //!
    TBranch        *b_impactX_HGCal_layer_26;   //!
    TBranch        *b_impactY_HGCal_layer_26;   //!
    TBranch        *b_impactX_HGCal_layer_27;   //!
    TBranch        *b_impactY_HGCal_layer_27;   //!
    TBranch        *b_impactX_HGCal_layer_28;   //!
    TBranch        *b_impactY_HGCal_layer_28;   //!
    TBranch        *b_impactX_HGCal_layer_29;   //!
    TBranch        *b_impactY_HGCal_layer_29;   //!
    TBranch        *b_impactX_HGCal_layer_30;   //!
    TBranch        *b_impactY_HGCal_layer_30;   //!
    TBranch        *b_impactX_HGCal_layer_31;   //!
    TBranch        *b_impactY_HGCal_layer_31;   //!
    TBranch        *b_impactX_HGCal_layer_32;   //!
    TBranch        *b_impactY_HGCal_layer_32;   //!
    TBranch        *b_impactX_HGCal_layer_33;   //!
    TBranch        *b_impactY_HGCal_layer_33;   //!
    TBranch        *b_impactX_HGCal_layer_34;   //!
    TBranch        *b_impactY_HGCal_layer_34;   //!
    TBranch        *b_impactX_HGCal_layer_35;   //!
    TBranch        *b_impactY_HGCal_layer_35;   //!
    TBranch        *b_impactX_HGCal_layer_36;   //!
    TBranch        *b_impactY_HGCal_layer_36;   //!
    TBranch        *b_impactX_HGCal_layer_37;   //!
    TBranch        *b_impactY_HGCal_layer_37;   //!
    TBranch        *b_impactX_HGCal_layer_38;   //!
    TBranch        *b_impactY_HGCal_layer_38;   //!
    TBranch        *b_impactX_HGCal_layer_39;   //!
    TBranch        *b_impactY_HGCal_layer_39;   //!
    TBranch        *b_impactX_HGCal_layer_40;   //!
    TBranch        *b_impactY_HGCal_layer_40;   //!
    TBranch        *b_trackChi2_X;   //!
    TBranch        *b_trackChi2_Y;   //!
    TBranch        *b_dwcReferenceType;   //!
    TBranch        *b_m_x;   //!
    TBranch        *b_m_y;   //!
    TBranch        *b_b_x;   //!
    TBranch        *b_b_y;   //!

    // For rechit_var
    vector<vector<double> > *hit_mip;
    vector<vector<double> > *hit_x;
    vector<vector<double> > *hit_y;
    vector<vector<double> > *hit_z;
    Int_t           layerNhit[40];
    Double_t        totalE;
    Double_t        totalNhit_CEE;
    Double_t        totalNhit_CEH;
    Double_t        totalE_CEE;
    Double_t        totalE_CEH;
    Double_t        layerE[40];
    Double_t        layerE1[40];
    Double_t        layerE7[40];
    Double_t        layerE19[40];
    Double_t        layerE37[40];
    Double_t        layerE61[40];
    Double_t        layerE1_showerAxis[40];
    Double_t        layerE7_showerAxis[40];
    Double_t        layerE19_showerAxis[40];
    Double_t        layerE37_showerAxis[40];
    Double_t        layerE61_showerAxis[40];
    Double_t        impactX[40];
    Double_t        impactY[40];
    Double_t        COGx[40];
    Double_t        COGy[40];
    Int_t           maxID[40];
    Double_t        ahc_Esum;

    // List of branches
    TBranch        *b_hit_mip;   //!
    TBranch        *b_hit_x;   //!
    TBranch        *b_hit_y;   //!
    TBranch        *b_hit_z;   //!
    TBranch        *b_layerNhit;   //!
    TBranch        *b_totalE;   //!
    TBranch        *b_totalE_CEE;   //!
    TBranch        *b_totalE_CEH;   //!
    TBranch        *b_totalNhit_CEE;   //!
    TBranch        *b_totalNhit_CEH;   //!
    TBranch        *b_layerE;   //!
    TBranch        *b_layerE1;   //!
    TBranch        *b_layerE7;   //!
    TBranch        *b_layerE19;   //!
    TBranch        *b_layerE37;   //!
    TBranch        *b_layerE61;   //!
    TBranch        *b_layerE1_showerAxis;   //!
    TBranch        *b_layerE7_showerAxis;   //!
    TBranch        *b_layerE19_showerAxis;   //!
    TBranch        *b_layerE37_showerAxis;   //!
    TBranch        *b_layerE61_showerAxis;   //!
    TBranch        *b_impactX;   //!
    TBranch        *b_impactY;   //!
    TBranch        *b_COGx;   //!
    TBranch        *b_COGy;   //!
    TBranch        *b_maxID;
    TBranch        *b_ahc_Esum;
};

#endif

