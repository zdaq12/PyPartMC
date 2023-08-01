![logo](https://raw.githubusercontent.com/wiki/open-atmos/PyPartMC/logo.svg)

# PyPartMC

PyPartMC is a Python interface to [PartMC](https://lagrange.mechse.illinois.edu/partmc/), 
  a particle-resolved Monte-Carlo code for atmospheric aerosol simulation.
PyPartMC is implemented in C++ and it also constitutes a C++ API to the PartMC Fortran internals.
The Python API can facilitate using PartMC from other environments - see, e.g., Julia example below.

[![US Funding](https://img.shields.io/static/v1?label=US%20DOE%20Funding%20by&color=267c32&message=ASR&logoWidth=25&logo=image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAB4AAAAQCAMAAAA25D/gAAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAASFBMVEVOTXyyIjRDQnNZWINZWITtzdFUU4BVVIFVVYHWiZM9PG/KZnNXVoJaWYT67/FKSXhgX4hgX4lcW4VbWoX03uHQeIN2VXj///9pZChlAAAAAWJLR0QXC9aYjwAAAAd0SU1FB+EICRMGJV+KCCQAAABdSURBVBjThdBJDoAgEETRkkkZBBX0/kd11QTTpH1/STqpAAwWBkobSlkGbt0o5xmEfqxDZJB2Q6XMoBwnVSbTylWp0hi42rmbwTOYPDfR5Kc+07IIUQQvghX9THsBHcES8/SiF0kAAAAldEVYdGRhdGU6Y3JlYXRlADIwMTctMDgtMDlUMTk6MDY6MzcrMDA6MDCX1tBgAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDE3LTA4LTA5VDE5OjA2OjM3KzAwOjAw5oto3AAAAABJRU5ErkJggg==)](https://asr.science.energy.gov/)
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![Copyright](https://img.shields.io/static/v1?label=Copyright&color=249fe2&message=UIUC&)](https://atmos.illinois.edu/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/open-atmos/PyPartMC/graphs/commit-activity)
[![Github Actions Build Status](https://github.com/open-atmos/PyPartMC/workflows/tests/badge.svg?branch=main)](https://github.com/open-atmos/PyPartMC/actions)
[![API docs](https://img.shields.io/badge/API_docs-pdoc3-blue.svg)](https://open-atmos.github.io/PyPartMC/)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.7662635.svg)](https://doi.org/10.5281/zenodo.7662635)


## TL;DR (try in a Jupyter notebook)

[![Python 3](https://img.shields.io/static/v1?label=Python&logo=Python&color=3776AB&message=3)](https://www.python.org/)
[![Linux OK](https://img.shields.io/static/v1?label=Linux&logo=Linux&color=yellow&message=%E2%9C%93)](https://en.wikipedia.org/wiki/Linux)
[![macOS OK](https://img.shields.io/static/v1?label=macOS&logo=Apple&color=silver&message=%E2%9C%93)](https://en.wikipedia.org/wiki/macOS)
[![Windows OK](https://img.shields.io/static/v1?label=Windows&logo=Windows&color=white&message=%E2%9C%93)](https://en.wikipedia.org/wiki/Windows)
[![Jupyter](https://img.shields.io/static/v1?label=Jupyter&logo=Jupyter&color=f37626&message=%E2%9C%93)](https://jupyter.org/)

```python
! pip install PyPartMC
import PyPartMC
```

#### Jupyter notebooks with examples 

- Urban plum scenario demo (as in [PartMC](https://github.com/compdyn/partmc/tree/master/scenarios/1_urban_plume)):    
[![nbviewer](https://raw.githubusercontent.com/jupyter/design/master/logos/Badges/nbviewer_badge.svg)](https://nbviewer.jupyter.org/github/open-atmos/PyPartMC/blob/main/examples/particle_simulation.ipynb)
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/open-atmos/PyPartMC/blob/main/examples/particle_simulation.ipynb)
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/open-atmos/PyPartMC.git/main?urlpath=lab/tree/examples/particle_simulation.ipynb)
- Dry-Wet Particle Size Equilibration with PartMC and PySDM:   
[![nbviewer](https://raw.githubusercontent.com/jupyter/design/master/logos/Badges/nbviewer_badge.svg)](https://nbviewer.jupyter.org/github/open-atmos/PyPartMC/blob/main/examples/lognorm_ex.ipynb)
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/open-atmos/PyPartMC/blob/main/examples/lognorm_ex.ipynb)
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/open-atmos/PyPartMC.git/main?urlpath=lab/tree/examples/lognorm_ex.ipynb)
[![Voila](https://img.shields.io/static/v1?label=Voil%C3%A0&logo=jupyter&color=teal&message=web+app)](https://mybinder.org/v2/gh/open-atmos/PyPartMC/main?urlpath=voila%2Frender%2Fexamples%2Flognorm_ex.ipynb)

## Features

- works on Linux, macOS and Windows (compatibility assured with [CI builds](https://github.com/open-atmos/PyPartMC/blob/main/.github/workflows/tests.yml))
- hassle-free installation using `pip` (prior PartMC installation **not needed**)
- works out of the box on [mybinder.org](https://mybinder.org/), [Google Colab](colab.research.google.com/) and alike
- ships with [a set of examples](https://github.com/open-atmos/PyPartMC/tree/main/examples) maintained in a form of Jupyter notebooks
- Pythonic API (but retaining PartMC jargon) incl. Python GC deallocation of Fortran objects
- specification of parameters using native Python datatypes (lists, dicts) in place of PartMC spec files
- code snippets in README depicting how to use PyPartMC from Julia (also executed on CI)
- auto-generated [API docs on the web](https://open-atmos.github.io/PyPartMC/)
- support for [de]serialization of selected wrapped structures using JSON 
- based on [unmodified PartMC code](https://github.com/open-atmos/PyPartMC/tree/main/gitmodules)
- does not use or require shell or any pre-installed libraries
- aiming at 100% [unit test coverage](https://github.com/open-atmos/PyPartMC/tree/main/tests)

## Usage examples

#### example object instantiation in Python

```python
import PyPartMC as ppmc
print(ppmc.__version__)
gas_data = ppmc.GasData(("H2SO4", "HNO3", "HCl", "NH3", "NO", "NO2"))
```

#### example object instantiation in Julia
```Julia
using Pkg
Pkg.add("PyCall")

using PyCall
ppmc = pyimport("PyPartMC")
print(ppmc.__version__)
gas_data = ppmc.GasData(("H2SO4", "HNO3", "HCl", "NH3", "NO", "NO2"))
```

#### usage in other projects

PyPartMC is used within the [test workflow of the PySDM project](https://github.com/atmos-cloud-sim-uj/PySDM/tree/main/tests/smoke_tests/partmc).

## Implementation outline

- PyPartMC is written in C++, Fortran and uses [pybind11](https://pybind11.readthedocs.io/en/stable/) and [CMake](https://cmake.org/).
- JSON support is handled with [nlohmann::json](https://github.com/nlohmann/json) and [pybind11_json](https://github.com/pybind/pybind11_json)
- PartMC and selected parts of SUNDIALS are statically linked (and compiled in during `pip install` or `python -m build`) 
- C (SUNDIALS, netCDF), C++ (pybind11, ...) and Fortran (PartMC, CAMP, netCDF-fortran) dependencies are linked through [git submodules](https://github.com/open-atmos/PyPartMC/blob/main/.gitmodules)
- MOSAIC dependency is optionally linked through setting the environmental variable `MOSAIC_HOME`
- a [drop-in replacement of the PartMC spec file routines](https://github.com/open-atmos/PyPartMC/blob/main/src/fake_spec_file.F90) is used for i/o from/to JSON 

## Implementation architecture

```mermaid
flowchart TD
    subgraph J ["Julia"]
        julia_user_code["Julia user code"] --> PyCall.jl
    end
    subgraph P ["Python"]
        PyCall.jl --> PyPartMC
        python_user_code -.-> NumPy
        python_user_code["Python user code"] ---> PyPartMC["pubind11-generated PyPartMC module"]
    end
    subgraph Cpp ["C++"]
        cpp_user_code["C++ user code"] ----> ppmc_cpp
        PyPartMC --> ppmc_cpp["PyPartMC-C++"]
        ppmc_cpp --> pybind11_json
        pybind11_json ---> nlohmann::JSON
        fake_spec_file_cpp --> nlohmann::JSON
    end
    subgraph C ["C"]
        fake_spec_file_c --> fake_spec_file_cpp["SpecFile-C++"]
        ppmc_cpp --> ppmc_c["PyPartMC-C"]
        netCDF-C
        SUNDIALS
        camp_c["CAMP C code"]
    end
    subgraph Fortran ["Fortran"]
        PartMC -....-> MOSAIC
        ppmc_c --> ppmc_f["PyPartMC-F"]
        ppmc_f ---> PartMC
        PartMC --> netCDF-F
        netCDF-F --> netCDF-C
        PartMC --> SUNDIALS
        PartMC ---> camp_f
        camp_f["CAMP"] --> camp_c
        PartMC ----> fake_spec_file_f[SpecFile-F]
        fake_spec_file_f --> fake_spec_file_c["SpecFile-C"]
    end

    style PartMC fill:#7ae7ff,stroke-width:2px,color:#2B2B2B
```

## Troubleshooting 

#### Common installation issues 
```
error: [Errno 2] No such file or directory: 'cmake'
```
Try rerunning after installing CMake, e.g., using `apt-get install cmake` (Ubuntu/Debian), `brew install cmake` (homebrew on macOS) or using [MSYS2](https://www.msys2.org/docs/cmake/) on Windows.

```
No CMAKE_Fortran_COMPILER could be found.
```
Try installing a Fortran compiler (e.g., `brew reinstall gcc` with Homebrew on macOS or using [MSYS2](https://packages.msys2.org/package/mingw-w64-x86_64-gcc-fortran?repo=mingw64) on Windows).

```
Could not find NC_M4 using the following names: m4, m4.exe
```
Try installing `m4` (e.g., using [MSYS2](https://packages.msys2.org/package/m4?repo=msys&variant=x86_64) on Windows).

## Notes for developers
#### How to debug
```sh
git clone --recursive git+https://github.com/open-atmos/PyPartMC.git
cd PyPartMC
DEBUG=1 VERBOSE=1 pip --verbose install -e .
gdb python 
(gdb) run -m pytest -s -vv -We -p no:unraisableexception tests
```
#### Pre-commit hooks
PyPartMC codebase benefits from Pylint, Black and isort code analysis (which are all part of the CI workflows where we also use pre-commit hooks. The pre-commit hooks can be run locally, and then the resultant changes need to be staged before committing. To set up the hooks locally, install pre-commit via `pip install pre-commit` and set up the git hooks via `pre-commit install` (this needs to be done every time you clone the project). To run all pre-commit hooks, run `pre-commit run --all-files`. The `.pre-commit-config.yaml` file can be modified in case new hooks are to be added or existing ones need to be altered.

## Credits

#### PyPartMC:

authors: [PyPartMC developers](https://github.com/open-atmos/PyPartMC/graphs/contributors)   
funding: [US Department of Energy Atmospheric System Research programme](https://asr.science.energy.gov/)   
copyright: [University of Illinois at Urbana-Champaign](https://atmos.illinois.edu/)   
licence: [GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)

#### PartMC:
authors: [Nicole Riemer](https://www.atmos.uiuc.edu/~nriemer/), [Matthew West](https://lagrange.mechse.illinois.edu/mwest/), [Jeff Curtis](https://publish.illinois.edu/jcurtis2/) et al.   
licence: [GPL v2](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html) or later

