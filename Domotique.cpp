#include <sstream>
#include "Domotique.h"
Domotique::Domotique(string _IP,string _cle)
{	IP=_IP;
	cle=_cle;
}
std::string Domotique::ListeCapteurs()
{	jSON.Extraction(GetAppareil("sensors"));
	return jSON.Description();
}
std::string Domotique::ListeLampes()
{	jSON.Extraction(GetAppareil("lights"));
	return jSON.Description();
}
std::string Domotique::PutAppareil(std::string appareil,std::string etatJSON)
{	IRClientTCP passerelleDomotic;
	std::string requete="PUT /api/"+cle+"/"+appareil+"/state HTTP/1.1"+"\r\nHost: "+IP+"\r\nConnection: keep-alive\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36\r\nContent-Type: application/json\r\nAccept: */*\r\n\r\n";
	bool ok=passerelleDomotic.SeConnecterAUnServeur(IP,80);
	if(ok)
	{   requete=requete+etatJSON;
		passerelleDomotic.Envoyer(requete.c_str(),requete.length());
		char reponse[1501];
		int n;
		n=passerelleDomotic.Recevoir(reponse,1500);
		reponse[n]=0;
		passerelleDomotic.SeDeconnecter();
		return reponse;
	}
	return "Serveur introuvable";
}
std::string Domotique::GetAppareil(std::string appareil)
{   IRClientTCP passerelleDomotic;
	bool ok=passerelleDomotic.SeConnecterAUnServeur(IP.c_str(),80);
	std::string requete="GET /api/"+cle+"/"+appareil+" HTTP/1.1"+"\r\nHost: "+IP+"\r\nConnection: keep-alive\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36\r\nContent-Type: application/json\r\nAccept: */*\r\n\r\n";
	std::string reponseComplete="";
	if(ok)
	{   passerelleDomotic.Envoyer(requete.c_str(),requete.length());
		char reponse[1501];
		int n,NbOctetsDonnees=0,contentLengthInt,debutDonnee;
		do
		{   std::string rechercheDebut="Content-Length: ",rechercheFin="\r\n";
			n=passerelleDomotic.Recevoir(reponse,1500);
			reponse[n]=0;
			std::string reponseString=reponse;
			if(!NbOctetsDonnees)
			{	int d=reponseString.find(rechercheDebut,0);
				int f=reponseString.find(rechercheFin,d);
				d=d+rechercheDebut.length();
				std::string contentLength=reponseString.substr(d,f-d);
				std::stringstream ss;
				ss<<contentLength;
				ss>>contentLengthInt;
				debutDonnee=reponseString.find("\r\n\r\n",f)+4;
				NbOctetsDonnees=n-debutDonnee;
				strcpy(reponse,reponseString.substr(debutDonnee,NbOctetsDonnees).c_str());
			}
			else NbOctetsDonnees+=n;
			reponseComplete=reponseComplete+reponse+"\n";
		}while(NbOctetsDonnees<contentLengthInt);
	} else return "Serveur introuvable";
	passerelleDomotic.SeDeconnecter();
	return reponseComplete;
}

