/* Copyright 2014, Mariano Cerdeiro
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Short description of this file
 **
 ** Long description of this file
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Template Template to start a new module
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaak.h"
/* TODO configuration dependent includes */
#include "ciaaDevices.h"
#include "ciaaSerialDevices.h"
#include "ciaaBlockDevices.h"
#include "ciaaDriverUart.h"
#include "ciaaDriverFlash.h"
#include "ciaaDriverAio.h"
#include "ciaaDriverDio.h"

#include "ciaaPOSIX_stdlib.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void ciaak_start(void)
{
   /* init stdlib */
   /* ATTENTION: ciaaPOSIX_stdlib_init has to be done before to any call to
    * ciaaPOSIX_malloc or ciaak_malloc */
   ciaaPOSIX_stdlib_init();

   /* init device manager */
   ciaaDevices_init();

   /* init devices types */
   ciaaSerialDevices_init();
   ciaaBlockDevices_init();

   /* init drivers */
   //ciaaDriverUart_init();
   ciaaDriverFlash_init();

   /* ciaaDioDevices_init(); */
   ciaaDriverDio_init();

   ciaaDriverAio_init();
}

void *ciaak_malloc(size_t size)
{
   /* try to alloc memory */
   void* ret = ciaaPOSIX_malloc(size);

   /* kernel memory shall not failed :( */
   if (NULL == ret)
   {
      ciaaPOSIX_printf("Kernel out of memory :( ...\n");
      while(1)
      {
         /* TODO perform an kernel panic or like */
      }
   }

   return ret;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

