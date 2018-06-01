//
// Created by Junpei Kishi on 2018/05/25.
//

#include "JAL.h"

int op_jal(Cpub *cpub){
    cpub->acc = cpub->pc++ + 2;

    cpub->pc = GET_CURRENT_PC;
    return RUN_STEP;
}