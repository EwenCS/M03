#include "LampeMulticolore.h"
LampeMulticolore::LampeMulticolore(std::string IP,std::string cle,std::string _nom, std::string _id):Domotique(IP,cle)
{	nom=_nom;
	id=_id;
}
std::string LampeMulticolore::Allumer(std::string on)  //"true" "false"
{	return PutAppareil("lights/"+id,"{\"on\":"+on+"}");
}
std::string LampeMulticolore::Teinte(std::string teinte)	//"0" à "65535"
{	return PutAppareil("lights/"+id,"{\"hue\":"+teinte+"}");
}
std::string LampeMulticolore::Intensite(std::string intensite)   //"0" à "255"
{	return PutAppareil("lights/"+id,"{\"bri\":"+intensite+"}");
}
std::string LampeMulticolore::Type()
{   jSON.Extraction(GetAppareil("lights"));
	return jSON.ValeurAttributNiveau1("name",nom,"type");
}

