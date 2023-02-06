#! /bin/ksh
export VERSION_MAILLAGE=10000
export LIB_MAGIX3D=$1

print "VARIANT GSCC = "$3
print "SYSTEM = "$SYSTEM

# gcc ou icpc ?
COMPILO=`echo $2 | awk -F '-' '{print $2}'`
print "COMPILO="$COMPILO

# recuperation de la version et du variant pour Lima
INFO_LIMA=`cd Magix3D;/ccc/products/nec/bin/gscc/gscc_showDependencies.py -e Lima $COMPILO | sed 's/, / --variant=/g'`
VERSION_LIMA=`echo $INFO_LIMA | awk  '{print $1}'`
VARIANT_LIMA=`echo $INFO_LIMA | awk  '{print $2}'`
print "VARIANT_LIMA="$VARIANT_LIMA

SWIG_COMPILER_VERSION=`echo $3 | awk -vRS='-' '/Swig/{print $1}'`
PYTHON_LIB_VERSION=`echo $3 | awk -vRS='-' '/Python/{print $1}'`

# les variants par défaut ayant changés, on doit les nommer explicitement
if [ "${PYTHON_LIB_VERSION}" == "" ]
then
	PYTHON_LIB_VERSION="Python_2.6"
fi
if [ "${SWIG_COMPILER_VERSION}" == "" ]
then
	SWIG_COMPILER_VERSION="Swig_1.3"
fi

print "PYTHON_LIB_VERSION="$PYTHON_LIB_VERSION
print "SWIG_COMPILER_VERSION="$SWIG_COMPILER_VERSION

export LIB_LIMA=`/ccc/products/nec/bin/gscc/gscc_getpath.py --component=LimaBindings --target_dir=binding --version=$VERSION_LIMA $VARIANT_LIMA-$SWIG_COMPILER_VERSION-$PYTHON_LIB_VERSION`

print "LIB_LIMA="$LIB_LIMA
print "LIB_MAGIX3D="$LIB_MAGIX3D

# recherche de l'executable python adaptée à la version actuelle
if [ "${PYTHON_LIB_VERSION}" == "Python_2.7" ]
then
	PYTHON_EXE="/ccc/products/opendist/bin/python2.7"
else
   print "Cette version de python n'est pas supportée par le lanceur.ksh"
fi

if [ "$4" == "" ]
then
	print "=============================================="
	print "Il faut mettre un fichier python en parametre"
	print "  soit en ligne gscc_test.py -atoto.py"
	print "  soit sous eclipse dans le champ Arg"
	print "=============================================="
	exit 1
fi		

echo "cd TestsPython; "$PYTHON_EXE $4
cd TestsPython; $PYTHON_EXE $4
