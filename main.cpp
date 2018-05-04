#include "AmobaJatekMester.hpp"

using namespace std;
using namespace genv;


int main()
{
	gout.open(700,700);
	AmobaJatekMester vindo;
	vindo.event_loop();

	return 0;
}
