cmake_minimum_required(VERSION 3.8)
project(KIT_ProjectExII_CPU_Simulator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c
        cpuboard.c
        cpuboard.h)

set(OP_SOURCE_FILES
        Operation/ADD.c Operation/ADD.h Operation/ADC.c Operation/ADC.h Operation/LD.c Operation/LD.h Operation/ST.c Operation/ST.h Operation/SUB.c Operation/SUB.h Operation/SBC.c Operation/SBC.h Operation/CMP.c Operation/CMP.h Operation/AND.c Operation/AND.h Operation/OR.c Operation/OR.h Operation/EOR.c Operation/EOR.h Operation/OUT.c Operation/OUT.h Operation/IN.c Operation/IN.h Operation/RCF.c Operation/RCF.h Operation/SCF.c Operation/SCF.h Operation/BBC.c Operation/BBC.h Operation/JAL.c Operation/JAL.h Operation/JR.c Operation/JR.h Operation/SSM.c Operation/SSM.h Operation/RSM.c Operation/RSM.h)

add_executable(KIT_ProjectExII_CPU_Simulator ${SOURCE_FILES} ${OP_SOURCE_FILES})
target_link_libraries(KIT_ProjectExII_CPU_Simulator)