#ifndef DomotiqueH
#define DomotiqueH
#include "IRJSONExtraction.h"
#include "IRClientTCP.h"
class Domotique
{   protected:
		IRJSONExtraction jSON;
		std::string IP,cle;
	public:
		Domotique(std::string _IP,std::string _cle);
		std::string ListeCapteurs();
		std::string ListeLampes();
		std::string PutAppareil(std::string appareil,std::string etatJSON);
		std::string GetAppareil(std::string appareil);
};
#endif
