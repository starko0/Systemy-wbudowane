# Systemy-wbudowane

Aktualna lista elementow:

1 Płytka stykowa 400 otworów
2 Bateria 9 V 
3 Rezystory przewlekane: 330Ω, 1 kΩ (po 10 szt.).
4 Potencjometr montażowy
5 Diody LED 5 mm: zielona (5 szt.), czerwona (5 szt.), żółta (5 szt.), niebieska (1 szt.).
6 Dwa fotorezystory
7 Serwomechanizm modelarski typu micro.
8 Wyświetlacz LCD 16x2 ze złączami.
9 Sterownik silników L293D - mostek H 
10 Czujnik odległości - ultradźwiękowy HC-SR04 działający w zakresie od 2 cm do 200 cm.
11 Buzzer z generatorem 
12 Stabilizator napięcia 5 V z kondensatorami.
13 Przyciski typu tact-switch - 5 szt.

!!! PLAN DZIALANIA !!!
1. Zakup czesci potrzebnych - do środy (10.04)
2. Weryfikacja podlaczenia czesci i czy sa wszystkie potrzebne elementy - do soboty (13.04)
3. Skonczenie schematu (13.04)
4. Zaczecie programowania (od 13.04)


Funkcjonalnosci:
1. obliczanie czasu reakcji, ewentualnie nutka na brzeczku rowniez timer, ewentualnie melodia ale tutaj pwm [TIMER]
2. reagowanie na sygnal (dioda) [GPIO/PWM] tutaj trzeba dopytac
3. reagowanie na sygnal (dzwiek) [GPIO/PWM)
4. zapisywanie pliku na komputerze (wyniki, wykresy, cokolwiek...) [UART]
5. wyswietlanie menu, oraz czasu reakcji przy pojedynczej probie [WYSWIETLACZ LCD]
6. czujnik odleglosci (zagranie reki spod czujnika w okreslonym czasie, na dany sygnal) [URZADZENIE ZEWNETRZNE]
7. odczyt i zapis danych na karte sd (ostatnie wyniki, podsumowanie wynikow z okreslonych gier na refleks) [SPI]
8. silnik wibrujacy sterowany PWM (wykorzystany do sygnalizacji, np fallstartu przy grach refleks) [PWM]

Rzeczy do kupienia:
- buzzer aktywny do pkt 3
- czytnik kart sd
- konwerter napiec do czytnika 
- duza plyta stykowa, lub wiecej malych plytek
- przewody
- extender do pinow
- silnik wibracyjny sterowany PWM

