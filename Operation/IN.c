//
// Created by Junpei Kishi on 2018/05/25.
//

#include "IN.h"

/**
* @brief Operation IN
*
* IN Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_in(Cpub *cpub){
    cpub->acc = cpub->ibuf->buf;
    cpub->pc++;
    return RUN_STEP;
}
