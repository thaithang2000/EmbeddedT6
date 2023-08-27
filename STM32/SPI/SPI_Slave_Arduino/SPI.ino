/*
  File: Slave.ino
  Author: Thang
  Date: 27/08/2023
  Description: Chương trình mô phỏng quá trình Truyền Nhận Data của Slave
*/
#define SCK  3   // chân SCK
#define MOSI 5   // Chân MOSI
#define SS   7   // Chân SS
#define MISO 4   // chân MISO

bool stateSlave = 1;
uint8_t dataReceived = 0x00;
uint8_t sizeDataReceived = 0;
uint8_t dataTransmited = 0x00;
uint8_t sizeDataTransmited = 0;
uint8_t data_I = 10;

void spiSoftTransmit();// chương trình gửi 1 byte
void spiSoftReceived();// chương trình nhận về 1 byte
void spiSoftSlave();// chương trình ngắt khi có xung SCK
/*
*  Function: setup
*  Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
*  Input:
*    void
*  Output:
*   return: None
*/
void setup()
{
  Serial.begin(9600);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(SS, INPUT);
  pinMode(MISO, OUTPUT);
  dataTransmited = data_I;
  attachInterrupt(1, spiSoftSlave, RISING);
  
}

/*
*  Function: loop
*  Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
*  Input:
*    void
*  Output:
*   return: None
*/
void loop()
{
  if (digitalRead(SS) == HIGH) {
    if (sizeDataReceived == 8) {
      Serial.print("Data Received from Master: ");
      Serial.println((char)dataReceived);
      dataReceived = 0x00;
      sizeDataReceived = 0;
      //stateSlave = false;
    }
  }

}

/*
*  Function: spiSoftSlave
*  Description: Hàm ngắt khi xung SCK của Master phát ra
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftSlave()
{
  if (digitalRead(SS) == HIGH) return;
  //Serial.println("Xung clock");
  if (stateSlave) 
  {
    spiSoftReceived();
  }
  else
  {
    spiSoftTransmit();
  }
}

/*
*  Function: spiSoftReceived
*  Description: Hàm nhận Data từ Master -> Slave
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftReceived()
{
  
  dataReceived = dataReceived << 1; // dịch dữ liệu lên 1 bit
  dataReceived = dataReceived | digitalRead(MOSI);    //đọc chân MOSI
  
  
  sizeDataReceived++;
  
}

/*
*  Function: spiSoftTransmit
*  Description: Hàm truyền Data từ Slave -> Master
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftTransmit()
{
  
  uint8_t x = 0;
  x = dataTransmited & 0x80; // đưa bit cần truyền lên chân MOSI
  if (x > 0)
    digitalWrite(MISO, HIGH);
  else
    digitalWrite(MISO, LOW);
    
  
  dataTransmited = dataTransmited << 1; // dịch dữ liệu cần gửi lên 1 bits
  sizeDataTransmited++;
  
}

uint8_t receive()
{
  uint8_t data = 0;
  while(digitalRead(SS) == 1);
  for(uint8_t i = 0; i << 8; i++){
    while(digitalRead(SCK) == 0);
    while(digitalRead(SCK) == 1);
    if(digitalRead(MOSI) == 1) data = data | (0x80 >> i);
  }

  return data;
}