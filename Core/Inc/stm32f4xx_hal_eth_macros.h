//
// Created by Nando on 13/11/2022.
//

#ifndef SALT_STM32_STM32F4XX_HAL_ETH_MACROS_H
#define SALT_STM32_STM32F4XX_HAL_ETH_MACROS_H

/** @addtogroup ETH
 * @{
 */



/** @defgroup ETH_Duplex_Mode ETH Duplex Mode
 * @{
 */
#define ETH_MODE_FULLDUPLEX    ( ( uint32_t ) 0x00000800U )
#define ETH_MODE_HALFDUPLEX    ( ( uint32_t ) 0x00000000U )

/* Ethernet DMA Rx descriptors Frame length Shift */
#define  ETH_DMARXDESC_FRAMELENGTHSHIFT                   ( ( uint32_t ) 16U )

/* Ethernet MAC address offsets */
#define ETH_MAC_ADDR_HBASE      ( uint32_t ) ( ETH_MAC_BASE + ( uint32_t ) 0x40U ) \
/* Ethernet MAC address high offset */
#define ETH_MAC_ADDR_LBASE      ( uint32_t ) ( ETH_MAC_BASE + ( uint32_t ) 0x44U ) \
/* Ethernet MAC address low offset */










#endif //SALT_STM32_STM32F4XX_HAL_ETH_MACROS_H
