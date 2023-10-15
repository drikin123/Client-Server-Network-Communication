# Explanation (French)

Le projet de communication client-serveur consistait à mettre en place un système permettant à un client d'envoyer un message à un serveur, qui le renverrait ensuite au client.

Pour ce faire, nous avons défini deux classes : la classe « Client » et la classe « Serveur ».

La classe « Client » comprend principalement trois parties :

La déclaration des variables : nous avons déclaré ici un descripteur de socket (sockfd), une structure d’adresse du serveur (adresse_serveur), un pointeur vers la structure descriptive de machine (hote) et deux zones de mémoire (buffer et message) destinées respectivement à accueillir le nom de la machine et le message à envoyer.
Le code du client : dans cette partie, nous avons ouvert le socket du client et rempli la structure d’adresse du serveur avec la famille d’adresse, l’adresse IP et le port. Nous avons également utilisé la fonction « gethostbyname » pour récupérer l’adresse IP du serveur à partir de son nom donné en ligne de commande. Ensuite, nous avons demandé à l’utilisateur d’entrer le message à envoyer et l’avons envoyé au serveur grâce à la fonction « sendto ».
La réception du message : dans cette dernière partie, nous avons utilisé la fonction « recvfrom » pour recevoir le message envoyé par le serveur et l’afficher à l’écran.

La classe « Serveur » comprend également trois parties :

La déclaration des variables : nous avons déclaré ici le descripteur de socket (sockfd), la structure d’adresse locale du serveur (adresse_locale), la structure d’adresse du client (adresse_client) et la taille de l’adresse du client (taille_adresse_client).
Le code du serveur : dans cette partie, nous avons ouvert le socket du serveur et rempli la structure d’adresse locale avec la famille d’adresse, l’adresse IP et le port. Nous avons également spécifié l’adresse locale du socket du serveur grâce à la fonction « bind ».
La boucle générale du serveur : dans cette dernière partie, nous avons défini une boucle infinie qui permet au serveur de rester en attente de messages à recevoir. Lorsqu’un message est reçu, nous l’affichons à l’écran et l’envoyons au client grâce à la fonction « sendto ».

En résumé, la classe « Client » permet de lire le nom de la machine et le message à envoyer, de les envoyer au serveur et de recevoir le message envoyé par le serveur. La classe « Serveur » permet de recevoir le message envoyé par le client, de l’afficher à l’écran et de l’envoyer au client. Grâce à ces deux classes, nous avons mis en place un système de communication bidirectionnel entre le client et le serveur.
