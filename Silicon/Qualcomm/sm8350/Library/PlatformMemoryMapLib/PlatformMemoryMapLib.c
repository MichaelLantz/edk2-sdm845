#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

    /* DDR Regions */
    /* DDR Bank 0 Start */
    {"Hypervisor",        0x80000000, 0x00600000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, /* Added */
    {"Axon DMA",          0x80600000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN}, /* Added */
    {"RAM Partition",     0x80700000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"AOP",               0x80800000, 0x00060000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN}, /* Added */
    {"AOP CMD DB",        0x80860000, 0x00020000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"GPU PRR",           0x80880000, 0x00010000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"TPMControl",        0x80890000, 0x00010000, AddMem, MEM_RES, WRITE_COMBINEABLE, RtData, UNCACHED_UNBUFFERED_XN},
    {"USB HLOS Shared",   0x808A0000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN},
    {"XBL LOGS",          0x808B0000, 0x00010000, AddMem, SYS_MEM, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"HLOS2",             0x808C0000, 0x00030000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"RAM Partition",     0x808F0000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"SMEM",              0x80900000, 0x00200000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"CPUCP FW",          0x80B00000, 0x00100000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN}, /* Added */
    {"HLOS3",             0x80C00000, 0x02F00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"LPASS_NPU",         0x83B00000, 0x00F00000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"ADSP RPC",          0x84A00000, 0x00800000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"PIL Reserved",      0x85200000, 0x09200000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
    {"DXE Heap",          0x8E400000, 0x10C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"UEFI FD2",          0x9F000000, 0x00500000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"SEC Heap",          0x9F500000, 0x0008C000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"CPU Vectors",       0x9F58C000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"MMU PageTables",    0x9F58D000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"UEFI Stack",        0x9F590000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"RAM Partition",     0x9F5D0000, 0x00027000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"Log Buffer",        0x9F5F7000, 0x00008000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
    {"Info Blk",          0x9F5FF000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
    {"Sched Resv Bckup",  0x9F600000, 0x00500000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"Sched Heap",        0x9FB00000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"FV Region",         0x9FF00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"HLOS4",             0xA0000000, 0x0EB00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN},
    {"HYP RESERVED",      0xAEB00000, 0x11500000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
    /* DDR Bank 0 End (0xB9700000) */
    /* Carveout Region (0xB9700000 -> 0xB9D00000, size 0x00600000) */
    /* DDR Bank 1 0xB9D00000 -> 0xBBB00000 */
    /* Carveout Region (0xBBB00000 -> 0xC0000000, size 0x04500000) */
    /* DDR Bank 2 Start */
    {"RAM Partition",     0xC0000000, 0x01800000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"TZApps",            0xC1800000, 0x03900000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {"DBI Dump",          0xC5100000, 0x01100000, NoHob,  MMAP_IO, INITIALIZED, Conv,   UNCACHED_UNBUFFERED_XN},
    {"RAM Partition",     0xC6200000, 0x09E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"UEFI FD",           0xD0000000, 0x00600000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"RAM Partition",     0xD0600000, 0x08200000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"Removed Mem",       0xD8800000, 0x01800000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN}, /* Added */
    {"TZApps Reserved",   0xDA000000, 0x03900000, HobOnlyNoCacheSetting, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN}, /* Added */
    {"RAM Partition",     0xDD900000, 0x03700000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */
    {"Display Reserved",  0xE1000000, 0x02400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN}, /* Added */
    {"Apps Hob",          0xE3400000, 0x00001000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN}, /* Added */
    {"RAM Partition",     0xE3401000, 0x5CBFF000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN}, /* Added */

    /* RAM partition regions */
    {"RAM Partition",     0x140000000,0x40000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"RAM Partition",    0x180000000,0x100000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    /* DDR Bank 2 End */

    /* Other memory regions */
    {"IMEM Base",         0x14680000, 0x00040000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {"IMEM Cookie Base",  0x146BF000, 0x00001000, AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},

    /* Register regions */
    {"IPC_ROUTER_TOP",    0x00400000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"SECURITY CONTROL",  0x00780000, 0x00007000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"QUP",               0x00800000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PRNG_CFG_PRNG",     0x010D0000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"CRYPTO0 CRYPTO",    0x01DC0000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TCSR_TCSR_REGS",    0x01F00000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PERIPH_SS",         0x08800000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"USB",               0x0A400000, 0x00C00000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"AOSS",              0x0B000000, 0x04000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_WEST",         0x0F100000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_SOUTH",        0x0F500000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"TLMM_NORTH",        0x0F900000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"SMMU",              0x15000000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"USB4",              0x15600000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"APSS_HM",           0x17800000, 0x00D99000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_0_AXI",        0x60000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_1_AXI",        0x40000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_2A_AXI",       0x3C000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_2B_AXI",       0x38000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_3A_AXI",       0x34000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_3B_AXI",       0x32000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_4_AXI",        0x30000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_0_AHB",        0x01C30000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_1_AHB",        0x01C28000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_2A_AHB",       0x01C20000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_2B_AHB",       0x01C18000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_3A_AHB",       0x01C10000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_3B_AHB",       0x01C08000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"PCIE_4_AHB",        0x01C00000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
  return gDeviceMemoryDescriptorEx;
}