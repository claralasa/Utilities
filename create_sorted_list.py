####################################################################################
########## Creation of a list storing the input files sorted by number #############
####################################################################################
######################### Author: Clara Lasaosa Garcia #############################
####################################################################################

import glob
import sys

#####################
### HOW TO USE IT ###
#####################

# python create_sorted_list.py first_argument_input second_argument_output
# Ex: python create_sorted_list.py "/afs/cern.ch/work/c/clasaosa/JobsCondor/DIGI_4Elec_ChSh_0.4um_edgeGap/output/*.err" "/afs/cern.ch/work/c/clasaosa/JobsCondor/DIGI_4Elec_ChSh_0.4um_edgeGap/sorted_list.list"

#####################


def create_sorted_list (input_path, output_path):

    rootfiles = []
    sortedlist = []

    for file in glob.glob(input_path):
        rootfiles.append("file:"+file)

    sortedlist = sorted(rootfiles)

    f = open(output_path, "w")
    
    for i in sortedlist:
        f.write(i + "\n")
    f.close()

    return f


if __name__=='__main__':

    create_sorted_list(sys.argv[1], sys.argv[2])
