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
        Comandos/Comando.cpp
        Comandos/Comando.h
        Comandos/CmdAvanca.cpp
        Comandos/CmdAvanca.h
        Comandos/CmdFim.cpp
        Comandos/CmdFim.h
        Comandos/CmdMove.cpp
        Comandos/CmdMove.h
        Jogo.cpp
        Jogo.h
        Comandos/CmdJardim.cpp
        Comandos/CmdJardim.h
        Comandos/CmdEntra.cpp
        Comandos/CmdEntra.h
        Comandos/CmdSai.cpp
        Comandos/CmdSai.h
        Comandos/CmdLFerr.cpp
        Comandos/CmdLFerr.h
        Comandos/CmdLarga.cpp
        Comandos/CmdLarga.h
        Comandos/CmdPega.cpp
        Comandos/CmdPega.h
        Comandos/CmdCompra.cpp
        Comandos/CmdCompra.h
        Comandos/CmdPlanta.cpp
        Comandos/CmdPlanta.h
        Comandos/CmdLPlanta.cpp
        Comandos/CmdLPlanta.h
        Comandos/CmdLPlantas.cpp
        Comandos/CmdLPlantas.h
        Comandos/CmdLSolo.cpp
        Comandos/CmdLSolo.h
        Comandos/CmdLArea.cpp
        Comandos/CmdLArea.h
        Comandos/CmdColhe.cpp
        Comandos/CmdColhe.h
        Comandos/CmdExecuta.cpp
        Comandos/CmdExecuta.h
        Comandos/CmdApaga.cpp
        Comandos/CmdApaga.h
        Comandos/CmdRecupera.cpp
        Comandos/CmdRecupera.h
        Comandos/CmdGrava.cpp
        Comandos/CmdGrava.h
)


target_include_directories(trabalho PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Interface
        ${CMAKE_SOURCE_DIR}/Comandos
        ${CMAKE_SOURCE_DIR}/models
)
