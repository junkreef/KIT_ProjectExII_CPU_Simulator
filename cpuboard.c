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
    if(is_NOP(cpub->pc)){

    }else if(is_HLT(cpub->pc)){

    }else if(is_HLT(cpub->pc)) {

    }else if(is_OUT(cpub->pc)){

    }else if(is_IN(cpub->pc)){

    }else if(is_RCF(cpub->pc)){

    }else if(is_SCF(cpub->pc)){

    }else if(is_LD(cpub->pc)){

    }else if(is_ST(cpub->pc)){

    }else if(is_ADD(cpub->pc)){

    }else if(is_ADC(cpub->pc)){

    }else if(is_SUB(cpub->pc)){

    }else if(is_SBC(cpub->pc)){

    }else if(is_CMP(cpub->pc)){

    }else if(is_AND(cpub->pc)){

    }else if(is_OR(cpub->pc)){

    }else if(is_EOR(cpub->pc)){

    }else if(is_SSM(cpub->pc)){

    }else if(is_RSM(cpub->pc)){

    }else if(is_BBC(cpub->pc)){

    }else if(is_JAL(cpub->pc)){

    }else if(is_JR(cpub->pc)){

    }


	return RUN_HALT;
}


