// necessário para que o ficheiro atual seja incluido apenas uma vez
#pragma once 
// necessário para manipular objetos UDP
#include <Udp.h>

// necessário para colocar alguns tipos como o byte
#include "Arduino.h"

// tamanho do pacote de dados do protocolo
#define NTP_PACKET_SIZE 48
// porta local padrão do client

// class do objeto cliente
class NTPClient {
    // referencia de objeto UDP
    UDP*          _udp;

    // armazena o nome do servidor NTP
    char * _serverName;
    
    //buffer que irá armazenar o pacote de dados
    byte          _packetBuffer[NTP_PACKET_SIZE];

    // função para solicitação dos pacotes
    int          sendNTPPacket();

    public:

    //construtor para receber o objeto UDP e nome do servidor UDP 
    NTPClient(UDP& udp, char* serverName);

    //função que inicia a conexão UDP com o servidor NTC
    int begin();

    //atualiza a hora toda vez que a função é chamada
    int update();

    // retorna a hora atual em forma de string
    String getFormattedTime() const;




};
