1. Условие:
Имеется система сцепленных шестеренок, пронумерованных от 1 до N. 
Заданы пары номеров сцепленных шестеренок. Первая должна двигаться по  
часовой стрелке. Определить характер движения всех шестеренок.
 Варианты движения:
	clockwise - по часовой;
	unclockwise - против;
	immovable - шестеренка неподвижна;
	block - заклинивание.
Ввод из файла INPUT.TXT. В первой строке записаны через пробел число N - количество шестеренок (2 ≤ N ≤ 10000) 
и M - количество пар (1 ≤ M ≤ 100000). 
Во следующих M строках указаны пары шестеренок в виде двух номеров через пробел.
Вывод в файл OUTPUT.TXT. В i-й строке должна быть информация о движении i-й шестеренки: 
clockwise - по часовой, against - против, immovable – шестеренка неподвижна. 
Если система заклинивается, то выдать block.

2. Автор: Лашсманов Артём ПС-21

3. Среда: ISO C++17 Standard (/std:c++17)

4. На вход подаётся файл input.txt содержащий в первой строчке два числа, первое число N - количество шестеренок (2 ≤ N ≤ 10000)
второе M - количество пар (1 ≤ M ≤ 100000). Во следующих M строках указаны пары шестеренок в виде двух номеров через пробел.
Шестерёнка с номером 1 всегда крутится по часовой стрелке. 
В файл output.txt необходимо вывести направление вращения каждой из N шестерёнок.
В случаи если система из шестерёнок не может работать вывести block.

5. Примеры:

Примеры
Ввод 1       Ввод 2
5 4          5 4
1 2          1 2
2 3          2 3
3 4          1 3
4 1          4 5
Вывод 1      Вывод 2
clockwise    block
unclockwise
clockwise
unclockwise
immovable

