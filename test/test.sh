#!/bin/bash
congen(){
	echo "problem generation"
	count=0
	prob="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	while [ ${count} -le $(( ${!#} )) ]; do
		prob_name="${prob:${count}:1}.cpp"
		cp /workspaces/Algostudy/settings/template.cpp $prob_name
		count=$(( ${count}+1 ))
	done
}

congen
