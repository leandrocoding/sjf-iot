

#include <ESP8266WiFi.h>


//const char* host = "192.168.43.122";
//const int port = 8000;

const char* host = "sjf.zazzi.dev";
const int port = 80;

//String serverName="http://192.168.43.122:8000/api.php";


int sensorPin = A0; 
int val=0; 
int up=450;
int down=350;
#define SSIDD "Zazzi"
#define PASS "123456789zazzi"

int tempval;
int tempUp;
int tempDown;


//RestClient client = RestClient("192.168.43.122",8000);

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(13, OUTPUT);
   digitalWrite(13,HIGH);
   digitalWrite(LED_BUILTIN,HIGH);
   Serial.begin(9600);   
   //client.begin(SSIDD, PASS);
   wifiConnect();

   
         
}

void iot() {
  if(val>up){

    digitalWrite(13,LOW);
    digitalWrite(LED_BUILTIN, LOW);
    
   
    
  }
  else if(val<down){    
        
     digitalWrite(13,HIGH);
     digitalWrite(LED_BUILTIN, HIGH);
  }
             
  
}


void loop() {
  
  val = analogRead(sensorPin); 
  String snum;
  //itoa(val, snum, 10); 
  snum=String(val);
  Serial.print("Current Value: ");
  Serial.println(snum);
  iot();
  
  httpMain(snum);

  
  delay(250);
  
  }



void wifiConnect() {
  int count = 0;
  WiFi.begin(SSIDD, PASS);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    count = count +1;
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
}
int HttpReq(String path){
  int tmp;
  WiFiClient client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, port))
  {
    Serial.println("connected]");

    Serial.println("[Sending a request]");
    Serial.print(String("GET /api.php?")+path + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n");
    client.print(String("GET /api.php?")+path + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    Serial.println("[Response:]");
    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        Serial.println(line);
        
          if(atoi(line.c_str())>100){
           tmp= atoi(line.c_str());
          }
          
            
               
        }
        
        
      }
    
    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
    digitalWrite(13,HIGH);
    tmp=-111;
    
    
  }
  return tmp;
}
void httpMain(String val) {
 if(WiFi.status()== WL_CONNECTED){


      
      //String valpath = serverName + "?val=" + val;
      //String uppath = serverName + "?get=up";
      //String downpath = serverName + "?get=down";
      String up2path = String("get=up");
      String down2path = String("get=down");
      String val2path = String("val=" + val);
      tempval = HttpReq(val2path);
      tempUp = HttpReq(up2path);
      tempDown = HttpReq(down2path);
      if(tempUp>0){
        up = tempUp;
      }
      if(tempDown>0){
        down = tempDown;
      }
   
      
    }
    else {
      Serial.println("WiFi Disconnected");
      delay(1000);
    }
    
  
}