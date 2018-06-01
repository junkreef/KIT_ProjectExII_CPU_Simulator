//
// Created by Junpei Kishi on 2018/05/25.
//

#include "IN.h"

int op_in(Cpub *cpub){
    cpub->acc = cpub->ibuf->buf;
    cpub->pc++;
    return RUN_STEP;
}