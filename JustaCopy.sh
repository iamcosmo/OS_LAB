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
