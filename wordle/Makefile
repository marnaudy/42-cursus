
FRENCH = files/words_fr_5.txt

ENGLISH = files/words.txt

FRENCH_ALL = files/words_fr_5.txt files/words_fr_6.txt files/words_fr_7.txt files/words_fr_8.txt

all: 
	python3 main.py $(ENGLISH)

fr:
	python3 main.py $(FRENCH)

fra:
	python3 main.py $(FRENCH_ALL)

install:
	pip install pygame
	make all

.PHONY: all install occurence fr fra