/*!
    \file  readme.txt
    \brief description of the USB HID LPM Test demo

    \version 2017-02-10, V1.0.0, firmware for GD32F30x
    \version 2018-10-10, V1.1.0, firmware for GD32F30x
    \version 2018-12-25, V2.0.0, firmware for GD32F30x
*/

/*
    Copyright (c) 2018, GigaDevice Semiconductor Inc.

    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

  This demo is based on the GD32303E-EVAL-V1.1 board,it provides a description of 
how to test the USB LPM (Link Power Management) Feature.

  The demo is based on HID Keyboard example. All modifications versus original HID 
example are under #ifdef LPM_ENABLED which is defined in usb_conf.h file.

  When LPM packet is received from Host, GD32 USB will Acknowledge the LPM packet
and it will enter in L1 suspend mode. During USB L1 suspend mode, system will be
in STOP low power mode.

  On Host L1 resume, GD32 will wakeup from STOP and USB resumes operations.

  The demo also implements the USB L1 remote-wakeup, which allows device to wakeup
host during L1 suspend. L1 remote wakeup is initiated when pressing the Tamper button.

  You can test L1 suspend/resume, by running the USBCV3.0 chapter9 for USB2.0 devices 
and select (in debug mode) test "TD9.21: LPM L1 Suspend Resume Test".
  Please note that for running USBCV3.0, you'll need a PC with a USB3.0 (xHCI) host 
controller (please refer to USBCV3.0 documentation for more informations).

  You can also find in folder .\USBCV3.0_Test, the full USBCV3.0 chapter9 test report
showing the USB trace for the LPM test.

  As it can be seen in the trace, GD32 Acknowledges the LPM packet, then after 50us 
resume, GD32 is ready to receive transactions from host, it answers a GetDescriptor
request.