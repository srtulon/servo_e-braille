#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
  
#define OLED_MOSI   9 //SDA
#define OLED_CLK   8 //SCK
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 10
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
  
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
  
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
char input; 
int count;


void setup() {
  display.clearDisplay();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  display.clearDisplay();
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  s5.attach(6);
  s6.attach(7); 
  pinMode(A0,INPUT);
  delay(3000);
   
}

void(* resetFunc) (void) = 0;

void loop() {
  
  /*calibrate1();
   delay(5000);
   calibrate2();
   delay(5000);*/
   if(digitalRead(A0)){
      Serial.print(digitalRead(A0));
   }
  display.clearDisplay();
  count=0;
  char arr[15] ;
  display.setTextSize(2);
  display.setTextColor(WHITE);
  //Serial.println(count);
  display.setCursor(10,12);
  while(Serial.available()){
    
    input=Serial.read();
    if(input=='#'){
      break;
    }
    display.setCursor(count*12,0);
    display.print(input);
    display.display();
    arr[count]=input;
    count++;
  }
  
  int check=0;
  delay(5000);
  while(check<count){   
       
      switch(arr[check]){
        display.setCursor(check*12,18);
        input=arr[check];
        display.print(input);
        display.display();
        case 'a':a();
        break;
        case 'b':b();
        break;
        case 'c':c();
        break;
        case 'd':d();
        break;
        case 'e':e();
        break;
        case 'f':f();
        break;
        case 'g':g();
        break;
        case 'h':h();
        break;
        case 'i':i();
        break;
        case 'j':j();
        break;
        case 'k':k();
        break;
        case 'l':l();
        break;
        case 'm':m();
        break;
        case 'n':n();
        break;
        case 'o':o();
        break;
        case 'p':p();
        break;
        case 'q':q();
        break;
        case 'r':r();
        break;
        case 's':s();
        break;
        case 't':t();
        break;
        case 'u':u();
        break;
        case 'v':v();
        break;
        case 'w':w();
        break;
        case 'x':x();
        break;
        case 'y':y();
        break;
        case 'z':z();
        break;
        default: calibrate1();
        break;
        
      }
      check++;
      delay(1500);
    }
  
  resetFunc();
  
}


/* a();
 delay(4000);
 b();
 delay(4000);
 c();
 delay(4000);
 d();
 delay(4000);
 e();
 delay(4000);
 f();
 delay(4000);
 g();
 delay(4000);
 h();
 delay(4000);
 i();
 delay(4000);
 j();
 delay(4000);
 k();
 delay(4000);
 l();
 delay(4000);
 m();
 delay(4000);
 n();
 delay(4000);
 o();
 delay(4000);
 p();
 delay(4000);
 q();
 delay(4000);
 r();
 delay(4000);
 s();
 delay(4000);
 t();
 delay(4000);
 u();
 delay(4000);
 v();
 delay(4000);
 w();
 delay(4000);
 x();
 delay(4000);
 y();
 delay(4000);
 z();
 delay(4000);
 */


void calibrate(){
  s1.write(90);
  s2.write(90);
  s3.write(80);
  s4.write(90);
  s5.write(90);
  s6.write(90);
}
void calibrate1(){
  s1.write(80);
  s2.write(80);
  s3.write(80);
  s4.write(110);
  s5.write(80);
  s6.write(80);
}
void calibrate2(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(70);
  s5.write(110);
  s6.write(110);
}
void calibrate3(){
  s1.write(60);
  s2.write(120);
  s3.write(60);
  s4.write(60);
  s5.write(60);
  s6.write(120);
}
void calibrate4(){
  s1.write(120);
  s2.write(60);
  s3.write(135);
  s4.write(120);
  s5.write(120);
  s6.write(60);
}
void a(){
  s1.write(130);
  s2.write(80);
  s3.write(80);
  s4.write(110);
  s5.write(80);
  s6.write(80);
}

void b(){
  s1.write(130);
  s2.write(130);
  s3.write(80);
  s4.write(110);
  s5.write(80);
  s6.write(80);
}

void c(){
  s1.write(130);
  s2.write(80);
  s3.write(80);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void d(){
  s1.write(130);
  s2.write(80);
  s3.write(80);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void e(){
  s1.write(130);
  s2.write(80);
  s3.write(80);
  s4.write(110);
  s5.write(110);
  s6.write(80);
}

void f(){
  s1.write(130);
  s2.write(130);
  s3.write(80);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void g(){
  s1.write(130);
  s2.write(130);
  s3.write(80);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void h(){
  s1.write(130);
  s2.write(130);
  s3.write(80);
  s4.write(110);
  s5.write(110);
  s6.write(80);
}

void i(){
  s1.write(80);
  s2.write(130);
  s3.write(80);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void j(){
  s1.write(80);
  s2.write(130);
  s3.write(80);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void k(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(110);
  s5.write(80);
  s6.write(80);
}

void l(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(110);
  s5.write(80);
  s6.write(80);
}

void m(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void n(){
  s1.write(130);
  s2.write(80);
  s3.write(115);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void o(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(110);
  s5.write(110);
  s6.write(80);
}

void p(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void q(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void r(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(110);
  s5.write(110);
  s6.write(80);
}

void s(){
  s1.write(80);
  s2.write(130);
  s3.write(120);
  s4.write(70);
  s5.write(80);
  s6.write(80);
}

void t(){
  s1.write(80);
  s2.write(130);
  s3.write(120);
  s4.write(70);
  s5.write(110);
  s6.write(80);
}

void u(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(110);
  s5.write(80);
  s6.write(110);
}

void v(){
  s1.write(130);
  s2.write(130);
  s3.write(120);
  s4.write(110);
  s5.write(80);
  s6.write(110);
}

void w(){
  s1.write(80);
  s2.write(130);
  s3.write(80);
  s4.write(70);
  s5.write(110);
  s6.write(110);
}

void x(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(70);
  s5.write(80);
  s6.write(110);
}

void y(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(70);
  s5.write(110);
  s6.write(110);
}

void z(){
  s1.write(130);
  s2.write(80);
  s3.write(120);
  s4.write(110);
  s5.write(110);
  s6.write(110);
}



