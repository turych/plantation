#define  A_0      A0
#define  A_1      A1
#define  A_2      A2
#define  A_3      A3

const int relayShift = 2;

bool relay[4];

void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT); 
  pinMode(relayShift,OUTPUT);
  pinMode(relayShift + 1,OUTPUT);

  digitalWrite(relayShift,HIGH);
  digitalWrite(relayShift + 1,HIGH);
  digitalWrite(relayShift + 2,HIGH);
  digitalWrite(relayShift + 3,HIGH);
  delay(5000); 
}
void loop(){
  uint16_t analog_0 = analogRead(A_0);
  uint16_t analog_1 = analogRead(A_1);
  uint16_t analog_2 = analogRead(A_2);
  uint16_t analog_3 = analogRead(A_3);    

  relay[0] = analog_0 < 300;
  relay[1] = analog_1 < 300;
  relay[2] = analog_2 < 300;
  relay[3] = analog_3 < 300;

  for (int i = 0; i < 4; i++) {
    Serial.println("sensor");
    Serial.println(relay[i]);
    if (relay[i]) {
      turnOn(i + relayShift);
    }
  }

  delay(1800000);       
}

void turnOn(int relayPin) {
    Serial.println("relay");
    Serial.println(relayPin);
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(relayPin,LOW);
    delay(15000);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(relayPin,HIGH);
}
