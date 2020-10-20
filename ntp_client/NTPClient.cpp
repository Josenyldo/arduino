#include <NTPClient.h>


NTPClient::NTPClient(UDP& udp, char* serverName){
    this->_udp = &udp;
    this->_serverName = serverName;
}

int NTPClient::begin(){
    this->_udp->begin(1337);
}

int NTPClient::update(){
    return this->sendNTPPacket();
}

int NTPClient::sendNTPPacket(){

    //função para que todos os locais dos vetores recebam 0
    memset(this->_packetBuffer,0,NTP_PACKET_SIZE);
    return this->_udp->beginPacket(this->_serverName,123);

}
