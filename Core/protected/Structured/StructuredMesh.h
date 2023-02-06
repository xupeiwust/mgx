/**
 * \file		StructuredMesh.h
 * \author		Charles PIGNEROL
 * \date		23/11/2018
 */


#ifndef MGX3D_STRUCTURED_MESH_H
#define MGX3D_STRUCTURED_MESH_H


//#include <machine_types.h>

#include <string>


namespace Mgx3D
{

namespace Structured
{

/**
 * Classe de maillage structuré de dimensions ni * nj * nk (donc respectivement
 * ni+1, nj+1 et nk+1 noeuds dans chaque dimension).
 */
class StructuredMesh
{
	public :

	/**
	 * Constructeur.
	 * \param	<I>type</I> est le type de maillage structuré au sens 
	 *		<I>HIC</I> du terme, donc par exemple <I>Maillage-3D-S-Ortho</I>.
	 * \param	<I>ni</I>,<I>nj</I> et <I>nk</I> sont les dimensions du maillage.
	 * \param	<I>true</I> s'il faut allouer les tableaux contenant les composantes
	 *		des coordonnées des noeuds, <I>false</I> dans le cas contraire.
	 */
	StructuredMesh (const std::string& type, int ni, int nj, int nk,
	                bool allocate = true);

	/**
	 * Destructeur.Désalloue la mémoire utilisée (<U>tous</U> les tableaux).
	 */
	virtual ~StructuredMesh ( );

	/** \return	Le type de maillage structuré (au sens <I>HIC</I>). */
	virtual const std::string& type ( ) const
	{ return _type; }

	/** \return	Le nombre de noeuds du maillage. */
	int nodeNum ( ) const
	{ return (_ni + 1) * (_nj + 1) * (_nk + 1); }

	/** \return	Les dimensions du maillage. */
	int ni ( ) const
	{ return _ni; }
	int nj ( ) const
	{ return _nj; }
	int nk ( ) const
	{ return _nk; }

	/** \return	Les composantes des noeuds sur les 3 axes. */
	float* x ( )
	{ return _abs; }
	const float* x ( ) const
	{ return _abs; }
	const float* abs ( ) const
	{ return _abs; }
	float* abs ( )
	{ return _abs; }
	float* y ( )
	{ return _ord; }
	const float* y ( ) const
	{ return _ord; }
	const float* ord ( ) const
	{ return _ord; }
	float* ord ( )
	{ return _ord; }
	float* z ( )
	{ return _elev; }
	const float* z ( ) const
	{ return _elev; }
	const float* elev ( ) const
	{ return _elev; }
	float* elev ( )
	{ return _elev; }

	/**
	 * <P><I>Nombre de mailles = nombre de mailles pures + nombre de mailles mixtes.</I></P>
	 * \return	Le nombre de mailles.
	 * \see		mixedCellNum
	 * \see		pureCellNum
	 */
	int cellNum ( ) const
	{ return _cellNum; }

	/**
	 * \return	Le nombre de mailles mixtes.
	 * \see		cellNum
	 * \see		mixedIds
	 */
	int mixedCellNum ( ) const
	{ return _mixedCellNum; }

	/**
	 * \return	Les identifiants des mailles mixtes.
	 * \see		mixedCellNum
	 * \see		pureIds
	 */
	const int* mixedIds ( ) const
	{ return _mixedIds; }
	int* mixedIds ( )
	{ return _mixedIds; }

	/**
	 * \return	Le nombre de mailles pures.
	 * \see		mixedCellNum
	 * \see		setPureCellNum
	 */
	int pureCellNum ( ) const
	{ return _pureCellNum; }

	/**
	 * <P>Mémorise le nombre de mailles pures et alloue les tableaux
	 * contenant les identifiants des mailles pures et des mailles
	 * mixtes.</P>
	 * <P><I>Nombre de mailles = nombre de mailles pures + nombre de mailles mixtes.</I></P>
	 */
	void setPureCellNum (int num);

	/**
	 * \return	Les identifiants des mailles pures.
	 * \see		mixedCellNum
	 */
	const int* pureIds ( ) const
	{ return _pureIds; }
	int* pureIds ( )
	{ return _pureIds; }

	/**
	 * \param	Valeurs extrèmales prises par la densité, pour optimisation en vue
	 *		de ne pas multiplier les recherches.
	 * \see		cellDensities
	 */
	void setDensityRange (float min, float max);
	float densityMin ( ) const
	{ return _densityMin; }
	float densityMax ( ) const
	{ return _densityMax; }

	/**
	 * \return	Les densités des mailles.
	 * \see		setCellDensities
	 */
	const float* cellDensities ( ) const
	{ return _densities; }
	float* cellDensities ( )
	{ return _densities; }

	/**
	 * \param	Les nouvelles densités des mailles.
	 * \warning	<B>Détruit l'ancien tableau de densités et adopte celui reçu en argument.</B>
	 */
	void setCellDensities (float* densities);


	private :

	/**
	 * Constructeur de copie, opérateur = : interdits.
	 */
	StructuredMesh (const StructuredMesh&);
	StructuredMesh& operator = (const StructuredMesh&);

	std::string		_type;
	int			_ni, _nj, _nk;
	int			_cellNum;
	int			_mixedCellNum;
	int			_pureCellNum;
	float*		_abs;
	float*		_ord;
	float*		_elev;
	int*			_pureIds;
	int*			_mixedIds;
	float			_densityMin, _densityMax;
	float*		_densities;
};	// class StructuredMesh

}	// namespace Structured

}	// namespace Mgx3D



#endif	// MGX3D_STRUCTURED_MESH_H

