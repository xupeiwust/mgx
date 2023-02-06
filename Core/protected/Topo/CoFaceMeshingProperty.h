/*----------------------------------------------------------------------------*/
/*
 * \file CoFaceMeshingProperty.h
 *
 *  \author Eric Brière de l'Isle
 *
 *  \date 7/12/2011
 */
/*----------------------------------------------------------------------------*/


#ifndef COFACEPROPERTYMESHING_H_
#define COFACEPROPERTYMESHING_H_
/*----------------------------------------------------------------------------*/

#include "Utils/Point.h"
#include <TkUtil/UTF8String.h>
#include <sys/types.h>
#include "Utils/SerializedRepresentation.h"
/*----------------------------------------------------------------------------*/
namespace Mgx3D {
/*----------------------------------------------------------------------------*/
namespace Topo {

class CoFace;

/*----------------------------------------------------------------------------*/
/**
   @brief Propriété de la discrétisation d'une face commune
 */
class CoFaceMeshingProperty {
public:

    /** Les méthodes de maillage pour une face commune
     */
    typedef enum{
        directional,
		orthogonal,
        rotational,
        transfinite,
#ifdef USE_MESHGEMS
		MeshGems,        // recommandé, payant, mais le meilleur
#endif	// USE_MESHGEMS
        delaunayGMSH,    // recommandé / delaunay GMSH
	    quadPairing
    } meshLaw;

    /** Direction suivant laquelle est effectuée la discrétisation (relative à la face commune)
     * pour les méthodes avec une direction
     */
    typedef enum{
        dir_undef,
        dir_i,
        dir_j
    }meshDirLaw;

    /** Côté de départ pour les discrétisations orientés (tel que FaceMeshingPropertyOrthogonal)
     */
    typedef enum{
    	side_undef,
		side_min,
		side_max
    } meshSideLaw;

    /*------------------------------------------------------------------------*/
    /// Comparaison de 2 propriétés.
    virtual bool operator == (const CoFaceMeshingProperty&) const;
    virtual bool operator != (const CoFaceMeshingProperty&) const;
    /*------------------------------------------------------------------------*/
    /// Accesseur sur la méthode de maillage
    virtual meshLaw getMeshLaw() const =0;

    /// Accesseur sur le nom de la méthode de maillage
    virtual std::string getMeshLawName() const =0;

    /*------------------------------------------------------------------------*/
    /** \brief  Indique si la face est structurée
     */
    virtual bool isStructured() const =0;

#ifndef SWIG
    /** Création d'un clone, on copie toutes les informations */
    virtual CoFaceMeshingProperty* clone() =0;

    /// Destructeur
    virtual ~CoFaceMeshingProperty() {}

    /// Script pour la commande de création Python
    virtual TkUtil::UTF8String getScriptCommand() const =0;

    /// initialisation de la direction en fonction de ce qui a été donné à la construction pour certaines méthodes
    virtual void initDir(CoFace* coface) {}

    /*------------------------------------------------------------------------*/
    /// ajoute la description des propriétés spécifiques
    virtual void addProperties(Utils::SerializedRepresentation& ppt) const {};

#endif


protected:
    /*------------------------------------------------------------------------*/
    /// Constructeur par défaut
    CoFaceMeshingProperty() {}

    /*------------------------------------------------------------------------*/
#ifndef SWIG
    /// Constructeur par copie
    CoFaceMeshingProperty(const CoFaceMeshingProperty& pm) {}
#endif

    /*------------------------------------------------------------------------*/
#ifndef SWIG
    /// Cherche la direction dans la coface à partir de deux points
    static meshDirLaw _computeDir(CoFace* coface, Utils::Math::Point & v1, Utils::Math::Point & v2);
    /// Cherche le côté dans la coface à partir de deux points
    static meshSideLaw _computeSide(CoFace* coface, Utils::Math::Point & v1, Utils::Math::Point & v2, uint dir);
#endif

};
/*----------------------------------------------------------------------------*/
} // end namespace Topo
/*----------------------------------------------------------------------------*/
} // end namespace Mgx3D
/*----------------------------------------------------------------------------*/

#endif /* COFACEPROPERTYMESHING_H_ */
