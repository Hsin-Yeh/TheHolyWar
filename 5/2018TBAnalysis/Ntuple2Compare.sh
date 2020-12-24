#!/bin/bash

# Define paramter
ntuple_output=./output_root/
root_plot=root_plot/plot_
plot=./plots/
file=$( cut -d / -f 3 <<< $1 )
fileCutRoot=$( cut -d . -f 1 <<< $file )


# Do the job 
ls $1 > data_input.txt
./makePlots -n 0
ls ${ntuple_output}${file} > data_input.txt
./makePlots -m
ls ${root_plot}${file} > data_input.txt
mkdir ${plot}"plot_"${fileCutRoot} 
root -q -b ./Compare_DataMC.C



