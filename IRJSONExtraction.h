#ifndef IRJSONExtractionH
#define IRJSONExtractionH
#include "IRJSON.h"
#include <string>
class IRJSONExtraction
{   private:
		IRJSONObject jSON;
	public:
		IRJSONExtraction();
		void Extraction(std::string texteJSON);
		std::string Description();
		std::string ValeurAttributNiveau2(std::string nomAttributNiveau1Connu, std::string valeurAttributNiveau1Connue,std::string nomAttributPereNiveau1, std::string nomAttributFilsNiveau2Voulu);
		std::string ValeurAttributNiveau1(std::string nomAttributNiveau1Connu, std::string valeurAttributNiveau1Connue,std::string nomAttributNiveau1Voulu);
};
#endif
