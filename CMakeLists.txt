cmake_minimum_required(VERSION 4.0)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_executable(trabalho main.cpp
        models/solo/solo.h
        models/solo/solo.cpp
        models/jardim/jardim.h
        models/jardim/jardim.cpp
        models/planta/planta.h
        models/jardineiro/jardineiro.h
        Interface/Interface.cpp
        Interface/Interface.h
        Comandos/Comandos.cpp
        Comandos/Comandos.h
        models/ferramenta/ferramenta.h
        models/ferramenta/ferramenta.cpp
        models/planta/planta.cpp
        models/jardineiro/jardineiro.cpp
        models/planta/cacto.cpp
        models/planta/cacto.h
        Settings.cpp
        models/planta/roseira.cpp
        models/planta/roseira.h
        models/planta/ervaDaninha.cpp
        models/planta/ervaDaninha.h
        models/planta/plantaExotica.cpp
        models/planta/plantaExotica.h
        models/ferramenta/regador.cpp
        models/ferramenta/regador.h
        models/ferramenta/adubo.cpp
        models/ferramenta/adubo.h
        models/ferramenta/tesoura.cpp
        models/ferramenta/tesoura.h
        models/ferramenta/carroDeMao.cpp
        models/ferramenta/carroDeMao.h
)
