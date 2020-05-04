# RC-circuit-simulation
# Circuit RC serie cu intrare pe rezistenta, iesire pe condensator legat la Vcc

Algoritmul este scris in C++ si calculeaza valorile tensiunii Vout, supusa la intrare la un semnal de tip dreptunghiular produs de o sursa cu urmatoarele caracteristici: Von=5V, Tdelay=1ms, Trise=1ns, Tfall=1ns, Ton=4ms, Tperiod=8ms.

Valorile calculate sunt apoi scrise intr-un fisier ce este exportat in gnuplot pentru plotare folosind comanda: plot 'Output1.dat' with lines.

# Variabile

Variabile folosite reprezinta: 

Vo - vectorul in care sunt calculate valorile tensiunii Vo
it - folosit pentru parcurgerea vectorului
delay - timpul dupa care incepe semnalul (in milisecunde)
cycles - numarul de repetari al semnalului
T - durata unui front al impulsului
tau - constanta de timp
E - tensiunea de "1" logic a sursei
V0 - variabila auxiliara folosita pentru a memora ce tensiune este pe condensator dupa fiecare ciclu
R - valoarea rezistentei
C - valoarea capacitatii

# Functionalitate

Algoritmul calculeaza valorile tensiunii pe condensator, ce se incarca de la i=0 pana la i=T conform formulei de la randul 30. Vo nu depaseste 5V.Pe frontul de descarcare, tot de la i=0 pana i=T, sunt calculate valorile tensiunii folosind formula de la randul 35. Condensatorul, daca ne aflam in cazul 2, se descarca partial urmand ca urmatoarea incarcare sa porneasca de la aceasta valoare.   

Algoritmul este insotit de un fisier .plt ce poate fi incarcat intr-un software precum gnuplot.
