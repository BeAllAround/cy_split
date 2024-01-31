from setuptools import setup, find_packages
from distutils.core import Extension

from Cython.Distutils import build_ext

from Cython.Build import cythonize

with open('README.md') as f:
    README = f.read()

with open('LICENSE') as f:
    LICENSE = f.read()

if __name__ == '__main__':
    setup(
        install_requires=[ 'cython' ],
        name="cy_split",
        version="0.0.1",
        description="Efficient split for Python",
        long_description=README,
        author='Aleksandar Milenkovic',
        author_email='milenkovicaleksandar470@gmail.com',
        license=LICENSE,
        packages=find_packages(exclude=('tests')),
        ext_modules=[
            Extension('cy',
                sources=['./src/cy.pyx'],
                extra_compile_args=["-O3"],
            )
        ],
        cmdclass={'build_ext':build_ext}
    ) 
