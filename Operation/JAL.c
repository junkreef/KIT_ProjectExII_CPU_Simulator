//
// Created by Junpei Kishi on 2018/05/25.
//

#include "JAL.h"

/**
* @brief Operation JAL
*
* JAL Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_jal(Cpub *cpub){
    cpub->acc = cpub->pc++ + 2;

    cpub->pc = GET_CURRENT_PC;
    return RUN_STEP;
}
