
if test $# -eq 1
then
echo "Welcome $1"
else
echo "No user Found!! Please sign in"
fi
echo "Today is " 
date
cal
echo "Your files  and directory list are: " 
ls
echo "List of your currently running processes are:"
ps
echo "waiting for your command..."
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
if test $# -eq 1
then
echo "Welcome $1"
else
echo "No user Found!! Please sign in"
fi
echo "Today is " 
date
cal
echo "Your files  and directory list are: " 
ls
echo "List of your currently running processes are:"
ps
echo "waiting for your command..."
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
