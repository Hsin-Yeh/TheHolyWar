#include "ntupleMaker.h"
#include "makePlots.h"
#include "PlotSetting.h"
#include <fstream>
#include <iostream>

// General Setup
string main_outpath = "./";
string main_default_rootname = "ntuple.root";
string main_datainput = "./data_input.txt";
// Usage
void main_makeNtuple(bool Is_Data);
void main_makePlots(bool Is_Data);
string arg_string;
vector<string> all_args;
bool Is_Data = true;


int main(int argc, char** argv){
  TApplication *app = new TApplication("app",0,0);
  app->Init();
  PlotSetting *P;
  P->root_logon();
yo!
  for(int i = 0 ; i < argc ; ++i){
    arg_string = argv[i];
    all_args.push_back(arg_string);
  }    
  if(argc == 2){
    if     (all_args[1] == "-n" || all_args[1] == "-N" ){   main_makeNtuple( Is_Data );	}
    else{   std::cout << "Unknown option... print usage" << std::endl;  }
  }
  else if(argc == 3){
    if(all_args[1] == "-n" || all_args[1] == "-N" ){
      Is_Data = std::stoi(all_args[2]);
      main_makeNtuple( Is_Data );
    }
    else if(all_args[1] == "-m" || all_args[1] == "-M" ){
      Is_Data = std::stoi(all_args[2]);
      main_makePlots( Is_Data );
    }
    else{
      std::cout << "Unknown option... print usage" << std::endl;
    }
  }
  else{ cout << "unexpected number of option! QUIT!" << endl; }
    
  return 1;

}

void main_makeNtuple(bool Is_Data){

  TChain *chain1 = new TChain("rechitntupler/hits");
  TChain *chain2 = new TChain("trackimpactntupler/impactPoints");
  TChain *chain3 = new TChain("XCETntupler/XCET");
  
  string filename;
  ifstream infile(main_datainput.c_str());
  while(true){
    
    infile >> filename;
    if(infile.eof()) break;
    if( filename.length() > 2){
      cout << "input file: " << filename << endl;

      if(Is_Data){
        chain1->Add(filename.c_str());
        chain2->Add(filename.c_str());
        chain3->Add(filename.c_str());
        int check = 1; //chain3->GetEntries();
        if(check == 0){
          cout << "\n\n======================================" << endl;
          cout << "This file is probably MC" << endl;
          cout << "you probably want to run ./makePlots 0" << endl;
          cout << "======================================\n\n" << endl;
          Is_Data = false;
        }
      }
      else{
        chain1->Add(filename.c_str());
        chain2->Add(filename.c_str());      }
    }
    else{
      cout << filename << " is not available, please check "
           << main_datainput << endl;}
  }
  infile.close();


  ntupleMaker *N;
  if(Is_Data){   N = new ntupleMaker(chain1, chain2, chain3, filename); }
  else       {   N = new ntupleMaker(chain1, chain2, filename);         }
  N->Is_Data = Is_Data ;
  N->NtupleMaker();
}

void main_makePlots(bool Is_Data){
      
  TChain *chain1 = new TChain("hits");
  TChain *chain2 = new TChain("impactPoints");
  TChain *chain3 = new TChain("rechit_var");
  
  string filename;
  ifstream infile(main_datainput.c_str());
  while(true){
    
    infile >> filename;
    if(infile.eof()) break;
    if( filename.length() > 2){
      cout << "input file: " << filename << endl;
      chain1->Add(filename.c_str());
      chain2->Add(filename.c_str());
      chain3->Add(filename.c_str());
    }
    else{
      cout << filename << " is not available, please check "
           << main_datainput << endl;}
  }
  infile.close();
  makePlots *M;
  M = new makePlots(chain1,chain2,chain3,filename)
  M->Is_Data = Is_Data;
  //M->Event_Display();
  M->Loop();
}
   


