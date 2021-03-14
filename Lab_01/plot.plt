set term png # ustawienie typu terminala, np. m.in. x11 (ekran), postscript, pdf, png, table (kolumny współrzędnych). 

set out "z1.png" # ustawienie nazwy pliku wyjściowego 

set xl "t" # tytuł osi x
set yl "x(t)" # tytuł osi y
set title "Wychylenie x(t)" # tytuł wykresu
f(x) = cos(x)

p "out.txt" u 1:2 w p lt 3 pt 6 t "x(t), dt",f(x) w l t "cos(t)" # rysowanie wykresu


