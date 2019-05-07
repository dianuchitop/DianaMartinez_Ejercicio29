plot.png: Data.dat graficash.py
	python graficash.py

%.dat : a.out
	./a.out 

a.out: codigo.cpp
	g++ codigo.cpp

