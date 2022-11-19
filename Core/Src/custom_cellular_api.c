//
// Created by Nando on 18/11/2022.
//

// #include "cellular_types.h"

// CellularHandle_t CellularHandle

/* FreeRTOS Cellular Library API. */


//#include "../../FreeRTOS-Cellular-Interface/source/include/cellular_types.h"

#include <stdio.h>
#include "../../FreeRTOS-Cellular-Interface/source/include/cellular_api.h"

CellularError_t Cellular_SocketConnect(
        CellularHandle_t cellularHandle,
        CellularSocketHandle_t socketHandle,
        CellularSocketAccessMode_t dataAccessMode,
        const CellularSocketAddress_t * pRemoteSocketAddress
) {

    printf("socket connect");

    return CELLULAR_SUCCESS;
}

CellularError_t Cellular_SocketSend(
        CellularHandle_t cellularHandle,
         CellularSocketHandle_t socketHandle,
         const uint8_t * pData,
         uint32_t dataLength,
         uint32_t * pSentDataLength
 ) {
    return CELLULAR_SUCCESS;
}

CellularError_t Cellular_SocketRecv( CellularHandle_t cellularHandle,
                                     CellularSocketHandle_t socketHandle,
                                     uint8_t * pBuffer,
                                     uint32_t bufferLength,
                                     uint32_t * pReceivedDataLength ) {
    return CELLULAR_SUCCESS;
}

CellularError_t Cellular_SocketClose(
        CellularHandle_t cellularHandle,
        CellularSocketHandle_t socketHandle
) {
    return CELLULAR_SOCKET_CLOSED;
}

CellularError_t Cellular_SocketRegisterSocketOpenCallback(
        CellularHandle_t cellularHandle,
        CellularSocketHandle_t socketHandle,
        CellularSocketOpenCallback_t socketOpenCallback,
        void * pCallbackContext
) {
    return CELLULAR_SUCCESS;
}

CellularError_t Cellular_SocketRegisterDataReadyCallback(
        CellularHandle_t cellularHandle,
      CellularSocketHandle_t socketHandle,
      CellularSocketDataReadyCallback_t dataReadyCallback,
      void * pCallbackContext
) {
    return CELLULAR_SUCCESS;
}


CellularError_t Cellular_SocketRegisterClosedCallback(
        CellularHandle_t cellularHandle,
        CellularSocketHandle_t socketHandle,
        CellularSocketClosedCallback_t closedCallback,
        void * pCallbackContext )
{
    return CELLULAR_SOCKET_CLOSED;
}

CellularError_t Cellular_CreateSocket( CellularHandle_t cellularHandle,
                                       uint8_t pdnContextId,
                                       CellularSocketDomain_t socketDomain,
                                       CellularSocketType_t socketType,
                                       CellularSocketProtocol_t socketProtocol,
                                       CellularSocketHandle_t * pSocketHandle ) {
    return CELLULAR_SUCCESS;
}








