//
// Created by Junpei Kishi on 2018/05/25.
//

#include "JR.h"

/**
* @brief Operation JR
*
* JR Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_jr(Cpub *cpub){
    cpub->pc = cpub->acc;
    return RUN_STEP;
}
