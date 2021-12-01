##############################################################################
########## Look for the not enabled pixels throughout the file ###############
##########    in the column range of interest: 128 and 263     ###############
##############################################################################
###################### Author: Clara Lasaosa Garcia ##########################
##############################################################################

import sys

#####################
### HOW TO USE IT ###
#####################

# python3 find_not_enabled_pixels.py first_argument_input
# Example: python3 find_not_enabled_pixels.py "Run000525_CMSIT_RD53_50x50.txt"

#####################


def count_pixels(input_file):

    dead_pixels = 0
    with open(input_file) as my_file:
        lines = my_file.readlines()
        for position, line in enumerate(lines):
            if line.startswith("COL") and 128 <= int(line[-4:-1]) <= 263:
                col_dead_pixels = lines[position+1].count("0")
                if col_dead_pixels != 0:
                    dead_pixels += col_dead_pixels
                    print("The column {} contains {} stuck+noisy pixels".format(line[-4:-1],str(col_dead_pixels)))

    print("\nThis is the total number of stuck+noisy pixels that were masked online: "+str(dead_pixels))

if __name__=='__main__':

    count_pixels(sys.argv[1])
