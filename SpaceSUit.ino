int UP, DOWN, LEFT, RIGHT, A, B;


void setup()
{
  Serial.begin(9600);

}

void loop()
{
  ReadButtons()
}

void ReadButtons()
{
  LEFT = analogRead(A2);
  RIGHT = analogRead(A2);
  UP = analogRead(A2);
  DOWN = analogRead(A2);
  A = analogRead(A2);
  B = analogRead(A2);
}

void PrintAnalogPorts()
{
  Serial.print("A0=");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print("A1=");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print("A2=");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print("A3=");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print("A4=");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print("A5=");
  Serial.print(analogRead(A5));
  Serial.print(" ");
  Serial.print("A6=");
  Serial.print(analogRead(A6));
  Serial.print(" ");
  Serial.print("A7=");
  Serial.println(analogRead(A7));
}
