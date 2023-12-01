#include "CapteurTemperature.h"
CapteurTemperature::CapteurTemperature(string IP,string cle,string _nom):Domotique(IP,cle)
{	nom=_nom;
}
string CapteurTemperature::Temperature()
{   jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","temperature");
}
string CapteurTemperature::Humidite()
{   jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","humidity");
}
std::string CapteurTemperature::Pression()
{   jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","pressure");
}
std::string CapteurTemperature::Type()
{   jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau1("name",nom,"type");
}

