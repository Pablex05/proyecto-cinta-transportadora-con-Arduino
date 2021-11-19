int play = 7;
int pausa = 6;
int calibracion = 5;
int sensor1 = 3;
int sensor2 = 4;

int ledplay = 24;
int ledpausa = 22;
int ledcalibracion = 30;
int rele1 = 41;
int rele2 = 43;

void setup() {
  pinMode(rele1, OUTPUT);  //rele motor 1 y 2
  pinMode(rele2, OUTPUT);  //rele electrovalvulas
  
  pinMode(ledplay, OUTPUT);
  pinMode(ledpausa, OUTPUT);
  pinMode(ledcalibracion, OUTPUT);
  
  pinMode(pausa, INPUT);
  pinMode(play, INPUT);
  pinMode(calibracion, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele1, HIGH);
}

void loop() {
  digitalWrite(ledcalibracion, LOW);
  digitalWrite(ledpausa, HIGH);
  digitalWrite(ledplay, LOW);
  
  if (digitalRead(play) == HIGH)
  {
    while (digitalRead(pausa) != HIGH)
    {
     while (digitalRead(sensor2) != LOW)
    {
      digitalWrite(ledplay, HIGH);
      digitalWrite(ledpausa, LOW);
      digitalWrite(ledcalibracion, LOW);
      digitalWrite(rele2, LOW);
      digitalWrite(rele1, HIGH);
      delay(2000);
      digitalWrite(rele2, HIGH);
      digitalWrite(rele1, LOW);
      delay(1000);
       if (digitalRead(pausa) == HIGH)
       {
         digitalWrite(ledpausa, HIGH);
         digitalWrite(ledplay, LOW);
         digitalWrite(ledcalibracion, LOW);
         digitalWrite(rele1, HIGH);
         digitalWrite(rele2, HIGH);
         asm("jmp 0x0000");   
        }
       while (digitalRead(sensor1) == LOW)
       {
         digitalWrite(rele1, HIGH);
         digitalWrite(rele2, HIGH);
         digitalWrite(ledpausa, HIGH);
         digitalWrite(ledplay, HIGH);
         delay(300);
         digitalWrite(ledpausa, LOW);
         digitalWrite(ledplay, LOW);
         delay(300);
         while (digitalRead(pausa) == HIGH)
         asm("jmp 0x0000");
       }
      }
     }
    }
   if (digitalRead(calibracion) == HIGH)
   {
       digitalWrite(ledpausa, LOW);
       digitalWrite(ledplay, LOW);
       digitalWrite(ledcalibracion, HIGH);
     while (digitalRead(sensor1) == LOW)
      while (digitalRead(sensor2) == LOW)
    {
       digitalWrite(ledcalibracion, HIGH);
       digitalWrite(rele1, LOW);
       }
       digitalWrite(ledcalibracion, LOW);
       digitalWrite(rele1, HIGH);
       asm("jmp 0x0000");
      }
 }
