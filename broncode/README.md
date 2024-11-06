## Het programma Flipperkast

#### IDE Geany

Het programma **Flipperkast** is als een **Geany-project** gebouwd.
Op de Raspberry is de IDE **Geany** standaard geïnstalleerd.
Het project **Flipperkast.geany** kan daarmee worden geopend.
In de map **Flipperkast** staat de broncode.
Er is maar één code-bestand in het project aanwezig: **Flipperkast.cpp**.
Dit bestand bevat alle code van het programma.

#### C++

De code-taal van het programma **Flipperkast** is C++.
Het programma maakt gebruikt van de classes "Video" en "RgbLed" uit de code-bibliotheek **DeviceLib**.
Deze bibliotheek is als het goed is geïnstalleerd (zie bij **installatie/blanco**).
De programma-code moet samen werken met de MakeCode-uitbreiding **Flipperkast**.
De code hiervan vind je in het bestand **main.ts** van de repository **pxt-flipperkast**.

#### CLASS VIDEO

De class **Video** biedt de volgende instructies:

**Afspeelvenster**
* setTitle("Titel van het afspeelvenster");
* setSize(breedte,hoogte);
* setFullscreen();

**Frame na frame afspelen**
* start("Bestandsnaam van een video");
* play()
* rewind()
* stop()

De instructie **play** vertoont steeds het volgende frame.

**Hele video afspelen**
* play("Pad naar en bestandsnaam van een video");

**Afbeelding tonen**
* show("Pad naar en bestandsnaam van een afbeelding");

#### CLASS RGBLED

De class **RgbLed** biedt de volgende instructies:

**Instelling**
* setPin(rood,groen,blauw);
* setConnection(VCC of GND);

**Kleur**
* setColor(RED of GREEN of BLUE of YELLOW of MAGENTA of CYAN of WHITE);
* setColor(rood,groen,blauw);

**Aan/uit**
* on();
* off();

In de code mogen de instructies **setPin** en **setConnection** niet worden gewijzigd vanwege de hardware.
