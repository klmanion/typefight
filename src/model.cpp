/** model.cpp
 */

#include "model.h"

Model&
Model::step()
{
	++ticks;

	return *this;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
