//
// Created by Junpei Kishi on 2018/05/25.
//

#include "JR.h"

int op_jr(Cpub *cpub){
    cpub->pc = cpub->acc;
    return RUN_STEP;
}