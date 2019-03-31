# NDN IoT Package 

This project aims at providing a m-in-one package for those who want to try a new networking protocol, the Named Data Networking (NDN), with their IoT apps on constrained devices, e.g., Nordic nRF58240 boards. Here "m" stands for the following 4 parts, from bottom to top: 

1) communication adapation layer, which handles different communication mediums with the support from operating system (like RIOT), software development kit (like Nordic SDK), or even the raw device drivers.

2) basic NDN layer, which offers basic networking layer functionalities, including the basic security support, following the latest NDN specification.

3) application support layer, which includes some useful buliding blocks to NDN applications, such as security bootstraping, service discover as well as access control.

4) an example application, where two parties are invovled: a network controller (runs on a android phone) and two devices (Nordic nRF58240 boards).

The first 3 parts together make the NDN-Lite library, while the example application, as a reference, shows how to develop a simple application with the NDN-Lite library. 
Details of NDN-Lite library can be found in: https://github.com/named-data-iot/ndn-lite/wiki

## Installation
Here follows a step-by-step instruction on how to compile the whole package and how to run the example application with the NDN-Lite library. As currently the library only contains full support for the nRF52840 board, the following instructions will be based on using ndn-lite and the example applications with the recommended IDE for nRF52840 board development, Segger Embedded Studio. It will also assume that Android Studio is used for Android development.

## Prerequisites
1) One or more nRF52840 boards
2) An Android phone
3) Make sure that Segger Embedded Studio (http://infocenter.nordicsemi.com/pdf/getting_started_ses.pdf) and Android Studio (https://developer.android.com/studio/) are installed and properly functioning on the machine you would like to use for development.
  
### Step One: Download and compile NDN-Lite into a Segger Embedded Studio project

#### a) Download the example Segger Embedded Studio project, or start a new Segger Embedded Studio project
A guide for that is here: https://drive.google.com/open?id=11yvFf8lpF1A96V9AFMaW8Cld3V1snaB1
      
#### b) Import the NDN-Lite library into your Segger Embedded Studio Project and Compile it

First you will need to download NDN-Lite; you can do so from here:
    https://github.com/named-data-iot/ndn-lite

Whether you choose to start a new Segger Embedded Studio project or start from the example (which can be downloaded here https://github.com/gujianxiao/ndn-lite-application-for-nRF52840-BLE_version), you will have to import the NDN-Lite library into your project in order to compile it. The guide for starting a new Segger Embedded Studio project linked in part a) above contains help for accomplishing this (particularly steps 3, 4, and the "Extra Advice" section).
      
### Step Two: Download the example applications

There is a pair of example applications meant to demonstrate how the NDN-Lite library can be used for Android to board and board to board communication.

#### a) Download the Android example application

You can find the Android example application and instructions for installing / using it here:
    https://github.com/gujianxiao/NDN-IoT-Android
    
#### b) Download the nRF52840 example application
    
You can find the nRF52840 example application and instructions for installing / using it here:
    https://github.com/gujianxiao/ndn-lite-application-for-nRF52840-BLE_version

## IMPORTANT NOTES

Please note the following things when building your application using the nRF5 SDK with ndn-lite:

### YOU MUST CALL THE ndn_lite_over_nrf_sdk_startup() FUNCTION AT THE BEGINNING OF YOUR MAIN FUNCTION, JUST LIKE THE EXAMPLE

This will initialize all things needed for the ndn-lite library over nRF5 SDK to function properly.

### DO NOT REINITIALIZE THE APP_TIMER LIBRARY

The ndn-lite library uses the nRF5 SDK's app_timer library (i.e., a multi-timer abstraction built on top of RTC1) in order to keep system time. DO NOT REINITIALIZE THIS app_timer LIBRARY WITH A CALL TO app_timer_init(). THIS WILL STOP THE NDN-LITE'S SYSTEM TIME IMPLEMENTATION FROM WORKING PROPERLY.

You can see for yourself that the app_timer library is initialized in the ndn_lite_over_nrf_sdk_startup() function.
