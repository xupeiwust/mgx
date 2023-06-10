import sys
import pyMagix3D as Mgx3D

def test_import_mgx():
    ctx = Mgx3D.getStdContext()
    gm = ctx.getGeomManager ()
    tm = ctx.getTopoManager ()
    tm.newBoxWithTopo (Mgx3D.Point(0, 0, 0), Mgx3D.Point(1, 1, 1), 10, 10, 10)
    assert gm.getNbVolumes()==1
    assert gm.getNbSurfaces()==6
    assert gm.getNbCurves()==12
    assert gm.getNbVertices()==8
