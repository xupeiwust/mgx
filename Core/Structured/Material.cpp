/**
 * \file		Material.h
 * \author		Charles PIGNEROL
 * \date		23/11/2018
 */

#include "Utils/Common.h"
#include "Structured/Material.h"

#include <string.h>

#include <TkUtil/Exception.h>


using namespace TkUtil;
using namespace std;


namespace Mgx3D
{

namespace Structured
{

Material::Material (const std::string& name, int cellNum)
	: _name (name), _cellNum (cellNum < 0 ? 0 : cellNum), _mixedCellNum (0), _pureCellNum (0),
	  _cellIds (0), _cellDensities (0), _cellPresFrac (0)
{
	
	_cellIds	= new int [_cellNum];
	_cellDensities	= new float [_cellNum];
	_cellPresFrac	= new float [_cellNum];
	memset (_cellIds, 0, _cellNum * sizeof (int));
	memset (_cellDensities, 0, _cellNum * sizeof (float));
	memset (_cellPresFrac, 0, _cellNum * sizeof (float));
}	// Material::Material


Material::Material (const Material&)
	: _name ("No name"), _cellNum (0), _mixedCellNum (0), _pureCellNum (0),
	  _cellIds (0), _cellDensities (0), _cellPresFrac (0)
{
	MGX_FORBIDDEN ("Material copy constructor is not allowed.");
}	// Material::Material


Material& Material::operator = (const Material&)
{
	MGX_FORBIDDEN ("Material assignment operator is not allowed.");
	return *this;
}	// Material::operator =

Material::~Material ( )
{
	delete [] _cellIds;		_cellIds	= 0;
	delete [] _cellDensities;	_cellDensities	= 0;
	delete [] _cellPresFrac;	_cellPresFrac	= 0;
}	// Material::~Material


void Material::setMixedCellNum  (int num)
{
	if (num < 0)
	{
		UTF8String	error (Charset::UTF_8);
		error << "Affectation au matériau " << name ( ) << " d'un nombre négatif de mailles mixtes.";
		throw Exception (error);
	}	// if (num < 0)

	_mixedCellNum	= num;
}	// Material::setMixedCellNum


void Material::setPureCellNum  (int num)
{
	if (num < 0)
	{
		UTF8String	error (Charset::UTF_8);
		error << "Affectation au matériau " << name ( ) << " d'un nombre négatif de mailles pures.";
		throw Exception (error);
	}	// if (num < 0)

	_pureCellNum	= num;
}	// Material::setPureCellNum

}	// namespace Structured

}	// namespace Mgx3D


