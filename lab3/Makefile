output: main.o menu.o tablica_operacje.o tablica_wysw.o tablica_zapis.o 
		g++ main.o menu.o tablica_operacje.o tablica_wysw.o tablica_zapis.o -o output

main.o:	main.cpp
		g++ -c main.cpp

menu.o: menu.cpp
		g++ -c menu.cpp

tablica_operacje.o:	tablica_operacje.cpp
			g++ -c tablica_operacje.cpp

tablica_wysw.o: tablica_wysw.cpp
				g++ -c tablica_wysw.cpp

tablica_zapis.o: tablica_zapis.cpp
				g++ -c tablica_zapis.cpp

clean:	rm *.o output