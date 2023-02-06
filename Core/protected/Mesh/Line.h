/*----------------------------------------------------------------------------*/
/*
 * \file Line.h
 *
 *  \author Eric Brière de l'Isle
 *
 *  \date 24/08/16
 */
/*----------------------------------------------------------------------------*/
#ifndef MGX3D_MESH_LINE_H_
#define MGX3D_MESH_LINE_H_
/*----------------------------------------------------------------------------*/
#include "Mesh/MeshEntity.h"
#include <TkUtil/UTF8String.h>
#include "Utils/Container.h"
#include "Topo/MeshLineTopoProperty.h"

namespace gmds {
class Node;
class Edge;
}
/*----------------------------------------------------------------------------*/
namespace Mgx3D {

namespace Internal {
class InfoCommand;
}
/*----------------------------------------------------------------------------*/
namespace Mesh {
/*----------------------------------------------------------------------------*/
/**
   @brief Ligne de bras du maillage
 */
#ifdef SWIG
%name(MeshLine)
#endif
class Line : public MeshEntity {
    static const char* typeNameMeshLine;

public:

    /// Constructeur
#ifndef SWIG
    Line(Internal::Context& ctx, Utils::Property* prop, Utils::DisplayProperties* disp);
#endif

    /// Destructeur
    virtual ~Line();

    /*------------------------------------------------------------------------*/
    /** \brief  retourne la dimension des entités du groupe
     */
    int getDim() const {return 1;}

    /*------------------------------------------------------------------------*/
    /** \brief  Retourne la boite englobante de l'entité.
	 * \param	En retour, la boite englobante définit comme suit
	 * 			<I>(xmin, xmax, ymin, ymax, zmin, zmax)</I>.
	 */
#ifndef SWIG
	virtual void getBounds (double bounds[6]) const;
#endif	// SWIG

    /*------------------------------------------------------------------------*/
    /** \brief  Fournit une représentation affichable de l'entité en se basant
     *          sur la représentation passée en paramètre
     *
     *  \param  dr la représentation que l'on demande à afficher
     *  \param	Lève une exception si checkDestroyed vaut true
     */
#ifndef SWIG
    virtual void getRepresentation(
			Mgx3D::Utils::DisplayRepresentation& dr, bool checkDestroyed) const;
#endif

    /*------------------------------------------------------------------------*/
    /** \brief  Fournit une représentation textuelle de l'entité.
	 * \param	true si l'entité fourni la totalité de sa description, false si
	 * 			elle ne fournit que les informations non calculées (objectif :
	 * 			optimisation)
     * \return  Description, à détruire par l'appelant.
     */
#ifndef SWIG
    virtual Mgx3D::Utils::SerializedRepresentation* getDescription (
													bool alsoComputed) const;
#endif

    /*------------------------------------------------------------------------*/
    /** \brief Donne le nom du type d'objet (un nom distinct par type d'objet)
     */
    virtual std::string getTypeName() const {return typeNameMeshLine;}

    /*------------------------------------------------------------------------*/
    /** \brief Donne le type de l'objet
     */
    virtual Utils::Entity::objectType getType() const {return Utils::Entity::MeshLine;}

    /*------------------------------------------------------------------------*/
   /** \brief Donne le nom court du type d'objet (pour le nommage des entités)
    */
    static std::string getTinyName() {return "Li";}

    /*------------------------------------------------------------------------*/
    /** \brief Test si l'entité est un Line suivant son nom
     */
    static bool isA(std::string& name);

    /*------------------------------------------------------------------------*/
    /// pour l'affichage d'informations
#ifndef SWIG
    friend TkUtil::UTF8String & operator << (TkUtil::UTF8String & , const Cloud &);
#endif

    /*------------------------------------------------------------------------*/
    /// \brief Ajoute une relation vers une arête commune
#ifndef SWIG
    void addCoEdge(Topo::CoEdge* e);
#endif

    /// Retire une relation vers une Edge
#ifndef SWIG
    void removeCoEdge(Topo::CoEdge* e);
#endif

    ///  Fournit l'accès aux arêtes topologiques qui ont participées à la constitution de la ligne
    void getCoEdges(std::vector<Topo::CoEdge* >& edges) const;

    /** supprime les relations vers les arêtes */
    void clearCoEdges()
    {m_topo_property->clear();}

    /*----------------------------------------------------------------------------*/
    ///  Fournit l'accès aux bras GMDS
    void getGMDSEdges(std::vector<gmds::Edge >& AEdges) const;

    ///  Fournit l'accès aux noeuds GMDS
    void getGMDSNodes(std::vector<gmds::Node >& ANodes) const;

    /*------------------------------------------------------------------------*/
    /** Duplique le MeshLineTopoProperty pour en conserver une copie
     *  (non modifiée par les accesseurs divers)
     *  Si le MeshLineTopoProperty a déjà une copie de sauvegarde, il n'est rien fait
     *
     *  Si InfoCommand n'est pas nul, il est informé de la modification de l'entité
     */
    void saveMeshLineTopoProperty(Internal::InfoCommand* icmd);

    /** Echange le MeshLineTopoProperty avec celui donné, retourne l'ancien
     * C'est à l'appelant de le détruire
     */
    Topo::MeshLineTopoProperty* setProperty(Topo::MeshLineTopoProperty* prop);

    /** Transmet les propriétés sauvegardées
      *  dont la destruction est alors à la charge du CommandCreateMesh
      *  On ne garde pas de lien dessus
      */
#ifndef SWIG
    virtual void  saveInternals(Mesh::CommandCreateMesh* ccm);
#endif

private:
    /// Constructeur par copie
    Line(const Line& cl);

    /// Opérateur de copie
    Line & operator = (const Line& ln);

    // lien sur les Topo::CoEdge qui ont participées à la constitution des noeuds
    Topo::MeshLineTopoProperty* m_topo_property;

    /// sauvegarde du m_topo_property
    Topo::MeshLineTopoProperty* m_save_topo_property;
};
/*----------------------------------------------------------------------------*/
} // end namespace Mesh
/*----------------------------------------------------------------------------*/
} // end namespace Mgx3D
/*----------------------------------------------------------------------------*/
#endif /* MGX3D_MESH_LINE_H_ */
/*----------------------------------------------------------------------------*/
