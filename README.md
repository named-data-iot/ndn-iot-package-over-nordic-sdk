# NDN IoT Package 

This project aims at providing a m-in-one package for those who want to try a new networking protocol, the Named Data Networking (NDN), with their IoT apps on constrained devices, e.g., Nordic nRF58240 boards. Here "m" stands for the following 4 parts, from bottom to top: 

1) communication adapation layer, which handels different communicate mediums with the support from operating system (like RIOT), software development kit (like Nordic SDK), or even the raw device drivers

2) basic NDN layer, which offers basic networking layer functionalities, including the basic security support, following the latest NDN specification

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
  
## Step 1) Download and compile NDN-Lite into a Segger Embedded Studio project

### a) Download the example Segger Embedded Studio project, or start a new Segger Embedded Studio project
A guide for that is here: https://drive.google.com/file/d/1mZEiv9JIDn57H9chCPhR2HgvpES6qa8M/view?usp=sharing
      
### b) Import the NDN-Lite library into your Segger Embedded Studio Project and Compile it

First you will need to download NDN-Lite; you can do so from here:
    https://github.com/named-data-iot/ndn-lite

Whether you choose to start a new Segger Embedded Studio project or start from the example (which can be downloaded here https://github.com/gujianxiao/ndn-lite-application-for-nRF52840-BLE_version), you will have to import the NDN-Lite library into your project in order to compile it. The guide for starting a new Segger Embedded Studio project linked in part a) above contains help for accomplishing this (particularly steps 3, 4, and the "Extra Advice" section).
      
## Step 2) Download the example applications

There is a pair of example applications meant to demonstrate how the NDN-Lite library can be used for Android to board and board to board communication.

### a) Download the Android example application

You can find the Android example application and instructions for installing / using it here:
    https://github.com/gujianxiao/NDN-IoT-Android
    
### b) Download the nRF52840 example application
    
You can find the nRF52840 example application and instructions for installing / using it here:
    https://github.com/gujianxiao/ndn-lite-application-for-nRF52840-BLE_version

