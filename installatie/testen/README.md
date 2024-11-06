## De flipperkast testen

#### Bestanden kopiëren

De bestanden in deze map zijn bedoeld om de flipperkast mee te testen.
Schrijf deze bestanden in de **root** van een USB-stick met de volumenaam **BRG2**.

#### Micro:bit programma maken

Start **MakeCode** en sluit een **micro:bit** aan.
Importeer het programma **Flipperkast_test.hex** van de USB-stick.
Klik op het vlak **Downloaden** om het programma naar de **micro-bit** te schrijven.

#### Programma testen

Start de raspberry onder de flipperkast op.
Het programma **Flipperkast** vind je op het bureaublad.
(Zo niet, kijk dan eerst in de map **installatie/blanco**.)
Dubbel-klik op het programma en kies de optie **Uitvoeren in terminal**. 

Plaats de USB-stick in een USB-ingang van de Raspberry onder de flipperkast.
Plaats de **micro:bit** in de edge-connector.
Als het goed is werkt het programma nu.
* Led 3 moet voortdurend van kleur veranderen
* Sluit met je vinger poortje 1: Led 1 wordt rood en **video1.mp4** wordt getoond.
* Sluit met je vinger poortje 2: Led 2 wordt rood en **video2.mp4** wordt getoond.
* Na het afspelen van een video wordt **achtergrond.png** getoond.

#### Controleren in de terminal

Je kunt de werking van het programma **Flipperkast** als volgt controleren.
Terwijl het programma draait, klik je op het tabblad **uxterm** in de werkbalk bovenin het scherm.
De terminal verschijnt op het scherm.
Bij iedere test-actie (hierboven beschreven) meldt de terminal wat het programma precies doet.
Als het goed is, zie dat terug op de flipperkast.
(Zo niet, dan is de hardware defect. Kijk dan in de map **hardware**)
