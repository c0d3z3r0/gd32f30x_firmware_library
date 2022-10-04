/*!
    \file  exmc_nandflash.h
    \brief the header file of nandflash(hynix HY27UF081G2A) driver
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-02-10, V1.0.0, firmware for GD32F30x
*/

#ifndef EXMC_NANDFLASH_H
#define EXMC_NANDFLASH_H

#include "gd32f30x.h"

/* NAND area definition */
/* A16 = CLE high command area */
#define EXMC_CMD_AREA              (uint32_t)(1<<16)
/* A17 = ALE high address area */
#define EXMC_ADDR_AREA             (uint32_t)(1<<17)
/* data area */
#define EXMC_DATA_AREA             ((uint32_t)0x00000000)

/* NAND memory command (hynix HY27UF081G2A) */
#define NAND_CMD_READ1_1ST         ((uint8_t)0x00)
#define NAND_CMD_READ1_2ND         ((uint8_t)0x30)
#define NAND_CMD_WRITE_1ST         ((uint8_t)0x80)
#define NAND_CMD_WRITE_2ND         ((uint8_t)0x10)
#define NAND_CMD_ERASE_1ST         ((uint8_t)0x60)
#define NAND_CMD_ERASE_2ND         ((uint8_t)0xD0)
#define NAND_CMD_READID            ((uint8_t)0x90)
#define NAND_CMD_STATUS            ((uint8_t)0x70)
#define NAND_CMD_LOCK_STATUS       ((uint8_t)0x7A)
#define NAND_CMD_RESET             ((uint8_t)0xFF)

/* NAND memory status */
#define NAND_BUSY                  ((uint8_t)0x00)
#define NAND_ERROR                 ((uint8_t)0x01)
#define NAND_READY                 ((uint8_t)0x40)
#define NAND_TIMEOUT_ERROR         ((uint8_t)0x80)

/* NAND memory parameters */
/* NAND zone count */
#define NAND_ZONE_COUNT            ((uint16_t)0x0001)

/* 1024 block per zone */
#define NAND_ZONE_SIZE             ((uint16_t)0x0400)

/* 64 pages per block */
#define NAND_BLOCK_SIZE            ((uint16_t)0x0040)

/* 2 * 1024 bytes per page */
#define NAND_PAGE_SIZE             ((uint16_t)0x0800)

/* last 64 bytes as spare area */
#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x0040)

/* total page size = page size + spare are size */
#define NAND_PAGE_TOTAL_SIZE       (NAND_PAGE_SIZE + NAND_SPARE_AREA_SIZE)

/* max read and write address */
#define NAND_MAX_ADDRESS           (((NAND_ZONE_COUNT*NAND_ZONE_SIZE)*NAND_BLOCK_SIZE)*NAND_PAGE_SIZE)

/* block count */
#define NAND_BLOCK_COUNT            1024

/* NAND memory address computation */
#define ADDR_1ST_CYCLE(ADDR)       (uint8_t)((ADDR)& 0xFF)
#define ADDR_2ND_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF00) >> 8)
#define ADDR_3RD_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF0000) >> 16)
#define ADDR_4TH_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF000000) >> 24)

/* define return value of functions */
#define NAND_OK                    0
#define NAND_FAIL                  1

/* NAND id structure */
typedef struct
{
    uint8_t maker_id;
    uint8_t device_id;
    uint8_t third_id;
    uint8_t fourth_id;
}nand_id_struct;

typedef struct 
{
    uint16_t zone;
    uint16_t block;
    uint16_t page;
    uint16_t page_in_offset;
} nand_address_struct;

/* function declarations */
/* nand flash peripheral initialize */
void exmc_nandflash_init(void);
/* read NAND flash ID */
void nand_read_id(nand_id_struct* nand_id);
/* write the spare area information for the specified pages addresses */
uint8_t exmc_nand_writespare(uint8_t *pbuffer, nand_address_struct address, uint16_t bytecount);
/* read the spare area information for the specified pages addresses */
uint8_t exmc_nand_readspare(uint8_t *pbuffer, nand_address_struct address, uint16_t bytecount);
/* reset nand flash */
uint8_t nand_reset(void);
/* write the main area information for the specified logic addresses */
uint8_t nand_write(uint32_t memaddr, uint8_t *pwritebuf, uint16_t bytecount);
/* read the main area information for the specified logic addresses */
uint8_t nand_read(uint32_t mem_addr, uint8_t *preadbuf, uint16_t bytecount);
/* format nand flash */
uint8_t nand_format(void);
/* fill the buffer with specified value */
void fill_buffer_nand(uint8_t *pbuffer, uint16_t buffer_lenght, uint32_t value);

#endif /* EXMC_NANDFLASH_H */
