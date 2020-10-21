#include <NTPClient.h>


NTPClient::NTPClient(UDP& udp, char* serverName){
    this->_udp = &udp;
    this->_serverName = serverName;
}

int NTPClient::begin(){
    this->_udp->begin(3123);
}

void NTPClient::update(){

    this->begin();

    this->sendNTPPacket();

    int cb = 0;
    do {
        delay ( 10 );
        cb = this->_udp->parsePacket();
        Serial.print("Aqui  ");
        Serial.println(cb);
       
  } while (cb == 0);

}

void NTPClient::sendNTPPacket(){

    //função para que todos os locais dos vetores recebam 0
    memset(this->_packetBuffer,0,NTP_PACKET_SIZE);
    this->_udp->beginPacket(this->_serverName,123);

    this->_packetBuffer[0] = 0b11100011;   
    this->_packetBuffer[1] = 0;     
    this->_packetBuffer[2] = 6;     
    this->_packetBuffer[3] = 0xEC;  
    // inicia o pacote de dados
    this->_udp->write(this->_packetBuffer,NTP_PACKET_SIZE);
    // envia o pacote de dados 
    this->_udp->endPacket();
}
