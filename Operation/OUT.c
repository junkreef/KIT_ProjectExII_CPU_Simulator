//
// Created by Junpei Kishi on 2018/05/25.
//

#include "OUT.h"

int op_out(Cpub *cpub){
    cpub->obuf.buf = cpub->acc;
    cpub->pc++;
    return RUN_STEP;
}