void root_logon(){

    cout << endl << "Welcome to the ATLAS rootlogon.C" << endl;

    //
    // based on a style file from BaBar
    //

    //..BABAR style from RooLogon.C in workdir
    TStyle *atlasStyle= new TStyle("ATLAS","Atlas style");

    // use plain black on white colors
    Int_t icol=0;
    atlasStyle->SetFrameBorderMode(icol);
    atlasStyle->SetCanvasBorderMode(icol);
    atlasStyle->SetPadBorderMode(icol);
    atlasStyle->SetPadColor(icol);
    atlasStyle->SetCanvasColor(icol);
    atlasStyle->SetStatColor(icol);
    //atlasStyle->SetFillColor(icol);

    // set the paper & margin sizes
    atlasStyle->SetPaperSize(20,26);
    atlasStyle->SetPadTopMargin(0.05);
    atlasStyle->SetPadTopMargin(0.11);
    atlasStyle->SetPadRightMargin(0.05);
    atlasStyle->SetPadBottomMargin(0.1);
    atlasStyle->SetPadLeftMargin(0.12);

    // use large fonts
    //Int_t font=72;
    Int_t font=42;
    Double_t tsize=0.045;
    atlasStyle->SetTextFont(font);



    atlasStyle->SetTextSize(tsize);
    atlasStyle->SetLabelFont(font,"x");
    atlasStyle->SetTitleFont(font,"x");
    atlasStyle->SetLabelFont(font,"y");
    atlasStyle->SetTitleFont(font,"y");
    atlasStyle->SetLabelFont(font,"z");
    atlasStyle->SetTitleFont(font,"z");

    atlasStyle->SetLabelSize(tsize,"x");
    atlasStyle->SetTitleSize(tsize,"x");
    atlasStyle->SetLabelSize(tsize,"y");
    atlasStyle->SetTitleSize(tsize,"y");
    atlasStyle->SetLabelSize(tsize,"z");
    atlasStyle->SetTitleSize(tsize,"z");

    atlasStyle->SetLabelOffset(tsize/4,"x");
    atlasStyle->SetLabelOffset(tsize/4,"y");
  


    //use bold lines and markers
    atlasStyle->SetMarkerStyle(20);
    atlasStyle->SetMarkerSize(0.5);
    atlasStyle->SetHistLineWidth(2.);
    atlasStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

    //
    atlasStyle->SetLegendFillColor(0);
    atlasStyle->SetLegendFont(62);
    //atlasStyle->SetLegendTextSize(0.03);

    //get rid of X error bars and y error bar caps
    //atlasStyle->SetErrorX(0.001);

    //do not display any of the standard histogram decorations
    //  atlasStyle->SetOptTitle(0);
    //atlasStyle->SetOptStat(1111);
    atlasStyle->SetOptStat(0);
    //atlasStyle->SetOptFit(1111);
    atlasStyle->SetOptFit(0);

    // put tick marks on top and RHS of plots
    atlasStyle->SetPadTickX(1);
    atlasStyle->SetPadTickY(1);

    //  gROOT->SetStyle("Plain");

    //gStyle->SetPadTickX(1);
    //gStyle->SetPadTickY(1);

    gROOT->SetStyle("ATLAS");
    gROOT->ForceStyle();
}

int Color(int c)
{
    if(c == 0){ return 633;}
    else if(c == 1){ return 600;}
    else if(c == 2){ return 800;}
    else if(c == 3){ return 419;}
    else if(c == 4){ return 880;}
    else if(c == 5){ return 803;}
    else{ return 0; }
}

void Compare_DataMC(){

    int MAXMODULE = 94;
    int NCHIP = 4;
    int NCHANNEL = 64;
    int imodule = 79;
    int NLAYER = 28;
    string Energy;
  
    char title[200];
    char plot_title[200];

    //TCanvas* c1 = new TCanvas();
    TCanvas *c1 = new TCanvas("c1","",600,650);
    //TCanvas *c1 = new TCanvas("c1", "c1",260,71,886,635);
    //c1->Range(-0.1244696,-0.007838658,1.125884,0.04384749);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    c1->SetGridx();
    c1->SetGridy();
    c1->SetBottomMargin(0.1516588);
    c1->SetFrameBorderMode(0);
    c1->SetFrameLineWidth(2);
    c1->SetFrameBorderMode(0);

    TLegend* legend = new TLegend(0.1,0.75,0.3,0.9);

    
    //c1->cd();

    /*
    TCanvas *c2 = new TCanvas("c2","c2",6400,3600);
    TCanvas *c3 = new TCanvas("c3","c3",6400,3600);
    c2->Divide(7,4);
    c3->Divide(7,4);
    */
    
    gStyle->SetOptStat(0);
    //gROOT->SetBatch(kTRUE);
    TImage *img = TImage::Create();
  
    //root_logon();

    string filename;
    ifstream infile("data_input.txt");
    infile >> filename;
    int start = filename.find_last_of("/");
    int end = filename.find(".root");
    string f_substr = filename.substr(start+1,end-start-1);

    start = filename.find("sim_");
    end = filename.find("GeV");
    Energy = filename.substr(start+4,end-start-4);

    cout << "Energy = " << Energy << " GeV " << endl;

    //sprintf(title,"%s",filename.c_str());
    sprintf(title,"root_plot/%s.root",f_substr.c_str());
    TFile f_MC(title);
    sprintf(title,"root_plot/plot_data_%sGeV_Ele.root",Energy.c_str());
    TFile f_Data(title);
    sprintf(title,"root_plot/plot_ntuple_sim_config22_pdgID11_beamMomentum%s_listFTFP_BERT_EMN.root",Energy.c_str());
    //sprintf(title,"root_plot/plot_sim_%sGeV_30TH1_300TH2_10X1_1X2.root",Energy.c_str());
    //sprintf(title,"root_plot/%s_noSmearingSamples.root",f_substr.c_str());
    TFile f_MC_original(title);

    sprintf(title,"output.root");
    TFile f_output(title,"recreate");

    TH1D *h_E1devE7[3][28];
    TH1D *h_E7devE19[3][28];
    TH1D *h_totalCEE[3];
    TH1D *h_E1devE7_differentMaxID_1[3][28];
    TH1D *h_E1devE7_differentMaxID_2[3][28];
    TGraph *g_Average_Nhits[3];
    TH1D *h_bx_by[3];
    TH1D *h_subtract;
    TH1D *h_E1devE7_lessBins[3][28];
    TH1D *h_E7devE19_lessBins[3][28];
    TH1D *h_E1devE7_smallAngle_lessBins[3][28];
    TH1D *h_E7devE19_smallAngle_lessBins[3][28];


    sprintf(title,"histo/h_totalCEE");
    h_totalCEE[0] = (TH1D *)f_MC.Get(title);
    h_totalCEE[0]->SetLineColor(Color(0));
    h_totalCEE[0]->SetLineWidth(2);
    h_totalCEE[1] = (TH1D *)f_MC_original.Get(title);
    h_totalCEE[1]->SetLineColor(4);
    h_totalCEE[1]->SetLineWidth(2);
    h_totalCEE[2] = (TH1D *)f_Data.Get(title);
    h_totalCEE[2]->SetLineColor(1);
    h_totalCEE[2]->SetLineWidth(2);
    
    
  
    sprintf(title,"graph/AverageNhits");
    g_Average_Nhits[0] = (TGraph *)f_MC.Get(title);
    g_Average_Nhits[0]->SetLineColor(Color(0));
    g_Average_Nhits[0]->SetMarkerColor(Color(0));
    g_Average_Nhits[0]->SetLineWidth(2);
    g_Average_Nhits[1] = (TGraph *)f_MC_original.Get(title);
    g_Average_Nhits[1]->SetLineColor(4);
    g_Average_Nhits[1]->SetMarkerColor(4);
    g_Average_Nhits[1]->SetLineWidth(2);
    g_Average_Nhits[2] = (TGraph *)f_Data.Get(title);
    g_Average_Nhits[2]->SetLineColor(1);
    g_Average_Nhits[2]->SetLineWidth(2);

/*
      sprintf(title,"histo/h_bx_by");
      h_bx_by[0] = (TGraph *)f_MC.Get(title);
      h_bx_by[0]->SetLineColor(Color(0));
      h_bx_by[0]->SetMarkerColor(Color(0));
      h_bx_by[0]->SetLineWidth(2);
      h_bx_by[1] = (TGraph *)f_MC_original.Get(title);
      h_bx_by[1]->SetLineColor(4);
      h_bx_by[1]->SetMarkerColor(4);
      h_bx_by[1]->SetLineWidth(2);
      h_bx_by[2] = (TGraph *)f_Data.Get(title);
      h_bx_by[2]->SetLineColor(1);
      h_bx_by[2]->SetLineWidth(2);

      h_bx_by[0]->Draw("colz");
      c1->Update();
      c1->SaveAs("bxbyMC");
      h_bx_by[1]->Draw("colz");
      c1->Update();
      c1->SaveAs("bxbyMCoriginal");
      h_bx_by[2]->Draw("colz");
      c1->Update();
      c1->SaveAs("bxbyData");
*/
    double chi_cross_E1devE7[NLAYER], chi_original_E1devE7[NLAYER], chi_cross_E7devE19[NLAYER], chi_original_E7devE19[NLAYER];
    double layerID[NLAYER];
  
    for(int iL = 0; iL < NLAYER ; ++iL){
	layerID[iL] = iL+1;
      
	sprintf(title,"histo/layer%i/layer%i_E1devE7_smallAngle_lessBins",iL+1, iL+1);
	h_E1devE7[0][iL] = (TH1D *)f_MC.Get(title);
	h_E1devE7[0][iL]->SetLineColor(Color(0));
	h_E1devE7[0][iL]->SetLineWidth(2.0);
	h_E1devE7[1][iL] = (TH1D *)f_MC_original.Get(title);
	h_E1devE7[1][iL]->SetLineColor(4);
	h_E1devE7[1][iL]->SetLineWidth(2);
	h_E1devE7[2][iL] = (TH1D *)f_Data.Get(title);
	h_E1devE7[2][iL]->SetLineColor(1);
	h_E1devE7[2][iL]->SetLineWidth(2);


	int n = h_E1devE7[1][iL]->GetNbinsX();
	cout << n << endl;
	Double_t res1[n], res2[n], x[20];
    
	chi_original_E1devE7[iL] = h_E1devE7[1][iL]->Chi2Test(h_E1devE7[2][iL],"UU NORM CHI2/NDF P",res2);
	chi_cross_E1devE7[iL] = h_E1devE7[0][iL]->Chi2Test(h_E1devE7[2][iL],"UU NORM CHI2/NDF P",res1);

	sprintf(title,"histo/layer%i/layer%i_E7devE19_smallAngle_lessBins",iL+1, iL+1);
	h_E7devE19[0][iL] = (TH1D *)f_MC.Get(title);
	h_E7devE19[0][iL]->SetLineColor(Color(0));
	h_E7devE19[0][iL]->SetLineWidth(2.0);
	h_E7devE19[1][iL] = (TH1D *)f_MC_original.Get(title);
	h_E7devE19[1][iL]->SetLineColor(4);
	h_E7devE19[1][iL]->SetLineWidth(2);
	h_E7devE19[2][iL] = (TH1D *)f_Data.Get(title);
	h_E7devE19[2][iL]->SetLineColor(1);
	h_E7devE19[2][iL]->SetLineWidth(2);

	chi_original_E7devE19[iL] = h_E7devE19[1][iL]->Chi2Test(h_E7devE19[2][iL],"UU NORM CHI2/NDF P",res2);
	chi_cross_E7devE19[iL] = h_E7devE19[0][iL]->Chi2Test(h_E7devE19[2][iL],"UU NORM CHI2/NDF P",res1);


	sprintf(title,"histo/layer%i/layer%i_E1devE7_maxID50_70",iL+1, iL+1);
	h_E1devE7_differentMaxID_1[0][iL] = (TH1D *)f_MC.Get(title);
	h_E1devE7_differentMaxID_1[0][iL]->SetLineColor(Color(0));
	h_E1devE7_differentMaxID_1[0][iL]->SetLineWidth(2.0);
	h_E1devE7_differentMaxID_1[1][iL] = (TH1D *)f_MC_original.Get(title);
	h_E1devE7_differentMaxID_1[1][iL]->SetLineColor(4);
	h_E1devE7_differentMaxID_1[1][iL]->SetLineWidth(2);
	h_E1devE7_differentMaxID_1[2][iL] = (TH1D *)f_Data.Get(title);
	h_E1devE7_differentMaxID_1[2][iL]->SetLineColor(1);
	h_E1devE7_differentMaxID_1[2][iL]->SetLineWidth(2);

	sprintf(title,"histo/layer%i/layer%i_E1devE7_maxID75_100",iL+1, iL+1);
	h_E1devE7_differentMaxID_2[0][iL] = (TH1D *)f_MC.Get(title);
	h_E1devE7_differentMaxID_2[0][iL]->SetLineColor(Color(0));
	h_E1devE7_differentMaxID_2[0][iL]->SetLineWidth(2.0);
	h_E1devE7_differentMaxID_2[1][iL] = (TH1D *)f_MC_original.Get(title);
	h_E1devE7_differentMaxID_2[1][iL]->SetLineColor(4);
	h_E1devE7_differentMaxID_2[1][iL]->SetLineWidth(2);
	h_E1devE7_differentMaxID_2[2][iL] = (TH1D *)f_Data.Get(title);
	h_E1devE7_differentMaxID_2[2][iL]->SetLineColor(1);
	h_E1devE7_differentMaxID_2[2][iL]->SetLineWidth(2);
    }
/*
    sprintf(title,"Total Energy CEE ");
    h_totalCEE[0]->SetTitle("Total Energy CEE");
    h_totalCEE[0]->Draw("HIST");
    h_totalCEE[1]->Draw("HISTSame");
    h_totalCEE[2]->Draw("Same");
*/
    legend->AddEntry(h_totalCEE[0],"w/ Xtalk","L");
    legend->AddEntry(h_totalCEE[1],"w/o Xtalk","L");
    //legend->AddEntry(h_totalCEE[0],"w/ smearing","L");
    //legend->AddEntry(h_totalCEE[1],"w/o smearing","L");
    //legend->AddEntry(h_totalCEE[2],"Data","LP");
    //legend->AddEntry(h_totalCEE[0],"new method","L");
    //legend->AddEntry(h_totalCEE[1],"old method","L");
    legend->AddEntry(h_totalCEE[2],"Data","LP");
    //  sprintf(title,"beamE=%dGeV",Energy);
    //  legend->SetHeader(title);
    legend->SetTextSize(0.035);
    legend->Draw();
//    c1->Update();
    sprintf(title,"plots/%s/Total Energy CEE.png",f_substr.c_str());
    //  c1->SaveAs(title);
    img->FromPad(c1);
    img->WriteImage(title);

/*
    // Compare Average_Nhits
    c1->SetGrid();
    TLegend* legend_Nhits = new TLegend(0.7,0.75,0.9,0.9);
    sprintf(title,"Total Energy CEE ");
    g_Average_Nhits[0]->SetTitle("Average_Nhits");
    g_Average_Nhits[0]->GetYaxis()->SetNdivisions(20);
    g_Average_Nhits[0]->GetYaxis()->SetTitle("Average #hits");
    g_Average_Nhits[0]->GetXaxis()->SetTitle("LayerID");
    g_Average_Nhits[1]->Draw("APL");
    g_Average_Nhits[2]->Draw("PLSame");
    g_Average_Nhits[0]->Draw("PLSame");
    legend_Nhits->AddEntry(g_Average_Nhits[0],"w/ Xtalk","L");
    legend_Nhits->AddEntry(h_totalCEE[1],"w/o Xtalk","L");
    //legend_Nhits->AddEntry(g_Average_Nhits[0],"new method","L");
    //legend_Nhits->AddEntry(h_totalCEE[1],"old method","L");
    legend_Nhits->AddEntry(g_Average_Nhits[2],"Data","LP");
    legend_Nhits->Draw();
    c1->Update();
    sprintf(title,"plots/%s/Average_Nhits_%sGeV.png",f_substr.c_str(), Energy.c_str());
    c1->SaveAs(title);
    img->FromPad(c1);
    img->WriteImage(title);
*/

    for(int iL = 0; iL < NLAYER ; ++iL){

	TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
	TPad *pad2 = new TPad("pad2","pad2",0,0.,1,0.3);

	c1->SetBorderSize(5);
	c1->cd();
	sprintf(title,"TB2018 %sGeV.", Energy.c_str());
	h_E1devE7[0][iL]->GetXaxis()->SetLabelFont(63); //font in pixels
	h_E1devE7[0][iL]->GetXaxis()->SetLabelSize(16); //in pixels
	h_E1devE7[0][iL]->GetYaxis()->SetLabelFont(63); //font in pixels
	h_E1devE7[0][iL]->GetYaxis()->SetLabelSize(16); //in pixelsp
	//h_E1devE7[0][iL]->GetYaxis()->SetRangeUser(0,0.06);
	//h_E1devE7[0][iL]->SetTitle(title);
	pad1->SetBottomMargin(0);
	pad1->Draw();
	pad1->cd();
	pad1->SetGrid();
	pad1->SetBorderSize(2);
	h_E1devE7[0][iL]->DrawCopy("HIST");
	h_E1devE7[1][iL]->DrawCopy("HISTSame");
	h_E1devE7[2][iL]->Draw("Same");
	legend->Draw();

	c1->cd();

	pad2->SetTopMargin(0);
	pad2->SetBottomMargin(0.6);
	pad2->Draw();
	pad2->cd();
	pad2->SetGrid();
	h_E1devE7[0][iL]->Divide(h_E1devE7[2][iL]);
	h_E1devE7[0][iL]->GetYaxis()->SetRangeUser(0,2);
	h_E1devE7[0][iL]->SetMarkerColor(Color(0));
	h_E1devE7[0][iL]->SetTitleOffset(1);
	h_E1devE7[0][iL]->SetMarkerSize(0.2);
	h_E1devE7[0][iL]->SetLineWidth(1);
	h_E1devE7[0][iL]->GetYaxis()->SetNdivisions(5);
	h_E1devE7[0][iL]->GetYaxis()->SetTitle("MC / Data");
	h_E1devE7[0][iL]->GetYaxis()->SetLabelFont(63);
	h_E1devE7[0][iL]->GetYaxis()->SetLabelSize(16);
	h_E1devE7[0][iL]->GetYaxis()->SetTitleSize(0.13);
	//h_E1devE7[0][iL]->GetYaxis()->SetTitleOffset(0.8);

	h_E1devE7[0][iL]->GetXaxis()->SetTitle("E1/E7 contaminant variable");
	h_E1devE7[0][iL]->GetXaxis()->SetLabelFont(63);
	//h_E1devE7[0][iL]->GetXaxis()->SetLabelOffset(0.1125);
	h_E1devE7[0][iL]->GetXaxis()->SetLabelSize(16);
	h_E1devE7[0][iL]->GetXaxis()->SetTitleSize(0.13);
	//h_E1devE7[0][iL]->GetXaxis()->SetTitleOffset(6);
	//h_E1devE7[0][iL]->GetXaxis()->SetTitleFont(42);
	h_E1devE7[0][iL]->Draw("ep");
	h_E1devE7[1][iL]->SetMarkerSize(0.2);
	h_E1devE7[1][iL]->SetLineWidth(1);
	h_E1devE7[1][iL]->Divide(h_E1devE7[2][iL]);
	h_E1devE7[1][iL]->SetMarkerColor(Color(1));
	h_E1devE7[1][iL]->Draw("epSame");
	c1->cd();
	c1->Update();
	gPad->WaitPrimitive();

	sprintf(title,"plots/%s/E1devE7_layer%02d_%sGeV.png", f_substr.c_str(), iL+1, Energy.c_str());
	img->FromPad(c1);
	img->WriteImage(title);
	cout << title << " plotted!! " << endl;
/*
	c2->cd(iL+1);
	c1->DrawClonePad();
	c2->Update();
*/

	c1->cd();
	sprintf(title,"E7devE19_layer%02d_%sGeV", iL+1, Energy.c_str());
	h_E7devE19[0][iL]->GetXaxis()->SetLabelFont(63); //font in pixels
	h_E7devE19[0][iL]->GetXaxis()->SetLabelSize(16); //in pixels
	h_E7devE19[0][iL]->GetYaxis()->SetLabelFont(63); //font in pixels
	h_E7devE19[0][iL]->GetYaxis()->SetLabelSize(16); //in pixelsp
	//h_E7devE19[0][iL]->GetYaxis()->SetRangeUser(0,0.06);
	h_E7devE19[0][iL]->SetTitle(title);
	pad1->SetBottomMargin(0);
	pad1->Draw();
	pad1->cd();
	pad1->SetGrid();
	h_E7devE19[0][iL]->DrawCopy("HIST");
	h_E7devE19[1][iL]->DrawCopy("HISTSame");
	h_E7devE19[2][iL]->Draw("Same");
	legend->Draw();
	c1->cd();
	pad2->SetTopMargin(0);
	pad2->Draw();
	pad2->cd();
	pad2->SetGrid();
	h_E7devE19[0][iL]->Divide(h_E7devE19[2][iL]);
	h_E7devE19[0][iL]->GetYaxis()->SetRangeUser(0,2);
	h_E7devE19[0][iL]->SetMarkerColor(Color(0));
	h_E7devE19[0][iL]->SetTitle("Bin by Bin Ratio of MC and Data");
	h_E7devE19[0][iL]->SetTitleOffset(1);
	h_E7devE19[0][iL]->SetMarkerSize(0.2);
	h_E7devE19[0][iL]->SetLineWidth(1);
	h_E7devE19[0][iL]->GetYaxis()->SetNdivisions(5);
	h_E7devE19[0][iL]->GetYaxis()->SetTitle("MC / Data");
	h_E7devE19[0][iL]->GetYaxis()->SetTitleSize(0.08);
	h_E7devE19[0][iL]->GetYaxis()->SetTitleOffset(0.5);
	h_E7devE19[0][iL]->Draw("ep");
	
	h_E7devE19[1][iL]->SetMarkerSize(0.2);
	h_E7devE19[1][iL]->SetLineWidth(1);
	h_E7devE19[1][iL]->Divide(h_E7devE19[2][iL]);
	h_E7devE19[1][iL]->SetMarkerColor(Color(1));
	h_E7devE19[1][iL]->Draw("epSame");
	c1->cd();
	c1->Update();

	sprintf(title,"plots/%s/E7devE19_layer%02d_%sGeV.png", f_substr.c_str(), iL+1, Energy.c_str());
	img->FromPad(c1);
	img->WriteImage(title);
	cout << title << " plotted!! " << endl;
/*
	c3->cd(iL+1);
	c1->DrawClonePad();
	c3->Update();
*/
    }
/*
    sprintf(title,"plots/%s/E1devE7_%sGeV.png", f_substr.c_str(), Energy.c_str());
    c2->SaveAs(title);
    sprintf(title,"plots/%s/E7devE19_%sGeV.png", f_substr.c_str(), Energy.c_str());
    c3->SaveAs(title);
*/

    TCanvas* c4 = new TCanvas();
    c4->cd();
    c4->SetGrid();
    TGraph* g_chi_cross_E1devE7 = new TGraph(NLAYER, layerID, chi_cross_E1devE7);
    g_chi_cross_E1devE7->SetMarkerColor(1);
    g_chi_cross_E1devE7->SetMarkerStyle(20);
    g_chi_cross_E1devE7->SetFillColor(0);
    g_chi_cross_E1devE7->SetTitle("w/ xtalk");
    TGraph* g_chi_original_E1devE7 = new TGraph(NLAYER, layerID, chi_original_E1devE7);
    g_chi_original_E1devE7->SetTitle("w/o xtalk");
    g_chi_original_E1devE7->SetFillColor(0);
    g_chi_original_E1devE7->SetMarkerStyle(20);
    g_chi_original_E1devE7->SetMarkerColor(2);
    TMultiGraph* multi_chi_E1devE7 = new TMultiGraph();
    multi_chi_E1devE7->Add(g_chi_cross_E1devE7);
    multi_chi_E1devE7->Add(g_chi_original_E1devE7);
    sprintf(title,"Chi2Test_%sGeV",Energy.c_str());
    multi_chi_E1devE7->SetTitle(title);
    multi_chi_E1devE7->Draw("AP");
    multi_chi_E1devE7->GetXaxis()->SetTitle("layerID");
    multi_chi_E1devE7->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_E1devE7->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%s/chi2_compareE1devE7_%sGeV.png", f_substr.c_str(), Energy.c_str());
    c4->SaveAs(title);

    
    TGraph* g_chi_cross_E7devE19 = new TGraph(NLAYER, layerID, chi_cross_E7devE19);
    g_chi_cross_E7devE19->SetMarkerColor(1);
    g_chi_cross_E7devE19->SetMarkerStyle(20);
    g_chi_cross_E7devE19->SetFillColor(0);
    g_chi_cross_E7devE19->SetTitle("w/ xtalk");
    TGraph* g_chi_original_E7devE19 = new TGraph(NLAYER, layerID, chi_original_E7devE19);
    g_chi_original_E7devE19->SetTitle("w/o xtalk");
    g_chi_original_E7devE19->SetFillColor(0);
    g_chi_original_E7devE19->SetMarkerStyle(20);
    g_chi_original_E7devE19->SetMarkerColor(2);
    TMultiGraph* multi_chi_E7devE19 = new TMultiGraph();
    multi_chi_E7devE19->Add(g_chi_cross_E7devE19);
    multi_chi_E7devE19->Add(g_chi_original_E7devE19);
    sprintf(title,"Chi2Test_%sGeV",Energy.c_str());
    multi_chi_E7devE19->SetTitle(title);
    multi_chi_E7devE19->Draw("AP");
    multi_chi_E7devE19->GetXaxis()->SetTitle("layerID");
    multi_chi_E7devE19->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_E7devE19->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%s/chi2_compareE7devE19_%sGeV.png", f_substr.c_str(), Energy.c_str());
    c4->SaveAs(title);

    f_output.Write();
    f_output.Close();
  
    delete c1;

}

