This project aims at providing a m-in-one package for those who want to try a new networking protocol, the Named Data Networking (NDN), with their IoT apps on constrained devices, e.g., Nordic nRF58240 boards. Here "m" stands for the following 4 parts, from bottom to top: 

1) communication adapation layer, which handels different communicate mediums with the support from operating system (like RIOT), software development kit (like Nordic SDK), or even the raw device drivers

2) basic NDN layer, which offers basic networking layer functionalities, including the basic security support, following the latest NDN specification

3) application support layer, which includes some useful buliding blocks to NDN applications, such as security bootstraping, service discover as well as access control.

4) an example application, where two parties are invovled: a network controller (runs on a android phone) and two devices (Nordic nRF58240 boards).

The first 3 parts together make the NDN-Lite library, while the example application, as a reference, shows how to develop a simple application with the NDN-Lite library. Details of NDN-Lite library and the example application can be found in: 


Here follows a step-by-step instruction on how to compile the whole package and how to run the example application with the NDN-Lite library. As currently the library only contains full support for the nRF52840 board, the following instructions will be based on using ndn-lite and the example applications with the recommended IDE for nRF52840 board development, Segger Embedded Studio. It will also assume that Android Studio is used for Android development.

Things you will need:
  1) One or more nRF52840 boards
  2) An Android phone
  
Step 1) Install Segger Embedded Studio

    Segger Embedded Studio is the recommended IDE for development on the nRF52840; you can find detailed instructions for installing that here: 
    http://infocenter.nordicsemi.com/pdf/getting_started_ses.pdf
    You can also find a guide for starting a new Segger Embedded Studio project here:
    https://drive.google.com/file/d/1mZEiv9JIDn57H9chCPhR2HgvpES6qa8M/view?usp=sharing
    
Step 2) Install Android Studio

    To do development for your Android phone, you can use Android Studio. You can find installation instructions for that here: 
    https://developer.android.com/studio/
    
Step 3) Download the example applications

    There is a pair of example applications meant to demonstrate how the NDN-Lite library can be used for Android to board and board to board communication.
    You can find the Android example application and instructions for installing it here:
    https://github.com/gujianxiao/NDN-IoT-Android
    You can find the nRF52840 example application and instructions for installing it here:
    https://github.com/gujianxiao/ndn-lite-application-for-nRF52840-BLE_version
    
Step 4) Download the NDN-Lite library

    You will need to download the NDN-Lite library separately from the example application.
    You can download the NDN-Lite library from here:
    https://github.com/named-data-iot/ndn-lite
    In order to add the NDN-Lite library to the Segger Embedded Studio example project downloaded in Step 3), you can follow the guide to starting a new Segger Embedded Studio project linked in Step 1) (steps 3, 4, and the "Extra Advice" section of that document will be particularly helpful in getting the NDN-Lite library to compile within your Segger Embedded Studio project).
