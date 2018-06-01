/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.h
 *	Descrioption:	resource definition of the educational computer board
 */

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
#define	MEMORY_SIZE	256*2
#define	IMEMORY_SIZE	256

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
#define	RUN_HALT	0
#define	RUN_STEP	1
int	step(Cpub *);


/*=============================================================================
 *   Operation defines
 *===========================================================================*/
#define is_NOP(OP)      ((OP&0xf8) == 0x00)
#define is_HLT(OP)      ((OP&0xfc) == 0x0c)

#define is_OUT(OP)      ((OP&0xf8) == 0x10)
#define is_IN(OP)       ((OP&0xf8) == 0x18)

#define is_RCF(OP)      ((OP&0xf8) == 0x20)
#define is_SCF(OP)      ((OP&0xf8) == 0x28)

#define is_LD(OP)       ((OP&0xf0) == 0x60)
#define is_ST(OP)       ((OP&0xf0) == 0x70)

#define is_ADD(OP)      ((OP&0xf0) == 0xb0)
#define is_ADC(OP)      ((OP&0xf0) == 0x90)
#define is_SUB(OP)      ((OP&0xf0) == 0xa0)
#define is_SBC(OP)      ((OP&0xf0) == 0x80)
#define is_CMP(OP)      ((OP&0xf0) == 0xf0)
#define is_AND(OP)      ((OP&0xf0) == 0xe0)
#define is_OR(OP)       ((OP&0xf0) == 0xd0)
#define is_EOR(OP)      ((OP&0xf0) == 0xc0)

#define is_SSM(OP)      ((OP&0xf4) == 0x40)
#define is_RSM(OP)      ((OP&0xf4) == 0x44)

#define is_BBC(OP)      ((OP&0xf0) == 0x30)
#define is_JAL(OP)      ((OP&0xff) == 0x0a)
#define is_JR(OP)       ((OP&0xff) == 0x0b)

#define mask_A(OP)   (OP&0x08)
#define mask_B(OP)   (OP&0x07)
#define mask_SM(OP)  (OP&0x03)
#define mask_BC(OP)  (OP&0x0f)

#define GET_CURRENT_PC (cpub->mem[cpub->pc])

Uword *extract_A(Cpub *cpub);
Uword *extract_B(Cpub *cpub);

Uword alu(Uword *A, Uword *B, uint8_t CF);

#endif //KIT_PROJECTEXII_CPU_SIMULATOR_CPU_H