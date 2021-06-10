Krótka instrukcja w jaki sposób pliki czytają informacje:

1)Plik z lekami

<informacja_czy_lek_jest_na_recepte> <nazwa_leku> <id> <koszt> <wiek_min> <wiek_max>

informacja czy lek jest na recepte:
r- na recepte
n-nie na recepte

wiek_min i wiek_max określają widełki wiekowe dla pacjenta

2)Plik z objawami

<nazwa> <id-1> <id-2> <id-3> ... <id-n> -1

-1 na końcu linii służy temu,aby program wiedział kiedy może skończyć
czytać do listy id.

Jeśli żaden lek nie zostanie znaleziony do pliku zostanie wypisany stosowny komunikat.

Przełącznik -i <nazwa_pliku> pozwala otworzyć wybrany plik z lekami
np. -i leki.txt
Brak przełącznika spowoduje że program zadziała na pliku domyślnym z lekami.