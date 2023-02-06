/*----------------------------------------------------------------------------*/
/** \file Loop.h
 *
 *  \author Franck Ledoux
 *
 *  \date 18/10/2010
 */
/*----------------------------------------------------------------------------*/
#ifndef LOOP_H_
#define LOOP_H_
/*----------------------------------------------------------------------------*/
#include <vector>
/*----------------------------------------------------------------------------*/
#include "Geom/Curve.h"
/*----------------------------------------------------------------------------*/
namespace Mgx3D {
/*----------------------------------------------------------------------------*/
namespace Geom {
/*----------------------------------------------------------------------------*/
/**
 * \class Loop
 * \brief Une entité de type Loop regroupe un ensemble de courbes formant un
 *        bord d'une surface.
 */
class Loop{

public:

    /*------------------------------------------------------------------------*/
    /** \brief  Constructeur
     */
    Loop();

    /*------------------------------------------------------------------------*/
    /** \brief  Destructeur
     */
    virtual ~Loop();

    /*------------------------------------------------------------------------*/
    /** \brief  Ajoute une courbe dans la boucle. La méthode teste que c
     *          n'est pas déjà présente dans la boucle
     *
     *  \param c une nouvelle courbe
     */
    void add(Curve* c);

    /*------------------------------------------------------------------------*/
    /** \brief  Fournit l'accès aux courbes géométriques composant la boucle
     *
     *  \param curves les courbes
     */
    void get(std::vector<Curve*>& curves) const;

protected:
    std::vector<Curve*> m_curves;
};
/*----------------------------------------------------------------------------*/
} // end namespace Geom
/*----------------------------------------------------------------------------*/
} // end namespace Mgx3D
/*----------------------------------------------------------------------------*/
#endif /* LOOP_H_ */
/*----------------------------------------------------------------------------*/
