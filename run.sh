rm -rf possiblity.log
./generate_possiblity < start.log > possiblity.log
rm -rf move_done.log
./reversi < possiblity.log > move_done.log
rm -rf final.log
./modify possiblity.log move_done.log > final.log

for VARIABLE in 1 2 3 4 5 
do
rm -rf possiblity.log
./generate_possiblity < final.log > possiblity.log
rm -rf move_done.log
./reversi < possiblity.log > move_done.log
rm -rf final.log
./modify possiblity.log move_done.log > final.log
done

