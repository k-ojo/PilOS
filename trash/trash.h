//elf type
#define EI_MAG0     0 // File identification
#define EI_MAG1     1 // File identification
#define EI_MAG2     2 // File identification
#define EI_MAG3     3 // File identification
#define EI_CLASS    4 // File class
#define EI_DATA     5 // Data encoding
#define EI_VERSION  6 // File version
#define EI_PAD      7 // Start of padding bytes
#define EI_NIDENT   16 // Size of e_ident[]

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

//section header indexes
#define SHN_UNDEF     0
#define SHN_LORESERVE 0xff00
#define SHN_LOPROC    0xff00
#define SHN_HIPROC    0xff1f
#define SHN_ABS       0xfff1
#define SHN_COMMON    0xfff2
#define SHN_HIRESERVE 0xffff

//section type
#define SHT_NULL     0   //it does not have an associated section
#define SHT_PROGBITS 1 // n holds information defined by the program
#define SHT_SYMTAB   2  // a symbol table
#define SHT_STRTAB   3  // n holds a string table
#define SHT_RELA     4 // holds relocation entries with explicit addends
#define SHT_HASH     5  //holds a symbol hash table
#define SHT_DYNAMIC  6 // n holds information for dynamic linking
#define SHT_NOTE     7  // n holds information that marks the file in some way
#define SHT_NOBITS   8  //occupies no space in the file but otherwise resembles SHT_PROGBITS
#define SHT_REL      9  //holds relocation entries without explicit addends, such as type Elf32_Rel
#define SHT_SHLIB    10 // reserved but has unspecified semantics.
#define SHT_DYNSYM   11  // a symbol table
#define SHT_LOPROC   0x70000000  //e reserved for processor-specific semantics.
#define SHT_HIPROC   0x7fffffff
#define SHT_LOUSER   0x80000000 // specifies the lower bound of the range of indexes reserved for application programs
#define SHT_HIUSER   0xffffffff

//sh_flags
#define SHF_WRITE 0x1
#define SHF_ALLOC 0x2
#define SHF_EXECINSTR 0x4
#define SHF_MASKPROC 0xf0000000

typedef unsigned int Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int Elf32_Off;
typedef unsigned int Elf32_Sword;
typedef unsigned int Elf32_Word;


/**
 * Elf32_Ehdr- the ELF header struct
 * @e_ident: identify file as an elf file
 * @e_type: identifies the object file type.
 * @e_machine: specifies the required architecture for an individual file.
 * @e_version: identifies the object file version.
 * @e_entry: gives the virtual address to which the system first transfers control.
 * @e_phoff: holds the program header table's file offset in bytes
 * @e_shoff: holds the section header table's file offset in bytes.
 * @e_flags: holds processor-specific flags associated with the file
 * @e_ehsize: This member holds the ELF header's size in bytes
 * @e_phentsize: holds the size in bytes of one entry in the file's program header table
 * @e_phnum: holds the number of entries in the program header table
 * @e_shentsize: holds a section header's size in bytes
 * @e_shnum: holds the number of entries in the section header table.
 * @e_shstrndx:holds the section header table index of the entry associated with the section name string table.
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
 * @sh_name: specifies the name of the section
 * @sh_type: categorizes the section's contents and semantics.
 * @sh_flags: support 1-bit flags that describe miscellaneous attributes
 * @sh_addr: gives the address at which the section's first byte should reside
 * @sh_offset: gives the byte offset from the beginning of the file to the first byte in the section
 * @sh_size: gives the section's size in bytes
 * @sh_link: holds a section header table index link
 * @sh_info: holds extra information, whose interpretation depends on the section type
 * @sh_addralign: alignment of section struct
 * @sh_entsize: gives the size in bytes of each entry in a table of fixed-size entries
 * 
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
