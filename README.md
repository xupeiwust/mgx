# mgx

![spack-ci](https://github.com/LIHPC-Computational-Geometry/mgx/actions/workflows/spack-ci.yml/badge.svg)

Mgx, is an interactive software dedicated to block-structured hex meshing. It provides many interactive tools to design blocks. It also give access to basic functionalities to build CAD models.

The following graph shows the dependencies between mgx and other LIHPC-CG projects. The red square nodes are external products: they are downloaded, built and installed in [`cmake-cgcore`](https://github.com/LIHPC-Computational-Geometry/spack_recipes_meshing/pkgs/container/cmake-cgcore) docker image (not with `apt install`). The black round nodes are LIHPC-CG projects.

This graph is built from the explicit Cmake dependencies specified in the `ci` presets of each project (see `CMakePresets.json` file).

![Dependencies Graph Image](cg-dependencies.png)
