from distutils.core import setup, Extension
import os, subprocess, numpy
from tools import make_exceptions, make_attributes

include_dirs = []

include_dirs.append(numpy.get_include())
include_dirs.append(os.path.join('.','starlink','include'))
include_dirs.append(os.path.join('.','ast'))

#  Create the support files needed for the build. These find the AST
#  source code using the environment variable AST_SOURCE, so set AST_SOURCE
#  to point to the AST source code directory distributed with PyAST.
os.environ[ "AST_SOURCE" ] = os.path.join( os.getcwd(), 'ast' )
make_exceptions.make_exceptions( os.path.join('starlink','ast') )
make_attributes.make_attributes( os.path.join('starlink','ast') )

#  Configure the AST source code.
subprocess.call( os.path.join('.','configure'), cwd='ast' )

#  List the C source files needed to build the AST library locally.
ast_c = ( 'axis.c', 'box.c', 'channel.c', 'circle.c', 'cmpframe.c',
          'cmpmap.c', 'cmpregion.c', 'dsbspecframe.c', 'dssmap.c',
	  'ellipse.c', 'error.c', 'fitschan.c', 'fluxframe.c', 'frame.c',
	  'frameset.c', 'globals.c', 'grf3d.c', 'grf_2.0.c', 'grf_3.2.c',
	  'grf_5.6.c', 'grismmap.c', 'interval.c', 'keymap.c',
	  'levmar.c', 'loader.c', 'lutmap.c', 'mapping.c', 'mathmap.c',
	  'matrixmap.c', 'memory.c', 'normmap.c', 'nullregion.c',
	  'object.c', 'pal.c', 'pcdmap.c', 'permmap.c', 'plot.c',
	  'pointlist.c', 'pointset.c', 'polygon.c', 'polymap.c',
	  'prism.c', 'proj.c', 'ratemap.c', 'region.c', 'shiftmap.c',
	  'skyaxis.c', 'skyframe.c', 'slamap.c', 'specfluxframe.c',
	  'specframe.c', 'specmap.c', 'sphmap.c', 'stcschan.c',
	  'timeframe.c', 'timemap.c', 'tpn.c', 'tranmap.c', 'unit.c',
	  'unitmap.c', 'wcsmap.c', 'wcstrig.c', 'winmap.c', 'xml.c',
	  'xmlchan.c', 'zoommap.c')

#  Initialise the list of sources files needed to build the starlink.Ast
#  module.
sources = [os.path.join('starlink', 'ast', 'Ast.c')]

#  Append all the .c and .h files needed to build the AST library locally.
for cfile in ast_c:
   sources.append( os.path.join( 'ast', cfile ) )

#  Create the description of the starlink.Ast module.
Ast = Extension('starlink.Ast',
                include_dirs  = include_dirs,
                sources       = sources )

setup (name = 'starlink-ast',
       version = '1.0',
       description = 'This is the starlink AST package',
       url = 'http://http://starlink.jach.hawaii.edu/starlink/Ast',
       author = 'David Berry',
       author_email = 'd.berry@jach.hawaii.edu',
       packages =['starlink'],
       package_data = { 'starlink': [os.path.join('include','star','pyast.h')] },
       ext_modules=[Ast],
       py_modules=['starlink.Grf','starlink.Atl'])
