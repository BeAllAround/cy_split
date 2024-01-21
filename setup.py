from distutils.core import setup
from distutils.core import Extension

from Cython.Distutils import build_ext

from Cython.Build import cythonize


setup(
        ext_modules=[
            Extension('_splits',
                sources=['_splits.pyx'],
                extra_compile_args=["-O3"],
            )
        ],
        cmdclass = { 'build_ext': build_ext }
) 
