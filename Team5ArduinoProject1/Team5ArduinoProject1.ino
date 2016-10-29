//Hey guys, here is a file with which you can begin programming. - Theo
//The blinking yellow light doesn't work. I'm probably mising something really stupid. - Mitchel
int temperaturePin = 0; 

int ledDigitalOne[] = {9, 10, 11}; 
const boolean ON = LOW;     
const boolean OFF = HIGH;
const boolean RED[] = {ON, OFF, OFF};    
const boolean GREEN[] = {OFF, OFF, ON}; 
const boolean BLUE[] = {OFF, ON, OFF}; 
const boolean YELLOW[] = {ON, OFF, ON}; 
const boolean CYAN[] = {OFF, ON, ON}; 
const boolean MAGENTA[] = {ON, ON, OFF}; 
const boolean WHITE[] = {ON, ON, ON}; 
const boolean BLACK[] = {OFF, OFF, OFF}; 
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};

void setup() {
Serial.begin(9600); 
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   
  } 
}

void loop() {
 float temperature = getVoltage(temperaturePin);  
 temperature = (temperature - .5) * 100;         
                                                 
 Serial.println(temperature);                     
 delay(1000);

  if((temperature > 20.9) &&(temperature < 29.1)){
    setColor(ledDigitalOne, GREEN);
  }

  if(temperature >= 29.1){
    digitalWrite(ledDigitalOne, LOW);
    delay(500);
    digitalWrite(ledDigitalOne, HIGH);
    delay(500);
    setColor(ledDigitalOne, YELLOW);
  }
  if(temperature > 30){
    setColor(ledDigitalOne, RED);
  } 

  if(temperature <= 20.9){
    digitalWrite(ledDigitalOne, LOW);
    delay(500);
    digitalWrite(ledDigitalOne, HIGH);
    delay(500);
    setColor(ledDigitalOne, YELLOW);
  }
  if(temperature < 20){
    setColor(ledDigitalOne, RED);
  }
}

float getVoltage(int pin){
  return (analogRead(pin) * .004882814); 
}

void setColor(int* led, boolean* color){
  for(int i = 0; i < 3; i++){
    digitalWrite(led[i], color[i]);
  }
}
