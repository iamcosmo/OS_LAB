if test $# -eq 2
then
if test -f "$1"
then
if test -f "$2"
then
cp $1 $2
echo "Files Copied"
else
echo "Destination file invalid"
fi
else
echo "Source File Invalid"
fi
elif test $# -eq 1
then
echo "Source or destination File missing"
else
echo "both file missing"
fi
