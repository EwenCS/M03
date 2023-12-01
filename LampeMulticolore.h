#ifndef LampeMulticoloreH
#define LampeMulticoloreH
#include "Domotique.h"
class LampeMulticolore : public Domotique
{   private:
		std::string nom,id;
	public:
		LampeMulticolore(std::string IP,std::string cle,std::string _nom, std::string _id);
		std::string Allumer(std::string on);  //"true" "false"
		std::string Teinte(std::string teinte);	//"0" à "65535"
		std::string Intensite(std::string intensite);   //"0" à "255"
		std::string Type();
};
#endif
