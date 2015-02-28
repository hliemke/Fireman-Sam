/*
 Fireman Sam main modified test this shit again
 */
#include <SoftwareSerial.h>
SoftwareSerial Thermal(2, 3);

#define PLAY 8
#define RESET 9
#define PRT_ON 7
int zero=0;
int heatTime = 255;
int heatInterval = 255;
char printDensity = 15; 
char printBreakTime = 15;
void setup() 
{
 Serial.begin(57600); // for debug info to serial monitor
 Thermal.begin(19200); // to write to our new printer
 pinMode(PLAY, OUTPUT);
 pinMode(RESET, OUTPUT);
 pinMode(PRT_ON, OUTPUT);
 initPrinter();
}
void initPrinter()
{
 //Modify the print speed and heat
 Thermal.write(27);
 Thermal.write(55);
 Thermal.write(7); //Default 64 dots = 8*('7'+1)
 Thermal.write(heatTime); //Default 80 or 800us
 Thermal.write(heatInterval); //Default 2 or 20us
 //Modify the print density and timeout
 Thermal.write(18);
 Thermal.write(35);
 int printSetting = (printDensity<<4) | printBreakTime;
 Thermal.write(printSetting); //Combination of printDensity and printBreakTime
 Serial.println();
 Serial.println("Printer ready"); 
}
void loop()
{

 //digitalWrite(RESET, LOW);
 //digitalWrite(PLAY, LOW);
 //delay(1000);
 //digitalWrite(PLAY, HIGH);
 delay(1000);
 //digitalWrite(PLAY, LOW);
 //digitalWrite(RESET, HIGH);
 //delay(20000);
 digitalWrite(PRT_ON, HIGH);

 // underline - one pixel

 Thermal.write(10); //Sends the LF to the printer, advances the paper
 delay(3000);
// height/width enlarge
 //Thermal.write(29); 
 //Thermal.write(33);
 //Thermal.write(255);
 Thermal.println(".......7$$$$$$$$$$$$Z::$$$$M+N..");
 Thermal.println("   MO::777777$$$$$$$Z::$$$$M+N  ");
 Thermal.println("  .~,..77777777$$$$$Z::$$$$M+N  ");
 Thermal.println("M:.:MN.777777777$$$$Z::$$$$M+N  ");
 Thermal.println("M:.=.=:777=777777$$$Z::$$$$M+M..");
 Thermal.println("M:::=:.777===777777$Z::$$$MMZOOM");
 Thermal.println("M:=~8=.77$=====7777$Z::$$MOODDDO");
 Thermal.println("M:+::7M777777$ZZZZ$7Z::$MOOD:::D");
 Thermal.println("M:.=.+.77777777$$$$7Z::$MOD,:M::");
 Thermal.println("M:.=ZMO777777777$$$7$::$MOD::==,");
 Thermal.println("M:.IIMO777=777777$$7$::$MODM:M:M");
 Thermal.println("M:::NMO777===7777777$.:$8MO8DDDD");
 Thermal.println("M:8OD:.777=====77777$ .$$$MOOOOO");
 Thermal.println("M: MM:.7777777$$$$$7$ .Z$$$MMM  ");
 Thermal.println("M:.= :.77777777$$$$7$..7$$$M++..");
 Thermal.println("M:MM.:.7777777777$$7$..77$$M++..");
 Thermal.println("M:=  :.777==777777$7$ .777$M++  ");
 Thermal.println("M:MMM:.777====777777$..7777M++..");
 Thermal.println("M:::::.777$$$$$77777$ .7777M++  ");
 Thermal.println("M:=  :.7777777777777$ .7777M++  ");
 Thermal.println("M:MM :.  .$$$$$$$$$$Z::$$$$M++  ");
 Thermal.println("M: = :.777$$$$$$$$$$Z::$$$$M++  ");
 Thermal.println("M: MD:M7777$$$$$$$$$Z::$$$$M++  ");
 Thermal.println("M:  =:M7,,,,~~~~$ZM$Z::$$$$M++  ");
 Thermal.println("M:::::M7,,,,,,~~$ZO$Z::$$$$M++  ");
 Thermal.println("M:+==:M7,,,,,,,,$$M$Z::$$$$M++  ");
 Thermal.println("=::==:M7,.,,,,,,7$$$Z::$$$$M++  ");
 Thermal.println("==::=:M7..:.,,,,7$$$Z::$$$$MMM .");
 Thermal.println("===:::M7,,..,.:,77$$Z::$$MMOOOOO");
 Thermal.println("====::M77777777777$$Z::$MMODDMND");
 Thermal.println("=====.M777777777777$Z::$MODM:N::");
 Thermal.println("    MMM7=,,,:~~~7Z87Z::$MOD::=MM");
 Thermal.println("    IMM7+.,,,,,~7Z87$::$MODM::::");
 Thermal.println("   .IMM7~.:.:,,,7777$::$MDODMMMD");
 Thermal.println("     .77+,. ,,,,7777$ :$$MMOOOOO");
 Thermal.println("       M,DM77MD:7777$ .$$$$MMMI ");
 Thermal.println("         .M:,,,,$777$ .77$$$$$  ");
 Thermal.println("             .M:7=77$ .777$$$$..");
 Thermal.println("                .M77$..7777OOOOM");
 Thermal.println("                           OOOO ");     
 delay(3000);
 Thermal.write(10);
 Thermal.println("Fireman Max");
 Thermal.write(10);
 Thermal.write(10);
 digitalWrite(RESET, LOW); 
 digitalWrite(PRT_ON, LOW);
 do { } while (1>0); // do nothing
}
