#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define PORT 9600

int main(int argc, char *argv[]) {
  // Variables du client
  int sockfd; // descripteur de socket
  struct sockaddr_in adresse_serveur; // structure d'adresse du serveur
  struct hostent *hote; // pointeur vers la structure descriptive de machine (hostent)
  char buffer[256]; // zone de mémoire destinée à accueillir la chaîne entrée au clavier
  char message[256]; // taille de la chaîne à envoyer

  // Code du client
  sockfd = socket(PF_INET, SOCK_DGRAM, 0); // Ouvrir le socket du client
  cout << "Entrez le nom de la machine : " << endl;
  cin >> buffer;
  hote = gethostbyname(buffer); // Récupérer l'adresse IP du serveur à partir de son nom donné en ligne de commande
  adresse_serveur.sin_family = AF_INET;
  adresse_serveur.sin_port = htons(PORT);
  memcpy(&adresse_serveur.sin_addr, hote->h_addr, hote->h_length);
  cout << "Entrez le message à envoyer : " << endl;
  cin.getline(message, 256); // Lire une ligne de l'entrée standard
  if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&adresse_serveur, sizeof(adresse_serveur)) < 0) { // Envoyer la chaîne lue au serveur
    cout << "Erreur lors de l'envoi du message" << endl;
  } else {
    cout << "Message envoyé" << endl;
  }

  // Reception du message
  memset(message, 0, 256);
  if (recvfrom(sockfd, message, 256, 0, NULL, NULL) < 0) {
    cout << "Erreur lors de la réception du message" << endl;
  } else {
    cout << "Message reçu : " << message << endl;
  }

  return 0;
}
