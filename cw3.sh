> "$3"

for found_file in $(find . -name "*$1" -print);
do

    mod=$(date -r $found_file +%s)
    now=$(date +%s)
    days=$(expr \( $now - $mod \) / 86400)
    [ "$days" -le "$2" ] && echo "$found_file" >> "$3"

done
