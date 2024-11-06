## Installatie van de Raspberry Pi

Onder de flipperkast zit een Raspberry Pi die de programma-instructies verwerkt.
De programma-instructies krijgt dit computertje van een micro:bit.

Een Raspberry doet niets zonder een SD-kaart met de benodige software.
Installeer de software volgens de onderstaande procedure.

Om te weten of de flipperkast correct functioneert, ga je naar de map **testen**.

## Procedure

#### 1. Raspberry Pi Imager

Gebruik de **Raspberry Pi Imager** tool om het standaard **Raspberry Pi OS** op een SD-kaart te schrijven.
De laatste versie van deze tool kan worden gedownload van:
[https://www.raspberrypi.com/software/

#### 2. Download de bestanden

Download de bestanden **bcm2835-1.70.tar.gz**, **DeviceLib_Raspberry.tar** en **Flipperkast**
en kopieer ze naar een USB-stick.

#### 3. Start de Raspberry

Doe de SD-kaart in de Raspberry en start hem op.
Open de **Bestandsbeheerder** van de Raspberry.
Kopieer de bestanden van de USB-stick naar **/home/pi/Download**.
Je werkt vervolgens vanuit deze map.

#### 4. Installeer de BCM2835 bibliotheek

Het hart van de Raspberry (t/m versie 4) is de bcm2835-chip.
Om het programma **Flipperkast** daarmee te laten samenwerken is een code-bibliotheek nodig.
Dubbel-klik op het bestand **bcm2835-1.70.tar.gz** om de code-bibliotheek te installeren.

#### 5. Installeer de DeviceLib bibliotheek

Het programma **Flipperkast** maakt gebruik van de **DeviceLib**-bibliotheek om video's af te spelen.
Dubbel-klik op het bestand **DeviceLib_Raspberry.tar** om de bibliotheek uit te pakken.
Open vervolgens de map **DeviceLib_Raspberry** en dubbel-klik op het bestand **Install.sh**.
Daarmee is **DeviceLib** geïnstalleerd.

#### 6. Het programma Flipperkast

Kopieer het programma **Flipperkast** naar het bureaublad om er gemakkelijker mee te kunnen werken.
