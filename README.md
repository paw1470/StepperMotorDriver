Podłączenie kabli:
    przyciski:
        czarny - gnd
        biały - 2 - prawy przycisk (stan sprawdzany przed nowym obrotem albo krokiem )
        szary - 3 - srodkowy przycisk (zmienia tryb dzialania po wcisnieciu)
        fiolet - 4 - lewy przycisk (stan sprawdzany przed nowym obrotem albo krokiem)

    niebieska dioda - 5

    sterownik silnika - 6, 7, 8, 9 

    potencjometr:
        szary - gnd
        fiolet - vcc
        biały - a3 - stan sprawdzany przed nowym obrotem albo krokiem 

zasilanie (mozesz podłączyć do sterownika):
    brązowy - gnd (do gnd sterownika)
    czerwony - vcc (do +5v sterownika, NIE POMYL)

diody (jak rozumieć):
    1 czerwona - działa i będzie sie obracaę cały czas jak wybierzesz kierunek
    2 czerwone - kroki, jedno nacisniecie to 1 krok i przerwa na 150ms (bo ciężko było zrobić 1 krok) 
    niebieska dioda - arduino steruje silnikiem i nie działa wybieranie kierunku (za dużo kombinowania z kodem)

jak używać:
Po podłączeniu zasilania powinny świecić 2 diody. Jak wybierzesz kierunek to zrobi krok. 
Jak naciśniesz środkowy to przejdzie do ciagłego obracania po wybraniu kierunku. 
Wtedy zatrzyma sie przy nacisnieciu środkowego jak skończy się aktualny obrót. 
Jak będziesz trzymał boczny przycisk podczas obracania i wejdzie na nastepny obrót to sprawdzi kierunek i może się zmieni.
Łatwiej nacisnac srodkowy 2 razy i wtedy wybrac kierunek jak sie zatrzyma.
Prędkość jest ustalana przed każdym krokiem albo obrotem.