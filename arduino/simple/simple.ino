
int sensorPin = A0; 
int val=0; 

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(13, OUTPUT);
   Serial.begin(9600);           
  
}

void loop() {
  
  val = analogRead(sensorPin); 
  char snum[12];
  itoa(val, snum, 10); 
  Serial.println(snum);
  if(val>450){
    digitalWrite(13,LOW);
    digitalWrite(LED_BUILTIN, LOW);
    
   
    
  }
  else if(val<350){               
     digitalWrite(13,HIGH);
     digitalWrite(LED_BUILTIN, HIGH);
  }}

