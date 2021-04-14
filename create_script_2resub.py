###################################################################
############ Creation of a script to resubmit jobs ################
###################################################################
################ Author: Clara Lasaosa Garcia #####################
###################################################################

import sys

#####################
### HOW TO USE IT ###
#####################

# python create_script_2resub.py scriptname cluster_id job_flavour failed_jobs_separated_by_blank_spaces
# Ex: python create_script_2resub.py DIGI_4Mu_eta0 123456 "workday" "62 15 34 22 1"
# Ex: python create_script_2resub.py GENSIM_4Mu_eta0 789101 "longlunch" "14 21"

#####################


def create_script (scriptname, cluster_id, job_flavour, failed_jobs):

    failed_jobs_id = failed_jobs.replace(" ", "\n ")

    subfile ="executable   = {0}_$(oldId).sh\n".format(scriptname)
    subfile+="arguments    = {0}_1 $(oldId)\n".format(cluster_id)
    subfile+="output       = output/{0}.{1}_1.$(oldId).out\n".format(scriptname, cluster_id)
    subfile+="error        = output/{0}.{1}_1.$(oldId).err\n".format(scriptname, cluster_id)
    subfile+="log          = log/{0}.{1}_1.$(oldId).log\n".format(scriptname, cluster_id)
    subfile+="+JobFlavour   = \"{0}\"\n".format(job_flavour)
    subfile+="queue oldId from (\n {0}\n)".format(failed_jobs_id)

    fname = scriptname+"_2resub.sub"
    
    with open(fname,"w") as f:
        f.write(subfile)
        f.close()
    
    return fname


if __name__=='__main__':                                                                                                                                                                      

    create_script(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
