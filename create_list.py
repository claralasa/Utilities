###################################################################
########## Creation of a list storing the input files #############
###################################################################
################ Author: Clara Lasaosa Garcia #####################
###################################################################

import glob
import sys

#####################
### HOW TO USE IT ###
#####################

# python create_list_of_files.py first_argument_input second_argument_output
# Ex: python create_list_of_files.py "/eos/user/c/clasaosa/TFM/FourMuExtendedPt1_200_2026D54_eta0/GENSIM*.root" "/afs/cern.ch/user/c/clasaosa/CONDORJOBS/DIGI_4Mu_eta0/inputList.list"

#####################


def create_list (input_path, output_path):

    rootfiles = []

    for file in glob.glob(input_path):
        rootfiles.append("file:"+file)

    f = open(output_path, "w")
    
    for i in rootfiles:
        f.write(i + "\n")
    f.close()

    return f


if __name__=='__main__':

    create_list(sys.argv[1], sys.argv[2])
