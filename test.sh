
i=1
for (( i; i<11; i=i+1 ))
do   
    
    echo $i 
    ./Main  3 20 $i 1  >> 20D/Sample_CEC_${i}_basic.txt

done