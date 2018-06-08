/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.h
 *	Descrioption:	resource definition of the educational computer board
 */

//******** Includes ********//
#include "Operation/LD.h"
#include "Operation/ST.h"
#include "Operation/OUT.h"
#include "Operation/IN.h"
#include "Operation/RCF.h"
#include "Operation/SCF.h"
#include "Operation/ADD.h"
#include "Operation/ADC.h"
#include "Operation/SUB.h"
#include "Operation/SBC.h"
#include "Operation/CMP.h"
#include "Operation/AND.h"
#include "Operation/OR.h"
#include "Operation/EOR.h"
#include "Operation/SSM.h"
#include "Operation/RSM.h"
#include "Operation/BBC.h"
#include "Operation/JAL.h"
#include "Operation/JR.h"

#include <stdint.h>

#ifndef KIT_PROJECTEXII_CPU_SIMULATOR_CPU_H
#define KIT_PROJECTEXII_CPU_SIMULATOR_CPU_H


/*=============================================================================
 *   Architectural Data Types
 *===========================================================================*/
typedef int8_t	Sword;
typedef uint8_t	Uword;
typedef uint16_t	Addr;
typedef uint8_t	Bit;


/*=============================================================================
 *   CPU Board Resources
 *===========================================================================*/
#define	MEMORY_SIZE	256*2 /**< @def Define memory size (TEXT+DATA) */
#define	IMEMORY_SIZE	256 /**< @def Define memory size of TEXT block */

typedef struct iobuf {
	Bit	flag;
	Uword	buf;
} IOBuf;

typedef struct cpuboard {
	Uword	pc;
	Uword	acc;
	Uword	ix;
	Bit	cf, vf, nf, zf;
	IOBuf	*ibuf;
	IOBuf	obuf;
	/*
	 *   [ add here the other CPU resources if necessary ]
	 */
	Uword	mem[MEMORY_SIZE];	/* 0XX:Program, 1XX:Data */
} Cpub;


/*=============================================================================
 *   Top Function of an Instruction Simulation
 *===========================================================================*/
#define	RUN_HALT	0 /**< @def for step() return, cpu is halted */
#define	RUN_STEP	1 /**< @def for step() return, cpu is not halted */
int	step(Cpub *);


/*=============================================================================
 *   Operation defines
 *===========================================================================*/
#define is_NOP(OP)      ((OP&0xf8) == 0x00) /**< @def Distinguish OP is NOP or not */
#define is_HLT(OP)      ((OP&0xfc) == 0x0c) /**< @def Distinguish OP is HLT or not */

#define is_OUT(OP)      ((OP&0xf8) == 0x10) /**< @def Distinguish OP is OUT or not */
#define is_IN(OP)       ((OP&0xf8) == 0x18) /**< @def Distinguish OP is IN or not */

#define is_RCF(OP)      ((OP&0xf8) == 0x20) /**< @def Distinguish OP is RCF or not */
#define is_SCF(OP)      ((OP&0xf8) == 0x28) /**< @def Distinguish OP is SCF or not */

#define is_LD(OP)       ((OP&0xf0) == 0x60) /**< @def Distinguish OP is LD or not */
#define is_ST(OP)       ((OP&0xf0) == 0x70) /**< @def Distinguish OP is ST or not */

#define is_ADD(OP)      ((OP&0xf0) == 0xb0) /**< @def Distinguish OP is ADD or not */
#define is_ADC(OP)      ((OP&0xf0) == 0x90) /**< @def Distinguish OP is ADC or not */
#define is_SUB(OP)      ((OP&0xf0) == 0xa0) /**< @def Distinguish OP is SUB or not */
#define is_SBC(OP)      ((OP&0xf0) == 0x80) /**< @def Distinguish OP is SBC or not */
#define is_CMP(OP)      ((OP&0xf0) == 0xf0) /**< @def Distinguish OP is CMP or not */
#define is_AND(OP)      ((OP&0xf0) == 0xe0) /**< @def Distinguish OP is AND or not */
#define is_OR(OP)       ((OP&0xf0) == 0xd0) /**< @def Distinguish OP is OR or not */
#define is_EOR(OP)      ((OP&0xf0) == 0xc0) /**< @def Distinguish OP is EOR or not */

#define is_SSM(OP)      ((OP&0xf4) == 0x40) /**< @def Distinguish OP is SSM or not */
#define is_RSM(OP)      ((OP&0xf4) == 0x44) /**< @def Distinguish OP is RSM or not */

#define is_BBC(OP)      ((OP&0xf0) == 0x30) /**< @def Distinguish OP is BBC or not */
#define is_JAL(OP)      ((OP&0xff) == 0x0a) /**< @def Distinguish OP is JAL or not */
#define is_JR(OP)       ((OP&0xff) == 0x0b) /**< @def Distinguish OP is JR or not */

#define mask_A(OP)   (OP&0x08) /**< @def Mask OP with A section */
#define mask_B(OP)   (OP&0x07) /**< @def Mask OP with B section */
#define mask_SM(OP)  (OP&0x03) /**< @def Mask OP with SM section */
#define mask_BC(OP)  (OP&0x0f) /**< @def Mask OP with BC section */

#define GET_CURRENT_PC (cpub->mem[cpub->pc]) /**< @def Get data on memory which is pointed by PC */

Uword *extract_A(Cpub *cpub);
Uword *extract_B(Cpub *cpub);

Uword alu(Uword *A, Uword *B, uint8_t CF);

#endif //KIT_PROJECTEXII_CPU_SIMULATOR_CPU_H
