#!/bin/bash
rm -rf possiblity.log
./generate_possiblity < start.log > possiblity.log
rm -rf move_done.log
./reversi < possiblity.log > move_done.log
rm -rf final.log
./modify possiblity.log move_done.log > final.log

for i in `seq 1 95`;
do
rm -rf possiblity.log
./generate_possiblity < final.log > possiblity.log
rm -rf move_done.log
./reversi < possiblity.log > move_done.log
rm -rf final.log
./modify possiblity.log move_done.log > final.log
done

