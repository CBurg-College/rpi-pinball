#include <video.h>
#include <rgbled.h>

/* HARDWARE				RPI
 * ------------------------
 * GATE1				2
 * GATE2				3
 * 
 * LED1 RED				27
 * LED1	GREEN			17
 * LED1 BLUE			22
 * 
 * LED2 RED				20
 * LED2 GREEN			16
 * LED2 BLUE			21
 * 
 * LED3	RED				19
 * LED3 GREEN			13
 * LED3 BLUE			26
*/

#define PIN_GATE1_IN	2
#define PIN_GATE2_IN	3
#define PIN_L1_RED		27
#define PIN_L1_GREEN	17
#define PIN_L1_BLUE		22
#define PIN_L2_RED		20
#define PIN_L2_GREEN	16
#define PIN_L2_BLUE		21
#define PIN_L3_RED		19
#define PIN_L3_GREEN	13
#define PIN_L3_BLUE		26

/* COMMUNICATION		MBIT <>	RPI
 * -------------		-----------
 * GATE1 CLOSED			P1	 <	6
 * GATE2 CLOSED			P2	 <	5
 * 
 * DATA VALID			P0	 >	7
 * DATA RECEIVED		P3	 <	8
 * 
 * DATA:
 * -----
 * MEDIA SELECT			P20	 >	18
 * MEDIA SELECT			P19	 >	23
 * LED SELECT			P13	 >	24
 * LED SELECT			P12	 >	25
 * LED COLOR RED		P14  >	11
 * LED COLOR GREEN		P15  >	9
 * LED COLOR BLUE		P16  >	10
*/

#define PIN_GATE1_OUT	6
#define PIN_GATE2_OUT	5

#define PIN_DVALID		7
#define PIN_DRECEIVED	8

#define PIN_MEDSEL_A	18
#define PIN_MEDSEL_B 	23
#define PIN_LEDSEL_A	24
#define PIN_LEDSEL_B	25
#define PIN_RED			11
#define PIN_GREEN		9
#define PIN_BLUE		10

// -------------------

Video 	vid;
RgbLed	led1;
RgbLed	led2;
RgbLed	led3;

int ledsel = 0;
int medsel = 0;
int gt1 = 1;
int gt2 = 1;


int color[] = { 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
EString cs[] = { "uit", "rood", "groen", "geel", "blauw", "paars", "l.blauw", "wit" };

// -------------------

void setup()
{
	// HARDWARE

	led1.setPin( PIN_L1_RED, PIN_L1_GREEN, PIN_L1_BLUE);
	led2.setPin( PIN_L2_RED, PIN_L2_GREEN, PIN_L2_BLUE);
	led3.setPin( PIN_L3_RED, PIN_L3_GREEN, PIN_L3_BLUE);
	led1.setConnection( VCC);
	led2.setConnection( VCC);
	led3.setConnection( VCC);

	vid.setTitle( "Flipperkast");
	vid.setAcceleration( 4);
	vid.setFullScreen();

	// MICRO:BIT

	pinMode( PIN_GATE1_OUT, OUTPUT);
	pinMode( PIN_GATE2_OUT, OUTPUT);
	digitalWrite( PIN_GATE1_OUT, LOW);
	digitalWrite( PIN_GATE2_OUT, LOW);

	pinMode( PIN_DVALID, INPUT);
	pinMode( PIN_DRECEIVED, OUTPUT);
	digitalWrite( PIN_DRECEIVED, LOW);

	pinMode( PIN_MEDSEL_A, INPUT);
	pinMode( PIN_MEDSEL_B, INPUT);

	pinMode( PIN_LEDSEL_A, INPUT);
	pinMode( PIN_LEDSEL_B, INPUT);
	pinMode( PIN_RED, INPUT);
	pinMode( PIN_GREEN, INPUT);
	pinMode( PIN_BLUE, INPUT);

	// START

	led1.off();
	led2.off();
	led3.off();
	printf( "GESTART\n\n");
}

void loop()
{
	if ( digitalRead( PIN_GATE1_IN) != gt1 ) {
		digitalWrite( PIN_GATE1_OUT, gt1);
		gt1 = (gt1 ? 0 : 1);
		if ( !gt1 )
			printf( "Door poortje 1\n");
	}
	if ( digitalRead( PIN_GATE2_IN) != gt2 ) {
		digitalWrite( PIN_GATE2_OUT, gt2);
		gt2 = (gt2 ? 0 : 1);
		if ( !gt2 )
			printf( "Door poortje 2\n");
	}

	if ( !digitalRead( PIN_DVALID) ) return;

	ledsel = (digitalRead( PIN_LEDSEL_A) * 2) + digitalRead( PIN_LEDSEL_B);
	medsel = (digitalRead( PIN_MEDSEL_A) * 2) + digitalRead( PIN_MEDSEL_B);

	if ( ledsel ) {
		RgbLed* led;
		switch ( ledsel ) {
			case 1 : led = &led1; break;
			case 2 : led = &led2; break;
			case 3 : led = &led3; break;
		}
		int clr = digitalRead( PIN_RED) + digitalRead( PIN_GREEN) * 2 + digitalRead( PIN_BLUE) * 4;
		if ( clr ) {
			led->setColor( color[clr]);
			led->on();
			printf( "Led %d op %s\n", ledsel, cs[clr].c_str());
		}
		else {
			led->off();
			printf( "Led %d uit\n", ledsel);
		}
	}
	else
	if ( medsel ) {
		switch ( medsel ) {
			case 1 :	printf( "Start 'video1.mp4' van usb 'BRG2'\n");
						vid.play( "/media/pi/BRG2/video1.mp4");
						break;
			case 2 :	printf( "Start 'video2.mp4' van usb 'BRG2'\n");
						vid.play( "/media/pi/BRG2/video2.mp4");
						break;
			default:	vid.show( "/media/pi/BRG2/achtergrond.png");
						printf( "Toont 'achtergrond.png' van usb 'BRG2'\n");
		}
	}
	else
		return; // invalid, should never happen

	digitalWrite( PIN_DRECEIVED, HIGH);
	while ( digitalRead( PIN_DVALID) );
	digitalWrite( PIN_DRECEIVED, LOW);
}
