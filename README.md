## Deze repository

#### Introductie

De repositories **pxt-pinball** en **rpi-pinball** vormen een twee-eenheid.
Repository **pxt-pinball** is een uitbreiding voor **MakeCode** om de **micro:bit** te programmeren.
Het programma op de **micro:bit** werkt samen met het host-programma **Pinball** op de **Raspberry Pi**.
Repository **rpi-pinball** (deze repository dus) bevat de benodigde software en code hiervoor.
Het programma op de **micro:bit** stuurt de flipperkast dus aan via het programma **Pinball**.

#### De submappen

Submap **broncode** bevat het code-project waarmee het programma Flipperkast wordt gebouwd.
Deze is alleen interessant als het programma moet worden gewijzigd.

Submap **hardware** beschrijft de elektronische componenten in de flipperkast en hoe deze aan te sluiten.
Het bevat ook de bestanden om nieuwe flippers met de lasersnijder te snijden en deze zo nodig aan te passen.

Submap **installatie** biedt de mogelijkheid om de de **SD-kaart** van de Raspberry Pi opnieuw te installeren.
In deze map bevinden zich ook de bestanden om de flipperkast te testen.
