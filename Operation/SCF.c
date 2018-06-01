//
// Created by Junpei Kishi on 2018/05/25.
//

#include "SCF.h"

int op_scf(Cpub *cpub){
    cpub->cf = 0;
    cpub->pc++;
    return RUN_STEP;
}