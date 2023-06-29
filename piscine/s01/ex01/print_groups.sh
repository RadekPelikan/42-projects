#!/bin/sh
ids=`id $FT_USER -G`

count=0
out=""
for id in $ids; do
    out+=`getent group $id | cut -d: -f1`
    if  (( $count != ${#count[@]} )); then
        out+=','
    fi
    count+=1
done
echo -n $out
# groups $FT_USER | tr " " ","
