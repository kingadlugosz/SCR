pwd="home/kinga/SCR"

for mail in $(cat $pwd/adresy.txt)
do
cat $pwd/mail.txt | mutt -s "OKNA PCV" $mail -a $pwd/spec*.pdf
done
