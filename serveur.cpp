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

#define PORT 9600 // port local du serveur

int main(int argc, char *argv[]) {
    /*
  Variables du serveur

  Déclarer ici les variables suivantes  
     -sockfd le descripteur du socket
     -structure d'adresse locale du serveur
     -structure d'adresse du client
     -taille de l'adresse du client
  */  
    int sockfd;
    struct sockaddr_in adresse_serveur;
    struct sockaddr_in adresse_client;
    socklen_t adresse_client_taille = sizeof(adresse_client);
    char buffer[256];

    /*
  *Code du serveur
  *Ouvrir le socket
  *Remplir la structure d'adresse locale du serveur
    -la famille d'adresse
    -l'adresse ip
    -le port
    -Spécifier l'adresse locale du socket du serveur
  */
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    adresse_serveur.sin_family = AF_INET;
    adresse_serveur.sin_port = htons(PORT);
    adresse_serveur.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *)&adresse_serveur, sizeof(adresse_serveur));

    /*
   * Boucle générale du serveur (infinie)
   */
    while (true) {
        // Reception du message
        memset(buffer, 0, 256);
        if (recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&adresse_client,
                     &adresse_client_taille) < 0) {
            cout << "Erreur lors de la réception du message" << endl;
        } else {
            cout << "Message reçu : " << buffer << endl;
        }

        // Envoi du message
        cout << "Entrez le message à envoyer : " << endl;
        cin.getline(buffer, 256);
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&adresse_client,
                   adresse_client_taille) < 0) {
            cout << "Erreur lors de l'envoi du message" << endl;
        } else {
            cout << "Message envoyé" << endl;
        }
    }

    return 0;
}
