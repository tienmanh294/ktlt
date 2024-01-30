#!/bin/bash

for i in `seq -w 1 99`
do
  touch "test/output/output"$i.txt
done