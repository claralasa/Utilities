##################################################################################################################
########## This script allows to replace a string in all the files of a directory with the sh extension ##########
##################################################################################################################
####################################### Author: Clara Lasaosa Garcia #############################################
##################################################################################################################

#How to run: bash replace_string.sh '/this/is/the/directory/where/the/files/to/change/are/stored' first_arg second_arg

cd $1

var1=$2
var2=$3

echo "Replacing $var1 with $var2 in .sh scripts located in $1"

[ ! -d $1/backups ] && mkdir -p $1/backups

#If you want to replace the string without creating a backup of the files
#sed -i -- "s/$var1/$var2/g" *.sh

#If you want to replace the string creating a backup of the initial files
sed -i_bkp -- "s/$var1/$var2/g" *.sh

mv *.sh_bkp $1/backups
