#include <iostream>
#include <string>
#include "IRClientTCP.h"
#include "IRJSON.h"
#include "IRJSONExtraction.h"
using namespace std;


int main()
{
	IRClientTCP passerelleDomotic;
	string IP ="172.20.21.4";
	char reponse [10001];
	int debutDonnee;

	passerelleDomotic.SeConnecterAUnServeur("172.20.21.4",80);
	string requete = "GET /api/B91F81E525/sensors HTTP/1.1\r\nHost: 172.20.21.4\r\nConnection: keep-alive\r\nAccept: */*\r\n\r\n";
	//string requete = "PUT /api/B91F81E525/sensors HTTP/1.1\r\nHost: 172.20.21.4\r\nConnection: keep-alive\r\nAccept: */*\r\n\r\n";
	passerelleDomotic.Envoyer(requete.c_str(),requete.length());
	int n=passerelleDomotic.Recevoir(reponse,10000);

	string reponseString=reponse;
	n=passerelleDomotic.Recevoir(reponse,10000);
	reponse[n]='\0';
	reponseString += reponse;
	debutDonnee = reponseString.find("\r\n\r\n",0);
	reponseString=reponseString.substr(debutDonnee+4);
	//cout<<reponseString<<endl;
	IRJSONExtraction jSON;
	jSON.Extraction(reponseString);
	//cout<<jSON.Description()<<endl;
	cout<<jSON.ValeurAttributNiveau2("name","temp A6-1","states","temperature")<<" degres "<<endl;
	cout<<jSON.ValeurAttributNiveau2("name","temp A6-1","states","humidity")<<" % "<<endl;
	cout<<jSON.ValeurAttributNiveau2("name","temp A6-1","states","pressure")<<" hPa "<<endl;
	while(1)
    {   string on,hue,bri;
        cout<<"teinte, intensite, on (ex : 40000 255 true) ? ";cin>>hue>>bri>>on;
        requete = "PUT /api/880F0E80F5/lights/3/state HTTP/1.1\r\nHost: 172.20.21.4\r\nConnection: keep-alive\r\nContent-Type: application/json\r\nAccept: */*\r\n\r\n";
        requete+="{\"hue\":"+hue+",\"bri\":"+bri+",\"on\":"+on+"}";
        passerelleDomotic.Envoyer(requete.c_str(),requete.length());

    }
	cin.get();
	passerelleDomotic.SeDeconnecter();
	return 0;

}
