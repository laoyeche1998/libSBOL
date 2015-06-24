#include "documented.h"

using namespace std;
using namespace sbol;

Documented::Documented(std::string uri_prefix, std::string display_id)
{
	identity.set(uri_prefix + "/" + display_id + "/1.0.0");
	persistentIdentity.set(uri_prefix + "/" + display_id + "/1.0.0");
	displayID.set(display_id);
	name.set("");
	description.set("");
}
//sbol_type Documented::getTypeURI()
//{
//	return type;
//}