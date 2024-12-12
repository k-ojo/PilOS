//elf type
#define EI_MAG0 0 // File identification
#define EI_MAG1 1 // File identification
#define EI_MAG2 2 // File identification
#define EI_MAG3 3 // File identification
#define EI_CLASS 4 // File class
#define EI_DATA 5 // Data encoding
#define EI_VERSION 6 // File version
#define EI_PAD 7 // Start of padding bytes
#define EI_NIDENT 16 // Size of e_ident[]

//Type of files
#define EI_NIDENT  16
#define ET_NONE     0
#define ET_REL      1
#define ET_EXEC     2
#define ET_DYN      3
#define ET_CORE     4
#define ET_LOPROC   0xff00
#define ET_HIPROC   0xffff   //ET stands for executable type

// Type of machine
#define ET_NONE         0 //No machine
#define EM_M32          1 //AT&T WE 32100
#define EM_SPARC        2 // SPARC
#define EM_386          3 //Intel Architecture
#define EM_68K          4 //Motorola 68000
#define EM_88K          5 //Motorola 88000
#define EM_860          7 //Intel 80860
#define EM_MIPS         8 //MIPS RS3000 Big-Endian
#define EM_MIPS_RS4_BE 10 //MIPS RS4000 Big-Endian

//e_version 
#define EV_NONE 0 Invalid versionn
#define EV_CURRENT 1 Current version

typedef unsigned int Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int Elf32_Off;
typedef unsigned int Elf32_Sword;
typedef unsigned int Elf32_Word;


/**
 * Elf32_Ehdr- the ELF header struct
 * @e_ident: identify file as an elf file
 * @e_type: This member identifies the object file type.
 * @e_machine:
 * @e_version:
 * @e_entry:
 * @e_phoff:
 * @e_shoff:
 * @e_flags:
 * @e_ehsize:
 * @e_phentsize:
 * @e_phnum:
 * @e_shentsize:
 * @e_shnum:
 * @e_shstrndx:
 */
typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
}Elf32_Ehdr;

/**
 * Elf32_Shdr: 
 */
typedef struct {
    Elf32_Word sh_name;
    Elf32_Word sh_type;
    Elf32_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off sh_offset;
    Elf32_Word sh_size;
    Elf32_Word sh_link;
    Elf32_Word sh_info;
    Elf32_Word sh_addralign;
    Elf32_Word sh_entsize;
} Elf32_Shdr;
