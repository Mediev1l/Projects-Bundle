/*
Mors - lampka num lock by miga³a + wypisywanie do konsoli + zapis na dysk
	w jednej klasie , kontener  na inne klasy
	metoda na beep oraz druga na  strumien wyjsciowy
	abstrakcyjny obiekt
	wzorzec projektowy


	morse	blink
			beep
			disk
			console



	setExtraInfo("  ") formatujace dla danego pliku

	factory f;
	f.setExtraInfo("200 200 400") czasy <- parser, oraz nazwa pliku
	f.setOutput(factory::beep)
	f.comvert("Ala ma kota")
	f.setOutput(factory::disk)
	f.convert("a pies")
	f.convert(123)
	f.convert(1,23)
	wlasny parser

	mors abstrakcyjny i dziedziczace klasy

	convert musi byæ wszêdzie 

	wskaznik na morsa

	fabryka abstrakcyjna

	ma klase parser i ustawia parametry dla kazdego z obiektow
	lub kazda klasa ma sama interpretowac // raczej  nie




*/