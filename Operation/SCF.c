//
// Created by Junpei Kishi on 2018/05/25.
//

#include "SCF.h"

/**
* @brief Operation SCF
*
* SCF Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_scf(Cpub *cpub){
    cpub->cf = 0;
    cpub->pc++;
    return RUN_STEP;
}
