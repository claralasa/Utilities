####################################################################################
###### Creation of a list with the number of missing jobs to resubmit them #########
####################################################################################
######################### Author: Clara Lasaosa Garcia #############################
####################################################################################

import glob
import sys

#####################
### HOW TO USE IT ###
#####################

# python create_missing_list.py first_argument_input second_argument_output third_argument_njobs
# Ex: python create_missing_list.py "/afs/cern.ch/work/c/clasaosa/JobsCondor/DIGI_4Elec_ChSh_0.4um_edgeGap/output/*.err" "/afs/cern.ch/work/c/clasaosa/JobsCondor/DIGI_4Elec_ChSh_0.4um_edgeGap/sorted_list.list" "800"

#####################

def create_missing_list (input_path, output_path, njobs):

    rootfiles = []
    sortedlist = []
    missinglist = []

    for file in glob.glob(input_path):
        rootfiles.append(int(file.split(".")[-2]))

    sortedlist = sorted(rootfiles)

    for x in range(0, int(njobs)):
        if x not in sortedlist:
            missinglist.append(str(x))

    f = open(output_path, "w")
    
    for i in missinglist:
        f.write(i + "\n")
    f.close()

    return f


if __name__=='__main__':

    create_missing_list(sys.argv[1], sys.argv[2], sys.argv[3])
