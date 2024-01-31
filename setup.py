from distutils.core import setup
from setuptools import find_packages
from distutils.core import Extension

from Cython.Distutils import build_ext

from Cython.Build import cythonize

with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
        name="cy_split",
        version="0.0.1",
        description="Efficient split for Python",
        long_description=readme,
        author='Aleksandar Milenkovic',
        author_email='milenkovicaleksandar470@gmail.com',
        license=license,
        packages=find_packages(exclude=('tests')),
        ext_modules=[
            Extension('cy',
                sources=['./src/cy.pyx'],
                extra_compile_args=["-O3"],
            )
        ],
        cmdclass = { 'build_ext': build_ext }
) 
