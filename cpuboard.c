/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.c
 *	Descrioption:	simulation(emulation) of an instruction
 */

#include	"cpuboard.h"


/*=============================================================================
 *   Simulation of a Single Instruction
 *===========================================================================*/
int
step(Cpub *cpub)
{
    Uword op = GET_CURRENT_PC;
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


	return RUN_HALT;
}


