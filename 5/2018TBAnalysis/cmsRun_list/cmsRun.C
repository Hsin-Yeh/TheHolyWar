#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    
    char c[1000];
    sprintf(c,"cmsRun_%sGeV_EMN.txt",argv[1]);
    std::ofstream f(c);

    sprintf(c,"cmsRun runConfigurationsCERNOctober2018/processSim.py reportEvery=10000 processedFile=CMSSW.root ntupleFile=sim_%sGeV_EMN.root electronicMap=emap_full_October2018_setup1_v5_promptReco.txt hgcalLayout=layer_geom_full_October2018_setup1_v5_promptReco.txt noisyChannelsFile=/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/pedestals/v1/noisyChannels_381.txt MaskNoisyChannels=0 beamEnergy=%s.0 beamParticlePDGID=11 setupConfiguration=22 physicsListUsed=FTFP_BERT_EMM NHexaBoards=94 layerPositionFile=CondObjects/data/layer_distances_CERN_Hexaboard_October2018_setup1_promptReco_v2.txt areaSpecification=H2_October2018 stopAtEvent=-1 ", argv[1], argv[1]);
    f << c;
    
    for ( int i = 0; i < 500; i++ ) {
	sprintf(c,"inputFiles=%sTBGenSim_%d.root ",argv[2], i);
	f << c;
    }
    
}

