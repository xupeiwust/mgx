/**
 * \file		Material.h
 * \author		Charles PIGNEROL
 * \date		23/11/2018
 */

#ifndef MGX3D_MATERIAL_H
#define MGX3D_MATERIAL_H

//#include <machine_types.h>

#include <string>


namespace Mgx3D
{

namespace Structured
{

/**
 * Classe représentant la répartition d'un matériau (milieu) dans un maillage.
 */
class Material
{
	public :

	/**
	 * Constructeur. Effectue les allocations des différents tableaux
	 * (identifiants, densités, fractions de présence) pour <I>cellNum</I>
	 * mailles.
	 * \param	Nom du matériau
	 * \param	Nombre de mailles où ce matériau est présent.
	 */
	Material (const std::string& name, int cellNum);

	/**
	 * Destructeur.
	 * Détruit <U>tous</U> les tableaux.
	 */
	~Material ( );

	/** \return	Le nom du matériau. */
	const std::string& name ( ) const
	{ return _name; }

	/** \return	Le nombre de mailles où ce matériau est présent. */
	int cellNum ( ) const
	{ return _cellNum; }

	/**
	 * \return	Le nombre de mailles mixtes contenant ce matériau.
	 * \see		setMixedCellNum
	 * \see		setPureCellNum
	 */
	int mixedCellNum ( ) const
	{ return _mixedCellNum; }

	/**
	 * \param	Le nombre de mailles mixtes contenant ce matériau.
	 * \see		mixedCellNum
	 * \see		setPureCellNum
	 */
	void setMixedCellNum (int num);

	/**
	 * \return	Le nombre de mailles pures contenant ce matériau.
	 * \see		setPureCellNum
	 * \see		setMixedCellNum
	 */
	int pureCellNum ( ) const
	{ return _pureCellNum; }

	/**
	 * \param	Le nombre de mailles pures contenant ce matériau.
	 * \see		pureCellNum
	 * \see		setPixedCellNum
	 */
	void setPureCellNum (int num);

	/**
	 * \return	Les identifiants des mailles contenant le matériau.
	 * \see		cellDensities
	 * \see		cellPresFrac
	 */
	const int* cellIds ( ) const
	{ return _cellIds; }
	int* cellIds ( )
	{ return _cellIds; }

	/**
	 * \return	Les densités des mailles.
	 * \see		cellIds
	 * \see		cellPresFrac
	 */
	const float* cellDensities ( ) const
	{ return _cellDensities; }
	float* cellDensities ( )
	{ return _cellDensities; }

	/**
	 * \return	Les fractions de présence dans chaque maille.
	 * \see		cellIds
	 * \see		cellDensities
	 */
	const float* cellPresFrac ( ) const
	{ return _cellPresFrac; }
	float* cellPresFrac ( )
	{ return _cellPresFrac; }


	private :

	Material (const Material&);
	Material& operator = (const Material&);

	std::string		_name;
	int			_cellNum;
	int			_mixedCellNum;
	int			_pureCellNum;
	int*			_cellIds;
	float*		_cellDensities;
	float*		_cellPresFrac;
};	// class Material


}	// namespace Structured

}	// namespace Mgx3D


#endif	// MGX3D_MATERIAL_H

