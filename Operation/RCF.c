//
// Created by Junpei Kishi on 2018/05/25.
//

#include "RCF.h"

int op_rcf(Cpub *cpub){
    cpub->cf = 0;
    cpub->pc++;
    return RUN_STEP;
}