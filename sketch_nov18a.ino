int redPin = 10;
int bluePin = 8;
int greenPin = 9;
int buttonPin = 7;


int lastButton = LOW;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 11;
int g = 12;

int buzzy = 13;

void setup()
{
  //7 segment LED
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  //Button
  pinMode(buttonPin, INPUT);

  //RGB LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  //Buzzer Sound
  pinMode(buzzy, OUTPUT);


  //Test
  Serial.begin(9600);
}
void rgb_color(int redPinValue, int greenPinValue, int bluePinValue)
{
  analogWrite(redPin, redPinValue);
  analogWrite(greenPin, greenPinValue);
  analogWrite(bluePin, bluePinValue);
}


void turnOffLed()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void ledN(int digit)
{
  if (digit == 0)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
  }
  if (digit == 1)
  {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
  }
  if (digit == 2)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(g, HIGH);
  }
  if (digit == 3)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
  }
  if (digit == 4)
  {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (digit == 5)
  {
    digitalWrite(a, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (digit == 6)
  {
    digitalWrite(a, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
  }
  if (digit == 7)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
  }
  if (digit == 8)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (digit == 9)
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
}
void progressBar()
{


  digitalWrite(d, HIGH);
  delay(20);
  digitalWrite(e, HIGH);
  delay(24);
  digitalWrite(f, HIGH);
  delay(28);
  digitalWrite(a, HIGH);
  delay(32);
  digitalWrite(b, HIGH);
  delay(36);
  digitalWrite(c, HIGH);
  delay(41);


  digitalWrite(d, LOW);
  delay(20);
  digitalWrite(e, LOW);
  delay(24);
  digitalWrite(f, LOW);
  delay(28);
  digitalWrite(a, LOW);
  delay(32);
  digitalWrite(b, LOW);
  delay(36);
  digitalWrite(c, LOW);
  delay(41);

}

void loop()
{

  
  int prButton = digitalRead(buttonPin);
  if (prButton != lastButton)
  {
    for (int i = 9; i > -1; i--)
    {
      ledN(i);
      switch (i)
      {
        case 0:
          tone(buzzy, 950, 1000);
          for (int n = 5; n > 0; n--)
          {
            rgb_color(0, 0, 255);
            delay(175);
            rgb_color(LOW, LOW, LOW);
            delay(175);
          }
          break;
        case 1:
          tone(buzzy, 650, 250);
          rgb_color(255, 0, 255);
          break;

        case 2:
          tone(buzzy, 650, 250);
          rgb_color(255, 0, 255);
          break;
        default:
          tone(buzzy, 450, 250);
          rgb_color(255, 0, 0);
          break;
      }

      delay(500);

      turnOffLed();
      delay(100);
      progressBar();
      turnOffLed();
      delay(40);

    };


  }


}
