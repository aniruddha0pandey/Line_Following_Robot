#include <LiquidCrystal.h>

const int rs = 2, en = 6, d4 = 7, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int mot1=3;
int mot2=8;
int mot3=5;
int mot4=4;

int left=13;
int right=12;

int Left=0;
int Right=0;

void LEFT (void){

   analogWrite(mot3,0);//don't change this
   analogWrite(mot4,10);//change this for speed
   
   
	   while(Left==0){

	    Left=digitalRead(left);
	    Right=digitalRead(right);

		    if(Right==0){

		      int lprev=Left;
		      int rprev=Right;

		      STOP();

			      while(((lprev==Left)&&(rprev==Right))==1){
			       
			         Left=digitalRead(left);
			         Right=digitalRead(right);
			      }

		    }

	    analogWrite(mot1,100);//change this for speed
	    analogWrite(mot2,0);//don't change this
	  }

   analogWrite(mot3,100);//change this for speed
   analogWrite(mot4,0);//don't change this

}


void RIGHT (void){
   
   analogWrite(mot1,0);//don't change this
   analogWrite(mot2,10);//change this for speed

	   while(Right==0){

	    Left=digitalRead(left);
	    Right=digitalRead(right);

		    if(Left==0){

		      int lprev=Left;
		      int rprev=Right;

		     STOP();

			      while(((lprev==Left)&&(rprev==Right))==1){
			      
			         Left=digitalRead(left);
			         Right=digitalRead(right);

			      }

		    }

	    analogWrite(mot3,100);//change this for speed
	    analogWrite(mot4,0);//don't change this

	  }

   analogWrite(mot1,100);//change this for speed
   analogWrite(mot2,0);//don't change this

}

void STOP (void){

analogWrite(mot1,0);
analogWrite(mot2,0);
analogWrite(mot3,0);
analogWrite(mot4,0);
  
}

void setup(){

  lcd.begin(16,2);
  lcd.setCursor(0,0);
	lcd.print("(0)   /_    (0)");
  lcd.setCursor(0,1);
	lcd.print("   \______/  ");
	lcd.clear();
  lcd.setCursor(0,1);
	lcd.print("LNE FOLWING ROBO");
	
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);

  pinMode(left,INPUT);
  pinMode(right,INPUT);

  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
  
}

void loop() {
 
analogWrite(mot1,100);
analogWrite(mot2,0);
analogWrite(mot3,100);
analogWrite(mot4,0);



	while(1){

	  Left=digitalRead(left);
	  Right=digitalRead(right);
	  
		  if((Left==0 && Right==1)==1){
		    
			  LEFT();
        lcd.begin(16,2);
		 	  lcd.setCursor(6,1);
	  		lcd.print("LEFT");
	  		delay(200);

		  }else if((Right==0 && Left==1)==1){
		    
			  RIGHT();
		    lcd.begin(16,2);
		  	lcd.setCursor(6,1);
	  		lcd.print("RIGHT");
	  		delay(200);

		  }


    }

}
