if test $# -eq 2
then
cat $1 $2 >> "File3rd.sh"
echo "Concanated"
else
echo "Files names missing"
fi
sort "File3rd.sh"
cat "File3rd.sh" | tr "[a-z]" "[A-Z]"

