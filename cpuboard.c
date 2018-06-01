/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.c
 *	Descrioption:	simulation(emulation) of an instruction
 */

#include <stdio.h>
#include	"cpuboard.h"


/*=============================================================================
 *   Simulation of a Single Instruction
 *===========================================================================*/
int
step(Cpub *cpub)
{
    Uword op = GET_CURRENT_PC;
    printf("PC=0x%02x Execute: ", cpub->pc);
    if(is_NOP(op)){

    }else if(is_HLT(op)){

    }else if(is_HLT(op)) {

    }else if(is_OUT(op)){

    }else if(is_IN(op)){

    }else if(is_RCF(op)){

    }else if(is_SCF(op)){

    }else if(is_LD(op)){

    }else if(is_ST(op)){

    }else if(is_ADD(op)){

    }else if(is_ADC(op)){

    }else if(is_SUB(op)){

    }else if(is_SBC(op)){

    }else if(is_CMP(op)){

    }else if(is_AND(op)){

    }else if(is_OR(op)){

    }else if(is_EOR(op)){

    }else if(is_SSM(op)){

    }else if(is_RSM(op)){

    }else if(is_BBC(op)){

    }else if(is_JAL(op)){

    }else if(is_JR(op)){

    }

    fflush(stdout);


	return RUN_HALT;
}

Uword *extract_A(Cpub *cpub){

    if(mask_A(GET_CURRENT_PC)) {
        return  &(cpub->ix);
    } else {
        return  &(cpub->acc);
    }
}

Uword *extract_B(Cpub *cpub){
    Uword B = mask_B(GET_CURRENT_PC);

    switch(B){
        case 0b000:
            return &(cpub->acc);

        case 0b001:
            return &(cpub->ix);

        case 0b010:
        case 0b011:
            cpub->pc++;
            return &(GET_CURRENT_PC);

        case 0b100:
            cpub->pc++;
            return &(cpub->mem[0x000 + GET_CURRENT_PC]);

        case 0b101:
            cpub->pc++;
            return &(cpub->mem[0x100 + GET_CURRENT_PC]);

        case 0b110:
            cpub->pc++;
            return &(cpub->mem[0x000 + GET_CURRENT_PC + cpub->ix]);

        case 0b111:
            cpub->pc++;
            return &(cpub->mem[0x100 + GET_CURRENT_PC + cpub->ix]);

        default:
            break;
    }
    return 0;
}

Uword alu(Uword *A, Uword *B, uint8_t CF){
    unsigned char time, vf = 0, result = 0, ret = 0;

    for(time = 0; time < 8; time++){
        switch(((*A >> time) & 1) + ((*B >> time) & 1) + vf + CF){
            case 0:
                vf = 0;
                break;
            case 1:
                vf = 0;
                result += 1 << time;
                break;
            case 2:
                vf = 1;
                break;
            case 3:
                result += 1 << time;
                vf = 1;
                break;
            default:
                break;
        }
        CF = 0;
        // Set VF if carried 1 from 6bit to 7bit
        if(time == 6 && vf == 1){
            ret |= 0x04;
        }
    }
    // Set VF if carried 1 from 7bit to (8)bit
    if(vf == 1){
        ret |= 0x08;
    }

    // Set NF if 7bit is 1
    if(result & 0x80){
        ret |= 0x02;
    }

    // Set ZF if result = 0
    if(result == 0){
        ret |= 0x01;
    }

    *A = result;
    return ret;
}