#include "IRJSONExtraction.h"
IRJSONExtraction::IRJSONExtraction()
{
}
void IRJSONExtraction::Extraction(std::string texteJSON)
{	jSON.Extraction(texteJSON);
}
std::string IRJSONExtraction::Description()
{	return jSON.Description();
}
std::string IRJSONExtraction::ValeurAttributNiveau2(std::string nomAttributNiveau1Connu, std::string valeurAttributNiveau1Connue,std::string nomAttributPereNiveau1, std::string nomAttributFilsNiveau2Voulu)
{   for(int i=0;i<jSON.NombreDeDonnees();i++)
	{	if(jSON.Objet(jSON[i]->Attribut())->Valeur(nomAttributNiveau1Connu)==valeurAttributNiveau1Connue
			&& jSON.Objet(jSON[i]->Attribut())->Objet(nomAttributPereNiveau1)->Valeur(nomAttributFilsNiveau2Voulu)!="")
			return jSON.Objet(jSON[i]->Attribut())->Objet(nomAttributPereNiveau1)->Valeur(nomAttributFilsNiveau2Voulu);
	}
	return "";
}
std::string IRJSONExtraction::ValeurAttributNiveau1(std::string nomAttributNiveau1Connu, std::string valeurAttributNiveau1Connue,std::string nomAttributNiveau1Voulu)
{   for(int i=0;i<jSON.NombreDeDonnees();i++)
		if(jSON.Objet(jSON[i]->Attribut())->Valeur(nomAttributNiveau1Connu)==valeurAttributNiveau1Connue
			&& jSON.Objet(jSON[i]->Attribut())->Valeur(nomAttributNiveau1Voulu)!="")
			return jSON.Objet(jSON[i]->Attribut())->Valeur(nomAttributNiveau1Voulu);
	return "";
}
